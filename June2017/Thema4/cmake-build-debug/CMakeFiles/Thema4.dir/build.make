# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/harry/Documents/GitHub/TEI-ATH-Algorithms/June2017/Thema4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/harry/Documents/GitHub/TEI-ATH-Algorithms/June2017/Thema4/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Thema4.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Thema4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Thema4.dir/flags.make

CMakeFiles/Thema4.dir/main.c.o: CMakeFiles/Thema4.dir/flags.make
CMakeFiles/Thema4.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/harry/Documents/GitHub/TEI-ATH-Algorithms/June2017/Thema4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Thema4.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Thema4.dir/main.c.o   -c /Users/harry/Documents/GitHub/TEI-ATH-Algorithms/June2017/Thema4/main.c

CMakeFiles/Thema4.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Thema4.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/harry/Documents/GitHub/TEI-ATH-Algorithms/June2017/Thema4/main.c > CMakeFiles/Thema4.dir/main.c.i

CMakeFiles/Thema4.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Thema4.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/harry/Documents/GitHub/TEI-ATH-Algorithms/June2017/Thema4/main.c -o CMakeFiles/Thema4.dir/main.c.s

CMakeFiles/Thema4.dir/main.c.o.requires:

.PHONY : CMakeFiles/Thema4.dir/main.c.o.requires

CMakeFiles/Thema4.dir/main.c.o.provides: CMakeFiles/Thema4.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/Thema4.dir/build.make CMakeFiles/Thema4.dir/main.c.o.provides.build
.PHONY : CMakeFiles/Thema4.dir/main.c.o.provides

CMakeFiles/Thema4.dir/main.c.o.provides.build: CMakeFiles/Thema4.dir/main.c.o


# Object files for target Thema4
Thema4_OBJECTS = \
"CMakeFiles/Thema4.dir/main.c.o"

# External object files for target Thema4
Thema4_EXTERNAL_OBJECTS =

Thema4: CMakeFiles/Thema4.dir/main.c.o
Thema4: CMakeFiles/Thema4.dir/build.make
Thema4: CMakeFiles/Thema4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/harry/Documents/GitHub/TEI-ATH-Algorithms/June2017/Thema4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Thema4"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Thema4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Thema4.dir/build: Thema4

.PHONY : CMakeFiles/Thema4.dir/build

CMakeFiles/Thema4.dir/requires: CMakeFiles/Thema4.dir/main.c.o.requires

.PHONY : CMakeFiles/Thema4.dir/requires

CMakeFiles/Thema4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Thema4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Thema4.dir/clean

CMakeFiles/Thema4.dir/depend:
	cd /Users/harry/Documents/GitHub/TEI-ATH-Algorithms/June2017/Thema4/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/harry/Documents/GitHub/TEI-ATH-Algorithms/June2017/Thema4 /Users/harry/Documents/GitHub/TEI-ATH-Algorithms/June2017/Thema4 /Users/harry/Documents/GitHub/TEI-ATH-Algorithms/June2017/Thema4/cmake-build-debug /Users/harry/Documents/GitHub/TEI-ATH-Algorithms/June2017/Thema4/cmake-build-debug /Users/harry/Documents/GitHub/TEI-ATH-Algorithms/June2017/Thema4/cmake-build-debug/CMakeFiles/Thema4.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Thema4.dir/depend
