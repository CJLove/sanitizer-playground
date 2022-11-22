# sanitizer-playground
Example code demonstrating categories of errors detected by gcc/clang sanitizers

## Building with CMake
```bash
$ ./buildAll.sh

# Override compilers
$ CC=/path/to/clang CXX=/path/to/clang++ ./buildAll.sh
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
- https://developers.redhat.com/blog/2014/10/16/gcc-undefined-behavior-sanitizer-ubsan


CMake support for sanitizer builds:
- http://www.stablecoder.ca/2018/02/01/analyzer-build-types.html
