#include "imlib/imerrno.h"

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "imlib/imlog.h"
#include "imlib/imstdinc.h"

/* Thread-local storage keys for error code and error message */
static pthread_key_t errcode_key;
static pthread_key_t errmsg_key;
static pthread_once_t key_once = PTHREAD_ONCE_INIT;

PRIVATE char *__dupstr__(char const *src) {
  return strcpy(calloc(strlen(src) + 1u, sizeof(*src)), src);
}

/* Initialize thread-local storage keys */
PRIVATE void create_keys(void) {
  pthread_key_create(&errcode_key, NULL);
  pthread_key_create(&errmsg_key, free);
}

/* Set the thread-local error code and message */
PUBLIC void imerr(int errcode, char const *errmsg) {
  int *perr;
  char *msg;

  pthread_once(&key_once, create_keys);

  /* Set the error code */
  perr = pthread_getspecific(errcode_key);
  if (perr == NULL) {
    perr = (int *)malloc(sizeof(int));
    pthread_setspecific(errcode_key, perr);
  }
  *perr = errcode;

  /* Set the error message */
  msg = pthread_getspecific(errmsg_key);
  if (msg != NULL) {
    free(msg);
  }
  msg = __dupstr__(errmsg);
  pthread_setspecific(errmsg_key, msg);
}

/* Get the current thread-local error code */
PUBLIC int imerrno(void) {
  int *perr;

  pthread_once(&key_once, create_keys);
  perr = pthread_getspecific(errcode_key);
  return perr ? *perr : IM_OK; /* Return IM_OK if no error is set */
}

/* Get the current thread-local error message */
PUBLIC char const *imerrmsg(void) {
  char *msg;

  pthread_once(&key_once, create_keys);
  msg = pthread_getspecific(errmsg_key);
  return msg ? msg : IM_OK_MSG; /* Return "No error" if no message is set */
}

/* Clear the error code and message */
PUBLIC void imclrerr(void) {
  int *perr;
  char *msg;

  pthread_once(&key_once, create_keys);

  /* Clear the error code */
  perr = pthread_getspecific(errcode_key);
  if (perr != NULL) {
    free(perr);
    pthread_setspecific(errcode_key, NULL);
  }

  /* Free the error message buffer if it is not NULL */
  msg = pthread_getspecific(errmsg_key);
  if (msg != NULL) {
    free(msg);
    pthread_setspecific(errmsg_key, NULL);
  }
}

PUBLIC void imperror(char const *str) {
  char *msg = pthread_getspecific(errmsg_key);
  if ((msg != NULL) && (*msg != '\0')) {
    imlogf2(LOG_ERROR, stderr, "%s: %s\n", str, msg);
  }
}
