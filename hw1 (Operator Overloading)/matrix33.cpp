#include "matrix33.h"
#include <iostream>
using namespace std;

matrix33::matrix33(){
	
	
};

matrix33::matrix33(vector3 inV_1, vector3 inV_2, vector3 inV_3){
	
	v_1=inV_1;
	v_2=inV_2;
	v_3=inV_3;
	
}


matrix33::matrix33(const matrix33 &m){
	
	v_1=m.v_1;
	v_2=m.v_2;
	v_3=m.v_3;
	
}

vector3 &matrix33::operator [] (unsigned int index){
	
	if(index==0){
		return v_1;
	}
	else if(index==1){
		return v_2;
	}
	else if(index==2){
		return v_3;
	}

}

const vector3 &matrix33::operator [] (unsigned int index) const{
	
	if(index==0){
		return v_1;
	}
	else if(index==1){
		return v_2;
	}
	else if(index==2){
		return v_3;
	}

}

matrix33 &matrix33::operator *= (float f){
	
	v_1*=f;
	v_2*=f;
	v_3*=f;
	
	return *this;
}

matrix33 &matrix33::operator = (const matrix33 &m){
	
	v_1=m.v_1;
	v_2=m.v_2;
	v_3=m.v_3;
	
	return *this;
}




bool operator == (const matrix33 &a, const matrix33 &b){
	
	return (a.v_1==b.v_1 && a.v_2==b.v_2 && a.v_3==b.v_3);
}

bool operator != (const matrix33 &a, const matrix33 &b){
	
	return (a.v_1!=b.v_1 || a.v_2!=b.v_2 || a.v_3!=b.v_3);
}


matrix33 operator * (const matrix33 &m, float f){
	
	matrix33 result(m.v_1*f, m.v_2*f, m.v_3*f);
	
	return result;
}

matrix33 operator * (const matrix33 &m, const matrix33 &n){
	
	float a=(m.v_1.x*n.v_1.x)+(m.v_2.x*n.v_1.y)+(m.v_3.x*n.v_1.z);
	float b=(m.v_1.y*n.v_1.x)+(m.v_2.y*n.v_1.y)+(m.v_3.y*n.v_1.z);
	float c=(m.v_1.z*n.v_1.x)+(m.v_2.z*n.v_1.y)+(m.v_3.z*n.v_1.z);
	float d=(m.v_1.x*n.v_2.x)+(m.v_2.x*n.v_2.y)+(m.v_3.x*n.v_2.z);
	float e=(m.v_1.y*n.v_2.x)+(m.v_2.y*n.v_2.y)+(m.v_3.y*n.v_2.z);
	float f=(m.v_1.z*n.v_2.x)+(m.v_2.z*n.v_2.y)+(m.v_3.z*n.v_2.z);
	float g=(m.v_1.x*n.v_3.x)+(m.v_2.x*n.v_3.y)+(m.v_3.x*n.v_3.z);
	float h=(m.v_1.y*n.v_3.x)+(m.v_2.y*n.v_3.y)+(m.v_3.y*n.v_3.z);
	float i=(m.v_1.z*n.v_3.x)+(m.v_2.z*n.v_3.y)+(m.v_3.z*n.v_3.z);
	
	vector3 v_1(a, b, c),v_2(d, e, f),v_3(g, h, i);
	matrix33 result(v_1, v_2, v_3);
	
	return result;
}



matrix33 operator + (const matrix33 &m, const matrix33 &n){
	
	matrix33 result(m.v_1+n.v_1, m.v_2+n.v_2, m.v_3+n.v_3);
	
	return result;
}

void matrix33::printMatrix() const{
	
	cout<<v_1.x<<" "<<v_2.x<<" "<<v_3.x<<endl;
	cout<<v_1.y<<" "<<v_2.y<<" "<<v_3.y<<endl;
	cout<<v_1.z<<" "<<v_2.z<<" "<<v_3.z<<endl;
	
	
}

matrix33 matrix33::invert(){
	
	float n=1/(this->determinant());
	
	float a= n    * (v_2.y*v_3.z-v_2.z*v_3.y);
	float b= (-n) * (v_1.y*v_3.z-v_1.z*v_3.y);
	float c= n    * (v_1.y*v_2.z-v_1.z*v_2.y);
	float d= (-n) * (v_2.x*v_3.z-v_2.z*v_3.x);
	float e= n    * (v_1.x*v_3.z-v_1.z*v_3.x);
	float f= (-n) * (v_1.x*v_2.z-v_1.z*v_2.x);
	float g= n    * (v_2.x*v_3.y-v_2.y*v_3.x);
	float h= (-n) * (v_1.x*v_3.y-v_1.y*v_3.x);
	float i= n    * (v_1.x*v_2.y-v_1.y*v_2.x);
	
	vector3 v_1(a, b, c),v_2(d, e, f),v_3(g, h, i);
	matrix33 result(v_1, v_2, v_3);
	
	return result;
}

void matrix33::identity(){
	
	v_1.x=1;
	v_1.y=0;
	v_1.z=0;
	v_2.x=0;
	v_2.y=1;
	v_2.z=0;
	v_3.x=0;
	v_3.y=0;
	v_3.z=1;
	
}

float matrix33::determinant(){
	
	float det= (v_1.x*v_2.y*v_3.z) + (v_2.x*v_3.y*v_1.z) + (v_3.x*v_1.y*v_2.z) - (v_1.z*v_2.y*v_3.x) - (v_2.z*v_3.y*v_1.x) - (v_3.z*v_1.y*v_2.x);
	
	return det;
}


























