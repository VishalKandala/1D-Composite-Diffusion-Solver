// 11/22 Mingxin, 11/25 Vishal Indivar Kandala
// MEEN 689 Computing Concepts Project 3
#include <cmath>
#include <iostream>
#include <vector>
#include "heat.hpp"
using namespace std;
//using namespace heat;

namespace heat {
    bool Crystal_Flag;
    double dt;
    double dr;
    int Num_of_nodes;
    int N;
    int Nt;
    double ft;
    double t;
    double avgcput;
    std::vector<std::vector<double>> T;
    std::vector<std::vector<double>> Told;
    std::vector<std::vector<double>> A;
    std::vector<double> B;
    vector<double> r;
    vector<double> Tg;
    
    //0:felt 1:carbon fiber 2:epoxy 3:aluminum 4:steel
    vector<double> alpha = {0.0, 0.0, 0.0, 0.0, 0.0};   //{(0.107/(145*2e4)), (10.0/(1850*1100)), (0.44/(300*1730)), (210.0/(2700*890)), (21.5/(8000*510))};
    vector<double> glass_t = {0.0, 0.0, 0.0, 0.0, 0.0}; //{1273.15, 523.15, 396.15, 610.0, 1033.15}; 
    vector<double> cp = {0.0, 0.0, 0.0, 0.0, 0.0};
    vector<double> k = {0.0, 0.0, 0.0, 0.0, 0.0};
    vector<double> rho = {0.0, 0.0, 0.0, 0.0, 0.0};

    userParams solverParams;
}

