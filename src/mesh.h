#ifndef MESH_H
#define MESH_H

#ifdef __CUDACC__
#define CUDA_CALLABLE __host__ __device__
#else
#define CUDA_CALLABLE 
#endif

class Point
{
private:
	float m_x;
	float m_y;
public:
	// Default constructor
	 CUDA_CALLABLE Point()
	{
		this->m_x=0;this->m_y=0;
	}
	// Overridden constructor
	CUDA_CALLABLE Point(float _x , float _y)
	{
		this->m_x = _x;
		this->m_y = _y;
	}
	
	CUDA_CALLABLE ~Point(){}

	void GetValues(void){std::cout<<"------------\n"<<"X : "<<m_x<<"\n"
						<<"Y : "<<m_y<<std::endl;} 
	float GetX(void)
	{
		return this->m_x;
	}

	float GetY(void)
	{
		return this->m_y;
	}

}; // end class Point

#endif
