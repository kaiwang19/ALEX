# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Code\C++\ALEX

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Code\C++\ALEX\build

# Include any dependencies generated for this target.
include CMakeFiles/example_int.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/example_int.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/example_int.dir/flags.make

CMakeFiles/example_int.dir/src/examples/example_int.cpp.obj: CMakeFiles/example_int.dir/flags.make
CMakeFiles/example_int.dir/src/examples/example_int.cpp.obj: CMakeFiles/example_int.dir/includes_CXX.rsp
CMakeFiles/example_int.dir/src/examples/example_int.cpp.obj: ../src/examples/example_int.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Code\C++\ALEX\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/example_int.dir/src/examples/example_int.cpp.obj"
	D:\program\mingw-w64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\example_int.dir\src\examples\example_int.cpp.obj -c D:\Code\C++\ALEX\src\examples\example_int.cpp

CMakeFiles/example_int.dir/src/examples/example_int.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/example_int.dir/src/examples/example_int.cpp.i"
	D:\program\mingw-w64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Code\C++\ALEX\src\examples\example_int.cpp > CMakeFiles\example_int.dir\src\examples\example_int.cpp.i

CMakeFiles/example_int.dir/src/examples/example_int.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/example_int.dir/src/examples/example_int.cpp.s"
	D:\program\mingw-w64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Code\C++\ALEX\src\examples\example_int.cpp -o CMakeFiles\example_int.dir\src\examples\example_int.cpp.s

# Object files for target example_int
example_int_OBJECTS = \
"CMakeFiles/example_int.dir/src/examples/example_int.cpp.obj"

# External object files for target example_int
example_int_EXTERNAL_OBJECTS =

example_int.exe: CMakeFiles/example_int.dir/src/examples/example_int.cpp.obj
example_int.exe: CMakeFiles/example_int.dir/build.make
example_int.exe: CMakeFiles/example_int.dir/linklibs.rsp
example_int.exe: CMakeFiles/example_int.dir/objects1.rsp
example_int.exe: CMakeFiles/example_int.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Code\C++\ALEX\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable example_int.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\example_int.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/example_int.dir/build: example_int.exe

.PHONY : CMakeFiles/example_int.dir/build

CMakeFiles/example_int.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\example_int.dir\cmake_clean.cmake
.PHONY : CMakeFiles/example_int.dir/clean

CMakeFiles/example_int.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Code\C++\ALEX D:\Code\C++\ALEX D:\Code\C++\ALEX\build D:\Code\C++\ALEX\build D:\Code\C++\ALEX\build\CMakeFiles\example_int.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/example_int.dir/depend

