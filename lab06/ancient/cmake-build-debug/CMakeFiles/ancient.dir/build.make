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
CMAKE_SOURCE_DIR = C:\Users\nwkeith\CLionProjects\ancient

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\nwkeith\CLionProjects\ancient\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ancient.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ancient.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ancient.dir/flags.make

CMakeFiles/ancient.dir/main.cpp.obj: CMakeFiles/ancient.dir/flags.make
CMakeFiles/ancient.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\nwkeith\CLionProjects\ancient\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ancient.dir/main.cpp.obj"
	C:\mingw-w64\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\ancient.dir\main.cpp.obj -c C:\Users\nwkeith\CLionProjects\ancient\main.cpp

CMakeFiles/ancient.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ancient.dir/main.cpp.i"
	C:\mingw-w64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\nwkeith\CLionProjects\ancient\main.cpp > CMakeFiles\ancient.dir\main.cpp.i

CMakeFiles/ancient.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ancient.dir/main.cpp.s"
	C:\mingw-w64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\nwkeith\CLionProjects\ancient\main.cpp -o CMakeFiles\ancient.dir\main.cpp.s

# Object files for target ancient
ancient_OBJECTS = \
"CMakeFiles/ancient.dir/main.cpp.obj"

# External object files for target ancient
ancient_EXTERNAL_OBJECTS =

ancient.exe: CMakeFiles/ancient.dir/main.cpp.obj
ancient.exe: CMakeFiles/ancient.dir/build.make
ancient.exe: CMakeFiles/ancient.dir/linklibs.rsp
ancient.exe: CMakeFiles/ancient.dir/objects1.rsp
ancient.exe: CMakeFiles/ancient.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\nwkeith\CLionProjects\ancient\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ancient.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ancient.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ancient.dir/build: ancient.exe

.PHONY : CMakeFiles/ancient.dir/build

CMakeFiles/ancient.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ancient.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ancient.dir/clean

CMakeFiles/ancient.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\nwkeith\CLionProjects\ancient C:\Users\nwkeith\CLionProjects\ancient C:\Users\nwkeith\CLionProjects\ancient\cmake-build-debug C:\Users\nwkeith\CLionProjects\ancient\cmake-build-debug C:\Users\nwkeith\CLionProjects\ancient\cmake-build-debug\CMakeFiles\ancient.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ancient.dir/depend

