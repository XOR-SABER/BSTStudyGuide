add_executable(MyTests mainTest.cc)

target_link_libraries(MyTests PRIVATE gtest_main)

add_test(NAME MyTests COMMAND MyTests)