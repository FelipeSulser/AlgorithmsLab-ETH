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
CMAKE_SOURCE_DIR = /home/algolab/Desktop/ExamPrep/week7/inball

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/algolab/Desktop/ExamPrep/week7/inball

# Include any dependencies generated for this target.
include CMakeFiles/inballv2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/inballv2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/inballv2.dir/flags.make

CMakeFiles/inballv2.dir/inballv2.cpp.o: CMakeFiles/inballv2.dir/flags.make
CMakeFiles/inballv2.dir/inballv2.cpp.o: inballv2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/algolab/Desktop/ExamPrep/week7/inball/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/inballv2.dir/inballv2.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/inballv2.dir/inballv2.cpp.o -c /home/algolab/Desktop/ExamPrep/week7/inball/inballv2.cpp

CMakeFiles/inballv2.dir/inballv2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/inballv2.dir/inballv2.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/algolab/Desktop/ExamPrep/week7/inball/inballv2.cpp > CMakeFiles/inballv2.dir/inballv2.cpp.i

CMakeFiles/inballv2.dir/inballv2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/inballv2.dir/inballv2.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/algolab/Desktop/ExamPrep/week7/inball/inballv2.cpp -o CMakeFiles/inballv2.dir/inballv2.cpp.s

CMakeFiles/inballv2.dir/inballv2.cpp.o.requires:

.PHONY : CMakeFiles/inballv2.dir/inballv2.cpp.o.requires

CMakeFiles/inballv2.dir/inballv2.cpp.o.provides: CMakeFiles/inballv2.dir/inballv2.cpp.o.requires
	$(MAKE) -f CMakeFiles/inballv2.dir/build.make CMakeFiles/inballv2.dir/inballv2.cpp.o.provides.build
.PHONY : CMakeFiles/inballv2.dir/inballv2.cpp.o.provides

CMakeFiles/inballv2.dir/inballv2.cpp.o.provides.build: CMakeFiles/inballv2.dir/inballv2.cpp.o


# Object files for target inballv2
inballv2_OBJECTS = \
"CMakeFiles/inballv2.dir/inballv2.cpp.o"

# External object files for target inballv2
inballv2_EXTERNAL_OBJECTS =

inballv2: CMakeFiles/inballv2.dir/inballv2.cpp.o
inballv2: CMakeFiles/inballv2.dir/build.make
inballv2: /usr/lib/i386-linux-gnu/libmpfr.so
inballv2: /usr/lib/i386-linux-gnu/libgmp.so
inballv2: /usr/lib/i386-linux-gnu/libCGAL_Core.so.11.0.1
inballv2: /usr/lib/i386-linux-gnu/libCGAL.so.11.0.1
inballv2: /usr/lib/i386-linux-gnu/libboost_thread.so
inballv2: /usr/lib/i386-linux-gnu/libboost_system.so
inballv2: /usr/lib/i386-linux-gnu/libpthread.so
inballv2: /usr/lib/i386-linux-gnu/libCGAL_Core.so.11.0.1
inballv2: /usr/lib/i386-linux-gnu/libCGAL.so.11.0.1
inballv2: /usr/lib/i386-linux-gnu/libboost_thread.so
inballv2: /usr/lib/i386-linux-gnu/libboost_system.so
inballv2: /usr/lib/i386-linux-gnu/libpthread.so
inballv2: CMakeFiles/inballv2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/algolab/Desktop/ExamPrep/week7/inball/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable inballv2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/inballv2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/inballv2.dir/build: inballv2

.PHONY : CMakeFiles/inballv2.dir/build

CMakeFiles/inballv2.dir/requires: CMakeFiles/inballv2.dir/inballv2.cpp.o.requires

.PHONY : CMakeFiles/inballv2.dir/requires

CMakeFiles/inballv2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/inballv2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/inballv2.dir/clean

CMakeFiles/inballv2.dir/depend:
	cd /home/algolab/Desktop/ExamPrep/week7/inball && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/algolab/Desktop/ExamPrep/week7/inball /home/algolab/Desktop/ExamPrep/week7/inball /home/algolab/Desktop/ExamPrep/week7/inball /home/algolab/Desktop/ExamPrep/week7/inball /home/algolab/Desktop/ExamPrep/week7/inball/CMakeFiles/inballv2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/inballv2.dir/depend

