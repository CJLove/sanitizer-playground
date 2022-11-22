cmake_minimum_required( VERSION 3.16 )

project (tsan)

add_executable(tsan_datarace tsan_datarace.cpp)

# Deadlock detection 
#add_executable(tsan_deadlock tsan_deadlock.cpp)
