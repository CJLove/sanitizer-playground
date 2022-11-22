# sanitizer-playground
Example code demonstrating categories of errors detected by gcc/clang sanitizers

## Building with CMake
```bash
$ mkdir build_asan; cd build_asan
$ cmake -DCMAKE_BUILD_TYPE=Asan ..
$ make

$ mkdir build_tsan; cd build_tsan
$ cmake -DCMAKE_BULID_TYPE=Tsan ..
$ make
```

## Address Sanitizer

## Leak Sanitizer

## Thread Sanitizer

## Memory Sanitizer (Clang only)

## References:
Code examples taken from:
- https://github.com/google/sanitizers/wiki/AddressSanitizer
- https://github.com/google/sanitizers/wiki/AddressSanitizerLeakSanitizer
- https://github.com/google/sanitizers/wiki/ThreadSanitizerCppManual
- https://github.com/google/sanitizers/wiki/MemorySanitizer

CMake support for sanitizer builds:
- http://www.stablecoder.ca/2018/02/01/analyzer-build-types.html
