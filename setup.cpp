// 11/22 Mingxin, 11/25 Vishal Indivar Kandala
// MEEN 689 Computing Concepts Project 3
#include <cmath>
#include <iostream>
#include <vector>
#include "heat.hpp"
using namespace std;
//using namespace heat;

namespace heat {
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
                output = 0.15/(130*2e4);
            }else if(x>0.020 && x<=0.025){        //Caxbon Fibex
                output = 10.0/(1850*1100);
            }else if(x>0.025 && x<=0.026){        //Epoxy
                output = 0.44/(300*1730);
            }else if(x>0.026 && x<=0.034){        //Caxbon Fibex
                output = 10.0/(1850*1100);
            }else if(x>0.034 && x<=0.035){        //Epoxy
                output = 0.44/(300*1730);
            }else if(x>0.035 && x<=2.035){        //Aluminium
                output = 210.0/(2700*890);
            }else if(x>2.035 && x<=5.965){        //Steel
                output = 21.5/(8000*510);
            }else if(x>5.965 && x<=7.965){        //Aluminium
                output = 210.0/(2700*890);
            }else if(x>7.965 && x<=7.966){        //Epoxy
                output = 0.44/(300*1730);
            }else if(x>7.966 && x<=7.974){        //Caxbon Fibex
                output = 10.0/(1850*1100);
            }else if(x>7.974 && x<=7.975){        //Epoxy
                output = 0.44/(300*1730);
            }else if(x>7.975 && x<=7.980){        //Caxbon Fibex
                output = 10.0/(1850*1100);
            }else{                                //Felt
                output = 0.15/(130*2e4);
              }
            }

    else if(layup==2){
            if (x>=0 && x<=0.030){                //Felt
                output = 0.15/(130*2e4);
            }else if(x>0.030 && x<=0.033){        //Caxbon Fibex
                output = 10.0/(1850*1100);
            }else if(x>0.033 && x<=0.034){        //Epoxy
                output = 0.44/(300*1730);
            }else if(x>0.034 && x<=0.046){        //Caxbon Fibex
                output = 10.0/(1850*1100);
            }else if(x>0.046 && x<=0.047){        //Epoxy
                output = 0.44/(300*1730);
            }else if(x>0.047 && x<=2.047){        //Aluminium
                output = 210.0/(2700*890);
            }else if(x>2.347 && x<=5.653){        //Steel
                output = 21.5/(8000*510);
            }else if(x>5.653 && x<=7.953){        //Aluminium
                output = 210.0/(2700*890);
            }else if(x>7.953 && x<=7.954){        //Epoxy
                output = 0.44/(300*1730);
            }else if(x>7.954 && x<=7.966){        //Caxbon Fibex
                output = 10.0/(1850*1100);
            }else if(x>7.966 && x<=7.967){        //Epoxy
                output = 0.44/(300*1730);
            }else if(x>7.967 && x<=7.970){        //Caxbon Fibex
                output = 10.0/(1850*1100);
            }else if(x>7.970 && x<=8.000){       //Felt
                output = 0.15/(130*2e4);
              }else{                                //Felt
                output = 0.15/(130*2e4);
              }
            }

    else if(layup==3){
            if (x>=0 && x<=0.020){                //Felt
                output = 0.15/(130*2e4);
            }else if(x>0.020 && x<=0.030){        //Caxbon Fibex
                output = 10.0/(1850*1100);
            }else if(x>0.030 && x<=0.031){        //Epoxy
                output = 0.44/(300*1730);
            }else if(x>0.031 && x<=0.043){        //Caxbon Fibex
                output = 10.0/(1850*1100);
            }else if(x>0.043 && x<=0.044){        //Epoxy
                output = 0.44/(300*1730);
            }else if(x>0.044 && x<=1.744){        //Aluminium
                output = 210.0/(2700*890);
            }else if(x>1.744 && x<=6.256){        //Steel
                output = 21.5/(8000*510);
            }else if(x>6.256 && x<=7.956){        //Aluminium
                output = 210.0/(2700*890);
            }else if(x>7.956 && x<=7.957){        //Epoxy
                output = 0.44/(300*1730);
            }else if(x>7.957 && x<=7.969){        //Caxbon Fibex
                output = 10.0/(1850*1100);
            }else if(x>7.969 && x<=7.970){        //Epoxy
                output = 0.44/(300*1730);
            }else if(x>7.970 && x<=7.980){        //Caxbon Fibex
                output = 10.0/(1850*1100);
            }else if (x>7.980 && x<=8.000){       //Felt
                output = 0.15/(130*2e4);
              }else{                                //Felt
                output = 0.15/(130*2e4);
              }
            }

    else if(layup==4){
            if (x>=0 && x<=0.0050){                 //Felt
                output = 0.15/(130*2e4);
            }else if(x>0.0050 && x<=0.0051){        //Carbon Fiber
                output = 10.0/(1850*1100);
            }else if(x>0.0051 && x<=0.0061){        //Epoxy
                output = 0.44/(300*1730);
            }else if(x>0.0061 && x<=0.0062){        //Carbon Fiber
                output = 10.0/(1850*1100);
            }else if(x>0.0062 && x<=0.0072){        //Epoxy
                output = 0.44/(300*1730);
            }else if(x>0.0072 && x<=2.8072){        //Aluminium
                output = 210.0/(2700*890);
            }else if(x>2.8072 && x<=5.1928){        //Steel
                output = 21.5/(8000*510);
            }else if(x>5.1928 && x<=7.9928){        //Aluminium
                output = 210.0/(2700*890);
            }else if(x>7.9928 && x<=7.9938){        //Epoxy
                output = 0.44/(300*1730);
            }else if(x>7.9938 && x<=7.9939){        //Caxbon Fibex
                output = 10.0/(1850*1100);
            }else if(x>7.9939 && x<=7.9949){        //Epoxy
                output = 0.44/(300*1730);
            }else if(x>7.9949 && x<=7.9950){        //Caxbon Fibex
                output = 10.0/(1850*1100);
            }else if (x>7.9950 && x<=8.000){       //Felt
                output = 0.15/(130*2e4);
              }else{                                //Felt
                output = 0.15/(130*2e4);
              }
            }
	else{
		cout<<"Layup not found"<<endl;
		output = 0.0;
	}
    return output;
    }
