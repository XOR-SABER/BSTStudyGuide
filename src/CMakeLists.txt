# Header-only library using INTERFACE
add_library(mylib INTERFACE)
target_include_directories(mylib INTERFACE
    ${PROJECT_SOURCE_DIR}/include
)

# Your app with main.cc
add_executable(MyProject main.cc)
target_link_libraries(MyProject mylib)
