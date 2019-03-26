# configure variables
set (TEST_APP_NAME "${LIB_NAME}_test")

# configure directories
set(TEST_PATH "${PROJECT_SOURCE_DIR}/test")

# set test sources
file(GLOB_RECURSE TEST_SOURCE_FILES "${TEST_PATH}/*.cpp")

# set target executable
add_executable (${TEST_APP_NAME} ${TEST_SOURCE_FILES})

# add the library and nessesary packages
target_link_libraries(${TEST_APP_NAME} ${LIB_NAME} Threads::Threads)

# filesystem support on gcc-8
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
	target_link_libraries(${TEST_APP_NAME} stdc++fs)
endif()

# Turn on CMake testing capabilities
enable_testing()

# Parse catch tests
ParseAndAddCatchTests(${TEST_APP_NAME})