double heat::Define_Lambda(double x, int layup){
double result;
result = Define_Alpha(x,layup);
result  = result*dt/pow(dr,2);
return result;
}

/*
int heat::layup_det(double theta){
    if(theta>=0 && theta<90){
        return 1;
    }else if(theta>=180 && theta<270){
        return 1;
    }else{
        return 2;
    }
}
*/
 

void heat::Define_Vars(int temp,double temp2,double temp3, double temp4){
 // cout << "Please type in the number of nodes N" << endl;
 //   cin >> N;
    dt = temp2;
    ft = temp3;
    Nt = ceil(ft/dt); // Nt = dt/ft + 1
    Num_of_nodes = temp;
    avgcput = 0.0;
    N = temp;
    dr = (8.0+(2*temp4))/(N-1);
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
	T[i][j] = 200;
	}
}

// Initializing Told
    Told.resize(N);
    for(int i=0;i<N;i++){
	Told[i].resize(5);
	for(int j=0;j<5;j++){
	Told[i][j] = 200;
	}
}
// Initializing A
    A.resize(N);
    for(int i=0;i<N;i++){
	A[i].resize(3);
	for(int j=0;j<3;j++){
	A[i][j] = 0;
	}
}

// Initializing B
B.resize(N);

}


// if add more features
// 

//  namespace heat{
    //add new things, the previously defined variables and methods won't disappear
//(Num_of_nodes,0);

//}


//Test
/*
int main(int argc, char **argv){
    using namespace heat;
    //double re = dr();
    //cout << re << endl;
    define_vars();
    cout << heat_flux(30.0) << endl;
    cout << Num_of_nodes << endl;
    cout << dr << endl;
    return 0;
}
*/

