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
CMAKE_COMMAND = "C:\IDE\CLion 2018.2.5\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\IDE\CLion 2018.2.5\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Project\c++\alogorithm\70. Climbing Stairs"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Project\c++\alogorithm\70. Climbing Stairs\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles\70__Climbing_Stairs.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\70__Climbing_Stairs.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\70__Climbing_Stairs.dir\flags.make

CMakeFiles\70__Climbing_Stairs.dir\main.cpp.obj: CMakeFiles\70__Climbing_Stairs.dir\flags.make
CMakeFiles\70__Climbing_Stairs.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Project\c++\alogorithm\70. Climbing Stairs\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/70__Climbing_Stairs.dir/main.cpp.obj"
	C:\PROGRA~2\MIB055~1\2017\COMMUN~1\VC\Tools\MSVC\1415~1.267\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\70__Climbing_Stairs.dir\main.cpp.obj /FdCMakeFiles\70__Climbing_Stairs.dir\ /FS -c "C:\Project\c++\alogorithm\70. Climbing Stairs\main.cpp"
<<

CMakeFiles\70__Climbing_Stairs.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/70__Climbing_Stairs.dir/main.cpp.i"
	C:\PROGRA~2\MIB055~1\2017\COMMUN~1\VC\Tools\MSVC\1415~1.267\bin\Hostx86\x86\cl.exe > CMakeFiles\70__Climbing_Stairs.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Project\c++\alogorithm\70. Climbing Stairs\main.cpp"
<<

CMakeFiles\70__Climbing_Stairs.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/70__Climbing_Stairs.dir/main.cpp.s"
	C:\PROGRA~2\MIB055~1\2017\COMMUN~1\VC\Tools\MSVC\1415~1.267\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\70__Climbing_Stairs.dir\main.cpp.s /c "C:\Project\c++\alogorithm\70. Climbing Stairs\main.cpp"
<<

# Object files for target 70__Climbing_Stairs
70__Climbing_Stairs_OBJECTS = \
"CMakeFiles\70__Climbing_Stairs.dir\main.cpp.obj"

# External object files for target 70__Climbing_Stairs
70__Climbing_Stairs_EXTERNAL_OBJECTS =

70__Climbing_Stairs.exe: CMakeFiles\70__Climbing_Stairs.dir\main.cpp.obj
70__Climbing_Stairs.exe: CMakeFiles\70__Climbing_Stairs.dir\build.make
70__Climbing_Stairs.exe: CMakeFiles\70__Climbing_Stairs.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Project\c++\alogorithm\70. Climbing Stairs\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 70__Climbing_Stairs.exe"
	"C:\IDE\CLion 2018.2.5\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\70__Climbing_Stairs.dir --manifests  -- C:\PROGRA~2\MIB055~1\2017\COMMUN~1\VC\Tools\MSVC\1415~1.267\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\70__Climbing_Stairs.dir\objects1.rsp @<<
 /out:70__Climbing_Stairs.exe /implib:70__Climbing_Stairs.lib /pdb:"C:\Project\c++\alogorithm\70. Climbing Stairs\cmake-build-debug\70__Climbing_Stairs.pdb" /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\70__Climbing_Stairs.dir\build: 70__Climbing_Stairs.exe

.PHONY : CMakeFiles\70__Climbing_Stairs.dir\build

CMakeFiles\70__Climbing_Stairs.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\70__Climbing_Stairs.dir\cmake_clean.cmake
.PHONY : CMakeFiles\70__Climbing_Stairs.dir\clean

CMakeFiles\70__Climbing_Stairs.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" "C:\Project\c++\alogorithm\70. Climbing Stairs" "C:\Project\c++\alogorithm\70. Climbing Stairs" "C:\Project\c++\alogorithm\70. Climbing Stairs\cmake-build-debug" "C:\Project\c++\alogorithm\70. Climbing Stairs\cmake-build-debug" "C:\Project\c++\alogorithm\70. Climbing Stairs\cmake-build-debug\CMakeFiles\70__Climbing_Stairs.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles\70__Climbing_Stairs.dir\depend

