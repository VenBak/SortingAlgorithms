# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.27.4/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.27.4/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/andrebrahin/Computing_Science/SortingAlgorithms

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/andrebrahin/Computing_Science/SortingAlgorithms/build

# Include any dependencies generated for this target.
include _deps/googletest-build/googlemock/CMakeFiles/gmock_main.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include _deps/googletest-build/googlemock/CMakeFiles/gmock_main.dir/compiler_depend.make

# Include the progress variables for this target.
include _deps/googletest-build/googlemock/CMakeFiles/gmock_main.dir/progress.make

# Include the compile flags for this target's objects.
include _deps/googletest-build/googlemock/CMakeFiles/gmock_main.dir/flags.make

_deps/googletest-build/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o: _deps/googletest-build/googlemock/CMakeFiles/gmock_main.dir/flags.make
_deps/googletest-build/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o: _deps/googletest-src/googlemock/src/gmock_main.cc
_deps/googletest-build/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o: _deps/googletest-build/googlemock/CMakeFiles/gmock_main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/andrebrahin/Computing_Science/SortingAlgorithms/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object _deps/googletest-build/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o"
	cd /Users/andrebrahin/Computing_Science/SortingAlgorithms/build/_deps/googletest-build/googlemock && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT _deps/googletest-build/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o -MF CMakeFiles/gmock_main.dir/src/gmock_main.cc.o.d -o CMakeFiles/gmock_main.dir/src/gmock_main.cc.o -c /Users/andrebrahin/Computing_Science/SortingAlgorithms/build/_deps/googletest-src/googlemock/src/gmock_main.cc

_deps/googletest-build/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/gmock_main.dir/src/gmock_main.cc.i"
	cd /Users/andrebrahin/Computing_Science/SortingAlgorithms/build/_deps/googletest-build/googlemock && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/andrebrahin/Computing_Science/SortingAlgorithms/build/_deps/googletest-src/googlemock/src/gmock_main.cc > CMakeFiles/gmock_main.dir/src/gmock_main.cc.i

_deps/googletest-build/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/gmock_main.dir/src/gmock_main.cc.s"
	cd /Users/andrebrahin/Computing_Science/SortingAlgorithms/build/_deps/googletest-build/googlemock && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/andrebrahin/Computing_Science/SortingAlgorithms/build/_deps/googletest-src/googlemock/src/gmock_main.cc -o CMakeFiles/gmock_main.dir/src/gmock_main.cc.s

# Object files for target gmock_main
gmock_main_OBJECTS = \
"CMakeFiles/gmock_main.dir/src/gmock_main.cc.o"

# External object files for target gmock_main
gmock_main_EXTERNAL_OBJECTS =

lib/libgmock_main.a: _deps/googletest-build/googlemock/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o
lib/libgmock_main.a: _deps/googletest-build/googlemock/CMakeFiles/gmock_main.dir/build.make
lib/libgmock_main.a: _deps/googletest-build/googlemock/CMakeFiles/gmock_main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/andrebrahin/Computing_Science/SortingAlgorithms/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ../../../lib/libgmock_main.a"
	cd /Users/andrebrahin/Computing_Science/SortingAlgorithms/build/_deps/googletest-build/googlemock && $(CMAKE_COMMAND) -P CMakeFiles/gmock_main.dir/cmake_clean_target.cmake
	cd /Users/andrebrahin/Computing_Science/SortingAlgorithms/build/_deps/googletest-build/googlemock && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gmock_main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
_deps/googletest-build/googlemock/CMakeFiles/gmock_main.dir/build: lib/libgmock_main.a
.PHONY : _deps/googletest-build/googlemock/CMakeFiles/gmock_main.dir/build

_deps/googletest-build/googlemock/CMakeFiles/gmock_main.dir/clean:
	cd /Users/andrebrahin/Computing_Science/SortingAlgorithms/build/_deps/googletest-build/googlemock && $(CMAKE_COMMAND) -P CMakeFiles/gmock_main.dir/cmake_clean.cmake
.PHONY : _deps/googletest-build/googlemock/CMakeFiles/gmock_main.dir/clean

_deps/googletest-build/googlemock/CMakeFiles/gmock_main.dir/depend:
	cd /Users/andrebrahin/Computing_Science/SortingAlgorithms/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/andrebrahin/Computing_Science/SortingAlgorithms /Users/andrebrahin/Computing_Science/SortingAlgorithms/build/_deps/googletest-src/googlemock /Users/andrebrahin/Computing_Science/SortingAlgorithms/build /Users/andrebrahin/Computing_Science/SortingAlgorithms/build/_deps/googletest-build/googlemock /Users/andrebrahin/Computing_Science/SortingAlgorithms/build/_deps/googletest-build/googlemock/CMakeFiles/gmock_main.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : _deps/googletest-build/googlemock/CMakeFiles/gmock_main.dir/depend

