# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.22.1/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.22.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/florrdv/Projects/pse-traffic-sim

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/florrdv/Projects/pse-traffic-sim/build

# Include any dependencies generated for this target.
include CMakeFiles/TrafficSim.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/TrafficSim.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/TrafficSim.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TrafficSim.dir/flags.make

CMakeFiles/TrafficSim.dir/src/TrafficSim.cc.o: CMakeFiles/TrafficSim.dir/flags.make
CMakeFiles/TrafficSim.dir/src/TrafficSim.cc.o: ../src/TrafficSim.cc
CMakeFiles/TrafficSim.dir/src/TrafficSim.cc.o: CMakeFiles/TrafficSim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/florrdv/Projects/pse-traffic-sim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TrafficSim.dir/src/TrafficSim.cc.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TrafficSim.dir/src/TrafficSim.cc.o -MF CMakeFiles/TrafficSim.dir/src/TrafficSim.cc.o.d -o CMakeFiles/TrafficSim.dir/src/TrafficSim.cc.o -c /Users/florrdv/Projects/pse-traffic-sim/src/TrafficSim.cc

CMakeFiles/TrafficSim.dir/src/TrafficSim.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TrafficSim.dir/src/TrafficSim.cc.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/florrdv/Projects/pse-traffic-sim/src/TrafficSim.cc > CMakeFiles/TrafficSim.dir/src/TrafficSim.cc.i

CMakeFiles/TrafficSim.dir/src/TrafficSim.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TrafficSim.dir/src/TrafficSim.cc.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/florrdv/Projects/pse-traffic-sim/src/TrafficSim.cc -o CMakeFiles/TrafficSim.dir/src/TrafficSim.cc.s

CMakeFiles/TrafficSim.dir/src/util/XMLParser.cc.o: CMakeFiles/TrafficSim.dir/flags.make
CMakeFiles/TrafficSim.dir/src/util/XMLParser.cc.o: ../src/util/XMLParser.cc
CMakeFiles/TrafficSim.dir/src/util/XMLParser.cc.o: CMakeFiles/TrafficSim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/florrdv/Projects/pse-traffic-sim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/TrafficSim.dir/src/util/XMLParser.cc.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TrafficSim.dir/src/util/XMLParser.cc.o -MF CMakeFiles/TrafficSim.dir/src/util/XMLParser.cc.o.d -o CMakeFiles/TrafficSim.dir/src/util/XMLParser.cc.o -c /Users/florrdv/Projects/pse-traffic-sim/src/util/XMLParser.cc

CMakeFiles/TrafficSim.dir/src/util/XMLParser.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TrafficSim.dir/src/util/XMLParser.cc.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/florrdv/Projects/pse-traffic-sim/src/util/XMLParser.cc > CMakeFiles/TrafficSim.dir/src/util/XMLParser.cc.i

CMakeFiles/TrafficSim.dir/src/util/XMLParser.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TrafficSim.dir/src/util/XMLParser.cc.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/florrdv/Projects/pse-traffic-sim/src/util/XMLParser.cc -o CMakeFiles/TrafficSim.dir/src/util/XMLParser.cc.s

CMakeFiles/TrafficSim.dir/src/lib/TinyXML/tinystr.cpp.o: CMakeFiles/TrafficSim.dir/flags.make
CMakeFiles/TrafficSim.dir/src/lib/TinyXML/tinystr.cpp.o: ../src/lib/TinyXML/tinystr.cpp
CMakeFiles/TrafficSim.dir/src/lib/TinyXML/tinystr.cpp.o: CMakeFiles/TrafficSim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/florrdv/Projects/pse-traffic-sim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/TrafficSim.dir/src/lib/TinyXML/tinystr.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TrafficSim.dir/src/lib/TinyXML/tinystr.cpp.o -MF CMakeFiles/TrafficSim.dir/src/lib/TinyXML/tinystr.cpp.o.d -o CMakeFiles/TrafficSim.dir/src/lib/TinyXML/tinystr.cpp.o -c /Users/florrdv/Projects/pse-traffic-sim/src/lib/TinyXML/tinystr.cpp

