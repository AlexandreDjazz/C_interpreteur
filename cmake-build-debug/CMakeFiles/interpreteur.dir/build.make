# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.29

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
CMAKE_COMMAND = "D:\CLion 2024.2.2\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "D:\CLion 2024.2.2\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\C\C_interpreteur

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\C\C_interpreteur\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/interpreteur.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/interpreteur.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/interpreteur.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/interpreteur.dir/flags.make

CMakeFiles/interpreteur.dir/main.c.obj: CMakeFiles/interpreteur.dir/flags.make
CMakeFiles/interpreteur.dir/main.c.obj: D:/C/C_interpreteur/main.c
CMakeFiles/interpreteur.dir/main.c.obj: CMakeFiles/interpreteur.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\C\C_interpreteur\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/interpreteur.dir/main.c.obj"
	"D:\CLion 2024.2.2\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/interpreteur.dir/main.c.obj -MF CMakeFiles\interpreteur.dir\main.c.obj.d -o CMakeFiles\interpreteur.dir\main.c.obj -c D:\C\C_interpreteur\main.c

CMakeFiles/interpreteur.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/interpreteur.dir/main.c.i"
	"D:\CLion 2024.2.2\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\C\C_interpreteur\main.c > CMakeFiles\interpreteur.dir\main.c.i

CMakeFiles/interpreteur.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/interpreteur.dir/main.c.s"
	"D:\CLion 2024.2.2\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\C\C_interpreteur\main.c -o CMakeFiles\interpreteur.dir\main.c.s

CMakeFiles/interpreteur.dir/file.c.obj: CMakeFiles/interpreteur.dir/flags.make
CMakeFiles/interpreteur.dir/file.c.obj: D:/C/C_interpreteur/file.c
CMakeFiles/interpreteur.dir/file.c.obj: CMakeFiles/interpreteur.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\C\C_interpreteur\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/interpreteur.dir/file.c.obj"
	"D:\CLion 2024.2.2\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/interpreteur.dir/file.c.obj -MF CMakeFiles\interpreteur.dir\file.c.obj.d -o CMakeFiles\interpreteur.dir\file.c.obj -c D:\C\C_interpreteur\file.c

CMakeFiles/interpreteur.dir/file.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/interpreteur.dir/file.c.i"
	"D:\CLion 2024.2.2\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\C\C_interpreteur\file.c > CMakeFiles\interpreteur.dir\file.c.i

CMakeFiles/interpreteur.dir/file.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/interpreteur.dir/file.c.s"
	"D:\CLion 2024.2.2\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\C\C_interpreteur\file.c -o CMakeFiles\interpreteur.dir\file.c.s

CMakeFiles/interpreteur.dir/lexer.c.obj: CMakeFiles/interpreteur.dir/flags.make
CMakeFiles/interpreteur.dir/lexer.c.obj: D:/C/C_interpreteur/lexer.c
CMakeFiles/interpreteur.dir/lexer.c.obj: CMakeFiles/interpreteur.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\C\C_interpreteur\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/interpreteur.dir/lexer.c.obj"
	"D:\CLion 2024.2.2\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/interpreteur.dir/lexer.c.obj -MF CMakeFiles\interpreteur.dir\lexer.c.obj.d -o CMakeFiles\interpreteur.dir\lexer.c.obj -c D:\C\C_interpreteur\lexer.c

CMakeFiles/interpreteur.dir/lexer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/interpreteur.dir/lexer.c.i"
	"D:\CLion 2024.2.2\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\C\C_interpreteur\lexer.c > CMakeFiles\interpreteur.dir\lexer.c.i

CMakeFiles/interpreteur.dir/lexer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/interpreteur.dir/lexer.c.s"
	"D:\CLion 2024.2.2\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\C\C_interpreteur\lexer.c -o CMakeFiles\interpreteur.dir\lexer.c.s

CMakeFiles/interpreteur.dir/string.c.obj: CMakeFiles/interpreteur.dir/flags.make
CMakeFiles/interpreteur.dir/string.c.obj: D:/C/C_interpreteur/string.c
CMakeFiles/interpreteur.dir/string.c.obj: CMakeFiles/interpreteur.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\C\C_interpreteur\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/interpreteur.dir/string.c.obj"
	"D:\CLion 2024.2.2\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/interpreteur.dir/string.c.obj -MF CMakeFiles\interpreteur.dir\string.c.obj.d -o CMakeFiles\interpreteur.dir\string.c.obj -c D:\C\C_interpreteur\string.c

CMakeFiles/interpreteur.dir/string.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/interpreteur.dir/string.c.i"
	"D:\CLion 2024.2.2\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\C\C_interpreteur\string.c > CMakeFiles\interpreteur.dir\string.c.i

CMakeFiles/interpreteur.dir/string.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/interpreteur.dir/string.c.s"
	"D:\CLion 2024.2.2\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\C\C_interpreteur\string.c -o CMakeFiles\interpreteur.dir\string.c.s

CMakeFiles/interpreteur.dir/token.c.obj: CMakeFiles/interpreteur.dir/flags.make
CMakeFiles/interpreteur.dir/token.c.obj: D:/C/C_interpreteur/token.c
CMakeFiles/interpreteur.dir/token.c.obj: CMakeFiles/interpreteur.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\C\C_interpreteur\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/interpreteur.dir/token.c.obj"
	"D:\CLion 2024.2.2\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/interpreteur.dir/token.c.obj -MF CMakeFiles\interpreteur.dir\token.c.obj.d -o CMakeFiles\interpreteur.dir\token.c.obj -c D:\C\C_interpreteur\token.c

