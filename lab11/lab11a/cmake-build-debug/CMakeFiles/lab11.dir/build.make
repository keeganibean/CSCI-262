# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files (x86)\JetBrains\CLion 2019.1.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files (x86)\JetBrains\CLion 2019.1.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = Z:\lab11

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = Z:\lab11\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/lab11.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lab11.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab11.dir/flags.make

CMakeFiles/lab11.dir/tests.cpp.obj: CMakeFiles/lab11.dir/flags.make
CMakeFiles/lab11.dir/tests.cpp.obj: CMakeFiles/lab11.dir/includes_CXX.rsp
CMakeFiles/lab11.dir/tests.cpp.obj: ../tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=Z:\lab11\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lab11.dir/tests.cpp.obj"
	C:\mingw-w64\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\lab11.dir\tests.cpp.obj -c Z:\lab11\tests.cpp

CMakeFiles/lab11.dir/tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab11.dir/tests.cpp.i"
	C:\mingw-w64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E Z:\lab11\tests.cpp > CMakeFiles\lab11.dir\tests.cpp.i

CMakeFiles/lab11.dir/tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab11.dir/tests.cpp.s"
	C:\mingw-w64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S Z:\lab11\tests.cpp -o CMakeFiles\lab11.dir\tests.cpp.s

# Object files for target lab11
lab11_OBJECTS = \
"CMakeFiles/lab11.dir/tests.cpp.obj"

# External object files for target lab11
lab11_EXTERNAL_OBJECTS =

lab11.exe: CMakeFiles/lab11.dir/tests.cpp.obj
lab11.exe: CMakeFiles/lab11.dir/build.make
lab11.exe: CMakeFiles/lab11.dir/linklibs.rsp
lab11.exe: CMakeFiles/lab11.dir/objects1.rsp
lab11.exe: CMakeFiles/lab11.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=Z:\lab11\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable lab11.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\lab11.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab11.dir/build: lab11.exe

.PHONY : CMakeFiles/lab11.dir/build

CMakeFiles/lab11.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\lab11.dir\cmake_clean.cmake
.PHONY : CMakeFiles/lab11.dir/clean

CMakeFiles/lab11.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" Z:\lab11 Z:\lab11 Z:\lab11\cmake-build-debug Z:\lab11\cmake-build-debug Z:\lab11\cmake-build-debug\CMakeFiles\lab11.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lab11.dir/depend
