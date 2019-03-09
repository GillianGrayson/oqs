# Distributed under the MIT License (See accompanying file /LICENSE )

# CMake build : global project

cmake_minimum_required(VERSION 3.3)

project(oqs)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

add_subdirectory(third_party EXCLUDE_FROM_ALL)

#configure variables
set(LIB_NAME "${PROJECT_NAME}")

#configure directories
set(LIB_INCLUDE_PATH "${PROJECT_SOURCE_DIR}/include")
set(LIB_TEST_PATH "${PROJECT_SOURCE_DIR}/test")

#set includes
include_directories (${LIB_INCLUDE_PATH} ${SPDLOG_INCLUDE_PATH} ${EIGEN_INCLUDE_PATH} ${CATCH_INCLUDE_PATH})

#set sources
file (GLOB_RECURSE LIB_HEADER_FILES "${LIBRARY_INCLUDE_PATH}/*.h")

#set library
add_library (${LIB_NAME} INTERFACE)

target_include_directories(
    ${LIB_NAME}
    INTERFACE
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>"
    "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
)

#add_custom_target(${LIB_NAME}_IDE SOURCES ${LIB_HEADER_FILES})

enable_testing()

add_subdirectory(test)

add_subdirectory(app)
