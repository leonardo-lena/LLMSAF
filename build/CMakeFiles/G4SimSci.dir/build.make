# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tip/Documents/unige/Sym/MSAFexam

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tip/Documents/unige/Sym/MSAFexam/build

# Utility rule file for G4SimSci.

# Include any custom commands dependencies for this target.
include CMakeFiles/G4SimSci.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/G4SimSci.dir/progress.make

CMakeFiles/G4SimSci: exampleG4SimSci

G4SimSci: CMakeFiles/G4SimSci
G4SimSci: CMakeFiles/G4SimSci.dir/build.make
.PHONY : G4SimSci

# Rule to build all files generated by this target.
CMakeFiles/G4SimSci.dir/build: G4SimSci
.PHONY : CMakeFiles/G4SimSci.dir/build

CMakeFiles/G4SimSci.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/G4SimSci.dir/cmake_clean.cmake
.PHONY : CMakeFiles/G4SimSci.dir/clean

CMakeFiles/G4SimSci.dir/depend:
	cd /home/tip/Documents/unige/Sym/MSAFexam/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tip/Documents/unige/Sym/MSAFexam /home/tip/Documents/unige/Sym/MSAFexam /home/tip/Documents/unige/Sym/MSAFexam/build /home/tip/Documents/unige/Sym/MSAFexam/build /home/tip/Documents/unige/Sym/MSAFexam/build/CMakeFiles/G4SimSci.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/G4SimSci.dir/depend

