# configure variables
set(EXAMPLE_APP_NAME "${PROJECT_NAME}_example")

# configure directories
set(EXAMPLE_PATH "${PROJECT_SOURCE_DIR}/example")

# set sources
file(GLOB APP_SOURCE_FILES "${EXAMPLE_PATH}/*.cpp")

# set target executable
add_executable(${EXAMPLE_APP_NAME} ${APP_SOURCE_FILES})

# add the library and nessesary packages
target_link_libraries(${EXAMPLE_APP_NAME} ${LIB_NAME} Threads::Threads)

# filesystem support on gcc-8
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
	target_link_libraries(${EXAMPLE_APP_NAME} stdc++fs)
endif()