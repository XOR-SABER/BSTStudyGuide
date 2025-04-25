cmake_minimum_required(VERSION 3.16)
project(myProject)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)

# GoogleTest
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.16.0
)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Add subdirectories
add_subdirectory(src)
add_subdirectory(test)

add_custom_target(clean-all
    COMMAND ${CMAKE_COMMAND} --build . --target clean
    COMMAND ${CMAKE_COMMAND} ..
    COMMAND ${CMAKE_COMMAND} --build .
    COMMAND ctest
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

add_custom_target(run
    COMMAND myProject
    DEPENDS myProject
    WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
    COMMENT "Running the main application..."
)


add_custom_target(test-run
    COMMAND ctest --output-on-failure
    DEPENDS MyTests
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running all tests..."
)
