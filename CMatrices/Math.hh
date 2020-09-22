#include "Variables.hh"
#ifndef Math_h
#define Math_h
double square(double a){ 
	return a*a;
}
int PM(int a){
	if(a%2==0){
		return 1;
	}
	else{
		return -1;
	}
}
double Min(double a, double b){
	if(a>b){
		return b;
	}
	else{
		return a;
	}
}
double Max(double a, double b){
	if(a>b){
		return a;
	}
	else{
		return b;
	}
}

//
//Randoms
double GenSineRandom(double x1,double x2){
	val=sinfn->GetRandom();
	return val;
}
double GenUniformRandom(double range){
	double rnd=gRandom->Rndm();
	return range*rnd;
}
double GenUniformRandom(){
	return GenUniformRandom(1);
}
double GenUniRnd(double range){
	return GenUniformRandom(range);
}
double GenUniRnd(){
	return GenUniformRandom(1);
}

void GenSphericalRandom(double &theta, double &phi){
	phi=GenUniRnd(2*Pi());
	theta=thfn->GetRandom();
}
void GenSphRnd(double &theta, double &phi){
	GenSphericalRandom(theta,phi);
}
#endif
