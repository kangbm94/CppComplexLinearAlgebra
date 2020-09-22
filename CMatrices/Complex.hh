#include "Math.hh"
#ifndef Complex_h
#define Complex_h
class Complex{
	private:
		double real;
		double img;
	public:
		Complex(){
			real=0;
			img=0;
		};
		Complex(double r, double i){
			real=r;
			img=i;
		};
		Complex(int r, double i){
			real=r;
			img=i;
		};
		Complex(double r, int i){
			real=r;
			img=i;
		};
		Complex(int r, int i){
			real=r;
			img=i;
		};
		double Real(){
			return real;
		}
		double Imaginary(){
			return img;
		}
		Complex Conjugate(){
			Complex ztmp;
			ztmp.real=real;
			ztmp.img=-img;
			return ztmp;
		}
		double Abs(){
			return sqrt(square(real)+square(img));
		}
		Complex operator+(Complex z){
			Complex ztmp;
			ztmp.real=real+z.Real();
			ztmp.img=img+z.Imaginary();
			return ztmp;
		}
		Complex operator+(int a){
			Complex ztmp;
			ztmp.real=real+a;
			ztmp.img=img;
			return ztmp;
		}
		Complex operator+(double a){
			Complex ztmp;
			ztmp.real=real+a;
			ztmp.img=img;
			return ztmp;
		}
		Complex operator-(Complex z){
			Complex ztmp;
			ztmp.real=real-z.Real();
			ztmp.img=img-z.Imaginary();
			return ztmp;
		}
		Complex operator-(double a){
			Complex ztmp;
			ztmp.real=real-a;
			ztmp.img=img;
			return ztmp;
		}
		Complex operator-(int a){
			Complex ztmp;
			ztmp.real=real-a;
			ztmp.img=img;
			return ztmp;
		}
		Complex operator-(){
			Complex ztmp;
			ztmp.real=-real;
			ztmp.img=-img;
			return ztmp;
		}
		Complex operator*(Complex z){
			Complex ztmp;
			ztmp.real=real*z.Real()-img*z.Imaginary();
			ztmp.img=img*z.Real()+real*z.Imaginary();
			return ztmp;
		}
		Complex operator*(int a){
			Complex ztmp;
			ztmp.real=real*a;
			ztmp.img=img*a;
			return ztmp;
		}
		Complex operator*(double a){
			Complex ztmp;
			ztmp.real=real*a;
			ztmp.img=img*a;
			return ztmp;
		}
		Complex operator/(double a){
			Complex ztmp;
			ztmp.real=real/a;
			ztmp.img=img/a;
			return ztmp;
		}
		Complex operator/(int a){
			Complex ztmp;
			ztmp.real=real/a;
			ztmp.img=img/a;
			return ztmp;
		}
		Complex operator/(Complex z){
			Complex ztmp;
			ztmp.real=real;
			ztmp.img=img;
			Complex z2=z.Conjugate();
			double zabs=z.Abs();
			Complex z3=z2/zabs/zabs;
			return ztmp*z3;
		}
		/*
		Complex operator=(Complex z){
			Complex ztmp;
			ztmp.real=z.real;
			ztmp.img=z.img;
			return ztmp;
		}
		*/
		Complex operator=(double a){
			Complex ztmp;
			ztmp.real=a;
			ztmp.img=0;
			return ztmp;
		}
		Complex operator=(int a){
			Complex ztmp;
			ztmp.real=a;
			ztmp.img=0;
			return ztmp;
		}
		Complex operator+=(Complex z){
			Complex ztmp;
			real+=z.real;
			img+=z.img;
			ztmp.real=real;
			ztmp.img=img;
			return ztmp;
		}
		Complex operator+=(double a){
			Complex ztmp;
			real+=a;
			ztmp.img=img;
			return ztmp;
		}
		Complex operator+=(int a){
			Complex ztmp;
			real+=a;
			ztmp.real=real;
			ztmp.img=img;
			return ztmp;
		}
	void Show(){
		cout<<"( "<<real<<" , "<<img<<" )";
	}
};
//Operators
Complex operator+(int a,Complex ztmp){
	return ztmp+a;
}
Complex operator+(double a,Complex ztmp){
	return ztmp+a;
}
Complex operator*(double a,Complex ztmp){
	return ztmp*a;
}
Complex operator*(int a,Complex ztmp){
	return ztmp*a;
}
Complex operator-(double a,Complex ztmp){
	return (ztmp-a)*(-1);
}
Complex operator-(int a,Complex ztmp){
	return (ztmp-a)*(-1);
}
Complex operator/(double a,Complex z){
	double zabs=z.Abs();
	Complex z2=z.Conjugate()/zabs/zabs;
	return z2*a;
}
Complex operator/(int a,Complex z){
	double zabs=z.Abs();
	Complex z2=z.Conjugate()/zabs/zabs;
	return z2*a;
}
#endif
