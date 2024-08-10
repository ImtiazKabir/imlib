cmake_minimum_required(VERSION 3.29)
project(Imlib C)

set(CMAKE_C_STANDARD 90)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_BUILD_TYPE Debug)

include_directories(include)
file(GLOB EXAMPLE_FILES "examples/*.c")
file(GLOB_RECURSE IMLIB_SOURCES "src/*.c")

add_compile_options(
  -g3 -ggdb
  -fsanitize=address,undefined,leak,null,alignment
  -Wall -Wextra -pedantic -Wparentheses -Wformat=2
  -Wshadow -Wwrite-strings -Wredundant-decls -Wmissing-include-dirs
  -pedantic-errors -Wuninitialized -Wmissing-declarations -Wconversion
  -Wdouble-promotion -Wfloat-equal -Wmain -Wundef
  -Wstrict-prototypes -Wnested-externs -Wold-style-definition
  -Wbad-function-cast -Wno-unknown-pragmas -Wno-unused-function
  -fno-strict-aliasing
)
add_link_options(-fsanitize=address,undefined,leak,null,alignment)

# Set the output directory for the library
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)

# Create the static library
add_library(imlib STATIC ${IMLIB_SOURCES})

# Set the output directory for the examples
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/examples)

# Link each example with the static library
foreach(EXAMPLE_FILE ${EXAMPLE_FILES})
  get_filename_component(EXAMPLE_NAME ${EXAMPLE_FILE} NAME_WE)
  add_executable(${EXAMPLE_NAME} ${EXAMPLE_FILE})
  target_link_libraries(${EXAMPLE_NAME} imlib)
endforeach()

