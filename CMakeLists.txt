cmake_minimum_required( VERSION 3.16 )

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(sanitizer_playground)

get_property(isMultiConfig GLOBAL PROPERTY GENERATOR_IS_MULTI_CONFIG)

if(isMultiConfig)
    if(NOT "Asan" IN_LIST CMAKE_CONFIGURATION_TYPES)
        list(APPEND CMAKE_CONFIGURATION_TYPES Asan)
    endif()

    if(NOT "Tsan" IN_LIST CMAKE_CONFIGURATION_TYPES)
        list(APPEND CMAKE_CONFIGURATION_TYPES Tsan)
    endif()
else()
    set(allowedBuildTypes Asan Tsan Debug Release RelWithDebInfo MinSizeRel)
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "${allowedBuildTypes}")

    if(CMAKE_BUILD_TYPE AND NOT CMAKE_BUILD_TYPE IN_LIST allowedBuildTypes)
        message(FATAL_ERROR "Invalid build type: ${CMAKE_BUILD_TYPE}")
    endif()
endif()

set(CMAKE_C_FLAGS_ASAN
    "${CMAKE_C_FLAGS_DEBUG} -g -O0 -fsanitize=address -fno-omit-frame-pointer" CACHE STRING
    "Flags used by the C compiler for Asan build type or configuration." FORCE)

set(CMAKE_CXX_FLAGS_ASAN
    "${CMAKE_CXX_FLAGS_DEBUG} -g -O0 -fsanitize=address -fno-omit-frame-pointer" CACHE STRING
    "Flags used by the C++ compiler for Asan build type or configuration." FORCE)

set(CMAKE_EXE_LINKER_FLAGS_ASAN
    "${CMAKE_SHARED_LINKER_FLAGS_DEBUG} -fsanitize=address" CACHE STRING
    "Linker flags to be used to create executables for Asan build type." FORCE)

set(CMAKE_SHARED_LINKER_FLAGS_ASAN
    "${CMAKE_SHARED_LINKER_FLAGS_DEBUG} -fsanitize=address" CACHE STRING
    "Linker lags to be used to create shared libraries for Asan build type." FORCE)

set(CMAKE_C_FLAGS_TSAN
    "${CMAKE_C_FLAGS_DEBUG} -g -O0 -fsanitize=thread" CACHE STRING
    "Flags used by the C compiler for Tsan build type or configuration." FORCE)

set(CMAKE_CXX_FLAGS_TSAN
    "${CMAKE_C_FLAGS_DEBUG} -g -O -fsanitize=thread" CACHE STRING
    "Flags used by the C++ compiler for Tsan build type or configuration." FORCE)

set(CMAKE_EXE_LINKER_FLAGS_TSAN
    "${CMAKE_SHARED_LINKER_FLAGS_DEBUG} -fsanitize=thread" CACHE STRING
    "Linker flags to be used to create executables for Tsan build type." FORCE)

set(CMAKE_SHARED_LINKER_FLAGS_TSAN
    "${CMAKE_SHARED_LINKER_FLAGS_DEBUG} -fsanitize=thread" CACHE STRING
    "Linker lags to be used to create shared libraries for Tsan build type." FORCE)

add_subdirectory(tsan )
add_subdirectory(asan)