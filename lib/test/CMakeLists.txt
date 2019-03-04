# Distributed under the MIT License (See accompanying file /LICENSE )

# CMake build : library tests

#configure variables
set (TEST_APP_NAME "${LIB_NAME}Test")

#configure directories
set (TEST_MODULE_PATH "${LIBRARY_MODULE_PATH}/test")

#set includes
include_directories (${LIBRARY_INCLUDE_PATH} ${CATCH_INCLUDE_PATH})

#set test sources
file (GLOB_RECURSE TEST_SOURCE_FILES "${TEST_MODULE_PATH}/*.cpp")

#set target executable
add_executable (${TEST_APP_NAME} ${TEST_SOURCE_FILES} ${TEST_TRAJECTORIES_SOURCE_FILES})

#add the library
target_link_libraries (${TEST_APP_NAME} ${LIB_NAME} Threads::Threads)

# Turn on CMake testing capabilities
enable_testing()

#parse catch tests
ParseAndAddCatchTests (${TEST_APP_NAME})
