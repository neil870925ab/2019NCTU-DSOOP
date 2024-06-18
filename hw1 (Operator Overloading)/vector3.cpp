#include "vector3.h"
#include "math.h"
#include <iostream>
using namespace std;

vector3::vector3(){
	
	
};

vector3::vector3(float inX, float inY, float inZ){
	
	x=inX;
	y=inY;
	z=inZ;
	
}

vector3::vector3(const vector3 &v){
	
	x=v.x;
	y=v.y;
	z=v.z;
	
}
	
float &vector3::operator [] (unsigned int index){
	
	if(index==0){
		return x;
	}
	else if(index==1){
		return y;
	}
	else if(index==2){
		return z;
	}
	
}

const float &vector3::operator [] (unsigned int index) const{
	
	if(index==0){
		return x;
	}
	else if(index==1){
		return y;
	}
	else if(index==2){
		return z;
	}
	
}

vector3 &vector3::operator = (const vector3 &v){
	
	x=v.x;
	y=v.y;
	z=v.z;
	
	return *this;
}	

vector3 &vector3::operator += (const vector3 &v){
	
	x+=v.x;
	y+=v.y;
	z+=v.z;

	return *this;
}

vector3 &vector3::operator -= (const vector3 &v){
	
	x-=v.x;
	y-=v.y;
	z-=v.z;

	return *this;
}
	
vector3 &vector3::operator *= (float f){
	
	x*=f;
	y*=f;
	z*=f;

	return *this;
}	
	
vector3 &vector3::operator /= (float f){
	
	x/=f;
	y/=f;
	z/=f;

	return *this;
}	

bool operator == (const vector3 &a, const vector3 &b){
	
	return (a.x==b.x && a.y==b.y && a.z==b.z);
}

bool operator != (const vector3 &a, const vector3 &b){
	
	return (a.x!=b.x || a.y!=b.y || a.z!=b.z);
}

vector3 operator - (const vector3 &a){
	
	vector3 result(a.x*(-1), a.y*(-1), a.z*(-1));
	
	return result;
}

vector3 operator + (const vector3 &a, const vector3 &b){
	
	vector3 result(a.x+b.x, a.y+b.y, a.z+b.z);
	
	return result;
}

vector3 operator - (const vector3 &a, const vector3 &b){
	
	vector3 result(a.x-b.x, a.y-b.y, a.z-b.z);
	
	return result;
}

vector3 operator * (const vector3 &v, float f){
	
	vector3 result(v.x*f, v.y*f, v.z*f);
	
	return result;
}

vector3 operator * (float f, const vector3 &v){
	
	vector3 result(f*v.x, f*v.y, f*v.z);
	
	return result;
}

vector3 operator / (const vector3 &v, float f){
	
	vector3 result(v.x/f, v.y/f, v.z/f);
	
	return result;
}

void vector3::set(float xIn, float yIn, float zIn){
	
	x=xIn;
	y=yIn;
	z=zIn;
}

float vector3::length() const{
	
	float length=sqrt(x*x + y*y + z*z);
	
	return length;
}

void vector3::printVector3() const{

	cout<<"("<<x<<", "<<y<<", "<<z<<")"<<endl;

}













