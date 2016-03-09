#Makefile for the CUDA + OpenGL project build

NVCC = nvcc
CC = g++
CCFLAGS = -c 
OPENGL_FLAGS = -lGL -lGLU -lGLEW -lglut

all: main

main: main.o cuda.cu
	$(NVCC) main.o cuda.cu  -o a
main.o: main.cpp
	$(CC) $(CCFLAGS) main.cpp 
gl: display.cpp
	$(CC) -o gl  display.cpp $(OPENGL_FLAGS)
clean:
	rm *o a a.out gl 
