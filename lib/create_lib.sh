#!/bin/bash

FN="liblist2";

gcc -shared -o "${FN}.so" -fPIC "${FN}.c"

cp "${FN}.so" ./..
cp "${FN}.h" ./..

