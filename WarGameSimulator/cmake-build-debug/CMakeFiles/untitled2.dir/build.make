# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /opt/clion-2021.1.1/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2021.1.1/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/joao_vieira/Desktop/CES_11/WarGameSimulator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/joao_vieira/Desktop/CES_11/WarGameSimulator/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/untitled2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/untitled2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/untitled2.dir/flags.make

CMakeFiles/untitled2.dir/main.cpp.o: CMakeFiles/untitled2.dir/flags.make
CMakeFiles/untitled2.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/joao_vieira/Desktop/CES_11/WarGameSimulator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/untitled2.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/untitled2.dir/main.cpp.o -c /home/joao_vieira/Desktop/CES_11/WarGameSimulator/main.cpp

CMakeFiles/untitled2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/untitled2.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/joao_vieira/Desktop/CES_11/WarGameSimulator/main.cpp > CMakeFiles/untitled2.dir/main.cpp.i

CMakeFiles/untitled2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/untitled2.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/joao_vieira/Desktop/CES_11/WarGameSimulator/main.cpp -o CMakeFiles/untitled2.dir/main.cpp.s

CMakeFiles/untitled2.dir/GameMode.cpp.o: CMakeFiles/untitled2.dir/flags.make
CMakeFiles/untitled2.dir/GameMode.cpp.o: ../GameMode.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/joao_vieira/Desktop/CES_11/WarGameSimulator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/untitled2.dir/GameMode.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/untitled2.dir/GameMode.cpp.o -c /home/joao_vieira/Desktop/CES_11/WarGameSimulator/GameMode.cpp

CMakeFiles/untitled2.dir/GameMode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/untitled2.dir/GameMode.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/joao_vieira/Desktop/CES_11/WarGameSimulator/GameMode.cpp > CMakeFiles/untitled2.dir/GameMode.cpp.i

CMakeFiles/untitled2.dir/GameMode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/untitled2.dir/GameMode.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/joao_vieira/Desktop/CES_11/WarGameSimulator/GameMode.cpp -o CMakeFiles/untitled2.dir/GameMode.cpp.s

CMakeFiles/untitled2.dir/DeckOperators.cpp.o: CMakeFiles/untitled2.dir/flags.make
CMakeFiles/untitled2.dir/DeckOperators.cpp.o: ../DeckOperators.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/joao_vieira/Desktop/CES_11/WarGameSimulator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/untitled2.dir/DeckOperators.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/untitled2.dir/DeckOperators.cpp.o -c /home/joao_vieira/Desktop/CES_11/WarGameSimulator/DeckOperators.cpp

CMakeFiles/untitled2.dir/DeckOperators.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/untitled2.dir/DeckOperators.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/joao_vieira/Desktop/CES_11/WarGameSimulator/DeckOperators.cpp > CMakeFiles/untitled2.dir/DeckOperators.cpp.i

CMakeFiles/untitled2.dir/DeckOperators.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/untitled2.dir/DeckOperators.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/joao_vieira/Desktop/CES_11/WarGameSimulator/DeckOperators.cpp -o CMakeFiles/untitled2.dir/DeckOperators.cpp.s

CMakeFiles/untitled2.dir/AdtQueue.cpp.o: CMakeFiles/untitled2.dir/flags.make
CMakeFiles/untitled2.dir/AdtQueue.cpp.o: ../AdtQueue.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/joao_vieira/Desktop/CES_11/WarGameSimulator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/untitled2.dir/AdtQueue.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/untitled2.dir/AdtQueue.cpp.o -c /home/joao_vieira/Desktop/CES_11/WarGameSimulator/AdtQueue.cpp

CMakeFiles/untitled2.dir/AdtQueue.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/untitled2.dir/AdtQueue.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/joao_vieira/Desktop/CES_11/WarGameSimulator/AdtQueue.cpp > CMakeFiles/untitled2.dir/AdtQueue.cpp.i

CMakeFiles/untitled2.dir/AdtQueue.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/untitled2.dir/AdtQueue.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/joao_vieira/Desktop/CES_11/WarGameSimulator/AdtQueue.cpp -o CMakeFiles/untitled2.dir/AdtQueue.cpp.s

# Object files for target untitled2
untitled2_OBJECTS = \
"CMakeFiles/untitled2.dir/main.cpp.o" \
"CMakeFiles/untitled2.dir/GameMode.cpp.o" \
"CMakeFiles/untitled2.dir/DeckOperators.cpp.o" \
"CMakeFiles/untitled2.dir/AdtQueue.cpp.o"

# External object files for target untitled2
untitled2_EXTERNAL_OBJECTS =

untitled2: CMakeFiles/untitled2.dir/main.cpp.o
untitled2: CMakeFiles/untitled2.dir/GameMode.cpp.o
untitled2: CMakeFiles/untitled2.dir/DeckOperators.cpp.o
untitled2: CMakeFiles/untitled2.dir/AdtQueue.cpp.o
untitled2: CMakeFiles/untitled2.dir/build.make
untitled2: CMakeFiles/untitled2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/joao_vieira/Desktop/CES_11/WarGameSimulator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable untitled2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/untitled2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/untitled2.dir/build: untitled2

.PHONY : CMakeFiles/untitled2.dir/build

CMakeFiles/untitled2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/untitled2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/untitled2.dir/clean

CMakeFiles/untitled2.dir/depend:
	cd /home/joao_vieira/Desktop/CES_11/WarGameSimulator/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/joao_vieira/Desktop/CES_11/WarGameSimulator /home/joao_vieira/Desktop/CES_11/WarGameSimulator /home/joao_vieira/Desktop/CES_11/WarGameSimulator/cmake-build-debug /home/joao_vieira/Desktop/CES_11/WarGameSimulator/cmake-build-debug /home/joao_vieira/Desktop/CES_11/WarGameSimulator/cmake-build-debug/CMakeFiles/untitled2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/untitled2.dir/depend

