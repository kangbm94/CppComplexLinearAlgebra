#include "Complex.hh"
#include "CVector.hh"
#ifndef CMatrix_h
#define CMatrix_h
void ReduceDim(Complex* Min, Complex* Mout, int dim, int row, int col){
	int cnt=0;
	for(int i=0;i<dim;i++){
		if(i%dim==col){
			continue;
		}
		else{
			for(int j=0;j<dim;j++){
				if(j%dim==row){
					continue;
				}
				else{
					Mout[cnt]=Min[dim*i+j];
					cnt++;
				
				}
			}
		}
	}
}
class CMat2D{
	private:
		Complex M_[4];
		int dim=2;
	public:
		CMat2D(){};
		CMat2D(Complex* M){
			for(int i=0;i<4;i++){
				M_[i]=M[i];
			}
		};
		Complex GetElement(int i, int j){
			if(dim*i+j<dim*dim){
				return M_[dim*i+j];
			}
			else{
				return Complex(-99999,-99999);
			}
		}
		Complex Minor(int col,int row){
			Complex M[2];
			ReduceDim(M_,M,dim,col,row);
			return M[0];
		}
		Complex Determinant(){
			return M_[0]*M_[3]-M_[1]*M_[2];
		}
		void List(){
			for(int i=0;i<dim*dim;i++){
				cout<<"( "<<M_[i].Real()<<" , "<<M_[i].Imaginary()<<" )"<<endl;
			}
		}
		CMat2D Transpose(){
			Complex MOut[dim*dim];
			for(int i=0;i<dim;i++){
				for(int j=0;j<dim;j++){
					MOut[dim*i+j]=M_[dim*j+i];
				}
			}
			CMat2D MT(MOut);
			return MT;
		}


		CMat2D Invert()
		{
			Complex Mout[dim*dim];
			for(int i=0;i<dim;i++){
				for(int j=0;j<dim;j++){
					Mout[j*dim+i]=PM(i+j)*(Minor(j,i)) /Determinant();
				}
			}
			CMat2D InvMat(Mout);
			return InvMat;
		}
		CMat2D operator*( CMat2D B){
			Complex MOut[dim*dim];
				for(int i=0;i<dim;i++){
					for(int j=0;j<dim;j++){
							MOut[dim*i+j]=0;
						for(int k=0;k<dim;k++){
								MOut[dim*i+j]+=GetElement(i,k)*(B.GetElement(k,j));
						}
					}
				}
			CMat2D C(MOut);
			return C;
		}
		CMat2D operator+(CMat2D A){
			for(int i=0;i<dim*dim;i++){
				M_[i]=M_[i]+A.GetElement((dim*i)%dim,i%dim);
			}
			return CMat2D(M_);
		}
		CMat2D operator-(CMat2D A){
			for(int i=0;i<dim*dim;i++){
				M_[i]=M_[i]-A.GetElement((dim*i)%dim,i%dim);
			}
			return CMat2D(M_);
		}
};
class CMat3D{
	private:
		Complex M_[9];
		 int dim=3;
	public:
		CMat3D(){};
		CMat3D(Complex* M){
			for(int i=0;i<9;i++){
				M_[i]=M[i];
			}
		};
		void List(){
			for(int i=0;i<dim*dim;i++){
				cout<<"( "<<M_[i].Real()<<" , "<<M_[i].Imaginary()<<" )"<<endl;
			}
		}
		Complex GetElement(int i, int j){
			if(dim*i+j<dim*dim){
				return M_[dim*i+j];
			}
			else{
				return Complex(-99999,-99999);
			}
		}
		CMat2D Minor(int col, int row){
			Complex Mred[4];
			ReduceDim(M_,Mred,dim,col,row);		
			return CMat2D(Mred);
		}
		Complex Determinant(){
			Complex z=Complex(0,0);
			for(int i=0;i<dim;i++){
				z+=M_[i]*(Minor(i,0).Determinant())*PM(i);
			}
			return z;
		}
		CMat3D Transpose(){
			Complex MOut[dim*dim];
			for(int i=0;i<dim;i++){
				for(int j=0;j<dim;j++){
					MOut[dim*i+j]=M_[dim*j+i];
				}
			}
			CMat3D MT(MOut);
			return MT;
		}
		CMat3D Cof(){
			Complex MOut[dim*dim];
			for(int i=0;i<dim;i++){
				for(int j=0;j<dim;j++){
					MOut[dim*i+j]=Minor(i,j).Determinant()*PM(i+j);
				}
			}
			CMat3D MT(MOut);
			return MT;
		}