double heat::Define_Tg(double x, int layup){
	double output;
	if (layup == 0){
		if (x <= 4.0){
			output = glass_t[4];
		}
		else{
			output = glass_t[0];
		}
	}
	else if(layup==1){
            if (x>=0 && x<=0.020){                //Felt
                output = glass_t[0];
            }else if(x>0.020 && x<=0.025){        //Caxbon Fibex
                output = glass_t[1];
            }else if(x>0.025 && x<=0.026){        //Epoxy
                output = glass_t[2];
            }else if(x>0.026 && x<=0.034){        //Caxbon Fibex
                output = glass_t[1];
            }else if(x>0.034 && x<=0.035){        //Epoxy
                output = glass_t[2];
            }else if(x>0.035 && x<=2.035){        //Aluminium
                output = glass_t[3];
            }else if(x>2.035 && x<=5.965){        //Steel
                output = glass_t[4];
            }else if(x>5.965 && x<=7.965){        //Aluminium
                output = glass_t[3];
            }else if(x>7.965 && x<=7.966){        //Epoxy
                output = glass_t[2];
            }else if(x>7.966 && x<=7.974){        //Caxbon Fibex
                output = glass_t[1];
            }else if(x>7.974 && x<=7.975){        //Epoxy
                output = glass_t[2];
            }else if(x>7.975 && x<=7.980){        //Caxbon Fibex
                output = glass_t[1];
            }else{                                //Felt
                output = glass_t[0];
              }
            }

    else if(layup==2){
            if (x>=0 && x<=0.030){                //Felt
                output = glass_t[0];
            }else if(x>0.030 && x<=0.033){        //Caxbon Fibex
                output = glass_t[1];
            }else if(x>0.033 && x<=0.034){        //Epoxy
                output = glass_t[2];
            }else if(x>0.034 && x<=0.046){        //Caxbon Fibex
                output = glass_t[1];
            }else if(x>0.046 && x<=0.047){        //Epoxy
                output = glass_t[2];
            }else if(x>0.047 && x<=2.047){        //Aluminium
                output = glass_t[3];
            }else if(x>2.347 && x<=5.653){        //Steel
                output = glass_t[4];
            }else if(x>5.653 && x<=7.953){        //Aluminium
                output = glass_t[3];
            }else if(x>7.953 && x<=7.954){        //Epoxy
                output = glass_t[2];
            }else if(x>7.954 && x<=7.966){        //Caxbon Fibex
                output = glass_t[1];
            }else if(x>7.966 && x<=7.967){        //Epoxy
                output = glass_t[2];
            }else if(x>7.967 && x<=7.970){        //Caxbon Fibex
                output = glass_t[1];
            }else if(x>7.970 && x<=8.000){       //Felt
                output = glass_t[0];
              }else{                                //Felt
                output = glass_t[0];
              }
            }

    else if(layup==3){
            if (x>=0 && x<=0.020){                //Felt
                output = glass_t[0];
            }else if(x>0.020 && x<=0.030){        //Caxbon Fibex
                output = glass_t[1];
            }else if(x>0.030 && x<=0.031){        //Epoxy
                output = glass_t[2];
            }else if(x>0.031 && x<=0.043){        //Caxbon Fibex
                output = glass_t[1];
            }else if(x>0.043 && x<=0.044){        //Epoxy
                output = glass_t[2];
            }else if(x>0.044 && x<=1.744){        //Aluminium
                output = glass_t[3];
            }else if(x>1.744 && x<=6.256){        //Steel
                output = glass_t[4];
            }else if(x>6.256 && x<=7.956){        //Aluminium
                output = glass_t[3];
            }else if(x>7.956 && x<=7.957){        //Epoxy
                output = glass_t[2];
            }else if(x>7.957 && x<=7.969){        //Caxbon Fibex
                output = glass_t[1];
            }else if(x>7.969 && x<=7.970){        //Epoxy
                output = glass_t[2];
            }else if(x>7.970 && x<=7.980){        //Caxbon Fibex
                output = glass_t[1];
            }else if (x>7.980 && x<=8.000){       //Felt
                output = glass_t[0];
              }else{                                //Felt
                output = glass_t[0];
              }
            }

    else if(layup==4){
            if (x>=0 && x<=0.0050){                 //Felt
                output = glass_t[0];
            }else if(x>0.0050 && x<=0.0051){        //Carbon Fiber
                output = glass_t[1];
            }else if(x>0.0051 && x<=0.0061){        //Epoxy
                output = glass_t[2];
            }else if(x>0.0061 && x<=0.0062){        //Carbon Fiber
                output = glass_t[1];
            }else if(x>0.0062 && x<=0.0072){        //Epoxy
                output = glass_t[2];
            }else if(x>0.0072 && x<=2.8072){        //Aluminium
                output = glass_t[3];
            }else if(x>2.8072 && x<=5.1928){        //Steel
                output = glass_t[4];
            }else if(x>5.1928 && x<=7.9928){        //Aluminium
                output = glass_t[3];
            }else if(x>7.9928 && x<=7.9938){        //Epoxy
                output = glass_t[2];
            }else if(x>7.9938 && x<=7.9939){        //Caxbon Fibex
                output = glass_t[1];
            }else if(x>7.9939 && x<=7.9949){        //Epoxy
                output = glass_t[2];
            }else if(x>7.9949 && x<=7.9950){        //Caxbon Fibex
                output = glass_t[1];
            }else if (x>7.9950 && x<=8.000){       //Felt
                output = glass_t[0];
              }else{                                //Felt
                output = glass_t[0];
              }
            }
	else{
		cout<<"Layup not found"<<endl;
		output = 0.0;
	}
      return output;
}


double heat::Define_Q(double x, int layup, int BC){
    double result;
    if(layup == 0){
	if(x == 0.0){    
    	result = 10e4/(21.5);
	}
	else{
		result = 2e4/(0.15);
	}
    }
    else if(layup==1){
         if (BC == 1){
            if (x == 0.0){
               result = (2e4)/(0.15);
               }
            else {result = 0.0;}
         }
         else {result = (2e4)/(0.15);}
    
        
    }else if(layup==2){
        if (BC == 1){
            if (x == 0.0){
               result = (4e4)/(0.15);
               }
            else {result = 0.0;}
        }
        else {result = (4e4)/(0.15);}
    
    
    }else if(layup==3){
        if (BC == 1){
        if (x == 0.0){
               result = (3.2e4)/(0.15);
               }
            else {result = 0.0;}
        }
        else {result = (3.2e4)/(0.15);}
    
    
    }else{
        if (BC == 1){
        if (x == 0.0){
               result = (5e4)/(0.15);
               }
            else {result = 0.0;}
        }
        else {result = (5e4)/(0.15);}
      }
    return result;
}

