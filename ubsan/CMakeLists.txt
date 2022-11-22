cmake_minimum_required( VERSION 3.16 )

project (ubsan)

add_executable(ubsan_shift ubsan_shift.cpp)

add_executable(ubsan_overflow ubsan_overflow.cpp)

add_executable(ubsan_null ubsan_null.cpp)

add_executable(ubsan_bounds ubsan_bounds.cpp)