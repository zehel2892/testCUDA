#include<iostream>
#include<vector>
#include<cmath>
#include"mesh.h"


void Solve(const std::vector<Point *>  p_upper,std::vector<float> & unknown_i,int _num); // _unknown_i will be  local

void FindQuadraticInterpolationUnknowns(const std::vector<Point *> & p_upper,
					const std::vector<Point *> & p_lower,
					std::vector<Point *> & unknown,
					int _num_of_lines)
{
	std::cout<<"p_upper[5]->GetY() = "<<p_upper[5]->GetY()<<std::endl;
	
	std::cout<<"Executing FindQuadraticInterpolationUnknowns()"<<std::endl;
	std::vector< float > unknown_upper(_num_of_lines);
	Solve(p_upper,unknown_upper,p_upper.size()-1); 
	
}

void Solve(const std::vector<Point *>  p_upper,std::vector<float> & unknown_i,int _num)
{	
	std::cout<<"Executing Solve() from FindQuadraticInterpolationUnknowns()"<<std::endl;
	// Create a NxN+1 matrix and initialize it to zero
	std::vector< std::vector<float> > mat(3*_num, std::vector<float> (3*(_num)+1,0));
	
	std::vector<float> tempVec((3*_num)+2,0);
	std::cout<<tempVec.size()<<std::endl;
	std::cout<<_num<<std::endl;
	
	for(int i=1;i<=2*_num;i++)
	{	
		std::cout<< " i = "<<i<<std::endl;
		/*
		tempVec.push_back(pow(_vec[i]->GetX,2));
		tempVec.push_back(_vec[i]->GetX);
		tempVec.push_back(1);
		tempVec.push_back(_vec[i]->GetY);
		*/
	///	tempVec.at(i*1)=(float)pow(_vec[i]->GetX(),2);
	//	tempVec.at(i*2)=_vec[i]->GetX();
		//tempVec.at(i*3)=1;
		float a = p_upper[1]->GetY();
		//tempVec.at((3*_num)+1)=_vec[i]->GetY();

	}
	
	
	
		/*for(int i=0;i<_num;i++)
	{
		for(int j=0;j<=_num+1;j++)
		{

			std::cout<<mat[i][j];
		}
	}
	*/
}
