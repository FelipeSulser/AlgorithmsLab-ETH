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
CMAKE_SOURCE_DIR = /home/algolab/Desktop/ExamPrep/week7/diet

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/algolab/Desktop/ExamPrep/week7/diet

# Include any dependencies generated for this target.
include CMakeFiles/dietv2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/dietv2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/dietv2.dir/flags.make

CMakeFiles/dietv2.dir/dietv2.cpp.o: CMakeFiles/dietv2.dir/flags.make
CMakeFiles/dietv2.dir/dietv2.cpp.o: dietv2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/algolab/Desktop/ExamPrep/week7/diet/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/dietv2.dir/dietv2.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dietv2.dir/dietv2.cpp.o -c /home/algolab/Desktop/ExamPrep/week7/diet/dietv2.cpp

CMakeFiles/dietv2.dir/dietv2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dietv2.dir/dietv2.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/algolab/Desktop/ExamPrep/week7/diet/dietv2.cpp > CMakeFiles/dietv2.dir/dietv2.cpp.i

CMakeFiles/dietv2.dir/dietv2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dietv2.dir/dietv2.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/algolab/Desktop/ExamPrep/week7/diet/dietv2.cpp -o CMakeFiles/dietv2.dir/dietv2.cpp.s

CMakeFiles/dietv2.dir/dietv2.cpp.o.requires:

.PHONY : CMakeFiles/dietv2.dir/dietv2.cpp.o.requires

CMakeFiles/dietv2.dir/dietv2.cpp.o.provides: CMakeFiles/dietv2.dir/dietv2.cpp.o.requires
	$(MAKE) -f CMakeFiles/dietv2.dir/build.make CMakeFiles/dietv2.dir/dietv2.cpp.o.provides.build
.PHONY : CMakeFiles/dietv2.dir/dietv2.cpp.o.provides

CMakeFiles/dietv2.dir/dietv2.cpp.o.provides.build: CMakeFiles/dietv2.dir/dietv2.cpp.o


# Object files for target dietv2
dietv2_OBJECTS = \
"CMakeFiles/dietv2.dir/dietv2.cpp.o"

# External object files for target dietv2
dietv2_EXTERNAL_OBJECTS =

dietv2: CMakeFiles/dietv2.dir/dietv2.cpp.o
dietv2: CMakeFiles/dietv2.dir/build.make
dietv2: /usr/lib/i386-linux-gnu/libmpfr.so
dietv2: /usr/lib/i386-linux-gnu/libgmp.so
dietv2: /usr/lib/i386-linux-gnu/libCGAL_Core.so.11.0.1
dietv2: /usr/lib/i386-linux-gnu/libCGAL.so.11.0.1
dietv2: /usr/lib/i386-linux-gnu/libboost_thread.so
dietv2: /usr/lib/i386-linux-gnu/libboost_system.so
dietv2: /usr/lib/i386-linux-gnu/libpthread.so
dietv2: /usr/lib/i386-linux-gnu/libCGAL_Core.so.11.0.1
dietv2: /usr/lib/i386-linux-gnu/libCGAL.so.11.0.1
dietv2: /usr/lib/i386-linux-gnu/libboost_thread.so
dietv2: /usr/lib/i386-linux-gnu/libboost_system.so
dietv2: /usr/lib/i386-linux-gnu/libpthread.so
dietv2: CMakeFiles/dietv2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/algolab/Desktop/ExamPrep/week7/diet/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable dietv2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dietv2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/dietv2.dir/build: dietv2

.PHONY : CMakeFiles/dietv2.dir/build

CMakeFiles/dietv2.dir/requires: CMakeFiles/dietv2.dir/dietv2.cpp.o.requires

.PHONY : CMakeFiles/dietv2.dir/requires

CMakeFiles/dietv2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/dietv2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/dietv2.dir/clean

CMakeFiles/dietv2.dir/depend:
	cd /home/algolab/Desktop/ExamPrep/week7/diet && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/algolab/Desktop/ExamPrep/week7/diet /home/algolab/Desktop/ExamPrep/week7/diet /home/algolab/Desktop/ExamPrep/week7/diet /home/algolab/Desktop/ExamPrep/week7/diet /home/algolab/Desktop/ExamPrep/week7/diet/CMakeFiles/dietv2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/dietv2.dir/depend

