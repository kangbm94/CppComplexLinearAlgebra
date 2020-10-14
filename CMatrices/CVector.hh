//#include "CMatrix.hh"
#ifndef CVector_h
#define CVector_h
class CTVec: public CMat2D{//By default, Column vector
	private:
		Complex v[3];
	public:

};
class CFVec : public CMat4D{//By default, Column vector
	private:
		Complex v[4];
	public:
		CFVec(){
			for(int i=0;i<dim;i++){
				v[i]=Complex(0,0);
			}
		}
		CFVec(int* V){
			for(int i=0;i<dim;i++){
				v[i]=Complex(V,0);
			}
		}
		CFVec(double* V){
			for(int i=0;i<dim;i++){
				v[i]=Complex(V,0);
			}
		}
		CFVec(Complex* V){
			for(int i=0;i<dim;i++){
				v[i]=V[i];
			}
		}
		void Col(){
			for(int i=0;i<dim;i++){
				M_[dim*i]=v[i];
			}
		}
		void Row(){
			for(int i=0;i<dim;i++){
				M_[i]=v[i];
			}
		}
};
#endif