CMakeFiles/TrafficSim.dir/src/lib/TinyXML/tinystr.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TrafficSim.dir/src/lib/TinyXML/tinystr.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/florrdv/Projects/pse-traffic-sim/src/lib/TinyXML/tinystr.cpp > CMakeFiles/TrafficSim.dir/src/lib/TinyXML/tinystr.cpp.i

CMakeFiles/TrafficSim.dir/src/lib/TinyXML/tinystr.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TrafficSim.dir/src/lib/TinyXML/tinystr.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/florrdv/Projects/pse-traffic-sim/src/lib/TinyXML/tinystr.cpp -o CMakeFiles/TrafficSim.dir/src/lib/TinyXML/tinystr.cpp.s

CMakeFiles/TrafficSim.dir/src/lib/TinyXML/tinyxml.cpp.o: CMakeFiles/TrafficSim.dir/flags.make
CMakeFiles/TrafficSim.dir/src/lib/TinyXML/tinyxml.cpp.o: ../src/lib/TinyXML/tinyxml.cpp
CMakeFiles/TrafficSim.dir/src/lib/TinyXML/tinyxml.cpp.o: CMakeFiles/TrafficSim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/florrdv/Projects/pse-traffic-sim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/TrafficSim.dir/src/lib/TinyXML/tinyxml.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TrafficSim.dir/src/lib/TinyXML/tinyxml.cpp.o -MF CMakeFiles/TrafficSim.dir/src/lib/TinyXML/tinyxml.cpp.o.d -o CMakeFiles/TrafficSim.dir/src/lib/TinyXML/tinyxml.cpp.o -c /Users/florrdv/Projects/pse-traffic-sim/src/lib/TinyXML/tinyxml.cpp

CMakeFiles/TrafficSim.dir/src/lib/TinyXML/tinyxml.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TrafficSim.dir/src/lib/TinyXML/tinyxml.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/florrdv/Projects/pse-traffic-sim/src/lib/TinyXML/tinyxml.cpp > CMakeFiles/TrafficSim.dir/src/lib/TinyXML/tinyxml.cpp.i

CMakeFiles/TrafficSim.dir/src/lib/TinyXML/tinyxml.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TrafficSim.dir/src/lib/TinyXML/tinyxml.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/florrdv/Projects/pse-traffic-sim/src/lib/TinyXML/tinyxml.cpp -o CMakeFiles/TrafficSim.dir/src/lib/TinyXML/tinyxml.cpp.s

CMakeFiles/TrafficSim.dir/src/lib/TinyXML/tinyxmlerror.cpp.o: CMakeFiles/TrafficSim.dir/flags.make
CMakeFiles/TrafficSim.dir/src/lib/TinyXML/tinyxmlerror.cpp.o: ../src/lib/TinyXML/tinyxmlerror.cpp
CMakeFiles/TrafficSim.dir/src/lib/TinyXML/tinyxmlerror.cpp.o: CMakeFiles/TrafficSim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/florrdv/Projects/pse-traffic-sim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/TrafficSim.dir/src/lib/TinyXML/tinyxmlerror.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TrafficSim.dir/src/lib/TinyXML/tinyxmlerror.cpp.o -MF CMakeFiles/TrafficSim.dir/src/lib/TinyXML/tinyxmlerror.cpp.o.d -o CMakeFiles/TrafficSim.dir/src/lib/TinyXML/tinyxmlerror.cpp.o -c /Users/florrdv/Projects/pse-traffic-sim/src/lib/TinyXML/tinyxmlerror.cpp

CMakeFiles/TrafficSim.dir/src/lib/TinyXML/tinyxmlerror.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TrafficSim.dir/src/lib/TinyXML/tinyxmlerror.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/florrdv/Projects/pse-traffic-sim/src/lib/TinyXML/tinyxmlerror.cpp > CMakeFiles/TrafficSim.dir/src/lib/TinyXML/tinyxmlerror.cpp.i

CMakeFiles/TrafficSim.dir/src/lib/TinyXML/tinyxmlerror.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TrafficSim.dir/src/lib/TinyXML/tinyxmlerror.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/florrdv/Projects/pse-traffic-sim/src/lib/TinyXML/tinyxmlerror.cpp -o CMakeFiles/TrafficSim.dir/src/lib/TinyXML/tinyxmlerror.cpp.s

