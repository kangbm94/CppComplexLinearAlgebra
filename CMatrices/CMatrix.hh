#include "Complex.hh"
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
		CMat2D(){
			for(int i=0;i<dim*dim;i++){
				M_[i]=Complex(0,0);
			}
		};
		CMat2D(int* M){
			for(int i=0;i<dim*dim;i++){
				M_[i]=Complex(M[i],0);
			}
		}
		CMat2D(double* M){
			for(int i=0;i<dim*dim;i++){
				M_[i]=Complex(M[i],0);
			}
		}
		CMat2D(Complex* M){
			for(int i=0;i<dim*dim;i++){
				M_[i]=M[i];
			}
		}
		void Init(){
			for(int i=0;i<dim*dim;i++){
				M_[i]=0;
			}
		}
		Complex GetElement(int i, int j){
			if(dim*i+j<dim*dim){
				return M_[dim*i+j];
			}
			else{
				cout<<"Dimmesion Error"<<endl;
				return Complex(0,0);
			}
		}
		double  GetElementReal(int i, int j){
			if(dim*i+j<dim*dim){
				return M_[dim*i+j].Real();
			}
			else{
				cout<<"Dimmesion Error"<<endl;
				return -99999;
			}
		}
		double GetElementImaginary(int i, int j){
			if(dim*i+j<dim*dim){
				return M_[dim*i+j].Imaginary();
			}
			else{
				cout<<"Dimmesion Error"<<endl;
				return -99999;
			}
		}
		void SetElement(int i, int j, Complex Z){
			M_[dim*i+j]=Z;
		}
		void SetElement(int i, int j, int a){
			M_[dim*i+j]=Complex(a,0);
		}
		void SetElement(int i, int j, double a){
			M_[dim*i+j]=Complex(a,0);
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
		CMat2D operator*( Complex B){
			Complex MOut[dim*dim];
			for(int i=0;i<dim;i++){
				for(int j=0;j<dim;j++){
					MOut[dim*i+j]=0;
					MOut[dim*i+j]=GetElement(i,j)*B;
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
CMat2D operator*( Complex B,CMat2D A){
	int dim=2;
		Complex MOut[dim*dim];
	for(int i=0;i<dim;i++){
		for(int j=0;j<dim;j++){
			MOut[dim*i+j]=0;
			MOut[dim*i+j]=A.GetElement(i,j)*B;
		}
	}
	CMat2D C(MOut);
	return C;
}
CMat2D CRow2D(Complex* Z){
	int dim=2;
	CMat2D Temp;
	for(int i=0;i<dim;i++){
		Temp.SetElement(i,0,Z[i]);
	}
	return Temp;
}
CMat2D CCol2D(Complex* Z){
	int dim=2;
	CMat2D Temp;
	for(int i=0;i<dim;i++){
		Temp.SetElement(0,i,Z[i]);
	}
	return Temp;
}
CMat2D CDiag2D(Complex* Z){
	int dim=2;
	CMat2D Temp;
	for(int i=0;i<dim;i++){
		Temp.SetElement(i,i,Z[i]);
	}
	return Temp;
}
class CMat3D{
	private:
		Complex M_[9];
		int dim=3;
	public:
		CMat3D(){
			for(int i=0;i<dim*dim;i++){
				M_[i]=Complex(0,0);
			}
		};
		CMat3D(int* M){
			for(int i=0;i<dim*dim;i++){
				M_[i]=Complex(M[i],0);
			}
		}
		CMat3D(double* M){
			for(int i=0;i<dim*dim;i++){
				M_[i]=Complex(M[i],0);
			}
		}
		CMat3D(Complex* M){
			for(int i=0;i<dim*dim;i++){
				M_[i]=M[i];
			}
		}
		void Init(){
			for(int i=0;i<dim*dim;i++){
				M_[i]=0;
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
		double  GetElementReal(int i, int j){
			if(dim*i+j<dim*dim){
				return M_[dim*i+j].Real();
			}
			else{
				cout<<"Dimmesion Error"<<endl;
				return -99999;
			}
		}
		double GetElementImaginary(int i, int j){
			if(dim*i+j<dim*dim){
				return M_[dim*i+j].Imaginary();
			}
			else{
				cout<<"Dimmesion Error"<<endl;
				return -99999;
			}
		}
		void SetElement(int i, int j, Complex Z){
			M_[dim*i+j]=Z;
		}
		void SetElement(int i, int j, int a){
			M_[dim*i+j]=Complex(a,0);
		}
		void SetElement(int i, int j, double a){
			M_[dim*i+j]=Complex(a,0);
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
		CMat3D operator*( Complex B){
			Complex MOut[dim*dim];
			for(int i=0;i<dim;i++){
				for(int j=0;j<dim;j++){
					MOut[dim*i+j]=0;
					MOut[dim*i+j]=GetElement(i,j)*B;
				}
			}
			CMat3D C(MOut);
			return C;
		}
};
CMat3D operator*( Complex B,CMat3D A){
	int dim=3;
		Complex MOut[dim*dim];
	for(int i=0;i<dim;i++){
		for(int j=0;j<dim;j++){
			MOut[dim*i+j]=0;
			MOut[dim*i+j]=A.GetElement(i,j)*B;
		}
	}
	CMat3D C(MOut);
	return C;
}
CMat3D CRow3D(Complex* Z){
	int dim=3;
	CMat3D Temp;
	for(int i=0;i<dim;i++){
		Temp.SetElement(i,0,Z[i]);
	}
	return Temp;
}
CMat3D CCol3D(Complex* Z){
	int dim=3;
	CMat3D Temp;
	for(int i=0;i<dim;i++){
		Temp.SetElement(0,i,Z[i]);
	}
	return Temp;
}
CMat3D CDiag3D(Complex* Z){
	int dim=3;
	CMat3D Temp;
	for(int i=0;i<dim;i++){
		Temp.SetElement(i,i,Z[i]);
	}
	return Temp;
}
class CMat4D{
	private:
		Complex M_[16];
		int dim=4;
	public:
		CMat4D(){
			for(int i=0;i<dim*dim;i++){
				M_[i]=Complex(0,0);
			}
		}
		CMat4D(int* M){
			for(int i=0;i<dim*dim;i++){
				M_[i]=Complex(M[i],0);
			}
		}
		CMat4D(double* M){
			for(int i=0;i<dim*dim;i++){
				M_[i]=Complex(M[i],0);
			}
		}
		CMat4D(Complex* M){
			for(int i=0;i<dim*dim;i++){
				M_[i]=M[i];
			}
		}
		void Init(){
			for(int i=0;i<dim*dim;i++){
				M_[i]=0;
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
		double  GetElementReal(int i, int j){
			if(dim*i+j<dim*dim){
				return M_[dim*i+j].Real();
			}
			else{
				cout<<"Dimmesion Error"<<endl;
				return -99999;
			}
		}
		double GetElementImaginary(int i, int j){
			if(dim*i+j<dim*dim){
				return M_[dim*i+j].Imaginary();
			}
			else{
				cout<<"Dimmesion Error"<<endl;
				return -99999;
			}
		}
		void SetElement(int i, int j, Complex Z){
			M_[dim*i+j]=Z;
		}
		void SetElement(int i, int j, int a){
			M_[dim*i+j]=Complex(a,0);
		}
		void SetElement(int i, int j, double a){
			M_[dim*i+j]=Complex(a,0);
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
		CMat4D operator*( Complex B){
			Complex MOut[dim*dim];
			for(int i=0;i<dim;i++){
				for(int j=0;j<dim;j++){
					MOut[dim*i+j]=0;
					MOut[dim*i+j]=GetElement(i,j)*B;
				}
			}
			CMat4D C(MOut);
			return C;
		}
};
CMat4D operator*( Complex B,CMat4D A){
	int dim=4;
		Complex MOut[dim*dim];
	for(int i=0;i<dim;i++){
		for(int j=0;j<dim;j++){
			MOut[dim*i+j]=0;
			MOut[dim*i+j]=A.GetElement(i,j)*B;
		}
	}
	CMat4D C(MOut);
	return C;
}
CMat4D CRow4D(Complex* Z){
	int dim=4;
	CMat4D Temp;
	for(int i=0;i<dim;i++){
		Temp.SetElement(i,0,Z[i]);
	}
	return Temp;
}
CMat4D CCol4D(Complex* Z){
	int dim=4;
	CMat4D Temp;
	for(int i=0;i<dim;i++){
		Temp.SetElement(0,i,Z[i]);
	}
	return Temp;
}
CMat4D CDiag4D(Complex* Z){
	int dim=4;
	CMat4D Temp;
	for(int i=0;i<dim;i++){
		Temp.SetElement(i,i,Z[i]);
	}
	return Temp;
}
#endif