CMakeFiles/interpreteur.dir/token.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/interpreteur.dir/token.c.i"
	"D:\CLion 2024.2.2\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\C\C_interpreteur\token.c > CMakeFiles\interpreteur.dir\token.c.i

CMakeFiles/interpreteur.dir/token.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/interpreteur.dir/token.c.s"
	"D:\CLion 2024.2.2\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\C\C_interpreteur\token.c -o CMakeFiles\interpreteur.dir\token.c.s

CMakeFiles/interpreteur.dir/parser.c.obj: CMakeFiles/interpreteur.dir/flags.make
CMakeFiles/interpreteur.dir/parser.c.obj: D:/C/C_interpreteur/parser.c
CMakeFiles/interpreteur.dir/parser.c.obj: CMakeFiles/interpreteur.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\C\C_interpreteur\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/interpreteur.dir/parser.c.obj"
	"D:\CLion 2024.2.2\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/interpreteur.dir/parser.c.obj -MF CMakeFiles\interpreteur.dir\parser.c.obj.d -o CMakeFiles\interpreteur.dir\parser.c.obj -c D:\C\C_interpreteur\parser.c

CMakeFiles/interpreteur.dir/parser.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/interpreteur.dir/parser.c.i"
	"D:\CLion 2024.2.2\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\C\C_interpreteur\parser.c > CMakeFiles\interpreteur.dir\parser.c.i

CMakeFiles/interpreteur.dir/parser.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/interpreteur.dir/parser.c.s"
	"D:\CLion 2024.2.2\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\C\C_interpreteur\parser.c -o CMakeFiles\interpreteur.dir\parser.c.s

CMakeFiles/interpreteur.dir/stack.c.obj: CMakeFiles/interpreteur.dir/flags.make
CMakeFiles/interpreteur.dir/stack.c.obj: D:/C/C_interpreteur/stack.c
CMakeFiles/interpreteur.dir/stack.c.obj: CMakeFiles/interpreteur.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\C\C_interpreteur\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/interpreteur.dir/stack.c.obj"
	"D:\CLion 2024.2.2\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/interpreteur.dir/stack.c.obj -MF CMakeFiles\interpreteur.dir\stack.c.obj.d -o CMakeFiles\interpreteur.dir\stack.c.obj -c D:\C\C_interpreteur\stack.c

CMakeFiles/interpreteur.dir/stack.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/interpreteur.dir/stack.c.i"
	"D:\CLion 2024.2.2\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\C\C_interpreteur\stack.c > CMakeFiles\interpreteur.dir\stack.c.i

CMakeFiles/interpreteur.dir/stack.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/interpreteur.dir/stack.c.s"
	"D:\CLion 2024.2.2\bin\mingw\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\C\C_interpreteur\stack.c -o CMakeFiles\interpreteur.dir\stack.c.s

# Object files for target interpreteur
interpreteur_OBJECTS = \
"CMakeFiles/interpreteur.dir/main.c.obj" \
"CMakeFiles/interpreteur.dir/file.c.obj" \
"CMakeFiles/interpreteur.dir/lexer.c.obj" \
"CMakeFiles/interpreteur.dir/string.c.obj" \
"CMakeFiles/interpreteur.dir/token.c.obj" \
"CMakeFiles/interpreteur.dir/parser.c.obj" \
"CMakeFiles/interpreteur.dir/stack.c.obj"

# External object files for target interpreteur
interpreteur_EXTERNAL_OBJECTS =

interpreteur.exe: CMakeFiles/interpreteur.dir/main.c.obj
interpreteur.exe: CMakeFiles/interpreteur.dir/file.c.obj
interpreteur.exe: CMakeFiles/interpreteur.dir/lexer.c.obj
interpreteur.exe: CMakeFiles/interpreteur.dir/string.c.obj
interpreteur.exe: CMakeFiles/interpreteur.dir/token.c.obj
interpreteur.exe: CMakeFiles/interpreteur.dir/parser.c.obj
interpreteur.exe: CMakeFiles/interpreteur.dir/stack.c.obj
interpreteur.exe: CMakeFiles/interpreteur.dir/build.make
interpreteur.exe: CMakeFiles/interpreteur.dir/linkLibs.rsp
interpreteur.exe: CMakeFiles/interpreteur.dir/objects1.rsp
interpreteur.exe: CMakeFiles/interpreteur.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=D:\C\C_interpreteur\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking C executable interpreteur.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\interpreteur.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/interpreteur.dir/build: interpreteur.exe
.PHONY : CMakeFiles/interpreteur.dir/build

CMakeFiles/interpreteur.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\interpreteur.dir\cmake_clean.cmake
.PHONY : CMakeFiles/interpreteur.dir/clean

CMakeFiles/interpreteur.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\C\C_interpreteur D:\C\C_interpreteur D:\C\C_interpreteur\cmake-build-debug D:\C\C_interpreteur\cmake-build-debug D:\C\C_interpreteur\cmake-build-debug\CMakeFiles\interpreteur.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/interpreteur.dir/depend

