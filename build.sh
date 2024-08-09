#!/bin/bash

rm ./ok

gcc main.c -o ok -L. -llist2 -Wl,-rpath,.
