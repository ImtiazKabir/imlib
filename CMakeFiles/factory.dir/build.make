# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
include CMakeFiles/factory.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/factory.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/factory.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/factory.dir/flags.make

CMakeFiles/factory.dir/codegen:
.PHONY : CMakeFiles/factory.dir/codegen

CMakeFiles/factory.dir/examples/factory/button.c.o: CMakeFiles/factory.dir/flags.make
CMakeFiles/factory.dir/examples/factory/button.c.o: examples/factory/button.c
CMakeFiles/factory.dir/examples/factory/button.c.o: CMakeFiles/factory.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/imkabir/c_programming/imlib/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/factory.dir/examples/factory/button.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/factory.dir/examples/factory/button.c.o -MF CMakeFiles/factory.dir/examples/factory/button.c.o.d -o CMakeFiles/factory.dir/examples/factory/button.c.o -c /home/imkabir/c_programming/imlib/examples/factory/button.c

CMakeFiles/factory.dir/examples/factory/button.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/factory.dir/examples/factory/button.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/imkabir/c_programming/imlib/examples/factory/button.c > CMakeFiles/factory.dir/examples/factory/button.c.i

CMakeFiles/factory.dir/examples/factory/button.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/factory.dir/examples/factory/button.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/imkabir/c_programming/imlib/examples/factory/button.c -o CMakeFiles/factory.dir/examples/factory/button.c.s

CMakeFiles/factory.dir/examples/factory/dialog.c.o: CMakeFiles/factory.dir/flags.make
CMakeFiles/factory.dir/examples/factory/dialog.c.o: examples/factory/dialog.c
CMakeFiles/factory.dir/examples/factory/dialog.c.o: CMakeFiles/factory.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/imkabir/c_programming/imlib/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/factory.dir/examples/factory/dialog.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/factory.dir/examples/factory/dialog.c.o -MF CMakeFiles/factory.dir/examples/factory/dialog.c.o.d -o CMakeFiles/factory.dir/examples/factory/dialog.c.o -c /home/imkabir/c_programming/imlib/examples/factory/dialog.c

CMakeFiles/factory.dir/examples/factory/dialog.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/factory.dir/examples/factory/dialog.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/imkabir/c_programming/imlib/examples/factory/dialog.c > CMakeFiles/factory.dir/examples/factory/dialog.c.i

CMakeFiles/factory.dir/examples/factory/dialog.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/factory.dir/examples/factory/dialog.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/imkabir/c_programming/imlib/examples/factory/dialog.c -o CMakeFiles/factory.dir/examples/factory/dialog.c.s

CMakeFiles/factory.dir/examples/factory/htmlbutton.c.o: CMakeFiles/factory.dir/flags.make
CMakeFiles/factory.dir/examples/factory/htmlbutton.c.o: examples/factory/htmlbutton.c
CMakeFiles/factory.dir/examples/factory/htmlbutton.c.o: CMakeFiles/factory.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/imkabir/c_programming/imlib/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/factory.dir/examples/factory/htmlbutton.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/factory.dir/examples/factory/htmlbutton.c.o -MF CMakeFiles/factory.dir/examples/factory/htmlbutton.c.o.d -o CMakeFiles/factory.dir/examples/factory/htmlbutton.c.o -c /home/imkabir/c_programming/imlib/examples/factory/htmlbutton.c

CMakeFiles/factory.dir/examples/factory/htmlbutton.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/factory.dir/examples/factory/htmlbutton.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/imkabir/c_programming/imlib/examples/factory/htmlbutton.c > CMakeFiles/factory.dir/examples/factory/htmlbutton.c.i

CMakeFiles/factory.dir/examples/factory/htmlbutton.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/factory.dir/examples/factory/htmlbutton.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/imkabir/c_programming/imlib/examples/factory/htmlbutton.c -o CMakeFiles/factory.dir/examples/factory/htmlbutton.c.s

CMakeFiles/factory.dir/examples/factory/main.c.o: CMakeFiles/factory.dir/flags.make
CMakeFiles/factory.dir/examples/factory/main.c.o: examples/factory/main.c
CMakeFiles/factory.dir/examples/factory/main.c.o: CMakeFiles/factory.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/imkabir/c_programming/imlib/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/factory.dir/examples/factory/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/factory.dir/examples/factory/main.c.o -MF CMakeFiles/factory.dir/examples/factory/main.c.o.d -o CMakeFiles/factory.dir/examples/factory/main.c.o -c /home/imkabir/c_programming/imlib/examples/factory/main.c

CMakeFiles/factory.dir/examples/factory/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/factory.dir/examples/factory/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/imkabir/c_programming/imlib/examples/factory/main.c > CMakeFiles/factory.dir/examples/factory/main.c.i

CMakeFiles/factory.dir/examples/factory/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/factory.dir/examples/factory/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/imkabir/c_programming/imlib/examples/factory/main.c -o CMakeFiles/factory.dir/examples/factory/main.c.s

CMakeFiles/factory.dir/examples/factory/webdialog.c.o: CMakeFiles/factory.dir/flags.make
CMakeFiles/factory.dir/examples/factory/webdialog.c.o: examples/factory/webdialog.c
CMakeFiles/factory.dir/examples/factory/webdialog.c.o: CMakeFiles/factory.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/imkabir/c_programming/imlib/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/factory.dir/examples/factory/webdialog.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/factory.dir/examples/factory/webdialog.c.o -MF CMakeFiles/factory.dir/examples/factory/webdialog.c.o.d -o CMakeFiles/factory.dir/examples/factory/webdialog.c.o -c /home/imkabir/c_programming/imlib/examples/factory/webdialog.c

