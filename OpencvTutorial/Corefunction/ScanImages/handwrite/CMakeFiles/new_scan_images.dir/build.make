# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.0

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/spider/mycode/github/atom_it/OpencvTutorial/Corefunction/ScanImages/ssss

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/spider/mycode/github/atom_it/OpencvTutorial/Corefunction/ScanImages/ssss

# Include any dependencies generated for this target.
include CMakeFiles/new_scan_images.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/new_scan_images.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/new_scan_images.dir/flags.make

CMakeFiles/new_scan_images.dir/new_scan_images.cpp.o: CMakeFiles/new_scan_images.dir/flags.make
CMakeFiles/new_scan_images.dir/new_scan_images.cpp.o: new_scan_images.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/spider/mycode/github/atom_it/OpencvTutorial/Corefunction/ScanImages/ssss/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/new_scan_images.dir/new_scan_images.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/new_scan_images.dir/new_scan_images.cpp.o -c /home/spider/mycode/github/atom_it/OpencvTutorial/Corefunction/ScanImages/ssss/new_scan_images.cpp

CMakeFiles/new_scan_images.dir/new_scan_images.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/new_scan_images.dir/new_scan_images.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/spider/mycode/github/atom_it/OpencvTutorial/Corefunction/ScanImages/ssss/new_scan_images.cpp > CMakeFiles/new_scan_images.dir/new_scan_images.cpp.i

CMakeFiles/new_scan_images.dir/new_scan_images.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/new_scan_images.dir/new_scan_images.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/spider/mycode/github/atom_it/OpencvTutorial/Corefunction/ScanImages/ssss/new_scan_images.cpp -o CMakeFiles/new_scan_images.dir/new_scan_images.cpp.s

CMakeFiles/new_scan_images.dir/new_scan_images.cpp.o.requires:
.PHONY : CMakeFiles/new_scan_images.dir/new_scan_images.cpp.o.requires

CMakeFiles/new_scan_images.dir/new_scan_images.cpp.o.provides: CMakeFiles/new_scan_images.dir/new_scan_images.cpp.o.requires
	$(MAKE) -f CMakeFiles/new_scan_images.dir/build.make CMakeFiles/new_scan_images.dir/new_scan_images.cpp.o.provides.build
.PHONY : CMakeFiles/new_scan_images.dir/new_scan_images.cpp.o.provides

CMakeFiles/new_scan_images.dir/new_scan_images.cpp.o.provides.build: CMakeFiles/new_scan_images.dir/new_scan_images.cpp.o

# Object files for target new_scan_images
new_scan_images_OBJECTS = \
"CMakeFiles/new_scan_images.dir/new_scan_images.cpp.o"

# External object files for target new_scan_images
new_scan_images_EXTERNAL_OBJECTS =

new_scan_images: CMakeFiles/new_scan_images.dir/new_scan_images.cpp.o
new_scan_images: CMakeFiles/new_scan_images.dir/build.make
new_scan_images: /usr/local/lib/libopencv_calib3d.so.3.3.0
new_scan_images: /usr/local/lib/libopencv_core.so.3.3.0
new_scan_images: /usr/local/lib/libopencv_dnn.so.3.3.0
new_scan_images: /usr/local/lib/libopencv_features2d.so.3.3.0
new_scan_images: /usr/local/lib/libopencv_flann.so.3.3.0
new_scan_images: /usr/local/lib/libopencv_highgui.so.3.3.0
new_scan_images: /usr/local/lib/libopencv_imgcodecs.so.3.3.0
new_scan_images: /usr/local/lib/libopencv_imgproc.so.3.3.0
new_scan_images: /usr/local/lib/libopencv_ml.so.3.3.0
new_scan_images: /usr/local/lib/libopencv_objdetect.so.3.3.0
new_scan_images: /usr/local/lib/libopencv_photo.so.3.3.0
new_scan_images: /usr/local/lib/libopencv_shape.so.3.3.0
new_scan_images: /usr/local/lib/libopencv_stitching.so.3.3.0
new_scan_images: /usr/local/lib/libopencv_superres.so.3.3.0
new_scan_images: /usr/local/lib/libopencv_video.so.3.3.0
new_scan_images: /usr/local/lib/libopencv_videoio.so.3.3.0
new_scan_images: /usr/local/lib/libopencv_videostab.so.3.3.0
new_scan_images: /usr/local/lib/libopencv_calib3d.so.3.3.0
new_scan_images: /usr/local/lib/libopencv_features2d.so.3.3.0
new_scan_images: /usr/local/lib/libopencv_flann.so.3.3.0
new_scan_images: /usr/local/lib/libopencv_highgui.so.3.3.0
new_scan_images: /usr/local/lib/libopencv_photo.so.3.3.0
new_scan_images: /usr/local/lib/libopencv_video.so.3.3.0
new_scan_images: /usr/local/lib/libopencv_videoio.so.3.3.0
new_scan_images: /usr/local/lib/libopencv_imgcodecs.so.3.3.0
new_scan_images: /usr/local/lib/libopencv_imgproc.so.3.3.0
new_scan_images: /usr/local/lib/libopencv_core.so.3.3.0
new_scan_images: CMakeFiles/new_scan_images.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable new_scan_images"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/new_scan_images.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/new_scan_images.dir/build: new_scan_images
.PHONY : CMakeFiles/new_scan_images.dir/build

CMakeFiles/new_scan_images.dir/requires: CMakeFiles/new_scan_images.dir/new_scan_images.cpp.o.requires
.PHONY : CMakeFiles/new_scan_images.dir/requires

CMakeFiles/new_scan_images.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/new_scan_images.dir/cmake_clean.cmake
.PHONY : CMakeFiles/new_scan_images.dir/clean

CMakeFiles/new_scan_images.dir/depend:
	cd /home/spider/mycode/github/atom_it/OpencvTutorial/Corefunction/ScanImages/ssss && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/spider/mycode/github/atom_it/OpencvTutorial/Corefunction/ScanImages/ssss /home/spider/mycode/github/atom_it/OpencvTutorial/Corefunction/ScanImages/ssss /home/spider/mycode/github/atom_it/OpencvTutorial/Corefunction/ScanImages/ssss /home/spider/mycode/github/atom_it/OpencvTutorial/Corefunction/ScanImages/ssss /home/spider/mycode/github/atom_it/OpencvTutorial/Corefunction/ScanImages/ssss/CMakeFiles/new_scan_images.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/new_scan_images.dir/depend
