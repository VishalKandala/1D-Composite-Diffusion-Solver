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

double heat::Define_Q(int layup){
    double result;
    if(layup==1){
        result = (2e4/(130*20000));
    }else if(layup==2){
        result = (4e4/(130*20000));
    }
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
double heat::Define_Alpha(double r, int layup){
    //int layup = layup_det(theta);
    double result;
    if(layup==1){
        if(r<=0){
            if (r>=-2 && r<=-1.99){
                result = 0.15/(130*2e4);
            }else if(r>-1.99 && r<=-1.965){
                result = 10/(1850*1100);
            }else if(r>-1.965 && r<=-1.96){
                result = 0.44/(300*1730);
            }else if(r>-1.96 && r<=-1.92){
                result = 10/(1850*1100);
            }else if(r>-1.92 && r<=-1.915){
                result = 0.44/(300*1730);
            }else if(r>-1.915 && r<=-0.915){
                result = 210/(2700*890);
            }else{
                result = 21.5/(8000*510);
            }
        }else if(r>=0){
            if(r<=2 && r>1.99){
                result = 0.15/(130*2e4);
            }else if(r<=1.99 && r>1.965){
                result = 10/(1850*1100);
            }else if(r<=1.965 && r>1.96){
                result = 0.44/(300*1730);
            }else if(r<=1.96 && r>1.92){
                result = 10/(1850*1100);
            }else if(r<=1.92 && r>1.915){
                result = 0.44/(300*1730);
            }else if(r<=1.915 && r>0.915){
                result = 210/(2710*890);
            }else{
                result = 21.5/(8000*510);
            }
        }
    }
    if(layup==2){
        if(r<=0){
            if (r>=-2 && r<=-1.985){
                result = 0.15;
            }else if(r>-1.985 && r<=-1.97){
                result = 10;
            }else if(r>-1.97 && r<=-1.965){
                result = 0.44;
            }else if(r>-1.965 && r<=-1.905){
                result = 10;
            }else if(r>-1.905 && r<=-1.9){
                result = 0.44;
            }else if(r>-1.9 && r<=-0.75){
                result = 210;
            }else{
                result = 21.5;
            }
        }else if(r>=0){
            if(r<=2 && r>1.985){
                result = 0.15/(130*2e4);
            }else if(r<=1.985 && r>1.97){
                result = 10/(1850*1100);
            }else if(r<=1.97 && r>1.965){
                result = 0.44/(300*1730);
            }else if(r<=1.965 && r>1.905){
                result = 10/(1850*1100);
            }else if(r<=1.905 && r>1.9){
                result = 0.44/(300*1730);
            }else if(r<=1.9 && r>0.75){
                result = 210/(2710*890);
            }else{
                result = 21.5/(8000*510);
            }
        }        
    }
    return result;
} 

void heat::Define_Vars(int temp,double temp2,double temp3){
 // cout << "Please type in the number of nodes N" << endl;
 //   cin >> N;
    dt = temp2;
    ft = temp3;
    Nt = ceil(ft/dt); // Nt = dt/ft + 1
    Num_of_nodes = temp;
    avgcput = 0.0;
    N = temp;
    dr = 2.0/(N-1);
    t = 0.0;
// Initializing r
    r.resize(N);
    r[0] = 0;
    
    for(int i=1;i<N;i++){
	r[i] = r[i-1] + dr;
    }

// Initializing T
    T.resize(N);
    for(int i=0;i<N;i++){
	T[i].resize(8);
	for(int j=0;j<8;j++){
	T[i][j] = 200;
	}
}

// Initializing Told
    Told.resize(N);
    for(int i=0;i<N;i++){
	Told[i].resize(8);
	for(int j=0;j<8;j++){
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

