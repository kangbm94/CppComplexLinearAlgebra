#include "Math.hh"
#ifndef Matrix_h
#define Matrix_h
void ReduceDim(double* Min, double* Mout, int dim, int row, int col){
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
class Mat2D{
	private:
		double M_[4];
		int dim=2;
	public:
		Mat2D(){};
		Mat2D(double* M){
			for(int i=0;i<4;i++){
				M_[i]=M[i];
			}
		};
		double GetElement(int i, int j){
			if(dim*i+j<dim*dim){
				return M_[dim*i+j];
			}
			else{
				return -99999;
			}
		}
		double Determinant(){
			return M_[0]*M_[3]-M_[1]*M_[2];
		}
		void List(){
			for(int i=0;i<dim*dim;i++){
				cout<<M_[i]<<endl;
			}
		}
		Mat2D Transpose(){
			double MOut[dim*dim];
			for(int i=0;i<dim;i++){
				for(int j=0;j<dim;j++){
					MOut[dim*i+j]=M_[dim*j+i];
				}
			}
			Mat2D MT(MOut);
			return MT;
		}


		Mat2D Invert()
		{
			double Mout[dim*dim];
			for(int i=0;i<dim;i++){
				for(int j=0;j<dim;j++){
					Mout[j*dim+i]=PM(i+j)*M_[i*dim+j] /Determinant();
				}
			}
			Mat2D InvMat(Mout);
			return InvMat;
		}
};
class Mat3D{
	private:
		double M_[9];
		int dim=3;
	public:
		Mat3D(){};
		Mat3D(double* M){
			for(int i=0;i<9;i++){
				M_[i]=M[i];
			}
		};
		void List(){
			for(int i=0;i<dim*dim;i++){
				cout<<M_[i]<<endl;
			}
		}
		double GetElement(int i, int j){
			if(dim*i+j<dim*dim){
				return M_[dim*i+j];
			}
			else{
				return -99999;
			}
		}
		Mat2D Minor(int col, int row){
			double Mred[4];
			ReduceDim(M_,Mred,dim,col,row);		
			return Mat2D(Mred);
		}
		double Determinant(){
			double val=0;
			for(int i=0;i<dim;i++){
				val+=M_[i]*(Minor(i,0).Determinant())*PM(i);
			}
			return val;
		}
		Mat3D Transpose(){
			double MOut[dim*dim];
			for(int i=0;i<dim;i++){
				for(int j=0;j<dim;j++){
					MOut[dim*i+j]=M_[dim*j+i];
				}
			}
			Mat3D MT(MOut);
			return MT;
		}
		Mat3D Cof(){
			double MOut[dim*dim];
			for(int i=0;i<dim;i++){
				for(int j=0;j<dim;j++){
					MOut[dim*i+j]=Minor(i,j).Determinant()*PM(i+j);
				}
			}
			Mat3D MT(MOut);
			return MT;
		}


		Mat3D Invert(){
			double MOut[dim*dim];
			for(int i=0;i<dim;i++){
				for(int j=0;j<dim;j++){
					MOut[j*dim+i]=PM(i+j)*(Minor(j,i).Determinant()) /Determinant();
				}
			}
			Mat3D InvMat(MOut);
			return InvMat;
		}
		Mat3D Product( Mat3D B){
			double MOut[dim*dim];
				for(int i=0;i<dim;i++){
					for(int j=0;j<dim;j++){
							MOut[dim*i+j]=0;
						for(int k=0;k<dim;k++){
							MOut[dim*i+j]+=(GetElement(i,k))*(B.GetElement(k,j));
						}
					}
				}
			Mat3D C(MOut);
			return C;
		}
};
class Mat4D{
	private:
		double M_[16];
		int dim=4;
	public:
		Mat4D(){};
		Mat4D(double* M){
			for(int i=0;i<16;i++){
				M_[i]=M[i];
			}
		}
		void List(){
			for(int i=0;i<dim*dim;i++){
				cout<<M_[i]<<endl;
			}
		}
		double GetElement(int i, int j){
			if(dim*i+j<dim*dim){
				return M_[dim*i+j];
			}
			else{
				return -99999;
			}
		}
		void GetElements(double* M){
			for(int i=0;i<16;i++){
				M[i]=M_[i];
		}
		}
		void Sum(Mat4D A){
			for(int i=0;i<16;i++){
				M_[i]=M_[i]+A.GetElement((dim*i)%dim,i%dim);
			}
		}
		void Sub(Mat4D A){
			for(int i=0;i<16;i++){
				M_[i]=M_[i]-A.GetElement((dim*i)%dim,i%dim);
			}
		}
		
		Mat3D Minor(int col, int row){
			double Mred[9];
			ReduceDim(M_,Mred,dim,col,row);
			return Mat3D(Mred);
		}
		double Determinant(){
			double val=0;
			for(int i=0;i<dim;i++){
				val+=M_[i]*(Minor(i,0).Determinant())*PM(i);
			}
			return val;
		}
		Mat4D Transpose(){
			double MOut[dim*dim];
			for(int i=0;i<dim;i++){
				for(int j=0;j<dim;j++){
					MOut[dim*i+j]=M_[dim*j+i];
				}
			}
			Mat4D MT(MOut);
			return MT;
		}
		Mat4D Invert(){
			double MOut[dim*dim];
			for(int i=0;i<dim;i++){
				for(int j=0;j<dim;j++){
					MOut[j*dim+i]=PM(i+j)*(Minor(j,i).Determinant()) /Determinant();
				}
			}
			Mat4D InvMat(MOut);
			return InvMat;
		}
		Mat4D Product( Mat4D B){
			double MOut[dim*dim];
				for(int i=0;i<dim;i++){
					for(int j=0;j<dim;j++){
							MOut[dim*i+j]=0;
						for(int k=0;k<dim;k++){
							MOut[dim*i+j]+=(GetElement(i,k))*(B.GetElement(k,j));
						}
					}
				}
			Mat4D C(MOut);
			return C;
		}
};
#endif
