#include "Complex.hh"
#include "CMatrix.hh"
void test(){
	gRandom->SetSeed();
	Complex z1=Complex(3,4);
	Complex z2=Complex(3,-4);
	Complex z3=z1*(z1.Conjugate());
	cout<<z3.Real()<<endl;
	cout<<z3.Imaginary()<<endl;

}
