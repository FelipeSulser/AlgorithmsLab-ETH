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
CMAKE_SOURCE_DIR = /home/algolab/Desktop/ExamPrep/week8/graypes

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/algolab/Desktop/ExamPrep/week8/graypes

# Include any dependencies generated for this target.
include CMakeFiles/graypesv5.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/graypesv5.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/graypesv5.dir/flags.make

CMakeFiles/graypesv5.dir/graypesv5.cpp.o: CMakeFiles/graypesv5.dir/flags.make
CMakeFiles/graypesv5.dir/graypesv5.cpp.o: graypesv5.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/algolab/Desktop/ExamPrep/week8/graypes/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/graypesv5.dir/graypesv5.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/graypesv5.dir/graypesv5.cpp.o -c /home/algolab/Desktop/ExamPrep/week8/graypes/graypesv5.cpp

CMakeFiles/graypesv5.dir/graypesv5.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/graypesv5.dir/graypesv5.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/algolab/Desktop/ExamPrep/week8/graypes/graypesv5.cpp > CMakeFiles/graypesv5.dir/graypesv5.cpp.i

CMakeFiles/graypesv5.dir/graypesv5.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/graypesv5.dir/graypesv5.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/algolab/Desktop/ExamPrep/week8/graypes/graypesv5.cpp -o CMakeFiles/graypesv5.dir/graypesv5.cpp.s

CMakeFiles/graypesv5.dir/graypesv5.cpp.o.requires:

.PHONY : CMakeFiles/graypesv5.dir/graypesv5.cpp.o.requires

CMakeFiles/graypesv5.dir/graypesv5.cpp.o.provides: CMakeFiles/graypesv5.dir/graypesv5.cpp.o.requires
	$(MAKE) -f CMakeFiles/graypesv5.dir/build.make CMakeFiles/graypesv5.dir/graypesv5.cpp.o.provides.build
.PHONY : CMakeFiles/graypesv5.dir/graypesv5.cpp.o.provides

CMakeFiles/graypesv5.dir/graypesv5.cpp.o.provides.build: CMakeFiles/graypesv5.dir/graypesv5.cpp.o


# Object files for target graypesv5
graypesv5_OBJECTS = \
"CMakeFiles/graypesv5.dir/graypesv5.cpp.o"

# External object files for target graypesv5
graypesv5_EXTERNAL_OBJECTS =

graypesv5: CMakeFiles/graypesv5.dir/graypesv5.cpp.o
graypesv5: CMakeFiles/graypesv5.dir/build.make
graypesv5: /usr/lib/i386-linux-gnu/libmpfr.so
graypesv5: /usr/lib/i386-linux-gnu/libgmp.so
graypesv5: /usr/lib/i386-linux-gnu/libCGAL_Core.so.11.0.1
graypesv5: /usr/lib/i386-linux-gnu/libCGAL.so.11.0.1
graypesv5: /usr/lib/i386-linux-gnu/libboost_thread.so
graypesv5: /usr/lib/i386-linux-gnu/libboost_system.so
graypesv5: /usr/lib/i386-linux-gnu/libpthread.so
graypesv5: /usr/lib/i386-linux-gnu/libCGAL_Core.so.11.0.1
graypesv5: /usr/lib/i386-linux-gnu/libCGAL.so.11.0.1
graypesv5: /usr/lib/i386-linux-gnu/libboost_thread.so
graypesv5: /usr/lib/i386-linux-gnu/libboost_system.so
graypesv5: /usr/lib/i386-linux-gnu/libpthread.so
graypesv5: CMakeFiles/graypesv5.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/algolab/Desktop/ExamPrep/week8/graypes/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable graypesv5"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/graypesv5.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/graypesv5.dir/build: graypesv5

.PHONY : CMakeFiles/graypesv5.dir/build

CMakeFiles/graypesv5.dir/requires: CMakeFiles/graypesv5.dir/graypesv5.cpp.o.requires

.PHONY : CMakeFiles/graypesv5.dir/requires

CMakeFiles/graypesv5.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/graypesv5.dir/cmake_clean.cmake
.PHONY : CMakeFiles/graypesv5.dir/clean

CMakeFiles/graypesv5.dir/depend:
	cd /home/algolab/Desktop/ExamPrep/week8/graypes && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/algolab/Desktop/ExamPrep/week8/graypes /home/algolab/Desktop/ExamPrep/week8/graypes /home/algolab/Desktop/ExamPrep/week8/graypes /home/algolab/Desktop/ExamPrep/week8/graypes /home/algolab/Desktop/ExamPrep/week8/graypes/CMakeFiles/graypesv5.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/graypesv5.dir/depend

