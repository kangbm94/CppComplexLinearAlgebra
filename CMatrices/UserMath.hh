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
double TwoBodyCM(double mi, double m1, double m2){
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
double EC=sqrt(4*Pi()/137.04);
void SetSpinor(double* u1, double* u2, double* d1,double* d2,int k ){
	switch(k){
		case 0:
			u1[0]=1.;
			u2[0]=1.;
			d1[0]=0.;
			d2[0]=0.;
			break;
		case 1:
			u1[0]=1.;
			u2[0]=0.;
			d1[0]=0.;
			d2[0]=1.;
			break;
		case 2:
			u1[0]=0.;
			u2[0]=1.;
			d1[0]=1.;
			d2[0]=0.;
			break;
		case 3:
			u1[0]=0.;
			u2[0]=0.;
			d1[0]=1.;
			d2[0]=1.;
			break;
	}
}




//Basics
Complex Id2_[2]={Complex(1,0),Complex(1,0)};
Complex Id3_[3]={Complex(1,0),Complex(1,0),Complex(1,0)};
Complex Id4_[4]={Complex(1,0),Complex(1,0),Complex(1,0),Complex(1,0)};


CMat2D Id2 = CDiag2D(Id2_);
CMat3D Id3 = CDiag3D(Id3_);
CMat4D Id4 = CDiag4D(Id4_);






//Pauli 
Complex Pauli1[4]={Complex(0,0),Complex(1,0),Complex(1,0),Complex(0,0)};
Complex Pauli2[4]={Complex(0,0),Complex(0,-1),Complex(0,1),Complex(0,0)};
Complex Pauli3[4]={Complex(1,0),Complex(0,0),Complex(0,0),Complex(-1,0)};

CMat2D sig1=CMat2D(Pauli1); 
CMat2D sig2=CMat2D(Pauli2); 
CMat2D sig3=CMat2D(Pauli3); 

//Gamma Matrices
Complex G0_[16]={
	Complex(1,0),Complex(0,0),Complex(0,0),Complex(0,0),
	Complex(0,0),Complex(1,0),Complex(0,0),Complex(0,0),
	Complex(0,0),Complex(0,0),Complex(-1,0),Complex(0,0),
	Complex(0,0),Complex(0,0),Complex(0,0),Complex(-1,0)
};
Complex G1_[16]={
	Complex(0,0),Complex(0,0),Complex(0,0),Complex(1,0),
	Complex(0,0),Complex(0,0),Complex(1,0),Complex(0,0),
	Complex(0,0),Complex(-1,0),Complex(0,0),Complex(0,0),
	Complex(-1,0),Complex(0,0),Complex(0,0),Complex(0,0)
};
Complex G2_[16]={
	Complex(0,0),Complex(0,0),Complex(0,0),Complex(0,-1),
	Complex(0,0),Complex(0,0),Complex(0,1),Complex(0,0),
	Complex(0,0),Complex(0,1),Complex(0,0),Complex(0,0),
	Complex(0,-1),Complex(0,0),Complex(0,0),Complex(0,0)
};
Complex G3_[16]={
	Complex(0,0),Complex(0,0),Complex(1,0),Complex(0,0),
	Complex(0,0),Complex(0,0),Complex(0,0),Complex(-1,0),
	Complex(-1,0),Complex(0,0),Complex(0,0),Complex(0,0),
	Complex(0,0),Complex(1,0),Complex(0,0),Complex(0,0)
};
Complex G5_[16]={
	Complex(0,0),Complex(0,0),Complex(1,0),Complex(0,0),
	Complex(0,0),Complex(0,0),Complex(0,0),Complex(1,0),
	Complex(1,0),Complex(0,0),Complex(0,0),Complex(0,0),
	Complex(0,0),Complex(1,0),Complex(0,0),Complex(0,0)
};
CMat4D G0=CMat4D(G0_);
CMat4D G1=CMat4D(G1_);
CMat4D G2=CMat4D(G2_);
CMat4D G3=CMat4D(G3_);
CMat4D G5=CMat4D(G5_);

//Spinors
CMat4D SpinorConjugate(CMat4D U){
	
	return (U.Transpose())*G0;
}







/*
Complex U1_[16]={
	Complex(1,0),Complex(0,0),Complex(0,0),Complex(0,0),
	Complex(0,0),Complex(1,0),Complex(0,0),Complex(0,0),
	Complex(0,0),Complex(0,0),Complex(-1,0),Complex(0,0),
	Complex(0,0),Complex(0,0),Complex(0,0),Complex(-1,0)
};
Complex U2_[16]={
	Complex(1,0),Complex(0,0),Complex(0,0),Complex(0,0),
	Complex(0,0),Complex(1,0),Complex(0,0),Complex(0,0),
	Complex(0,0),Complex(0,0),Complex(-1,0),Complex(0,0),
	Complex(0,0),Complex(0,0),Complex(0,0),Complex(-1,0)
};
Complex V1_[16]={
	Complex(1,0),Complex(0,0),Complex(0,0),Complex(0,0),
	Complex(0,0),Complex(1,0),Complex(0,0),Complex(0,0),
	Complex(0,0),Complex(0,0),Complex(-1,0),Complex(0,0),
	Complex(0,0),Complex(0,0),Complex(0,0),Complex(-1,0)
};
Complex V2_[16]={
	Complex(1,0),Complex(0,0),Complex(0,0),Complex(0,0),
	Complex(0,0),Complex(1,0),Complex(0,0),Complex(0,0),
	Complex(0,0),Complex(0,0),Complex(-1,0),Complex(0,0),
	Complex(0,0),Complex(0,0),Complex(0,0),Complex(-1,0)
};
CMat4D U1=CMat4D(U1_);
CMat4D U2=CMat4D(U2_);
CMat4D V1=CMat4D(V1_);
CMat4D V2=CMat4D(V2_);
*/

/*
	 Complex Pauli13[9]={Complex(0,0),Complex(1,0),Complex(0,0),Complex(1,0),Complex(0,0),Complex(0,0),Complex(0,0),Complex(0,0),Complex(0,0)};
	 Complex Pauli23[9]={Complex(0,0),Complex(0,-1),Complex(0,0),Complex(0,1),Complex(0,0),Complex(0,0),Complex(0,0),Complex(0,0),Complex(0,0)};
	 Complex Pauli33[9]={Complex(1,0),Complex(0,0),Complex(0,0),Complex(0,0),Complex(-1,0),Complex(0,0),Complex(0,0),Complex(0,0),Complex(0,0)};
	 CMat3D sig13=CMat3D(Pauli13); 
	 CMat3D sig23=CMat3D(Pauli23); 
	 CMat3D sig33=CMat3D(Pauli33); 
	 */
