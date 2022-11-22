cmake_minimum_required( VERSION 3.16 )

project (asan)

add_executable(asan_use_after_free asan_use_after_free.cpp)

add_executable(asan_global_out_of_bounds asan_global_out_of_bounds.cpp)

add_executable(asan_heap_out_of_bounds asan_heap_out_of_bounds.cpp)

add_executable(asan_init_order asan_init_order_a.cpp asan_init_order_b.cpp)

add_executable(asan_stack_out_of_bounds asan_stack_out_of_bounds.cpp)

add_executable(asan_use_after_return asan_use_after_return.cpp)

add_executable(asan_use_after_scope asan_use_after_scope.cpp)