#include<iostream>
#include<cmath>
#include<stdio.h>
#include<fstream>
#include<cstdlib> // for exit(EXIT_FAILURE)

#define BUFFER_SIZE 512
// Forward declaration
extern "C" void RunTest();
class Point
{
private:
	float m_x;
	float m_y;
public:
	Point()
	{
		this->m_x=0;this->m_y=0;
	}

	Point(float _x , float _y)
	{
		this->m_x = _x;
		this->m_y = _y;
	}
	
	~Point(){}

	void GetValues(void){std::cout<<"------------\n"<<"X : "<<m_x<<"\n"<<"Y : "<<m_y<<std::endl;} 
}; // end class Point

int main( int argc , char ** argv)
{
	std::cout<<"CUDA OpenGL CFD node creation demo"<<std::endl;

	std::cout<<"Importing aerofoil co-ordinates"<<std::endl;
	

	// Create input file stream
	std::ifstream file;

	// Open a text file for reading
	file.open("./res/NACA2412.dat");
	
	// Check for Open failure
	if(!file.is_open())
	{
		exit(EXIT_FAILURE);
	}
	
	
	int num_of_lines = 0;

	std::string line;
	while(std::getline(file,line))
			{ num_of_lines++;}

	std::cout<<"num_of_lines = "<<num_of_lines<<std::endl;

	file.close();
	file.clear();
	file.open("./res/NACA2412.dat");

	if(!file.is_open())
	{
		exit(EXIT_FAILURE);
	}

	// Create space for objects of class Point
	
	Point * p[num_of_lines];
	

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

	
	p[counter] = new Point(l_x,l_y);
//	p[counter]->GetValues();

//	std::cout<<"------"<<counter<<std::endl;
	counter++ ;


//	std::cout<<"------"<<counter<<std::endl;
	
//	std::cout<<"Counter "<<counter<<"  :   "<<l_x<<" "<<l_y<<std::endl;

	}
	
	std::cout<<"Total Count = "<<counter<<std::endl;
	
	for(unsigned  i = 0; i<=sizeof(p)/sizeof(p[0]) ;i++)
	{
		p[i]->GetValues();
	}




	file.close();
	RunTest();


return 0;

	
}
