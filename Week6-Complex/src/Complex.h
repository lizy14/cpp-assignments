#ifndef C_H
#define C_H

#include <iostream>
class Complex{
public:
	double r, i;
public:
	Complex(double real=0, double imaginary=0):r(real),i(imaginary){}
	void setValue(double real=0, double imaginary=0){
		r=real, i=imaginary;
	}
	void print(){
		std::cout << "\t" << (r<0?"(":"") << r << (r<0?")":"") << " + " << (i<0?"(":"") << i << (i<0?")":"") << " i\n";
	}
	Complex operator + (Complex& c){
		Complex ret;
		ret.r = r + c.r;
		ret.i = i + c.i;
		return ret;
	}
	Complex operator - (Complex& c){
		Complex ret;
		ret.r = r - c.r;
		ret.i = i - c.i;
		return ret;
	}
	Complex operator * (Complex& c){
		Complex ret;
		ret.r = r * c.r - i * c.i;
		ret.i = r * c.i + i * c.r;
		return ret;
	}
	Complex operator / (Complex& divisor){
		Complex ret;
		double a=r, b=i, c=divisor.r, d=divisor.i;
		if(!c && !d){
			std::cout << "\tERROR: division by zero!\n";
		}else{
			ret.r = (a*c+b*d)/(c*c+d*d);
			ret.i = (b*c-a*d)/(c*c+d*d);
		}
		return ret;
	}
	Complex& operator ++ (){ //prefix ++
		r++, i++;
		return (*this);
	}
	Complex operator ++ (int){ //postfix ++
		Complex old = *this;
		r++, i++;
		return old;
	}
	Complex& operator -- (){ //prefix --
		r--, i--;
		return (*this);
	}
	Complex operator -- (int){ //postfix --
		Complex old = *this;
		r--, i--;
		return old;
	}


};


#endif