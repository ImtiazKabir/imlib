cmake_minimum_required(VERSION 3.29)
project(Imlib C)

set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_BUILD_TYPE Debug)

include_directories(include)

file(GLOB_RECURSE MAIN_SOURCES "src/*.c")
add_executable(main ${MAIN_SOURCES})
target_compile_features(main PRIVATE c_std_90)
set_target_properties(main PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build
)
target_compile_options(main PRIVATE
  -g3 -ggdb
  -Wall -Wextra -pedantic -Wparentheses -Wformat=2
  -Wshadow -Wwrite-strings -Wredundant-decls -Wmissing-include-dirs
  -pedantic-errors -Wuninitialized -Wmissing-declarations -Wconversion
  -Wdouble-promotion -Wfloat-equal -Wmain -Wundef
  -Wstrict-prototypes -Wnested-externs -Wold-style-definition
  -Wbad-function-cast -Wno-unknown-pragmas -Wno-unused-function
  -fno-strict-aliasing
)

file(GLOB_RECURSE TEST_SOURCES "test/*.c")
list(APPEND TEST_SOURCES ${MAIN_SOURCES})
list(REMOVE_ITEM TEST_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/main.c")
add_executable(test ${TEST_SOURCES})
target_compile_features(test PRIVATE c_std_99)
set_target_properties(test PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/test)
target_compile_options(test PRIVATE
  -g3 -ggdb -Wno-dangling-else
  -Wall -Wextra -pedantic -Wparentheses -Wformat=2
  -Wshadow -Wwrite-strings -Wredundant-decls -Wmissing-include-dirs
  -pedantic-errors -Wuninitialized -Wmissing-declarations -Wconversion
  -Wdouble-promotion -Wfloat-equal -Wmain -Wundef
  -Wstrict-prototypes -Wnested-externs -Wold-style-definition
  -Wbad-function-cast -Wno-unknown-pragmas -Wno-unused-function
  -fno-strict-aliasing
)
target_link_libraries(test criterion)

