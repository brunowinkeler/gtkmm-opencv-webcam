# Set of Local Variables for location
set(TESTS_SRCS ${PROJECT_SOURCE_DIR}/tests)
set(PROJECT_SRCS ${PROJECT_SOURCE_DIR}/src)

# Include the directories that are the reference
include_directories(${PROJECT_SRCS}/acquisition/include)
include_directories(${PROJECT_SRCS}/image_processing/include)
include_directories(${TESTS_SRCS}/main/include)

# Collect sources and headers into the variables
file(GLOB MAIN_HEADERS 
        "${TESTS_SRCS}/main/include/*.h"
        "${TESTS_SRCS}/main/include/*.hpp"
        "${TESTS_SRCS}/main/include/*.hxx")
file(GLOB MAIN_SOURCES
        "${TESTS_SRCS}/main/src/*.c"
        "${TESTS_SRCS}/main/src/*.cpp"
        "${TESTS_SRCS}/main/src/*.cxx")

add_executable(${EXEC_NAME} ${MAIN_SOURCES} ${MAIN_HEADERS})

target_link_libraries(${EXEC_NAME} optimized acquisition)
target_link_libraries(${EXEC_NAME} debug     acquisition)
target_link_libraries(${EXEC_NAME} optimized image_processing)
target_link_libraries(${EXEC_NAME} debug     image_processing)

target_link_libraries(${EXEC_NAME} ${GTKMM_LIBRARIES})
target_link_libraries(${EXEC_NAME} ${OpenCV_LIBS})