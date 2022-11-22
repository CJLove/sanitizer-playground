cmake_minimum_required( VERSION 3.16 )

project (lsan)

add_executable(lsan_malloc_leak lsan_malloc_leak.cpp)

add_executable(lsan_new_leak lsan_new_leak.cpp)