CMakeFiles/TrafficSim.dir/src/lib/TinyXML/tinyxmlparser.cpp.o: CMakeFiles/TrafficSim.dir/flags.make
CMakeFiles/TrafficSim.dir/src/lib/TinyXML/tinyxmlparser.cpp.o: ../src/lib/TinyXML/tinyxmlparser.cpp
CMakeFiles/TrafficSim.dir/src/lib/TinyXML/tinyxmlparser.cpp.o: CMakeFiles/TrafficSim.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/florrdv/Projects/pse-traffic-sim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/TrafficSim.dir/src/lib/TinyXML/tinyxmlparser.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TrafficSim.dir/src/lib/TinyXML/tinyxmlparser.cpp.o -MF CMakeFiles/TrafficSim.dir/src/lib/TinyXML/tinyxmlparser.cpp.o.d -o CMakeFiles/TrafficSim.dir/src/lib/TinyXML/tinyxmlparser.cpp.o -c /Users/florrdv/Projects/pse-traffic-sim/src/lib/TinyXML/tinyxmlparser.cpp

CMakeFiles/TrafficSim.dir/src/lib/TinyXML/tinyxmlparser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TrafficSim.dir/src/lib/TinyXML/tinyxmlparser.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/florrdv/Projects/pse-traffic-sim/src/lib/TinyXML/tinyxmlparser.cpp > CMakeFiles/TrafficSim.dir/src/lib/TinyXML/tinyxmlparser.cpp.i

CMakeFiles/TrafficSim.dir/src/lib/TinyXML/tinyxmlparser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TrafficSim.dir/src/lib/TinyXML/tinyxmlparser.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/florrdv/Projects/pse-traffic-sim/src/lib/TinyXML/tinyxmlparser.cpp -o CMakeFiles/TrafficSim.dir/src/lib/TinyXML/tinyxmlparser.cpp.s

# Object files for target TrafficSim
TrafficSim_OBJECTS = \
"CMakeFiles/TrafficSim.dir/src/TrafficSim.cc.o" \
"CMakeFiles/TrafficSim.dir/src/util/XMLParser.cc.o" \
"CMakeFiles/TrafficSim.dir/src/lib/TinyXML/tinystr.cpp.o" \
"CMakeFiles/TrafficSim.dir/src/lib/TinyXML/tinyxml.cpp.o" \
"CMakeFiles/TrafficSim.dir/src/lib/TinyXML/tinyxmlerror.cpp.o" \
"CMakeFiles/TrafficSim.dir/src/lib/TinyXML/tinyxmlparser.cpp.o"

# External object files for target TrafficSim
TrafficSim_EXTERNAL_OBJECTS =

TrafficSim: CMakeFiles/TrafficSim.dir/src/TrafficSim.cc.o
TrafficSim: CMakeFiles/TrafficSim.dir/src/util/XMLParser.cc.o
TrafficSim: CMakeFiles/TrafficSim.dir/src/lib/TinyXML/tinystr.cpp.o
TrafficSim: CMakeFiles/TrafficSim.dir/src/lib/TinyXML/tinyxml.cpp.o
TrafficSim: CMakeFiles/TrafficSim.dir/src/lib/TinyXML/tinyxmlerror.cpp.o
TrafficSim: CMakeFiles/TrafficSim.dir/src/lib/TinyXML/tinyxmlparser.cpp.o
TrafficSim: CMakeFiles/TrafficSim.dir/build.make
TrafficSim: CMakeFiles/TrafficSim.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/florrdv/Projects/pse-traffic-sim/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable TrafficSim"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TrafficSim.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TrafficSim.dir/build: TrafficSim
.PHONY : CMakeFiles/TrafficSim.dir/build

CMakeFiles/TrafficSim.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TrafficSim.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TrafficSim.dir/clean

CMakeFiles/TrafficSim.dir/depend:
	cd /Users/florrdv/Projects/pse-traffic-sim/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/florrdv/Projects/pse-traffic-sim /Users/florrdv/Projects/pse-traffic-sim /Users/florrdv/Projects/pse-traffic-sim/build /Users/florrdv/Projects/pse-traffic-sim/build /Users/florrdv/Projects/pse-traffic-sim/build/CMakeFiles/TrafficSim.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TrafficSim.dir/depend

