# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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
include CMakeFiles/test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/test.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test.dir/flags.make

CMakeFiles/test.dir/test/string.c.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/test/string.c.o: test/string.c
CMakeFiles/test.dir/test/string.c.o: CMakeFiles/test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/imkabir/c_programming/imlib/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/test.dir/test/string.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/test.dir/test/string.c.o -MF CMakeFiles/test.dir/test/string.c.o.d -o CMakeFiles/test.dir/test/string.c.o -c /home/imkabir/c_programming/imlib/test/string.c

CMakeFiles/test.dir/test/string.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/test.dir/test/string.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/imkabir/c_programming/imlib/test/string.c > CMakeFiles/test.dir/test/string.c.i

CMakeFiles/test.dir/test/string.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/test.dir/test/string.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/imkabir/c_programming/imlib/test/string.c -o CMakeFiles/test.dir/test/string.c.s

CMakeFiles/test.dir/src/e4c.c.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/src/e4c.c.o: src/e4c.c
CMakeFiles/test.dir/src/e4c.c.o: CMakeFiles/test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/imkabir/c_programming/imlib/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/test.dir/src/e4c.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/test.dir/src/e4c.c.o -MF CMakeFiles/test.dir/src/e4c.c.o.d -o CMakeFiles/test.dir/src/e4c.c.o -c /home/imkabir/c_programming/imlib/src/e4c.c

CMakeFiles/test.dir/src/e4c.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/test.dir/src/e4c.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/imkabir/c_programming/imlib/src/e4c.c > CMakeFiles/test.dir/src/e4c.c.i

CMakeFiles/test.dir/src/e4c.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/test.dir/src/e4c.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/imkabir/c_programming/imlib/src/e4c.c -o CMakeFiles/test.dir/src/e4c.c.s

CMakeFiles/test.dir/src/imclass.c.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/src/imclass.c.o: src/imclass.c
CMakeFiles/test.dir/src/imclass.c.o: CMakeFiles/test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/imkabir/c_programming/imlib/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/test.dir/src/imclass.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/test.dir/src/imclass.c.o -MF CMakeFiles/test.dir/src/imclass.c.o.d -o CMakeFiles/test.dir/src/imclass.c.o -c /home/imkabir/c_programming/imlib/src/imclass.c

CMakeFiles/test.dir/src/imclass.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/test.dir/src/imclass.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/imkabir/c_programming/imlib/src/imclass.c > CMakeFiles/test.dir/src/imclass.c.i

CMakeFiles/test.dir/src/imclass.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/test.dir/src/imclass.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/imkabir/c_programming/imlib/src/imclass.c -o CMakeFiles/test.dir/src/imclass.c.s

CMakeFiles/test.dir/src/imerrno.c.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/src/imerrno.c.o: src/imerrno.c
CMakeFiles/test.dir/src/imerrno.c.o: CMakeFiles/test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/imkabir/c_programming/imlib/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/test.dir/src/imerrno.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/test.dir/src/imerrno.c.o -MF CMakeFiles/test.dir/src/imerrno.c.o.d -o CMakeFiles/test.dir/src/imerrno.c.o -c /home/imkabir/c_programming/imlib/src/imerrno.c

CMakeFiles/test.dir/src/imerrno.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/test.dir/src/imerrno.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/imkabir/c_programming/imlib/src/imerrno.c > CMakeFiles/test.dir/src/imerrno.c.i

CMakeFiles/test.dir/src/imerrno.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/test.dir/src/imerrno.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/imkabir/c_programming/imlib/src/imerrno.c -o CMakeFiles/test.dir/src/imerrno.c.s

CMakeFiles/test.dir/src/imlog.c.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/src/imlog.c.o: src/imlog.c
CMakeFiles/test.dir/src/imlog.c.o: CMakeFiles/test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/imkabir/c_programming/imlib/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/test.dir/src/imlog.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/test.dir/src/imlog.c.o -MF CMakeFiles/test.dir/src/imlog.c.o.d -o CMakeFiles/test.dir/src/imlog.c.o -c /home/imkabir/c_programming/imlib/src/imlog.c

