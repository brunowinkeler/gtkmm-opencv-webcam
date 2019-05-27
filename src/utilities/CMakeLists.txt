# Set of Local Variables for location
set(MODULE_NAME utilities)
set(MODULE_NAME_SRCS ${PROJECT_SOURCE_DIR}/src/${MODULE_NAME})

# Include the directories that are the reference
include_directories(${MODULE_NAME_SRCS}/include)

# Collect sources and headers into the variables
file(GLOB MODULE_HEADERS 
        "${MODULE_NAME_SRCS}/include/${MODULE_NAME}/*.h"
        "${MODULE_NAME_SRCS}/include/${MODULE_NAME}/*.hpp"
        "${MODULE_NAME_SRCS}/include/${MODULE_NAME}/*.hxx")
file(GLOB MODULE_SOURCES
        "${MODULE_NAME_SRCS}/src/*.c"
        "${MODULE_NAME_SRCS}/src/*.cpp"
        "${MODULE_NAME_SRCS}/src/*.cxx")

# Creates shared libraries with the listed sources collected in the variables
add_library(${MODULE_NAME} SHARED ${MODULE_SOURCES} ${MODULE_HEADERS})

# Creates a folder "pca_probe_acquisition" and adds target project (probe_acquisition.vcproj) under it
set_property(TARGET ${MODULE_NAME} PROPERTY FOLDER "${MODULE_NAME}")

# Link the libraries
# This is CUSTOM
#target_link_libraries(${MODULE_NAME} ${GTKMM_LIBRARIES})
#target_link_libraries(${MODULE_NAME} ${OpenCV_LIBS})

# Define installation folders
install(TARGETS ${MODULE_NAME}
        RUNTIME DESTINATION ${PROJECT_BINARIES}
        LIBRARY DESTINATION ${PROJECT_BINARIES}
        ARCHIVE DESTINATION ${PROJECT_LIBS})

install(DIRECTORY ${MODULE_NAME_SRCS}/include/ 
        DESTINATION ${PROJECT_INCLUDES})