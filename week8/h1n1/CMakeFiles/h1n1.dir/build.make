# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/algolab/Desktop/ExamPrep/week8/h1n1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/algolab/Desktop/ExamPrep/week8/h1n1

# Include any dependencies generated for this target.
include CMakeFiles/h1n1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/h1n1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/h1n1.dir/flags.make

CMakeFiles/h1n1.dir/h1n1.cpp.o: CMakeFiles/h1n1.dir/flags.make
CMakeFiles/h1n1.dir/h1n1.cpp.o: h1n1.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/algolab/Desktop/ExamPrep/week8/h1n1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/h1n1.dir/h1n1.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/h1n1.dir/h1n1.cpp.o -c /home/algolab/Desktop/ExamPrep/week8/h1n1/h1n1.cpp

CMakeFiles/h1n1.dir/h1n1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/h1n1.dir/h1n1.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/algolab/Desktop/ExamPrep/week8/h1n1/h1n1.cpp > CMakeFiles/h1n1.dir/h1n1.cpp.i

CMakeFiles/h1n1.dir/h1n1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/h1n1.dir/h1n1.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/algolab/Desktop/ExamPrep/week8/h1n1/h1n1.cpp -o CMakeFiles/h1n1.dir/h1n1.cpp.s

CMakeFiles/h1n1.dir/h1n1.cpp.o.requires:

.PHONY : CMakeFiles/h1n1.dir/h1n1.cpp.o.requires

CMakeFiles/h1n1.dir/h1n1.cpp.o.provides: CMakeFiles/h1n1.dir/h1n1.cpp.o.requires
	$(MAKE) -f CMakeFiles/h1n1.dir/build.make CMakeFiles/h1n1.dir/h1n1.cpp.o.provides.build
.PHONY : CMakeFiles/h1n1.dir/h1n1.cpp.o.provides

CMakeFiles/h1n1.dir/h1n1.cpp.o.provides.build: CMakeFiles/h1n1.dir/h1n1.cpp.o


# Object files for target h1n1
h1n1_OBJECTS = \
"CMakeFiles/h1n1.dir/h1n1.cpp.o"

# External object files for target h1n1
h1n1_EXTERNAL_OBJECTS =

h1n1: CMakeFiles/h1n1.dir/h1n1.cpp.o
h1n1: CMakeFiles/h1n1.dir/build.make
h1n1: /usr/lib/i386-linux-gnu/libmpfr.so
h1n1: /usr/lib/i386-linux-gnu/libgmp.so
h1n1: /usr/lib/i386-linux-gnu/libCGAL_Core.so.11.0.1
h1n1: /usr/lib/i386-linux-gnu/libCGAL.so.11.0.1
h1n1: /usr/lib/i386-linux-gnu/libboost_thread.so
h1n1: /usr/lib/i386-linux-gnu/libboost_system.so
h1n1: /usr/lib/i386-linux-gnu/libpthread.so
h1n1: /usr/lib/i386-linux-gnu/libCGAL_Core.so.11.0.1
h1n1: /usr/lib/i386-linux-gnu/libCGAL.so.11.0.1
h1n1: /usr/lib/i386-linux-gnu/libboost_thread.so
h1n1: /usr/lib/i386-linux-gnu/libboost_system.so
h1n1: /usr/lib/i386-linux-gnu/libpthread.so
h1n1: CMakeFiles/h1n1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/algolab/Desktop/ExamPrep/week8/h1n1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable h1n1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/h1n1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/h1n1.dir/build: h1n1

.PHONY : CMakeFiles/h1n1.dir/build

CMakeFiles/h1n1.dir/requires: CMakeFiles/h1n1.dir/h1n1.cpp.o.requires

.PHONY : CMakeFiles/h1n1.dir/requires

CMakeFiles/h1n1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/h1n1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/h1n1.dir/clean

CMakeFiles/h1n1.dir/depend:
	cd /home/algolab/Desktop/ExamPrep/week8/h1n1 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/algolab/Desktop/ExamPrep/week8/h1n1 /home/algolab/Desktop/ExamPrep/week8/h1n1 /home/algolab/Desktop/ExamPrep/week8/h1n1 /home/algolab/Desktop/ExamPrep/week8/h1n1 /home/algolab/Desktop/ExamPrep/week8/h1n1/CMakeFiles/h1n1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/h1n1.dir/depend

