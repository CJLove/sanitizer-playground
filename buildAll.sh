#!/bin/bash

builds="Asan Tsan Lsan UBsan"

# If building using Clang, include Memory sanitizer examples
[ $CXX == "clang++" ] && builds="$builds Msan"

for b in $builds
do
    echo "$Building examples for $b sanitizer"
    rm -rf build_${b}
    mkdir -p build_${b}
    cd build_${b}
    CC=${CC} CXX=${CXX} cmake -DCMAKE_BUILD_TYPE=${b} ..
    make
    cd ..
done