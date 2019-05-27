cmake_minimum_required(VERSION 3.5)

set(PROJ_NAME gtkmm-opencv-webcam)
set(EXEC_NAME WebCamPlayer)

project(${PROJ_NAME})
set(CMAKE_INSTALL_PREFIX "${PROJECT_SOURCE_DIR}/install" CACHE PATH "Default Install Path" FORCE)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build, options are: None Debug Release RelWithDebInfoMinSizeRel." FORCE)
endif()

# Add to path folder containing Find<package>.cmake files
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-3.0)
include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

# Define the folder of Includes, libraries and Runtime Files. (.h, .hpp, .ilk, .exe, .dll, .lib, .exp etc.)
set(PROJECT_INCLUDES "${CMAKE_INSTALL_PREFIX}/include")
set(PROJECT_LIBS     "${CMAKE_INSTALL_PREFIX}/lib")
set(PROJECT_BINARIES "${CMAKE_INSTALL_PREFIX}/bin")

# Create preprocessor definitions containing path information
set(PATH_RESOURCES "\"${PROJECT_SOURCE_DIR}/resources/\"")

# Add preprocessor definitions
add_definitions(-DPATH_RESOURCES=${PATH_RESOURCES})

# If on Windows, make sure all symbols are exported to create a shared lib
if(WIN32)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS 1)
endif()

# Check if compiler is MSVC or GNU
if(${CMAKE_CXX_COMPILER_ID} STREQUAL "MSVC")
    message(STATUS "Setting MSVC flags")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHc /MP")
elseif(${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU")
    message(STATUS "Setting GNU flags")
    set (CMAKE_CXX_STANDARD 11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
endif()

# Adds the respective subdirectories of the project
add_subdirectory(src/acquisition)
add_subdirectory(src/utilities)
add_subdirectory(tests/main)