double heat::Define_Alpha(double x, int layup){
    //int layup = layup_det(theta);
    double output;
    if(layup == 0){
    	if(x<=4.0){ //2.0){
	     output = 21.5/(8000*510);
             //output = 0.15/(130*2e4);

	}
//	else if(x>=0.02 && x<=7.98){
		//output = 210/(2700*890);
                //output = 21.5/(8000*510);
 //               output = 0.15/(130*2e4);


                
//	}
	else{
             output = 0.15/(130*2e4);
	       //output = 21.5/(8000*510);
	}
    }
    else if(layup==1){
            if (x>=0 && x<=0.020){                //Felt
                output = alpha[0];
            }else if(x>0.020 && x<=0.025){        //Caxbon Fibex
                output = alpha[1];
            }else if(x>0.025 && x<=0.026){        //Epoxy
                output = alpha[2];
            }else if(x>0.026 && x<=0.034){        //Caxbon Fibex
                output = alpha[1];
            }else if(x>0.034 && x<=0.035){        //Epoxy
                output = alpha[2];
            }else if(x>0.035 && x<=2.035){        //Aluminium
                output = alpha[3];
            }else if(x>2.035 && x<=5.965){        //Steel
                output = alpha[4];
            }else if(x>5.965 && x<=7.965){        //Aluminium
                output = alpha[3];
            }else if(x>7.965 && x<=7.966){        //Epoxy
                output = alpha[2];
            }else if(x>7.966 && x<=7.974){        //Caxbon Fibex
                output = alpha[1];
            }else if(x>7.974 && x<=7.975){        //Epoxy
                output = alpha[2];
            }else if(x>7.975 && x<=7.980){        //Caxbon Fibex
                output = alpha[1];
            }else{                                //Felt
                output = alpha[0];
              }
            }

    else if(layup==2){
            if (x>=0 && x<=0.030){                //Felt
                output = alpha[0];
            }else if(x>0.030 && x<=0.033){        //Caxbon Fibex
                output = alpha[1];
            }else if(x>0.033 && x<=0.034){        //Epoxy
                output = alpha[2];
            }else if(x>0.034 && x<=0.046){        //Caxbon Fibex
                output = alpha[1];
            }else if(x>0.046 && x<=0.047){        //Epoxy
                output = alpha[2];
            }else if(x>0.047 && x<=2.047){        //Aluminium
                output = alpha[3];
            }else if(x>2.347 && x<=5.653){        //Steel
                output = alpha[4];
            }else if(x>5.653 && x<=7.953){        //Aluminium
                output = alpha[3];
            }else if(x>7.953 && x<=7.954){        //Epoxy
                output = alpha[2];
            }else if(x>7.954 && x<=7.966){        //Caxbon Fibex
                output = alpha[1];
            }else if(x>7.966 && x<=7.967){        //Epoxy
                output = alpha[2];
            }else if(x>7.967 && x<=7.970){        //Caxbon Fibex
                output = alpha[1];
            }else if(x>7.970 && x<=8.000){       //Felt
                output = alpha[0];
              }else{                                //Felt
                output = alpha[0];
              }
            }

    else if(layup==3){
            if (x>=0 && x<=0.020){                //Felt
                output = alpha[0];
            }else if(x>0.020 && x<=0.030){        //Caxbon Fibex
                output = alpha[1];
            }else if(x>0.030 && x<=0.031){        //Epoxy
                output = alpha[2];
            }else if(x>0.031 && x<=0.043){        //Caxbon Fibex
                output = alpha[1];
            }else if(x>0.043 && x<=0.044){        //Epoxy
                output = alpha[2];
            }else if(x>0.044 && x<=1.744){        //Aluminium
                output = alpha[3];
            }else if(x>1.744 && x<=6.256){        //Steel
                output = alpha[4];
            }else if(x>6.256 && x<=7.956){        //Aluminium
                output = alpha[3];
            }else if(x>7.956 && x<=7.957){        //Epoxy
                output = alpha[2];
            }else if(x>7.957 && x<=7.969){        //Caxbon Fibex
                output = alpha[1];
            }else if(x>7.969 && x<=7.970){        //Epoxy
                output = alpha[2];
            }else if(x>7.970 && x<=7.980){        //Caxbon Fibex
                output = alpha[1];
            }else if (x>7.980 && x<=8.000){       //Felt
                output = alpha[0];
              }else{                                //Felt
                output = alpha[0];
              }
            }

    else if(layup==4){
            if (x>=0 && x<=0.0050){                 //Felt
                output = alpha[0];
            }else if(x>0.0050 && x<=0.0051){        //Carbon Fiber
                output = alpha[1];
            }else if(x>0.0051 && x<=0.0061){        //Epoxy
                output = alpha[2];
            }else if(x>0.0061 && x<=0.0062){        //Carbon Fiber
                output = alpha[1];
            }else if(x>0.0062 && x<=0.0072){        //Epoxy
                output = alpha[2];
            }else if(x>0.0072 && x<=2.8072){        //Aluminium
                output = alpha[3];
            }else if(x>2.8072 && x<=5.1928){        //Steel
                output = alpha[4];
            }else if(x>5.1928 && x<=7.9928){        //Aluminium
                output = alpha[3];
            }else if(x>7.9928 && x<=7.9938){        //Epoxy
                output = alpha[2];
            }else if(x>7.9938 && x<=7.9939){        //Caxbon Fibex
                output = alpha[1];
            }else if(x>7.9939 && x<=7.9949){        //Epoxy
                output = alpha[2];
            }else if(x>7.9949 && x<=7.9950){        //Caxbon Fibex
                output = alpha[1];
            }else if (x>7.9950 && x<=8.000){       //Felt
                output = alpha[0];
              }else{                                //Felt
                output = alpha[0];
              }
            }
	else{
		cout<<"Layup not found"<<endl;
		output = 0.0;
	}
    return output;
    }
