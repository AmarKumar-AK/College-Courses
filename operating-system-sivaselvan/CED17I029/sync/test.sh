#!/bin/bash
# gcc dining.c -lpthread
gcc mutex.c -lpthread
# gcc peterson.c -lpthread
# gcc producerconsumer.c -lpthread
./a.out
rm a.out