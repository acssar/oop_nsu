# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /snap/clion/169/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/169/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/roman/CLionProjects/сplusplus/task2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/roman/CLionProjects/сplusplus/task2/cmake-build-debug

# Utility rule file for NightlyCoverage.

# Include any custom commands dependencies for this target.
include _deps/catch2-build/CMakeFiles/NightlyCoverage.dir/compiler_depend.make

# Include the progress variables for this target.
include _deps/catch2-build/CMakeFiles/NightlyCoverage.dir/progress.make

_deps/catch2-build/CMakeFiles/NightlyCoverage:
	cd /home/roman/CLionProjects/сplusplus/task2/cmake-build-debug/_deps/catch2-build && /snap/clion/169/bin/cmake/linux/bin/ctest -D NightlyCoverage

NightlyCoverage: _deps/catch2-build/CMakeFiles/NightlyCoverage
NightlyCoverage: _deps/catch2-build/CMakeFiles/NightlyCoverage.dir/build.make
.PHONY : NightlyCoverage

# Rule to build all files generated by this target.
_deps/catch2-build/CMakeFiles/NightlyCoverage.dir/build: NightlyCoverage
.PHONY : _deps/catch2-build/CMakeFiles/NightlyCoverage.dir/build

_deps/catch2-build/CMakeFiles/NightlyCoverage.dir/clean:
	cd /home/roman/CLionProjects/сplusplus/task2/cmake-build-debug/_deps/catch2-build && $(CMAKE_COMMAND) -P CMakeFiles/NightlyCoverage.dir/cmake_clean.cmake
.PHONY : _deps/catch2-build/CMakeFiles/NightlyCoverage.dir/clean

_deps/catch2-build/CMakeFiles/NightlyCoverage.dir/depend:
	cd /home/roman/CLionProjects/сplusplus/task2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/roman/CLionProjects/сplusplus/task2 /home/roman/CLionProjects/сplusplus/task2/cmake-build-debug/_deps/catch2-src /home/roman/CLionProjects/сplusplus/task2/cmake-build-debug /home/roman/CLionProjects/сplusplus/task2/cmake-build-debug/_deps/catch2-build /home/roman/CLionProjects/сplusplus/task2/cmake-build-debug/_deps/catch2-build/CMakeFiles/NightlyCoverage.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : _deps/catch2-build/CMakeFiles/NightlyCoverage.dir/depend

