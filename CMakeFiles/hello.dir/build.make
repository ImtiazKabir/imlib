# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/imkabir/c_programming/imlib

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/imkabir/c_programming/imlib

# Include any dependencies generated for this target.
include CMakeFiles/hello.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/hello.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/hello.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hello.dir/flags.make

CMakeFiles/hello.dir/examples/hello.c.o: CMakeFiles/hello.dir/flags.make
CMakeFiles/hello.dir/examples/hello.c.o: examples/hello.c
CMakeFiles/hello.dir/examples/hello.c.o: CMakeFiles/hello.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/imkabir/c_programming/imlib/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/hello.dir/examples/hello.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/hello.dir/examples/hello.c.o -MF CMakeFiles/hello.dir/examples/hello.c.o.d -o CMakeFiles/hello.dir/examples/hello.c.o -c /home/imkabir/c_programming/imlib/examples/hello.c

CMakeFiles/hello.dir/examples/hello.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/hello.dir/examples/hello.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/imkabir/c_programming/imlib/examples/hello.c > CMakeFiles/hello.dir/examples/hello.c.i

CMakeFiles/hello.dir/examples/hello.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/hello.dir/examples/hello.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/imkabir/c_programming/imlib/examples/hello.c -o CMakeFiles/hello.dir/examples/hello.c.s

# Object files for target hello
hello_OBJECTS = \
"CMakeFiles/hello.dir/examples/hello.c.o"

# External object files for target hello
hello_EXTERNAL_OBJECTS =

examples/hello: CMakeFiles/hello.dir/examples/hello.c.o
examples/hello: CMakeFiles/hello.dir/build.make
examples/hello: lib/libimlib.a
examples/hello: CMakeFiles/hello.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/imkabir/c_programming/imlib/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable examples/hello"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hello.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hello.dir/build: examples/hello
.PHONY : CMakeFiles/hello.dir/build

CMakeFiles/hello.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hello.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hello.dir/clean

CMakeFiles/hello.dir/depend:
	cd /home/imkabir/c_programming/imlib && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/imkabir/c_programming/imlib /home/imkabir/c_programming/imlib /home/imkabir/c_programming/imlib /home/imkabir/c_programming/imlib /home/imkabir/c_programming/imlib/CMakeFiles/hello.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/hello.dir/depend