//----------------------------------------    
double heat::Define_Lambda(double x, int layup){
double result;
result = Define_Alpha(x,layup);
result  = result*dt/pow(dr,2);
return result;
} 

void heat::Define_Vars(int temp,double temp2,double temp3,double temp4,int layup, string filename){
 // cout << "Please type in the number of nodes N" << endl;
 //   cin >> N;
    Crystal_Flag = false;
    dt = temp2;
    ft = temp3;
    Nt = ceil(ft/dt); // Nt = dt/ft + 1
    Num_of_nodes = temp;
    avgcput = 0.0;
    N = temp;
    dr = (8.0 + (2*temp4))/(N-1);
    t = 0.0;
// Initializing r
    r.resize(N);
    r[0] = -temp4;
    
    for(int i=1;i<N;i++){
	r[i] = r[i-1] + dr;
    }

    heat::Print_Rfile();

// Initializing T
    T.resize(N);
    for(int i=0;i<N;i++){
	T[i].resize(5);
	for(int j=0;j<5;j++){
	T[i][j] = 200.0;
	}
}

// Initializing Told
    Told.resize(N);
    for(int i=0;i<N;i++){
	Told[i].resize(5);
	for(int j=0;j<5;j++){
	Told[i][j] = 200.0;
	}
}
// Initializing A
    A.resize(N);
    for(int i=0;i<N;i++){
	A[i].resize(3);
	for(int j=0;j<3;j++){
	A[i][j] = 0.0;
	}
}

// Initializing B
B.resize(N);

// Initializing Tg
Tg.resize(N);
for(int i=0;i<N;i++){
	Tg[i] = heat::Define_Tg(r[i],layup);
}
    //Assign elements here
    heat::File_Read(filename);

    for (int i = 0; i < 5; i++){
        alpha[i] = k[i]/(rho[i]*cp[i]);
        cout << "Alpha: " << alpha[i];
    }
}


