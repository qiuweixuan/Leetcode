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
CMAKE_SOURCE_DIR = C:\Project\C++\leetcode\Leetcode\102.BinaryTreeLevelOrderTraversal

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Project\C++\leetcode\Leetcode\102.BinaryTreeLevelOrderTraversal\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\102_BinaryTreeLevelOrderTraversal.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\102_BinaryTreeLevelOrderTraversal.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\102_BinaryTreeLevelOrderTraversal.dir\flags.make

CMakeFiles\102_BinaryTreeLevelOrderTraversal.dir\main.cpp.obj: CMakeFiles\102_BinaryTreeLevelOrderTraversal.dir\flags.make
CMakeFiles\102_BinaryTreeLevelOrderTraversal.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Project\C++\leetcode\Leetcode\102.BinaryTreeLevelOrderTraversal\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/102_BinaryTreeLevelOrderTraversal.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~1.0\VC\bin\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\102_BinaryTreeLevelOrderTraversal.dir\main.cpp.obj /FdCMakeFiles\102_BinaryTreeLevelOrderTraversal.dir\ /FS -c C:\Project\C++\leetcode\Leetcode\102.BinaryTreeLevelOrderTraversal\main.cpp
<<

CMakeFiles\102_BinaryTreeLevelOrderTraversal.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/102_BinaryTreeLevelOrderTraversal.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~1.0\VC\bin\cl.exe > CMakeFiles\102_BinaryTreeLevelOrderTraversal.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Project\C++\leetcode\Leetcode\102.BinaryTreeLevelOrderTraversal\main.cpp
<<

CMakeFiles\102_BinaryTreeLevelOrderTraversal.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/102_BinaryTreeLevelOrderTraversal.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~1.0\VC\bin\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\102_BinaryTreeLevelOrderTraversal.dir\main.cpp.s /c C:\Project\C++\leetcode\Leetcode\102.BinaryTreeLevelOrderTraversal\main.cpp
<<

# Object files for target 102_BinaryTreeLevelOrderTraversal
102_BinaryTreeLevelOrderTraversal_OBJECTS = \
"CMakeFiles\102_BinaryTreeLevelOrderTraversal.dir\main.cpp.obj"

# External object files for target 102_BinaryTreeLevelOrderTraversal
102_BinaryTreeLevelOrderTraversal_EXTERNAL_OBJECTS =

102_BinaryTreeLevelOrderTraversal.exe: CMakeFiles\102_BinaryTreeLevelOrderTraversal.dir\main.cpp.obj
102_BinaryTreeLevelOrderTraversal.exe: CMakeFiles\102_BinaryTreeLevelOrderTraversal.dir\build.make
102_BinaryTreeLevelOrderTraversal.exe: CMakeFiles\102_BinaryTreeLevelOrderTraversal.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Project\C++\leetcode\Leetcode\102.BinaryTreeLevelOrderTraversal\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 102_BinaryTreeLevelOrderTraversal.exe"
	"C:\software\CLion 2018.2.1\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\102_BinaryTreeLevelOrderTraversal.dir --manifests  -- C:\PROGRA~2\MICROS~1.0\VC\bin\link.exe /nologo @CMakeFiles\102_BinaryTreeLevelOrderTraversal.dir\objects1.rsp @<<
 /out:102_BinaryTreeLevelOrderTraversal.exe /implib:102_BinaryTreeLevelOrderTraversal.lib /pdb:C:\Project\C++\leetcode\Leetcode\102.BinaryTreeLevelOrderTraversal\cmake-build-debug\102_BinaryTreeLevelOrderTraversal.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\102_BinaryTreeLevelOrderTraversal.dir\build: 102_BinaryTreeLevelOrderTraversal.exe

.PHONY : CMakeFiles\102_BinaryTreeLevelOrderTraversal.dir\build

CMakeFiles\102_BinaryTreeLevelOrderTraversal.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\102_BinaryTreeLevelOrderTraversal.dir\cmake_clean.cmake
.PHONY : CMakeFiles\102_BinaryTreeLevelOrderTraversal.dir\clean

CMakeFiles\102_BinaryTreeLevelOrderTraversal.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Project\C++\leetcode\Leetcode\102.BinaryTreeLevelOrderTraversal C:\Project\C++\leetcode\Leetcode\102.BinaryTreeLevelOrderTraversal C:\Project\C++\leetcode\Leetcode\102.BinaryTreeLevelOrderTraversal\cmake-build-debug C:\Project\C++\leetcode\Leetcode\102.BinaryTreeLevelOrderTraversal\cmake-build-debug C:\Project\C++\leetcode\Leetcode\102.BinaryTreeLevelOrderTraversal\cmake-build-debug\CMakeFiles\102_BinaryTreeLevelOrderTraversal.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\102_BinaryTreeLevelOrderTraversal.dir\depend

