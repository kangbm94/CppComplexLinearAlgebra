#ifndef Variables_h
#define Variables_h
double Pi(){
	return 4*atan(1);
}
TF1* sinfn= new TF1("sinfn","sin(x)",0,2*Pi());
TF1* thfn= new TF1("thfn","abs(sin(x))",0,Pi());
double val=0;
double val2=0;
double val3=0;
double val4=0;

double dumd1=0;
double dumd2=0;
double dumd3=0;
double dumd4=0;

int dumi1=0;
int dumi2=0;
int dumi3=0;
int dumi4=0;
#endif
