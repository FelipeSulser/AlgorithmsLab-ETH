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
CMAKE_SOURCE_DIR = /home/algolab/Desktop/ExamPrep/week13/portfolios-revisited

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/algolab/Desktop/ExamPrep/week13/portfolios-revisited

# Include any dependencies generated for this target.
include CMakeFiles/portfolios-revisitedv3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/portfolios-revisitedv3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/portfolios-revisitedv3.dir/flags.make

CMakeFiles/portfolios-revisitedv3.dir/portfolios-revisitedv3.cpp.o: CMakeFiles/portfolios-revisitedv3.dir/flags.make
CMakeFiles/portfolios-revisitedv3.dir/portfolios-revisitedv3.cpp.o: portfolios-revisitedv3.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/algolab/Desktop/ExamPrep/week13/portfolios-revisited/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/portfolios-revisitedv3.dir/portfolios-revisitedv3.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/portfolios-revisitedv3.dir/portfolios-revisitedv3.cpp.o -c /home/algolab/Desktop/ExamPrep/week13/portfolios-revisited/portfolios-revisitedv3.cpp

CMakeFiles/portfolios-revisitedv3.dir/portfolios-revisitedv3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/portfolios-revisitedv3.dir/portfolios-revisitedv3.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/algolab/Desktop/ExamPrep/week13/portfolios-revisited/portfolios-revisitedv3.cpp > CMakeFiles/portfolios-revisitedv3.dir/portfolios-revisitedv3.cpp.i

CMakeFiles/portfolios-revisitedv3.dir/portfolios-revisitedv3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/portfolios-revisitedv3.dir/portfolios-revisitedv3.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/algolab/Desktop/ExamPrep/week13/portfolios-revisited/portfolios-revisitedv3.cpp -o CMakeFiles/portfolios-revisitedv3.dir/portfolios-revisitedv3.cpp.s

CMakeFiles/portfolios-revisitedv3.dir/portfolios-revisitedv3.cpp.o.requires:

.PHONY : CMakeFiles/portfolios-revisitedv3.dir/portfolios-revisitedv3.cpp.o.requires

CMakeFiles/portfolios-revisitedv3.dir/portfolios-revisitedv3.cpp.o.provides: CMakeFiles/portfolios-revisitedv3.dir/portfolios-revisitedv3.cpp.o.requires
	$(MAKE) -f CMakeFiles/portfolios-revisitedv3.dir/build.make CMakeFiles/portfolios-revisitedv3.dir/portfolios-revisitedv3.cpp.o.provides.build
.PHONY : CMakeFiles/portfolios-revisitedv3.dir/portfolios-revisitedv3.cpp.o.provides

CMakeFiles/portfolios-revisitedv3.dir/portfolios-revisitedv3.cpp.o.provides.build: CMakeFiles/portfolios-revisitedv3.dir/portfolios-revisitedv3.cpp.o


# Object files for target portfolios-revisitedv3
portfolios__revisitedv3_OBJECTS = \
"CMakeFiles/portfolios-revisitedv3.dir/portfolios-revisitedv3.cpp.o"

# External object files for target portfolios-revisitedv3
portfolios__revisitedv3_EXTERNAL_OBJECTS =

portfolios-revisitedv3: CMakeFiles/portfolios-revisitedv3.dir/portfolios-revisitedv3.cpp.o
portfolios-revisitedv3: CMakeFiles/portfolios-revisitedv3.dir/build.make
portfolios-revisitedv3: /usr/lib/i386-linux-gnu/libmpfr.so
portfolios-revisitedv3: /usr/lib/i386-linux-gnu/libgmp.so
portfolios-revisitedv3: /usr/lib/i386-linux-gnu/libCGAL_Core.so.11.0.1
portfolios-revisitedv3: /usr/lib/i386-linux-gnu/libCGAL.so.11.0.1
portfolios-revisitedv3: /usr/lib/i386-linux-gnu/libboost_thread.so
portfolios-revisitedv3: /usr/lib/i386-linux-gnu/libboost_system.so
portfolios-revisitedv3: /usr/lib/i386-linux-gnu/libpthread.so
portfolios-revisitedv3: /usr/lib/i386-linux-gnu/libCGAL_Core.so.11.0.1
portfolios-revisitedv3: /usr/lib/i386-linux-gnu/libCGAL.so.11.0.1
portfolios-revisitedv3: /usr/lib/i386-linux-gnu/libboost_thread.so
portfolios-revisitedv3: /usr/lib/i386-linux-gnu/libboost_system.so
portfolios-revisitedv3: /usr/lib/i386-linux-gnu/libpthread.so
portfolios-revisitedv3: CMakeFiles/portfolios-revisitedv3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/algolab/Desktop/ExamPrep/week13/portfolios-revisited/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable portfolios-revisitedv3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/portfolios-revisitedv3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/portfolios-revisitedv3.dir/build: portfolios-revisitedv3

.PHONY : CMakeFiles/portfolios-revisitedv3.dir/build

CMakeFiles/portfolios-revisitedv3.dir/requires: CMakeFiles/portfolios-revisitedv3.dir/portfolios-revisitedv3.cpp.o.requires

.PHONY : CMakeFiles/portfolios-revisitedv3.dir/requires

CMakeFiles/portfolios-revisitedv3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/portfolios-revisitedv3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/portfolios-revisitedv3.dir/clean

CMakeFiles/portfolios-revisitedv3.dir/depend:
	cd /home/algolab/Desktop/ExamPrep/week13/portfolios-revisited && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/algolab/Desktop/ExamPrep/week13/portfolios-revisited /home/algolab/Desktop/ExamPrep/week13/portfolios-revisited /home/algolab/Desktop/ExamPrep/week13/portfolios-revisited /home/algolab/Desktop/ExamPrep/week13/portfolios-revisited /home/algolab/Desktop/ExamPrep/week13/portfolios-revisited/CMakeFiles/portfolios-revisitedv3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/portfolios-revisitedv3.dir/depend
