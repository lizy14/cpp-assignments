//李肇阳 清华大学软件学院

//创建于 2015-7-20
//to be compiled with Microsoft Visual Studio 2012 (MSVC 11.0)

#include <iostream>
using namespace std;
#define extends : public
class Shape{
public:
	virtual double getarea(){
		return 0;
	};
};
class Circle extends Shape{
public:
	double r;
	static const double Pi;
	Circle(double r_){
		r=r_;
	}
	double getarea(){
		return r*r*Pi;
	}	
};
const double Circle::Pi =  3.14159;
class Rectangle extends Shape{
public:
	double a;
	double b;
	Rectangle(double a_,double b_){
		a=a_;
		b=b_;
	}
	double getarea(){
		return a*b;
	}
};
class Square extends Shape{
public:
	double a;
	Square(double a_){
		a=a_;
	}
	double getarea(){
		return a*a;
	}
};
int main(int argc, char **argv) {
	Shape * shapes[4];
	Circle circle(2.0);
	Rectangle rectangle(3.0, 4.0);
	Square square1(5.0);
	Square square2(4.0);
	shapes[0] = &circle; 
	shapes[1] = &rectangle; 
	shapes[2] = &square1;
	shapes[3] = &square2;
	for (int k = 0; k<4; k++) {
		cout << "Area is " << shapes[k]->getarea() << endl;
	}
	return 0;
}


