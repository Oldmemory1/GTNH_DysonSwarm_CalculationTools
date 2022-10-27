#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cmath>
#include<ctime>
#include<limits>
#include<windows.h> 
using namespace std;
class DysonSwarm{
	private:
	int InputModule;
	double ComputationNeed;
	double OutPutEnergy;
	double DIM;
	double moduleCount;
	public:
	void SetDataAndInitialization(int ModuleInput,double InputDIM){
		this->InputModule=ModuleInput;
		this->DIM=InputDIM;
		this->moduleCount=0;
		this->OutPutEnergy=0;
		this->ComputationNeed=0;
	}
	void GenerateModule(){
		this->moduleCount=this->moduleCount+this->InputModule;
		//cout<<this->moduleCount<<endl; 
	}
	void DestroyModule(){
		double a=1;
		/*while(a<0||a>2){
			a=generateGaussianNoise(1.0,1.0);	
		}*/
		this->moduleCount=this->moduleCount-(double)((5e-5)*a*pow((double)this->moduleCount,1.001));
		if(this->moduleCount<0){
			this->moduleCount=0;
		}
		//cout<<this->moduleCount<<endl;
	}
	void CalculateComputation(){
		this->ComputationNeed=(double)ceil(max(0.1*pow((double)this->moduleCount,1.075)-128,(double)0));
	}
	void CalculateOutPutEnergy(){
		this->OutPutEnergy=(double)((double)this->moduleCount*(double)262144*(double)DIM);
		//printf("%.0lf\n",this->OutPutEnergy);
	}
	double GetOutPutEnergy(){
		return this->OutPutEnergy;
	}
	double GetNeedComputation(){
		return this->ComputationNeed;
	}
}; 
int main(){
	DysonSwarm Dyson;
	cout<<"请输入放入的模块数，和戴森球所在维度的发电系数修正："<<endl;
	int num1;
	double num2;
	scanf("%d %lf",&num1,&num2);
	Dyson.SetDataAndInitialization(num1,num2);
	double temp=-114514;
	double Temp1=-1;
	double Temp2=-1; 
	/*while(true){
		Dyson.GenerateModule();
		Dyson.CalculateComputation();
		Dyson.CalculateOutPutEnergy();
		Dyson.DestroyModule();
		if(fabs(temp-Dyson.GetOutPutEnergy())<1){
			break;
		}else{
			temp=Dyson.GetOutPutEnergy();
		}
	}*/
	for(int i=1;i>0;i++){
		Dyson.GenerateModule();
		Dyson.CalculateComputation();
		Dyson.CalculateOutPutEnergy();
		Dyson.DestroyModule();		
		
		if(i%2==1){
			if((fabs)(Dyson.GetOutPutEnergy()-Temp1)<1){
				break;
			}
			Temp1=Dyson.GetOutPutEnergy();
		}else if(i%2==0){
			if((fabs)(Dyson.GetOutPutEnergy()-Temp2)<1){
				break;
			}
			Temp2=Dyson.GetOutPutEnergy();
		}
	}
	cout<<"发电量："<<endl; 
	printf("%.0lf\n",Dyson.GetOutPutEnergy()); 
	cout<<"所需算力："<<endl; 
	printf("%.0lf\n",Dyson.GetNeedComputation());
	cout<<"最少需要机箱："<<endl;
	int temp1=ceil(Dyson.GetNeedComputation()/(double)1154);
	printf("%d\n",temp1);
	cout<<"这些机箱的耗电量为："<<endl; 
	printf("%.0lf\n",temp1*0.8*524288);
	cout<<"净输出为："<<endl;
	printf("%.0lf\n",Dyson.GetOutPutEnergy()-temp1*-0.8*524288); 
	system("pause"); 
	return 0;
}
