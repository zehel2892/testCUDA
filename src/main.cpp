#include<iostream>
#include<cmath>
#include<stdio.h>
#include<fstream>
#include<cstdlib> // for exit(EXIT_FAILURE)
#include<vector>
#include"mesh.h"

#define BUFFER_SIZE 512
///////////////////////////////////////////////////////////////////////////////
// Forward declarations
extern "C" void RunTest();// interface for cuda.cu

extern void FindQuadraticInterpolationUnknowns(const std::vector<Point *>& p_upper,
						const std::vector<Point *>& p_lower,
						std::vector<Point *> & unknown,
						int _num_of_lines);
// Split the aerofoil into two parts
void SplitAerofoil(const std::vector<Point *>  & _p,std::vector<Point *>  &_p_upper,std::vector<Point *> & _p_lower, int _num_of_lines);
int CalculateUpperPart(const std::vector<Point *> & _p, int _num_of_lines);
int CalculateLowerPart(const std::vector<Point *> & _p, int _num_of_lines);
///////////////////////////////////////////////////////////////////////////////
int main( int argc , char ** argv)
{
	std::cout<<"CUDA OpenGL CFD node creation demo"<<std::endl;

	std::cout<<"Importing aerofoil co-ordinates"<<std::endl;
	

	// Create input file stream
	std::ifstream file;

	// Open a text file for reading
	file.open("../res/naca2412.dat");
	
	// Check for Open failure
	if(!file.is_open())
	{
		exit(EXIT_FAILURE);
	}
	
	
	static int num_of_lines = 0;

	std::string line;
	while(std::getline(file,line))
			{ num_of_lines++;}

	std::cout<<"num_of_lines = "<<num_of_lines<<std::endl;

	file.close();
	file.clear();
	file.open("../res/naca2412.dat");

	if(!file.is_open())
	{
		exit(EXIT_FAILURE);
	}

	// Create space for objects of class Point
	std::vector<Point *> p;	
	//Point * p[num_of_lines];
	//std::cout<<"XXXXXXXXX  "<<sizeof(p)/sizeof(p[0])<<std::endl;
	

	// Create space for the co-ordinates
	char _x[20];
	char _y[20];
	
	int counter = 0;
	
	while(!file.eof())
	{
	
	float l_x = atof(_x);
	float l_y = atof(_y);

	file >> l_x;
	file >> l_y;
	
	std::cout<<l_x<<"    |    "<<l_y<<std::endl;

	p.push_back(new Point(l_x,l_y));
	//p[counter] = new Point(l_x,l_y);
//	p[counter]->GetValues();

//	std::cout<<"------"<<counter<<std::endl;
	counter++ ;


//	std::cout<<"------"<<counter<<std::endl;
	
//	std::cout<<"Counter "<<counter<<"  :   "<<l_x<<" "<<l_y<<std::endl;

	}
	
	std::cout<<"Total Count = "<<counter<<std::endl;
	// make sure to check upto p.size()-1 not p.size() as it will cause segmentation fault
	for(unsigned  i = 0; i<=p.size()-1 ;i++)

	{
		p[i]->GetValues();
	}




	file.close();
//	RunTest(); // CUDA interface
	//Point * p_upper[CalculateUpperPart(p,num_of_lines)];
	//Point * p_lower[CalculateLowerPart(p,num_of_lines)];
	static 	std::vector<Point *> p_upper;
	static std::vector<Point *> p_lower;

	std::vector<Point *> unknown; // store the unknown coefficients a,b,c of Quadratic interpolation

	
	//SplitAerofoil(*p,*p_upper,*p_lower);
	SplitAerofoil(p,p_upper,p_lower,num_of_lines);
	std::cout<<p_upper[10]->GetX()<<std::endl;
	FindQuadraticInterpolationUnknowns(p_upper,p_lower,unknown,num_of_lines);

return 0;


}

void  SplitAerofoil(const std::vector<Point *> &  _p,std::vector<Point *> & _p_upper,std::vector<Point *> & _p_lower,int _num_of_lines)
{
	unsigned int originXPos =(unsigned int) CalculateUpperPart(_p, _num_of_lines);	
	// Copy all the data upto originXPos into _p_upper[] array
	for(unsigned int i=0; i<=originXPos; i++)
	{
	//	_p_upper[i] = _p[i];
		_p_upper.push_back(_p[i]);	
	}
	

	for(unsigned int i=originXPos-1; i<=_p.size();i++)
	{
	//	_p_lower[i] = _p[i];
		_p_lower.push_back(_p[i]);	
	}

	std::cout<<"Printing Upperpart "<<std::endl;
	for(unsigned int i=0; i<=_p_upper.size()-2;i++)
	{
		_p_upper[i]->GetValues();
	}
	std::cout<<"Printing Lower Part"<<std::endl;
	for(unsigned int i=0; i<=_p_lower.size()-2;i++)
	{
		_p_lower[i]->GetValues();
	}	
}

int CalculateUpperPart(const std::vector<Point *> & _p,int _num_of_lines)
{
	// Number of 0.00 x co-ordinates are found
	int originXPos;
	int n = _num_of_lines;	
	originXPos =(((n-1)/2)+1);
	int numUpperPart =(int) originXPos;

	std::cout<<"originXPos = "<<originXPos<<std::endl;
	std::cout<<"Upper Part = "<<numUpperPart<<std::endl;

return numUpperPart;

}
int CalculateLowerPart(const std::vector<Point *> & _p,int _num_of_lines)
{
	// Number of 0.00 x co-ordinates are found
	int originXCount=0;
	int originXPos;
	int n = _num_of_lines;	
	originXPos =(((n-1)/2)+1);

	int numLowerPart = n - originXPos;
	std::cout<<"Lower Part = "<<numLowerPart<<std::endl;

return numLowerPart;
}
