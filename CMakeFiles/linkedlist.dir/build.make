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
include CMakeFiles/linkedlist.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/linkedlist.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/linkedlist.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/linkedlist.dir/flags.make

CMakeFiles/linkedlist.dir/examples/linkedlist.c.o: CMakeFiles/linkedlist.dir/flags.make
CMakeFiles/linkedlist.dir/examples/linkedlist.c.o: examples/linkedlist.c
CMakeFiles/linkedlist.dir/examples/linkedlist.c.o: CMakeFiles/linkedlist.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/imkabir/c_programming/imlib/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/linkedlist.dir/examples/linkedlist.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/linkedlist.dir/examples/linkedlist.c.o -MF CMakeFiles/linkedlist.dir/examples/linkedlist.c.o.d -o CMakeFiles/linkedlist.dir/examples/linkedlist.c.o -c /home/imkabir/c_programming/imlib/examples/linkedlist.c

CMakeFiles/linkedlist.dir/examples/linkedlist.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/linkedlist.dir/examples/linkedlist.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/imkabir/c_programming/imlib/examples/linkedlist.c > CMakeFiles/linkedlist.dir/examples/linkedlist.c.i

CMakeFiles/linkedlist.dir/examples/linkedlist.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/linkedlist.dir/examples/linkedlist.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/imkabir/c_programming/imlib/examples/linkedlist.c -o CMakeFiles/linkedlist.dir/examples/linkedlist.c.s

# Object files for target linkedlist
linkedlist_OBJECTS = \
"CMakeFiles/linkedlist.dir/examples/linkedlist.c.o"

# External object files for target linkedlist
linkedlist_EXTERNAL_OBJECTS =

examples/linkedlist: CMakeFiles/linkedlist.dir/examples/linkedlist.c.o
examples/linkedlist: CMakeFiles/linkedlist.dir/build.make
examples/linkedlist: lib/libimlib.a
examples/linkedlist: CMakeFiles/linkedlist.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/imkabir/c_programming/imlib/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable examples/linkedlist"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/linkedlist.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/linkedlist.dir/build: examples/linkedlist
.PHONY : CMakeFiles/linkedlist.dir/build

CMakeFiles/linkedlist.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/linkedlist.dir/cmake_clean.cmake
.PHONY : CMakeFiles/linkedlist.dir/clean

CMakeFiles/linkedlist.dir/depend:
	cd /home/imkabir/c_programming/imlib && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/imkabir/c_programming/imlib /home/imkabir/c_programming/imlib /home/imkabir/c_programming/imlib /home/imkabir/c_programming/imlib /home/imkabir/c_programming/imlib/CMakeFiles/linkedlist.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/linkedlist.dir/depend

