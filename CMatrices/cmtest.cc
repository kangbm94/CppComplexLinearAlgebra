#include "UserMath.hh"
void cmtest(){
	Complex AM[16]={Complex(1,1),Complex(2,3),Complex(3,2),Complex(3,3),Complex(4,2),Complex(1,5),Complex(4,1),Complex(2,2),Complex(2,2),Complex(2,1),Complex(1,2),Complex(3,3),Complex(4,3),Complex(1,1),Complex(2,2),Complex(2,3)};
	CMat4D A=CMat4D(AM);
	Complex d=A.Determinant();
	CMat4D AI=A.Invert();
	CMat4D product=A*AI;
	cout<<"Det: ";
	d.Show();
	cout<<endl;
	for(int i=0;i<4;i++){
	for(int j=0;j<4;j++){
		cout<<"Element [ "<<i<<" , "<<j<<" ] = ( "<<(product.GetElement(i,j)).Real()<<" , "<<(product.GetElement(i,j)).Imaginary()<<" )"<<endl; 
	}
	}
}
