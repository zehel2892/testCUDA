#include<iostream>
#include<vector>
#include"mesh.h"

void Solve(const std::vector<Point *> & _vec,std::vector<float> & _unknown_i,int _num); // _unknown_i will be  local

void FindQuadraticInterpolationUnknowns(const std::vector<Point *> & _p_upper,
					const std::vector<Point *> & _p_lower,
					std::vector<Point *> & _unknown,
					int _num_of_lines)
{
	std::cout<<"Executing FindQuadraticInterpolationUnknowns()"<<std::endl;
	std::vector< float > _unknown_upper(_num_of_lines);
	Solve(_p_upper, _unknown_upper,_num_of_lines);
	
}

void Solve(const std::vector<Point *> & _vec,std::vector<float> & _unknown_i,int _num)
{	
	std::cout<<"Executing Solve() from FindQuadraticInterpolationUnknowns()"<<std::endl;
	// Create a NxN+1 matrix and initialize it to zero
	std::vector< std::vector<float> > mat(_num, std::vector<float> (_num+1,0));
	
	std::vector<float> testVec;
	testVec.push_back(5);
	mat[0][0]=testVec[0];
	std::cout<<mat[0][0]<<std::endl;

//	for(int i=0;i<=_num;i++)
//	{
//		for(int j=0;j<=_num+1;j++)
//		{
//
//			std::cout<<mat[i][j];
//		}
//	}
}
