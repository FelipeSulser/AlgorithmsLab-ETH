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
CMAKE_SOURCE_DIR = /home/algolab/Desktop/ExamPrep/week3/hiking-maps

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/algolab/Desktop/ExamPrep/week3/hiking-maps

# Include any dependencies generated for this target.
include CMakeFiles/hiking_mapsv9.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/hiking_mapsv9.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hiking_mapsv9.dir/flags.make

CMakeFiles/hiking_mapsv9.dir/hiking_mapsv9.cpp.o: CMakeFiles/hiking_mapsv9.dir/flags.make
CMakeFiles/hiking_mapsv9.dir/hiking_mapsv9.cpp.o: hiking_mapsv9.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/algolab/Desktop/ExamPrep/week3/hiking-maps/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/hiking_mapsv9.dir/hiking_mapsv9.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hiking_mapsv9.dir/hiking_mapsv9.cpp.o -c /home/algolab/Desktop/ExamPrep/week3/hiking-maps/hiking_mapsv9.cpp

CMakeFiles/hiking_mapsv9.dir/hiking_mapsv9.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hiking_mapsv9.dir/hiking_mapsv9.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/algolab/Desktop/ExamPrep/week3/hiking-maps/hiking_mapsv9.cpp > CMakeFiles/hiking_mapsv9.dir/hiking_mapsv9.cpp.i

CMakeFiles/hiking_mapsv9.dir/hiking_mapsv9.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hiking_mapsv9.dir/hiking_mapsv9.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/algolab/Desktop/ExamPrep/week3/hiking-maps/hiking_mapsv9.cpp -o CMakeFiles/hiking_mapsv9.dir/hiking_mapsv9.cpp.s

CMakeFiles/hiking_mapsv9.dir/hiking_mapsv9.cpp.o.requires:

.PHONY : CMakeFiles/hiking_mapsv9.dir/hiking_mapsv9.cpp.o.requires

CMakeFiles/hiking_mapsv9.dir/hiking_mapsv9.cpp.o.provides: CMakeFiles/hiking_mapsv9.dir/hiking_mapsv9.cpp.o.requires
	$(MAKE) -f CMakeFiles/hiking_mapsv9.dir/build.make CMakeFiles/hiking_mapsv9.dir/hiking_mapsv9.cpp.o.provides.build
.PHONY : CMakeFiles/hiking_mapsv9.dir/hiking_mapsv9.cpp.o.provides

CMakeFiles/hiking_mapsv9.dir/hiking_mapsv9.cpp.o.provides.build: CMakeFiles/hiking_mapsv9.dir/hiking_mapsv9.cpp.o


# Object files for target hiking_mapsv9
hiking_mapsv9_OBJECTS = \
"CMakeFiles/hiking_mapsv9.dir/hiking_mapsv9.cpp.o"

# External object files for target hiking_mapsv9
hiking_mapsv9_EXTERNAL_OBJECTS =

hiking_mapsv9: CMakeFiles/hiking_mapsv9.dir/hiking_mapsv9.cpp.o
hiking_mapsv9: CMakeFiles/hiking_mapsv9.dir/build.make
hiking_mapsv9: /usr/lib/i386-linux-gnu/libmpfr.so
hiking_mapsv9: /usr/lib/i386-linux-gnu/libgmp.so
hiking_mapsv9: /usr/lib/i386-linux-gnu/libCGAL_Core.so.11.0.1
hiking_mapsv9: /usr/lib/i386-linux-gnu/libCGAL.so.11.0.1
hiking_mapsv9: /usr/lib/i386-linux-gnu/libboost_thread.so
hiking_mapsv9: /usr/lib/i386-linux-gnu/libboost_system.so
hiking_mapsv9: /usr/lib/i386-linux-gnu/libpthread.so
hiking_mapsv9: /usr/lib/i386-linux-gnu/libCGAL_Core.so.11.0.1
hiking_mapsv9: /usr/lib/i386-linux-gnu/libCGAL.so.11.0.1
hiking_mapsv9: /usr/lib/i386-linux-gnu/libboost_thread.so
hiking_mapsv9: /usr/lib/i386-linux-gnu/libboost_system.so
hiking_mapsv9: /usr/lib/i386-linux-gnu/libpthread.so
hiking_mapsv9: CMakeFiles/hiking_mapsv9.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/algolab/Desktop/ExamPrep/week3/hiking-maps/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable hiking_mapsv9"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hiking_mapsv9.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hiking_mapsv9.dir/build: hiking_mapsv9

.PHONY : CMakeFiles/hiking_mapsv9.dir/build

CMakeFiles/hiking_mapsv9.dir/requires: CMakeFiles/hiking_mapsv9.dir/hiking_mapsv9.cpp.o.requires

.PHONY : CMakeFiles/hiking_mapsv9.dir/requires

CMakeFiles/hiking_mapsv9.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hiking_mapsv9.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hiking_mapsv9.dir/clean

CMakeFiles/hiking_mapsv9.dir/depend:
	cd /home/algolab/Desktop/ExamPrep/week3/hiking-maps && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/algolab/Desktop/ExamPrep/week3/hiking-maps /home/algolab/Desktop/ExamPrep/week3/hiking-maps /home/algolab/Desktop/ExamPrep/week3/hiking-maps /home/algolab/Desktop/ExamPrep/week3/hiking-maps /home/algolab/Desktop/ExamPrep/week3/hiking-maps/CMakeFiles/hiking_mapsv9.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hiking_mapsv9.dir/depend

