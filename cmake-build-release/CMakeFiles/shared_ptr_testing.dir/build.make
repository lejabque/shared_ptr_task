# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/lejabque/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/202.7319.72/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/lejabque/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/202.7319.72/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lejabque/Study/itmo/course2/cpp/shared_ptr_task

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lejabque/Study/itmo/course2/cpp/shared_ptr_task/cmake-build-release

# Include any dependencies generated for this target.
include CMakeFiles/shared_ptr_testing.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/shared_ptr_testing.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/shared_ptr_testing.dir/flags.make

CMakeFiles/shared_ptr_testing.dir/main.cpp.o: CMakeFiles/shared_ptr_testing.dir/flags.make
CMakeFiles/shared_ptr_testing.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lejabque/Study/itmo/course2/cpp/shared_ptr_task/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/shared_ptr_testing.dir/main.cpp.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/shared_ptr_testing.dir/main.cpp.o -c /home/lejabque/Study/itmo/course2/cpp/shared_ptr_task/main.cpp

CMakeFiles/shared_ptr_testing.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/shared_ptr_testing.dir/main.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lejabque/Study/itmo/course2/cpp/shared_ptr_task/main.cpp > CMakeFiles/shared_ptr_testing.dir/main.cpp.i

CMakeFiles/shared_ptr_testing.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/shared_ptr_testing.dir/main.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lejabque/Study/itmo/course2/cpp/shared_ptr_task/main.cpp -o CMakeFiles/shared_ptr_testing.dir/main.cpp.s

CMakeFiles/shared_ptr_testing.dir/test_object.cpp.o: CMakeFiles/shared_ptr_testing.dir/flags.make
CMakeFiles/shared_ptr_testing.dir/test_object.cpp.o: ../test_object.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lejabque/Study/itmo/course2/cpp/shared_ptr_task/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/shared_ptr_testing.dir/test_object.cpp.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/shared_ptr_testing.dir/test_object.cpp.o -c /home/lejabque/Study/itmo/course2/cpp/shared_ptr_task/test_object.cpp

CMakeFiles/shared_ptr_testing.dir/test_object.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/shared_ptr_testing.dir/test_object.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lejabque/Study/itmo/course2/cpp/shared_ptr_task/test_object.cpp > CMakeFiles/shared_ptr_testing.dir/test_object.cpp.i

CMakeFiles/shared_ptr_testing.dir/test_object.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/shared_ptr_testing.dir/test_object.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lejabque/Study/itmo/course2/cpp/shared_ptr_task/test_object.cpp -o CMakeFiles/shared_ptr_testing.dir/test_object.cpp.s

CMakeFiles/shared_ptr_testing.dir/control_block.cpp.o: CMakeFiles/shared_ptr_testing.dir/flags.make
CMakeFiles/shared_ptr_testing.dir/control_block.cpp.o: ../control_block.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lejabque/Study/itmo/course2/cpp/shared_ptr_task/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/shared_ptr_testing.dir/control_block.cpp.o"
	/usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/shared_ptr_testing.dir/control_block.cpp.o -c /home/lejabque/Study/itmo/course2/cpp/shared_ptr_task/control_block.cpp

CMakeFiles/shared_ptr_testing.dir/control_block.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/shared_ptr_testing.dir/control_block.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lejabque/Study/itmo/course2/cpp/shared_ptr_task/control_block.cpp > CMakeFiles/shared_ptr_testing.dir/control_block.cpp.i

CMakeFiles/shared_ptr_testing.dir/control_block.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/shared_ptr_testing.dir/control_block.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lejabque/Study/itmo/course2/cpp/shared_ptr_task/control_block.cpp -o CMakeFiles/shared_ptr_testing.dir/control_block.cpp.s

# Object files for target shared_ptr_testing
shared_ptr_testing_OBJECTS = \
"CMakeFiles/shared_ptr_testing.dir/main.cpp.o" \
"CMakeFiles/shared_ptr_testing.dir/test_object.cpp.o" \
"CMakeFiles/shared_ptr_testing.dir/control_block.cpp.o"

# External object files for target shared_ptr_testing
shared_ptr_testing_EXTERNAL_OBJECTS =

shared_ptr_testing: CMakeFiles/shared_ptr_testing.dir/main.cpp.o
shared_ptr_testing: CMakeFiles/shared_ptr_testing.dir/test_object.cpp.o
shared_ptr_testing: CMakeFiles/shared_ptr_testing.dir/control_block.cpp.o
shared_ptr_testing: CMakeFiles/shared_ptr_testing.dir/build.make
shared_ptr_testing: gtest/libgtest.a
shared_ptr_testing: CMakeFiles/shared_ptr_testing.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lejabque/Study/itmo/course2/cpp/shared_ptr_task/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable shared_ptr_testing"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/shared_ptr_testing.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/shared_ptr_testing.dir/build: shared_ptr_testing

.PHONY : CMakeFiles/shared_ptr_testing.dir/build

CMakeFiles/shared_ptr_testing.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/shared_ptr_testing.dir/cmake_clean.cmake
.PHONY : CMakeFiles/shared_ptr_testing.dir/clean

CMakeFiles/shared_ptr_testing.dir/depend:
	cd /home/lejabque/Study/itmo/course2/cpp/shared_ptr_task/cmake-build-release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lejabque/Study/itmo/course2/cpp/shared_ptr_task /home/lejabque/Study/itmo/course2/cpp/shared_ptr_task /home/lejabque/Study/itmo/course2/cpp/shared_ptr_task/cmake-build-release /home/lejabque/Study/itmo/course2/cpp/shared_ptr_task/cmake-build-release /home/lejabque/Study/itmo/course2/cpp/shared_ptr_task/cmake-build-release/CMakeFiles/shared_ptr_testing.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/shared_ptr_testing.dir/depend