		CMat3D Invert(){
			Complex MOut[dim*dim];
			for(int i=0;i<dim;i++){
				for(int j=0;j<dim;j++){
					MOut[j*dim+i]=PM(i+j)*(Minor(j,i).Determinant()) /Determinant();
				}
			}
			CMat3D InvMat(MOut);
			return InvMat;
		}
		CMat3D operator+(CMat3D A){
			for(int i=0;i<dim*dim;i++){
				M_[i]=M_[i]+A.GetElement((dim*i)%dim,i%dim);
			}
			return CMat3D(M_);
		}
		CMat3D operator-(CMat3D A){
			for(int i=0;i<dim*dim;i++){
				M_[i]=M_[i]-A.GetElement((dim*i)%dim,i%dim);
			}
			return CMat3D(M_);
		}
		CMat3D operator*( CMat3D B){
			Complex MOut[dim*dim];
				for(int i=0;i<dim;i++){
					for(int j=0;j<dim;j++){
							MOut[dim*i+j]=0;
						for(int k=0;k<dim;k++){
							MOut[dim*i+j]+=(GetElement(i,k))*(B.GetElement(k,j));
						}
					}
				}
			CMat3D C(MOut);
			return C;
		}
};
class CMat4D{
	private:
		Complex M_[16];
		 int dim=4;
	public:
		CMat4D(){};
		CMat4D(Complex* M){
			for(int i=0;i<16;i++){
				M_[i]=M[i];
			}
		}
		void List(){
			for(int i=0;i<dim*dim;i++){
				cout<<"( "<<M_[i].Real()<<" , "<<M_[i].Imaginary()<<" )"<<endl;
			}
		}
		Complex GetElement(int i, int j){
			if(dim*i+j<dim*dim){
				return M_[dim*i+j];
			}
			else{
				return Complex(-99999,-99999);
			}
		}
		void GetElements(Complex* M){
			for(int i=0;i<16;i++){
				M[i]=M_[i];
		}
		}
		CMat4D operator+(CMat4D A){
			for(int i=0;i<dim*dim;i++){
				M_[i]=M_[i]+A.GetElement((dim*i)%dim,i%dim);
			}
			return CMat4D(M_);
		}
		CMat4D operator-(CMat4D A){
			for(int i=0;i<dim*dim;i++){
				M_[i]=M_[i]-A.GetElement((dim*i)%dim,i%dim);
			}
			return CMat4D(M_);
		}
		
		CMat3D Minor(int col, int row){
			Complex Mred[9];
			ReduceDim(M_,Mred,dim,col,row);
			return CMat3D(Mred);
		}
		Complex Determinant(){
			Complex val=Complex(0,0);
			for(int i=0;i<dim;i++){
				val+=M_[i]*(Minor(i,0).Determinant())*PM(i);
			}
			return val;
		}
		CMat4D Transpose(){
			Complex MOut[dim*dim];
			for(int i=0;i<dim;i++){
				for(int j=0;j<dim;j++){
					MOut[dim*i+j]=M_[dim*j+i];
				}
			}
			CMat4D MT(MOut);
			return MT;
		}
		CMat4D Invert(){
			Complex MOut[dim*dim];
			for(int i=0;i<dim;i++){
				for(int j=0;j<dim;j++){
					MOut[j*dim+i]=PM(i+j)*(Minor(j,i).Determinant()) /Determinant();
				}
			}
			CMat4D InvMat(MOut);
			return InvMat;
		}
		CMat4D operator*( CMat4D B){
			Complex MOut[dim*dim];
				for(int i=0;i<dim;i++){
					for(int j=0;j<dim;j++){
							MOut[dim*i+j]=0;
						for(int k=0;k<dim;k++){
							MOut[dim*i+j]+=(GetElement(i,k))*(B.GetElement(k,j));
						}
					}
				}
			CMat4D C(MOut);
			return C;
		}
};
#endif
