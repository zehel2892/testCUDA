#Makefile for the CUDA + OpenGL project build

NVCC = nvcc
CC = g++
CCFLAGS = -c  
GLFW_FLAGS =  -lGLU -lGL -L/usr/local/lib  -lglfw3 -lrt -lXrandr -lXinerama -lXi -lXcursor -lGL -lm -ldl -lXrender -ldrm -lXdamage -lX11-xcb -lxcb-glx -lxcb-dri2 -lxcb-dri3 -lxcb-present -lxcb-sync -lxshmfence -lXxf86vm -lXfixes -lXext -lX11 -lpthread -lxcb -lXau -lXdmcp  

all: main

main: main.o quadraticInterpolation.o cuda.cu
	$(NVCC) quadraticInterpolation.o main.o  cuda.cu  -o a
main.o: main.cpp
	$(CC) $(CCFLAGS) main.cpp 
quadraticInterpolation.o: quadraticInterpolation.cpp
	$(CC) $(CCFLAGS) quadraticInterpolation.cpp
gl: glfw.cpp
	$(CC) $(CCFLAGS) glfw.cpp
	$(CC) -o gl  glfw.o $(GLFW_FLAGS)
gauss: gauss-elimination.cpp
	$(CC)  gauss-elimination.cpp -o inverseOfMatrix

clean:
	rm *o a a.out gl *~ 
