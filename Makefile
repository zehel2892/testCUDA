#Makefile for the CUDA + OpenGL project build

NVCC = nvcc
CC = g++
CCFLAGS = -c -Wall

all: main

main: main.o cuda.cu
	$(NVCC) main.o cuda.cu  -o a
main.o: main.cpp
	$(CC) $(CCFLAGS) main.cpp 
clean:
	rm *o a 
