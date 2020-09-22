#include "CMatrix.hh"
#include "Matrix.hh"
double PToBeta(double mom,double mass){
	val=sqrt(mass*mass+mom*mom);
	return sqrt(mom/val);
}
double BetaToP(double beta, double mass){
	val=1/sqrt(1-square(beta));
	return val*mass;
}
double Gamma(double beta){
	val=1/sqrt(1-square(beta));
	return val;
}
double Beta(double gamma){
	val=1-square(1/gamma);
	return sqrt(val);
}
double TwoBodyCMMom(double mi, double m1, double m2){
	return sqrt((mi*mi-square(m1+m2))*(mi*mi-square(m1-m2)))/(2*mi);
}
double TotalDecayWidth(double *Gamma,double size){
//	dumi1=Gamma.length();
//	cout<<"Size of Entries: "<<dumi1<<endl;
	for(dumi2=0;dumi2<size;dumi2++){
		val+=1/Gamma[dumi2];
	}
	return 1/val;
}




Complex Pauli1[4]={Complex(0,0),Complex(1,0),Complex(1,0),Complex(0,0)};
Complex Pauli2[4]={Complex(0,0),Complex(0,-1),Complex(0,1),Complex(0,0)};
Complex Pauli3[4]={Complex(1,0),Complex(0,0),Complex(0,0),Complex(-1,0)};
CMat2D sig1=CMat2D(Pauli1); 
CMat2D sig2=CMat2D(Pauli2); 
CMat2D sig3=CMat2D(Pauli3); 
/*
Complex Pauli13[9]={Complex(0,0),Complex(1,0),Complex(0,0),Complex(1,0),Complex(0,0),Complex(0,0),Complex(0,0),Complex(0,0),Complex(0,0)};
Complex Pauli23[9]={Complex(0,0),Complex(0,-1),Complex(0,0),Complex(0,1),Complex(0,0),Complex(0,0),Complex(0,0),Complex(0,0),Complex(0,0)};
Complex Pauli33[9]={Complex(1,0),Complex(0,0),Complex(0,0),Complex(0,0),Complex(-1,0),Complex(0,0),Complex(0,0),Complex(0,0),Complex(0,0)};
CMat3D sig13=CMat3D(Pauli13); 
CMat3D sig23=CMat3D(Pauli23); 
CMat3D sig33=CMat3D(Pauli33); 
*/
