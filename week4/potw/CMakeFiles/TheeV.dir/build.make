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
CMAKE_SOURCE_DIR = /home/algolab/Desktop/ExamPrep/week4/potw

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/algolab/Desktop/ExamPrep/week4/potw

# Include any dependencies generated for this target.
include CMakeFiles/TheeV.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TheeV.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TheeV.dir/flags.make

CMakeFiles/TheeV.dir/TheeV.cpp.o: CMakeFiles/TheeV.dir/flags.make
CMakeFiles/TheeV.dir/TheeV.cpp.o: TheeV.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/algolab/Desktop/ExamPrep/week4/potw/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TheeV.dir/TheeV.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TheeV.dir/TheeV.cpp.o -c /home/algolab/Desktop/ExamPrep/week4/potw/TheeV.cpp

CMakeFiles/TheeV.dir/TheeV.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TheeV.dir/TheeV.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/algolab/Desktop/ExamPrep/week4/potw/TheeV.cpp > CMakeFiles/TheeV.dir/TheeV.cpp.i

CMakeFiles/TheeV.dir/TheeV.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TheeV.dir/TheeV.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/algolab/Desktop/ExamPrep/week4/potw/TheeV.cpp -o CMakeFiles/TheeV.dir/TheeV.cpp.s

CMakeFiles/TheeV.dir/TheeV.cpp.o.requires:

.PHONY : CMakeFiles/TheeV.dir/TheeV.cpp.o.requires

CMakeFiles/TheeV.dir/TheeV.cpp.o.provides: CMakeFiles/TheeV.dir/TheeV.cpp.o.requires
	$(MAKE) -f CMakeFiles/TheeV.dir/build.make CMakeFiles/TheeV.dir/TheeV.cpp.o.provides.build
.PHONY : CMakeFiles/TheeV.dir/TheeV.cpp.o.provides

CMakeFiles/TheeV.dir/TheeV.cpp.o.provides.build: CMakeFiles/TheeV.dir/TheeV.cpp.o


# Object files for target TheeV
TheeV_OBJECTS = \
"CMakeFiles/TheeV.dir/TheeV.cpp.o"

# External object files for target TheeV
TheeV_EXTERNAL_OBJECTS =

TheeV: CMakeFiles/TheeV.dir/TheeV.cpp.o
TheeV: CMakeFiles/TheeV.dir/build.make
TheeV: /usr/lib/i386-linux-gnu/libmpfr.so
TheeV: /usr/lib/i386-linux-gnu/libgmp.so
TheeV: /usr/lib/i386-linux-gnu/libCGAL_Core.so.11.0.1
TheeV: /usr/lib/i386-linux-gnu/libCGAL.so.11.0.1
TheeV: /usr/lib/i386-linux-gnu/libboost_thread.so
TheeV: /usr/lib/i386-linux-gnu/libboost_system.so
TheeV: /usr/lib/i386-linux-gnu/libpthread.so
TheeV: /usr/lib/i386-linux-gnu/libCGAL_Core.so.11.0.1
TheeV: /usr/lib/i386-linux-gnu/libCGAL.so.11.0.1
TheeV: /usr/lib/i386-linux-gnu/libboost_thread.so
TheeV: /usr/lib/i386-linux-gnu/libboost_system.so
TheeV: /usr/lib/i386-linux-gnu/libpthread.so
TheeV: CMakeFiles/TheeV.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/algolab/Desktop/ExamPrep/week4/potw/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TheeV"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TheeV.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TheeV.dir/build: TheeV

.PHONY : CMakeFiles/TheeV.dir/build

CMakeFiles/TheeV.dir/requires: CMakeFiles/TheeV.dir/TheeV.cpp.o.requires

.PHONY : CMakeFiles/TheeV.dir/requires

CMakeFiles/TheeV.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TheeV.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TheeV.dir/clean

CMakeFiles/TheeV.dir/depend:
	cd /home/algolab/Desktop/ExamPrep/week4/potw && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/algolab/Desktop/ExamPrep/week4/potw /home/algolab/Desktop/ExamPrep/week4/potw /home/algolab/Desktop/ExamPrep/week4/potw /home/algolab/Desktop/ExamPrep/week4/potw /home/algolab/Desktop/ExamPrep/week4/potw/CMakeFiles/TheeV.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TheeV.dir/depend
