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

# Turn on CMake testing capabilities
enable_testing()

# Parse catch tests
ParseAndAddCatchTests(${TEST_APP_NAME})

# code coverage
option (CODE_COVERAGE "Enable coverage reporting." OFF)
if (CODE_COVERAGE AND CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
	# Add required flags (GCC & LLVM/Clang)
	target_compile_options(${LIB_NAME} INTERFACE
		-O0        # no optimization
		-g         # generate debug info
		--coverage # sets all required flags
	)
	target_link_libraries(${LIB_NAME} INTERFACE --coverage)
endif()

