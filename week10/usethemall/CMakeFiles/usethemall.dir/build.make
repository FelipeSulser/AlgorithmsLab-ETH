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
CMAKE_SOURCE_DIR = /home/algolab/Desktop/ExamPrep/week10/usethemall

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/algolab/Desktop/ExamPrep/week10/usethemall

# Include any dependencies generated for this target.
include CMakeFiles/usethemall.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/usethemall.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/usethemall.dir/flags.make

CMakeFiles/usethemall.dir/usethemall.cpp.o: CMakeFiles/usethemall.dir/flags.make
CMakeFiles/usethemall.dir/usethemall.cpp.o: usethemall.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/algolab/Desktop/ExamPrep/week10/usethemall/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/usethemall.dir/usethemall.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/usethemall.dir/usethemall.cpp.o -c /home/algolab/Desktop/ExamPrep/week10/usethemall/usethemall.cpp

CMakeFiles/usethemall.dir/usethemall.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/usethemall.dir/usethemall.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/algolab/Desktop/ExamPrep/week10/usethemall/usethemall.cpp > CMakeFiles/usethemall.dir/usethemall.cpp.i

CMakeFiles/usethemall.dir/usethemall.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/usethemall.dir/usethemall.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/algolab/Desktop/ExamPrep/week10/usethemall/usethemall.cpp -o CMakeFiles/usethemall.dir/usethemall.cpp.s

CMakeFiles/usethemall.dir/usethemall.cpp.o.requires:

.PHONY : CMakeFiles/usethemall.dir/usethemall.cpp.o.requires

CMakeFiles/usethemall.dir/usethemall.cpp.o.provides: CMakeFiles/usethemall.dir/usethemall.cpp.o.requires
	$(MAKE) -f CMakeFiles/usethemall.dir/build.make CMakeFiles/usethemall.dir/usethemall.cpp.o.provides.build
.PHONY : CMakeFiles/usethemall.dir/usethemall.cpp.o.provides

CMakeFiles/usethemall.dir/usethemall.cpp.o.provides.build: CMakeFiles/usethemall.dir/usethemall.cpp.o


# Object files for target usethemall
usethemall_OBJECTS = \
"CMakeFiles/usethemall.dir/usethemall.cpp.o"

# External object files for target usethemall
usethemall_EXTERNAL_OBJECTS =

usethemall: CMakeFiles/usethemall.dir/usethemall.cpp.o
usethemall: CMakeFiles/usethemall.dir/build.make
usethemall: /usr/lib/i386-linux-gnu/libmpfr.so
usethemall: /usr/lib/i386-linux-gnu/libgmp.so
usethemall: /usr/lib/i386-linux-gnu/libCGAL_Core.so.11.0.1
usethemall: /usr/lib/i386-linux-gnu/libCGAL.so.11.0.1
usethemall: /usr/lib/i386-linux-gnu/libboost_thread.so
usethemall: /usr/lib/i386-linux-gnu/libboost_system.so
usethemall: /usr/lib/i386-linux-gnu/libpthread.so
usethemall: /usr/lib/i386-linux-gnu/libCGAL_Core.so.11.0.1
usethemall: /usr/lib/i386-linux-gnu/libCGAL.so.11.0.1
usethemall: /usr/lib/i386-linux-gnu/libboost_thread.so
usethemall: /usr/lib/i386-linux-gnu/libboost_system.so
usethemall: /usr/lib/i386-linux-gnu/libpthread.so
usethemall: CMakeFiles/usethemall.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/algolab/Desktop/ExamPrep/week10/usethemall/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable usethemall"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/usethemall.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/usethemall.dir/build: usethemall

.PHONY : CMakeFiles/usethemall.dir/build

CMakeFiles/usethemall.dir/requires: CMakeFiles/usethemall.dir/usethemall.cpp.o.requires

.PHONY : CMakeFiles/usethemall.dir/requires

CMakeFiles/usethemall.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/usethemall.dir/cmake_clean.cmake
.PHONY : CMakeFiles/usethemall.dir/clean

CMakeFiles/usethemall.dir/depend:
	cd /home/algolab/Desktop/ExamPrep/week10/usethemall && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/algolab/Desktop/ExamPrep/week10/usethemall /home/algolab/Desktop/ExamPrep/week10/usethemall /home/algolab/Desktop/ExamPrep/week10/usethemall /home/algolab/Desktop/ExamPrep/week10/usethemall /home/algolab/Desktop/ExamPrep/week10/usethemall/CMakeFiles/usethemall.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/usethemall.dir/depend
