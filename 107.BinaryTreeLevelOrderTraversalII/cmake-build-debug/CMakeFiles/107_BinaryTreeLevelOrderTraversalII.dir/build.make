# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.12

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\software\CLion 2018.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\software\CLion 2018.2.1\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Project\C++\leetcode\Leetcode\107.BinaryTreeLevelOrderTraversalII

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Project\C++\leetcode\Leetcode\107.BinaryTreeLevelOrderTraversalII\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\107_BinaryTreeLevelOrderTraversalII.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\107_BinaryTreeLevelOrderTraversalII.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\107_BinaryTreeLevelOrderTraversalII.dir\flags.make

CMakeFiles\107_BinaryTreeLevelOrderTraversalII.dir\main.cpp.obj: CMakeFiles\107_BinaryTreeLevelOrderTraversalII.dir\flags.make
CMakeFiles\107_BinaryTreeLevelOrderTraversalII.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Project\C++\leetcode\Leetcode\107.BinaryTreeLevelOrderTraversalII\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/107_BinaryTreeLevelOrderTraversalII.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~1.0\VC\bin\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\107_BinaryTreeLevelOrderTraversalII.dir\main.cpp.obj /FdCMakeFiles\107_BinaryTreeLevelOrderTraversalII.dir\ /FS -c C:\Project\C++\leetcode\Leetcode\107.BinaryTreeLevelOrderTraversalII\main.cpp
<<

CMakeFiles\107_BinaryTreeLevelOrderTraversalII.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/107_BinaryTreeLevelOrderTraversalII.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~1.0\VC\bin\cl.exe > CMakeFiles\107_BinaryTreeLevelOrderTraversalII.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Project\C++\leetcode\Leetcode\107.BinaryTreeLevelOrderTraversalII\main.cpp
<<

CMakeFiles\107_BinaryTreeLevelOrderTraversalII.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/107_BinaryTreeLevelOrderTraversalII.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~1.0\VC\bin\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\107_BinaryTreeLevelOrderTraversalII.dir\main.cpp.s /c C:\Project\C++\leetcode\Leetcode\107.BinaryTreeLevelOrderTraversalII\main.cpp
<<

# Object files for target 107_BinaryTreeLevelOrderTraversalII
107_BinaryTreeLevelOrderTraversalII_OBJECTS = \
"CMakeFiles\107_BinaryTreeLevelOrderTraversalII.dir\main.cpp.obj"

# External object files for target 107_BinaryTreeLevelOrderTraversalII
107_BinaryTreeLevelOrderTraversalII_EXTERNAL_OBJECTS =

107_BinaryTreeLevelOrderTraversalII.exe: CMakeFiles\107_BinaryTreeLevelOrderTraversalII.dir\main.cpp.obj
107_BinaryTreeLevelOrderTraversalII.exe: CMakeFiles\107_BinaryTreeLevelOrderTraversalII.dir\build.make
107_BinaryTreeLevelOrderTraversalII.exe: CMakeFiles\107_BinaryTreeLevelOrderTraversalII.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Project\C++\leetcode\Leetcode\107.BinaryTreeLevelOrderTraversalII\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 107_BinaryTreeLevelOrderTraversalII.exe"
	"C:\software\CLion 2018.2.1\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\107_BinaryTreeLevelOrderTraversalII.dir --manifests  -- C:\PROGRA~2\MICROS~1.0\VC\bin\link.exe /nologo @CMakeFiles\107_BinaryTreeLevelOrderTraversalII.dir\objects1.rsp @<<
 /out:107_BinaryTreeLevelOrderTraversalII.exe /implib:107_BinaryTreeLevelOrderTraversalII.lib /pdb:C:\Project\C++\leetcode\Leetcode\107.BinaryTreeLevelOrderTraversalII\cmake-build-debug\107_BinaryTreeLevelOrderTraversalII.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\107_BinaryTreeLevelOrderTraversalII.dir\build: 107_BinaryTreeLevelOrderTraversalII.exe

.PHONY : CMakeFiles\107_BinaryTreeLevelOrderTraversalII.dir\build

CMakeFiles\107_BinaryTreeLevelOrderTraversalII.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\107_BinaryTreeLevelOrderTraversalII.dir\cmake_clean.cmake
.PHONY : CMakeFiles\107_BinaryTreeLevelOrderTraversalII.dir\clean

CMakeFiles\107_BinaryTreeLevelOrderTraversalII.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Project\C++\leetcode\Leetcode\107.BinaryTreeLevelOrderTraversalII C:\Project\C++\leetcode\Leetcode\107.BinaryTreeLevelOrderTraversalII C:\Project\C++\leetcode\Leetcode\107.BinaryTreeLevelOrderTraversalII\cmake-build-debug C:\Project\C++\leetcode\Leetcode\107.BinaryTreeLevelOrderTraversalII\cmake-build-debug C:\Project\C++\leetcode\Leetcode\107.BinaryTreeLevelOrderTraversalII\cmake-build-debug\CMakeFiles\107_BinaryTreeLevelOrderTraversalII.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\107_BinaryTreeLevelOrderTraversalII.dir\depend

