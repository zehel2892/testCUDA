#include<stdio.h>
#include<iostream>




__global__ void kernel()
{
	printf("Kernel Launched");
}

extern "C" void RunTest()
{
	kernel<<<1,1>>>();
	printf("cuda.cu launched \n");
	std::cout<<"cuda.cu launched"<<std::endl;
}
