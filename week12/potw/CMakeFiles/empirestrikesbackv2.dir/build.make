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
CMAKE_SOURCE_DIR = /home/algolab/Desktop/ExamPrep/week12/potw

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/algolab/Desktop/ExamPrep/week12/potw

# Include any dependencies generated for this target.
include CMakeFiles/empirestrikesbackv2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/empirestrikesbackv2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/empirestrikesbackv2.dir/flags.make

CMakeFiles/empirestrikesbackv2.dir/empirestrikesbackv2.cpp.o: CMakeFiles/empirestrikesbackv2.dir/flags.make
CMakeFiles/empirestrikesbackv2.dir/empirestrikesbackv2.cpp.o: empirestrikesbackv2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/algolab/Desktop/ExamPrep/week12/potw/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/empirestrikesbackv2.dir/empirestrikesbackv2.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/empirestrikesbackv2.dir/empirestrikesbackv2.cpp.o -c /home/algolab/Desktop/ExamPrep/week12/potw/empirestrikesbackv2.cpp

CMakeFiles/empirestrikesbackv2.dir/empirestrikesbackv2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/empirestrikesbackv2.dir/empirestrikesbackv2.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/algolab/Desktop/ExamPrep/week12/potw/empirestrikesbackv2.cpp > CMakeFiles/empirestrikesbackv2.dir/empirestrikesbackv2.cpp.i

CMakeFiles/empirestrikesbackv2.dir/empirestrikesbackv2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/empirestrikesbackv2.dir/empirestrikesbackv2.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/algolab/Desktop/ExamPrep/week12/potw/empirestrikesbackv2.cpp -o CMakeFiles/empirestrikesbackv2.dir/empirestrikesbackv2.cpp.s

CMakeFiles/empirestrikesbackv2.dir/empirestrikesbackv2.cpp.o.requires:

.PHONY : CMakeFiles/empirestrikesbackv2.dir/empirestrikesbackv2.cpp.o.requires

CMakeFiles/empirestrikesbackv2.dir/empirestrikesbackv2.cpp.o.provides: CMakeFiles/empirestrikesbackv2.dir/empirestrikesbackv2.cpp.o.requires
	$(MAKE) -f CMakeFiles/empirestrikesbackv2.dir/build.make CMakeFiles/empirestrikesbackv2.dir/empirestrikesbackv2.cpp.o.provides.build
.PHONY : CMakeFiles/empirestrikesbackv2.dir/empirestrikesbackv2.cpp.o.provides

CMakeFiles/empirestrikesbackv2.dir/empirestrikesbackv2.cpp.o.provides.build: CMakeFiles/empirestrikesbackv2.dir/empirestrikesbackv2.cpp.o


# Object files for target empirestrikesbackv2
empirestrikesbackv2_OBJECTS = \
"CMakeFiles/empirestrikesbackv2.dir/empirestrikesbackv2.cpp.o"

# External object files for target empirestrikesbackv2
empirestrikesbackv2_EXTERNAL_OBJECTS =

empirestrikesbackv2: CMakeFiles/empirestrikesbackv2.dir/empirestrikesbackv2.cpp.o
empirestrikesbackv2: CMakeFiles/empirestrikesbackv2.dir/build.make
empirestrikesbackv2: /usr/lib/i386-linux-gnu/libmpfr.so
empirestrikesbackv2: /usr/lib/i386-linux-gnu/libgmp.so
empirestrikesbackv2: /usr/lib/i386-linux-gnu/libCGAL_Core.so.11.0.1
empirestrikesbackv2: /usr/lib/i386-linux-gnu/libCGAL.so.11.0.1
empirestrikesbackv2: /usr/lib/i386-linux-gnu/libboost_thread.so
empirestrikesbackv2: /usr/lib/i386-linux-gnu/libboost_system.so
empirestrikesbackv2: /usr/lib/i386-linux-gnu/libpthread.so
empirestrikesbackv2: /usr/lib/i386-linux-gnu/libCGAL_Core.so.11.0.1
empirestrikesbackv2: /usr/lib/i386-linux-gnu/libCGAL.so.11.0.1
empirestrikesbackv2: /usr/lib/i386-linux-gnu/libboost_thread.so
empirestrikesbackv2: /usr/lib/i386-linux-gnu/libboost_system.so
empirestrikesbackv2: /usr/lib/i386-linux-gnu/libpthread.so
empirestrikesbackv2: CMakeFiles/empirestrikesbackv2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/algolab/Desktop/ExamPrep/week12/potw/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable empirestrikesbackv2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/empirestrikesbackv2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/empirestrikesbackv2.dir/build: empirestrikesbackv2

.PHONY : CMakeFiles/empirestrikesbackv2.dir/build

CMakeFiles/empirestrikesbackv2.dir/requires: CMakeFiles/empirestrikesbackv2.dir/empirestrikesbackv2.cpp.o.requires

.PHONY : CMakeFiles/empirestrikesbackv2.dir/requires

CMakeFiles/empirestrikesbackv2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/empirestrikesbackv2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/empirestrikesbackv2.dir/clean

CMakeFiles/empirestrikesbackv2.dir/depend:
	cd /home/algolab/Desktop/ExamPrep/week12/potw && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/algolab/Desktop/ExamPrep/week12/potw /home/algolab/Desktop/ExamPrep/week12/potw /home/algolab/Desktop/ExamPrep/week12/potw /home/algolab/Desktop/ExamPrep/week12/potw /home/algolab/Desktop/ExamPrep/week12/potw/CMakeFiles/empirestrikesbackv2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/empirestrikesbackv2.dir/depend
