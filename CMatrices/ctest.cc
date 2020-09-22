#include "UserMath.hh"
void ctest(){
	Complex z1=Complex(1,1);
	Complex z2=Complex(1,2);
	Complex z3=z2*z1/z2;
	z3.Show();
	cout<<endl;
}
