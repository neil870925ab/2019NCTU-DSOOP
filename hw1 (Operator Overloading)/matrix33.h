#ifndef _MATRIX33_H_
#define _MATRIX33_H_
#include "vector3.h"

class matrix33 
{  
public:
	
	/* data members */
	
	vector3 v_1, v_2, v_3;
	
	/* constructors */
	
	matrix33();
	
	matrix33(vector3 inV_1, vector3 inV_2, vector3 inV_3);
	
	matrix33(const matrix33 &m);

	/* Operators */
	
	vector3                 &operator [] (unsigned int index);
	const vector3           &operator [] (unsigned int index) const;
	matrix33                &operator *= (float f);	
	matrix33             	&operator =  (const matrix33 &m);
	
	
	friend bool           	operator == (const matrix33 &a, const matrix33 &b);
	friend bool           	operator != (const matrix33 &a, const matrix33 &b);
	friend matrix33        	operator * (const matrix33 &m, float f);
	friend matrix33 		operator * (const matrix33 &m, const matrix33 &n);
	friend matrix33 		operator + (const matrix33 &m, const matrix33 &n);

	/* Methods */
	
	void printMatrix() const;

	matrix33 invert();

	void identity();

	float determinant();






};

#endif
