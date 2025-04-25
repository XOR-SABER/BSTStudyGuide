add_executable(MyTests BSTTests.cc)

target_link_libraries(MyTests
    mylib
    gtest
    gtest_main
)

target_include_directories(MyTests PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

add_test(NAME MyTests COMMAND MyTests)
