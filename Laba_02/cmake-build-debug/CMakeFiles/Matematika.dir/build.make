# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2017.2.3\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2017.2.3\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\Documents\Sharaga v.2\1 sem\Matematika"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\Documents\Sharaga v.2\1 sem\Matematika\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Matematika.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Matematika.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Matematika.dir/flags.make

CMakeFiles/Matematika.dir/main.cpp.obj: CMakeFiles/Matematika.dir/flags.make
CMakeFiles/Matematika.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Documents\Sharaga v.2\1 sem\Matematika\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Matematika.dir/main.cpp.obj"
	C:\mingw32\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Matematika.dir\main.cpp.obj -c "D:\Documents\Sharaga v.2\1 sem\Matematika\main.cpp"

CMakeFiles/Matematika.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Matematika.dir/main.cpp.i"
	C:\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Documents\Sharaga v.2\1 sem\Matematika\main.cpp" > CMakeFiles\Matematika.dir\main.cpp.i

CMakeFiles/Matematika.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Matematika.dir/main.cpp.s"
	C:\mingw32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Documents\Sharaga v.2\1 sem\Matematika\main.cpp" -o CMakeFiles\Matematika.dir\main.cpp.s

CMakeFiles/Matematika.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/Matematika.dir/main.cpp.obj.requires

CMakeFiles/Matematika.dir/main.cpp.obj.provides: CMakeFiles/Matematika.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Matematika.dir\build.make CMakeFiles/Matematika.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/Matematika.dir/main.cpp.obj.provides

CMakeFiles/Matematika.dir/main.cpp.obj.provides.build: CMakeFiles/Matematika.dir/main.cpp.obj


# Object files for target Matematika
Matematika_OBJECTS = \
"CMakeFiles/Matematika.dir/main.cpp.obj"

# External object files for target Matematika
Matematika_EXTERNAL_OBJECTS =

Matematika.exe: CMakeFiles/Matematika.dir/main.cpp.obj
Matematika.exe: CMakeFiles/Matematika.dir/build.make
Matematika.exe: CMakeFiles/Matematika.dir/linklibs.rsp
Matematika.exe: CMakeFiles/Matematika.dir/objects1.rsp
Matematika.exe: CMakeFiles/Matematika.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\Documents\Sharaga v.2\1 sem\Matematika\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Matematika.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Matematika.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Matematika.dir/build: Matematika.exe

.PHONY : CMakeFiles/Matematika.dir/build

CMakeFiles/Matematika.dir/requires: CMakeFiles/Matematika.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/Matematika.dir/requires

CMakeFiles/Matematika.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Matematika.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Matematika.dir/clean

CMakeFiles/Matematika.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\Documents\Sharaga v.2\1 sem\Matematika" "D:\Documents\Sharaga v.2\1 sem\Matematika" "D:\Documents\Sharaga v.2\1 sem\Matematika\cmake-build-debug" "D:\Documents\Sharaga v.2\1 sem\Matematika\cmake-build-debug" "D:\Documents\Sharaga v.2\1 sem\Matematika\cmake-build-debug\CMakeFiles\Matematika.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Matematika.dir/depend

