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
CMAKE_SOURCE_DIR = C:\Project\C++\leetcode\Leetcode\98.ValidateBinarySearchTree

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Project\C++\leetcode\Leetcode\98.ValidateBinarySearchTree\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\98_ValidateBinarySearchTree.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\98_ValidateBinarySearchTree.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\98_ValidateBinarySearchTree.dir\flags.make

CMakeFiles\98_ValidateBinarySearchTree.dir\main.cpp.obj: CMakeFiles\98_ValidateBinarySearchTree.dir\flags.make
CMakeFiles\98_ValidateBinarySearchTree.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Project\C++\leetcode\Leetcode\98.ValidateBinarySearchTree\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/98_ValidateBinarySearchTree.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~1.0\VC\bin\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\98_ValidateBinarySearchTree.dir\main.cpp.obj /FdCMakeFiles\98_ValidateBinarySearchTree.dir\ /FS -c C:\Project\C++\leetcode\Leetcode\98.ValidateBinarySearchTree\main.cpp
<<

CMakeFiles\98_ValidateBinarySearchTree.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/98_ValidateBinarySearchTree.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~1.0\VC\bin\cl.exe > CMakeFiles\98_ValidateBinarySearchTree.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Project\C++\leetcode\Leetcode\98.ValidateBinarySearchTree\main.cpp
<<

CMakeFiles\98_ValidateBinarySearchTree.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/98_ValidateBinarySearchTree.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~1.0\VC\bin\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\98_ValidateBinarySearchTree.dir\main.cpp.s /c C:\Project\C++\leetcode\Leetcode\98.ValidateBinarySearchTree\main.cpp
<<

# Object files for target 98_ValidateBinarySearchTree
98_ValidateBinarySearchTree_OBJECTS = \
"CMakeFiles\98_ValidateBinarySearchTree.dir\main.cpp.obj"

# External object files for target 98_ValidateBinarySearchTree
98_ValidateBinarySearchTree_EXTERNAL_OBJECTS =

98_ValidateBinarySearchTree.exe: CMakeFiles\98_ValidateBinarySearchTree.dir\main.cpp.obj
98_ValidateBinarySearchTree.exe: CMakeFiles\98_ValidateBinarySearchTree.dir\build.make
98_ValidateBinarySearchTree.exe: CMakeFiles\98_ValidateBinarySearchTree.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Project\C++\leetcode\Leetcode\98.ValidateBinarySearchTree\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 98_ValidateBinarySearchTree.exe"
	"C:\software\CLion 2018.2.1\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\98_ValidateBinarySearchTree.dir --manifests  -- C:\PROGRA~2\MICROS~1.0\VC\bin\link.exe /nologo @CMakeFiles\98_ValidateBinarySearchTree.dir\objects1.rsp @<<
 /out:98_ValidateBinarySearchTree.exe /implib:98_ValidateBinarySearchTree.lib /pdb:C:\Project\C++\leetcode\Leetcode\98.ValidateBinarySearchTree\cmake-build-debug\98_ValidateBinarySearchTree.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\98_ValidateBinarySearchTree.dir\build: 98_ValidateBinarySearchTree.exe

.PHONY : CMakeFiles\98_ValidateBinarySearchTree.dir\build

CMakeFiles\98_ValidateBinarySearchTree.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\98_ValidateBinarySearchTree.dir\cmake_clean.cmake
.PHONY : CMakeFiles\98_ValidateBinarySearchTree.dir\clean

CMakeFiles\98_ValidateBinarySearchTree.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Project\C++\leetcode\Leetcode\98.ValidateBinarySearchTree C:\Project\C++\leetcode\Leetcode\98.ValidateBinarySearchTree C:\Project\C++\leetcode\Leetcode\98.ValidateBinarySearchTree\cmake-build-debug C:\Project\C++\leetcode\Leetcode\98.ValidateBinarySearchTree\cmake-build-debug C:\Project\C++\leetcode\Leetcode\98.ValidateBinarySearchTree\cmake-build-debug\CMakeFiles\98_ValidateBinarySearchTree.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\98_ValidateBinarySearchTree.dir\depend
