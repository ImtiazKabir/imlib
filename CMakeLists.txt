cmake_minimum_required(VERSION 3.29)
project(Imlib C)

include_directories(include)
file(GLOB_RECURSE SOURCES "src/*.c")
add_executable(main ${SOURCES})

target_compile_features(main PRIVATE c_std_90)
set(CMAKE_C_STANDARD_REQUIRED True)


set_target_properties(main PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build
)

set(CMAKE_BUILD_TYPE Debug)


target_compile_options(main PRIVATE
  -g3 -ggdb -Wno-dangling-else
  -Wall -Wextra -pedantic -Wparentheses -Wformat=2
  -Wshadow -Wwrite-strings -Wredundant-decls -Wmissing-include-dirs
  -pedantic-errors -Wuninitialized -Wmissing-declarations -Wconversion
  -Wdouble-promotion -Wfloat-equal -Wmain -Wundef
  -Wstrict-prototypes -Wnested-externs -Wold-style-definition
  -Wbad-function-cast -Wno-unknown-pragmas -Wno-unused-function
  -fno-strict-aliasing
)
