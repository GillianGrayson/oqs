# Distributed under the MIT License (See accompanying file /LICENSE )

# CMake build : library

#configure variables
set (LIB_NAME "${PROJECT_NAME}Lib")

#configure directories
set (LIBRARY_MODULE_PATH "${PROJECT_SOURCE_DIR}/lib")
set (LIBRARY_SRC_PATH  "${LIBRARY_MODULE_PATH}/src" )
set (LIBRARY_INCLUDE_PATH  "${LIBRARY_MODULE_PATH}/include")
set (LIBRARY_TEST_PATH "${LIBRARY_MODULE_PATH}/test")

#set includes
include_directories (${LIBRARY_INCLUDE_PATH} ${SPDLOG_INCLUDE_PATH} ${EIGEN_INCLUDE_PATH} ${CATCH_INCLUDE_PATH})

# -------------------------------------------------------------------------
# lib
# -------------------------------------------------------------------------

#set sources
file (GLOB_RECURSE LIB_HEADER_FILES "${LIBRARY_INCLUDE_PATH}/*.h")
file (GLOB_RECURSE LIB_SOURCE_FILES "${LIBRARY_SRC_PATH}/*.cpp")

#set library
add_library (${LIB_NAME} STATIC ${LIB_SOURCE_FILES} ${LIB_HEADER_FILES})

#export vars
set (LIBRARY_INCLUDE_PATH  ${LIBRARY_INCLUDE_PATH} PARENT_SCOPE)
set (LIB_NAME ${LIB_NAME} PARENT_SCOPE)

# -------------------------------------------------------------------------
# test
# -------------------------------------------------------------------------

#configure variables
set (TEST_APP_NAME "${LIB_NAME}Test")

#set test sources
file (GLOB_RECURSE TEST_SOURCE_FILES "${LIBRARY_TEST_PATH}/*.cpp")

#set target executable
add_executable (${TEST_APP_NAME} ${TEST_SOURCE_FILES})

#add the library
target_link_libraries (${TEST_APP_NAME} ${LIB_NAME} Threads::Threads)

# Turn on CMake testing capabilities
enable_testing()

#parse catch tests
ParseAndAddCatchTests (${TEST_APP_NAME})