CMakeFiles/factory.dir/examples/factory/webdialog.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/factory.dir/examples/factory/webdialog.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/imkabir/c_programming/imlib/examples/factory/webdialog.c > CMakeFiles/factory.dir/examples/factory/webdialog.c.i

CMakeFiles/factory.dir/examples/factory/webdialog.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/factory.dir/examples/factory/webdialog.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/imkabir/c_programming/imlib/examples/factory/webdialog.c -o CMakeFiles/factory.dir/examples/factory/webdialog.c.s

CMakeFiles/factory.dir/examples/factory/winbutton.c.o: CMakeFiles/factory.dir/flags.make
CMakeFiles/factory.dir/examples/factory/winbutton.c.o: examples/factory/winbutton.c
CMakeFiles/factory.dir/examples/factory/winbutton.c.o: CMakeFiles/factory.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/imkabir/c_programming/imlib/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/factory.dir/examples/factory/winbutton.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/factory.dir/examples/factory/winbutton.c.o -MF CMakeFiles/factory.dir/examples/factory/winbutton.c.o.d -o CMakeFiles/factory.dir/examples/factory/winbutton.c.o -c /home/imkabir/c_programming/imlib/examples/factory/winbutton.c

CMakeFiles/factory.dir/examples/factory/winbutton.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/factory.dir/examples/factory/winbutton.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/imkabir/c_programming/imlib/examples/factory/winbutton.c > CMakeFiles/factory.dir/examples/factory/winbutton.c.i

CMakeFiles/factory.dir/examples/factory/winbutton.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/factory.dir/examples/factory/winbutton.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/imkabir/c_programming/imlib/examples/factory/winbutton.c -o CMakeFiles/factory.dir/examples/factory/winbutton.c.s

CMakeFiles/factory.dir/examples/factory/windialog.c.o: CMakeFiles/factory.dir/flags.make
CMakeFiles/factory.dir/examples/factory/windialog.c.o: examples/factory/windialog.c
CMakeFiles/factory.dir/examples/factory/windialog.c.o: CMakeFiles/factory.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/imkabir/c_programming/imlib/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/factory.dir/examples/factory/windialog.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/factory.dir/examples/factory/windialog.c.o -MF CMakeFiles/factory.dir/examples/factory/windialog.c.o.d -o CMakeFiles/factory.dir/examples/factory/windialog.c.o -c /home/imkabir/c_programming/imlib/examples/factory/windialog.c

CMakeFiles/factory.dir/examples/factory/windialog.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/factory.dir/examples/factory/windialog.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/imkabir/c_programming/imlib/examples/factory/windialog.c > CMakeFiles/factory.dir/examples/factory/windialog.c.i

CMakeFiles/factory.dir/examples/factory/windialog.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/factory.dir/examples/factory/windialog.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/imkabir/c_programming/imlib/examples/factory/windialog.c -o CMakeFiles/factory.dir/examples/factory/windialog.c.s

# Object files for target factory
factory_OBJECTS = \
"CMakeFiles/factory.dir/examples/factory/button.c.o" \
"CMakeFiles/factory.dir/examples/factory/dialog.c.o" \
"CMakeFiles/factory.dir/examples/factory/htmlbutton.c.o" \
"CMakeFiles/factory.dir/examples/factory/main.c.o" \
"CMakeFiles/factory.dir/examples/factory/webdialog.c.o" \
"CMakeFiles/factory.dir/examples/factory/winbutton.c.o" \
"CMakeFiles/factory.dir/examples/factory/windialog.c.o"

# External object files for target factory
factory_EXTERNAL_OBJECTS =

examples/factory/factory: CMakeFiles/factory.dir/examples/factory/button.c.o
examples/factory/factory: CMakeFiles/factory.dir/examples/factory/dialog.c.o
examples/factory/factory: CMakeFiles/factory.dir/examples/factory/htmlbutton.c.o
examples/factory/factory: CMakeFiles/factory.dir/examples/factory/main.c.o
examples/factory/factory: CMakeFiles/factory.dir/examples/factory/webdialog.c.o
examples/factory/factory: CMakeFiles/factory.dir/examples/factory/winbutton.c.o
examples/factory/factory: CMakeFiles/factory.dir/examples/factory/windialog.c.o
examples/factory/factory: CMakeFiles/factory.dir/build.make
examples/factory/factory: CMakeFiles/factory.dir/compiler_depend.ts
examples/factory/factory: lib/libimlib.a
examples/factory/factory: CMakeFiles/factory.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/imkabir/c_programming/imlib/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking C executable examples/factory/factory"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/factory.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/factory.dir/build: examples/factory/factory
.PHONY : CMakeFiles/factory.dir/build

CMakeFiles/factory.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/factory.dir/cmake_clean.cmake
.PHONY : CMakeFiles/factory.dir/clean

CMakeFiles/factory.dir/depend:
	cd /home/imkabir/c_programming/imlib && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/imkabir/c_programming/imlib /home/imkabir/c_programming/imlib /home/imkabir/c_programming/imlib /home/imkabir/c_programming/imlib /home/imkabir/c_programming/imlib/CMakeFiles/factory.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/factory.dir/depend