CMakeFiles/test.dir/src/imlog.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/test.dir/src/imlog.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/imkabir/c_programming/imlib/src/imlog.c > CMakeFiles/test.dir/src/imlog.c.i

CMakeFiles/test.dir/src/imlog.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/test.dir/src/imlog.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/imkabir/c_programming/imlib/src/imlog.c -o CMakeFiles/test.dir/src/imlog.c.s

CMakeFiles/test.dir/src/immem.c.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/src/immem.c.o: src/immem.c
CMakeFiles/test.dir/src/immem.c.o: CMakeFiles/test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/imkabir/c_programming/imlib/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/test.dir/src/immem.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/test.dir/src/immem.c.o -MF CMakeFiles/test.dir/src/immem.c.o.d -o CMakeFiles/test.dir/src/immem.c.o -c /home/imkabir/c_programming/imlib/src/immem.c

CMakeFiles/test.dir/src/immem.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/test.dir/src/immem.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/imkabir/c_programming/imlib/src/immem.c > CMakeFiles/test.dir/src/immem.c.i

CMakeFiles/test.dir/src/immem.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/test.dir/src/immem.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/imkabir/c_programming/imlib/src/immem.c -o CMakeFiles/test.dir/src/immem.c.s

CMakeFiles/test.dir/src/imstr.c.o: CMakeFiles/test.dir/flags.make
CMakeFiles/test.dir/src/imstr.c.o: src/imstr.c
CMakeFiles/test.dir/src/imstr.c.o: CMakeFiles/test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/imkabir/c_programming/imlib/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/test.dir/src/imstr.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/test.dir/src/imstr.c.o -MF CMakeFiles/test.dir/src/imstr.c.o.d -o CMakeFiles/test.dir/src/imstr.c.o -c /home/imkabir/c_programming/imlib/src/imstr.c

CMakeFiles/test.dir/src/imstr.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/test.dir/src/imstr.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/imkabir/c_programming/imlib/src/imstr.c > CMakeFiles/test.dir/src/imstr.c.i

CMakeFiles/test.dir/src/imstr.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/test.dir/src/imstr.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/imkabir/c_programming/imlib/src/imstr.c -o CMakeFiles/test.dir/src/imstr.c.s

# Object files for target test
test_OBJECTS = \
"CMakeFiles/test.dir/test/string.c.o" \
"CMakeFiles/test.dir/src/e4c.c.o" \
"CMakeFiles/test.dir/src/imclass.c.o" \
"CMakeFiles/test.dir/src/imerrno.c.o" \
"CMakeFiles/test.dir/src/imlog.c.o" \
"CMakeFiles/test.dir/src/immem.c.o" \
"CMakeFiles/test.dir/src/imstr.c.o"

# External object files for target test
test_EXTERNAL_OBJECTS =

test/test: CMakeFiles/test.dir/test/string.c.o
test/test: CMakeFiles/test.dir/src/e4c.c.o
test/test: CMakeFiles/test.dir/src/imclass.c.o
test/test: CMakeFiles/test.dir/src/imerrno.c.o
test/test: CMakeFiles/test.dir/src/imlog.c.o
test/test: CMakeFiles/test.dir/src/immem.c.o
test/test: CMakeFiles/test.dir/src/imstr.c.o
test/test: CMakeFiles/test.dir/build.make
test/test: CMakeFiles/test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/imkabir/c_programming/imlib/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking C executable test/test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test.dir/build: test/test
.PHONY : CMakeFiles/test.dir/build

CMakeFiles/test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test.dir/clean

CMakeFiles/test.dir/depend:
	cd /home/imkabir/c_programming/imlib && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/imkabir/c_programming/imlib /home/imkabir/c_programming/imlib /home/imkabir/c_programming/imlib /home/imkabir/c_programming/imlib /home/imkabir/c_programming/imlib/CMakeFiles/test.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/test.dir/depend
