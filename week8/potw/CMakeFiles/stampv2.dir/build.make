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
include CMakeFiles/stampv2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/stampv2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/stampv2.dir/flags.make

CMakeFiles/stampv2.dir/stampv2.cpp.o: CMakeFiles/stampv2.dir/flags.make
CMakeFiles/stampv2.dir/stampv2.cpp.o: stampv2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/algolab/Desktop/ExamPrep/week8/potw/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/stampv2.dir/stampv2.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stampv2.dir/stampv2.cpp.o -c /home/algolab/Desktop/ExamPrep/week8/potw/stampv2.cpp

CMakeFiles/stampv2.dir/stampv2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stampv2.dir/stampv2.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/algolab/Desktop/ExamPrep/week8/potw/stampv2.cpp > CMakeFiles/stampv2.dir/stampv2.cpp.i

CMakeFiles/stampv2.dir/stampv2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stampv2.dir/stampv2.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/algolab/Desktop/ExamPrep/week8/potw/stampv2.cpp -o CMakeFiles/stampv2.dir/stampv2.cpp.s

CMakeFiles/stampv2.dir/stampv2.cpp.o.requires:

.PHONY : CMakeFiles/stampv2.dir/stampv2.cpp.o.requires

CMakeFiles/stampv2.dir/stampv2.cpp.o.provides: CMakeFiles/stampv2.dir/stampv2.cpp.o.requires
	$(MAKE) -f CMakeFiles/stampv2.dir/build.make CMakeFiles/stampv2.dir/stampv2.cpp.o.provides.build
.PHONY : CMakeFiles/stampv2.dir/stampv2.cpp.o.provides

CMakeFiles/stampv2.dir/stampv2.cpp.o.provides.build: CMakeFiles/stampv2.dir/stampv2.cpp.o


# Object files for target stampv2
stampv2_OBJECTS = \
"CMakeFiles/stampv2.dir/stampv2.cpp.o"

# External object files for target stampv2
stampv2_EXTERNAL_OBJECTS =

stampv2: CMakeFiles/stampv2.dir/stampv2.cpp.o
stampv2: CMakeFiles/stampv2.dir/build.make
stampv2: /usr/lib/i386-linux-gnu/libmpfr.so
stampv2: /usr/lib/i386-linux-gnu/libgmp.so
stampv2: /usr/lib/i386-linux-gnu/libCGAL_Core.so.11.0.1
stampv2: /usr/lib/i386-linux-gnu/libCGAL.so.11.0.1
stampv2: /usr/lib/i386-linux-gnu/libboost_thread.so
stampv2: /usr/lib/i386-linux-gnu/libboost_system.so
stampv2: /usr/lib/i386-linux-gnu/libpthread.so
stampv2: /usr/lib/i386-linux-gnu/libCGAL_Core.so.11.0.1
stampv2: /usr/lib/i386-linux-gnu/libCGAL.so.11.0.1
stampv2: /usr/lib/i386-linux-gnu/libboost_thread.so
stampv2: /usr/lib/i386-linux-gnu/libboost_system.so
stampv2: /usr/lib/i386-linux-gnu/libpthread.so
stampv2: CMakeFiles/stampv2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/algolab/Desktop/ExamPrep/week8/potw/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable stampv2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/stampv2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/stampv2.dir/build: stampv2

.PHONY : CMakeFiles/stampv2.dir/build

CMakeFiles/stampv2.dir/requires: CMakeFiles/stampv2.dir/stampv2.cpp.o.requires

.PHONY : CMakeFiles/stampv2.dir/requires

CMakeFiles/stampv2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/stampv2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/stampv2.dir/clean

CMakeFiles/stampv2.dir/depend:
	cd /home/algolab/Desktop/ExamPrep/week8/potw && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/algolab/Desktop/ExamPrep/week8/potw /home/algolab/Desktop/ExamPrep/week8/potw /home/algolab/Desktop/ExamPrep/week8/potw /home/algolab/Desktop/ExamPrep/week8/potw /home/algolab/Desktop/ExamPrep/week8/potw/CMakeFiles/stampv2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/stampv2.dir/depend

