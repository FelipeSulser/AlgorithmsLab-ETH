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
CMAKE_SOURCE_DIR = /home/algolab/Desktop/ExamPrep/week8/potw

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/algolab/Desktop/ExamPrep/week8/potw

# Include any dependencies generated for this target.
include CMakeFiles/stamp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/stamp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/stamp.dir/flags.make

CMakeFiles/stamp.dir/stamp.cpp.o: CMakeFiles/stamp.dir/flags.make
CMakeFiles/stamp.dir/stamp.cpp.o: stamp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/algolab/Desktop/ExamPrep/week8/potw/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/stamp.dir/stamp.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stamp.dir/stamp.cpp.o -c /home/algolab/Desktop/ExamPrep/week8/potw/stamp.cpp

CMakeFiles/stamp.dir/stamp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stamp.dir/stamp.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/algolab/Desktop/ExamPrep/week8/potw/stamp.cpp > CMakeFiles/stamp.dir/stamp.cpp.i

CMakeFiles/stamp.dir/stamp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stamp.dir/stamp.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/algolab/Desktop/ExamPrep/week8/potw/stamp.cpp -o CMakeFiles/stamp.dir/stamp.cpp.s

CMakeFiles/stamp.dir/stamp.cpp.o.requires:

.PHONY : CMakeFiles/stamp.dir/stamp.cpp.o.requires

CMakeFiles/stamp.dir/stamp.cpp.o.provides: CMakeFiles/stamp.dir/stamp.cpp.o.requires
	$(MAKE) -f CMakeFiles/stamp.dir/build.make CMakeFiles/stamp.dir/stamp.cpp.o.provides.build
.PHONY : CMakeFiles/stamp.dir/stamp.cpp.o.provides

CMakeFiles/stamp.dir/stamp.cpp.o.provides.build: CMakeFiles/stamp.dir/stamp.cpp.o


# Object files for target stamp
stamp_OBJECTS = \
"CMakeFiles/stamp.dir/stamp.cpp.o"

# External object files for target stamp
stamp_EXTERNAL_OBJECTS =

stamp: CMakeFiles/stamp.dir/stamp.cpp.o
stamp: CMakeFiles/stamp.dir/build.make
stamp: /usr/lib/i386-linux-gnu/libmpfr.so
stamp: /usr/lib/i386-linux-gnu/libgmp.so
stamp: /usr/lib/i386-linux-gnu/libCGAL_Core.so.11.0.1
stamp: /usr/lib/i386-linux-gnu/libCGAL.so.11.0.1
stamp: /usr/lib/i386-linux-gnu/libboost_thread.so
stamp: /usr/lib/i386-linux-gnu/libboost_system.so
stamp: /usr/lib/i386-linux-gnu/libpthread.so
stamp: /usr/lib/i386-linux-gnu/libCGAL_Core.so.11.0.1
stamp: /usr/lib/i386-linux-gnu/libCGAL.so.11.0.1
stamp: /usr/lib/i386-linux-gnu/libboost_thread.so
stamp: /usr/lib/i386-linux-gnu/libboost_system.so
stamp: /usr/lib/i386-linux-gnu/libpthread.so
stamp: CMakeFiles/stamp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/algolab/Desktop/ExamPrep/week8/potw/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable stamp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/stamp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/stamp.dir/build: stamp

.PHONY : CMakeFiles/stamp.dir/build

CMakeFiles/stamp.dir/requires: CMakeFiles/stamp.dir/stamp.cpp.o.requires

.PHONY : CMakeFiles/stamp.dir/requires

CMakeFiles/stamp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/stamp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/stamp.dir/clean

CMakeFiles/stamp.dir/depend:
	cd /home/algolab/Desktop/ExamPrep/week8/potw && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/algolab/Desktop/ExamPrep/week8/potw /home/algolab/Desktop/ExamPrep/week8/potw /home/algolab/Desktop/ExamPrep/week8/potw /home/algolab/Desktop/ExamPrep/week8/potw /home/algolab/Desktop/ExamPrep/week8/potw/CMakeFiles/stamp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/stamp.dir/depend

