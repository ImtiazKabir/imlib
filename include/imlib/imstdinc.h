#ifndef IMSTDINC_H_
#define IMSTDINC_H_

#ifndef PRIVATE
#define PRIVATE static
#endif /* !PRIVATE */

#ifndef PROTECTED
#define PROTECTED /* PROTECTED */
#endif            /* !PROTECTED */

#ifndef PUBLIC
#define PUBLIC extern
#endif

typedef enum { IM_FALSE, IM_TRUE } ImBool;

#define REINTERPRET_CAST(type, value) *(type *)&value

#endif /* !IMSTDINC_H_ */
