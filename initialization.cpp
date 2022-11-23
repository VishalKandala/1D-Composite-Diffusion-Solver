#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

namespace initialization {
    double dt = 0.001;
    double heat_flux(double theta);
    int layup_det(double theta);
    double alpha(double r, double theta);
    //double dr(); 
    double dr;
    int Num_of_nodes;
    void define_vars();
    vector<vector<double>> T(Num_of_nodes, vector<double>(8));
    vector<vector<double>> Told(Num_of_nodes, vector<double>(8));
}

double initialization::heat_flux(int layup){
    double result;
    if(layup==1){
        result == (2e4/0.15);
    }else if(layup==2){
        result == (4e4/0.15);
    }
    return result;
}

int initialization::layup_det(double theta){
    if(theta>=0 && theta<90){
        return 1;
    }else if(theta>=180 && theta<270){
        return 1;
    }else{
        return 2;
    }
}

double initialization::alpha(double r, double theta){
    int layup = layup_det(theta);
    double result;
    if(layup==1){
        if(r<=0){
            if (r>=-2 && r<=-1.99){
                result == 0.15/(130*2e4);
            }else if(r>-1.99 && r<=-1.965){
                result == 10/(1850*1100);
            }else if(r>-1.965 && r<=-1.96){
                result == 0.44/(300*1730);
            }else if(r>-1.96 && r<=-1.92){
                result == 10/(1850*1100);
            }else if(r>-1.92 && r<=-1.915){
                result == 0.44/(300*1730);
            }else if(r>-1.915 && r<=-0.915){
                result == 210/(2700*890);
            }else{
                result == 21.5/(8000*510);
            }
        }else if(r>=0){
            if(r<=2 && r>1.99){
                result == 0.15/(130*2e4);
            }else if(r<=1.99 && r>1.965){
                result == 10/(1850*1100);
            }else if(r<=1.965 && r>1.96){
                result == 0.44/(300*1730);
            }else if(r<=1.96 && r>1.92){
                result == 10/(1850*1100);
            }else if(r<=1.92 && r>1.915){
                result == 0.44/(300*1730);
            }else if(r<=1.915 && r>0.915){
                result == 210/(2710*890);
            }else{
                result == 21.5/(8000*510);
            }
        }
    }
    if(layup==2){
        if(r<=0){
            if (r>=-2 && r<=-1.985){
                result == 0.15;
            }else if(r>-1.985 && r<=-1.97){
                result == 10;
            }else if(r>-1.97 && r<=-1.965){
                result == 0.44;
            }else if(r>-1.965 && r<=-1.905){
                result == 10;
            }else if(r>-1.905 && r<=-1.9){
                result == 0.44;
            }else if(r>-1.9 && r<=-0.75){
                result == 210;
            }else{
                result == 21.5;
            }
        }else if(r>=0){
            if(r<=2 && r>1.985){
                result == 0.15/(130*2e4);
            }else if(r<=1.985 && r>1.97){
                result == 10/(1850*1100);
            }else if(r<=1.97 && r>1.965){
                result == 0.44/(300*1730);
            }else if(r<=1.965 && r>1.905){
                result == 10/(1850*1100);
            }else if(r<=1.905 && r>1.9){
                result == 0.44/(300*1730);
            }else if(r<=1.9 && r>0.75){
                result == 210/(2710*890);
            }else{
                result == 21.5/(8000*510);
            }
        }        
    }
    return result;
} 

// double initialization::dr(){
//     cout << "Please type in the number of nodes N" << endl;
//     double N;
//     cin >> N;
//     Num_of_nodes = N;
//     double delta = 4/(N-1);
//     return delta;
// }

void initialization::define_vars(){
    cout << "Please type in the number of nodes N" << endl;
    int N;
    cin >> N;
    Num_of_nodes = N;
    dr = 4.0/(N-1);
}


// if add more features
namespace initialization{
    //add new things, the previously defined variables and methods won't disappear
    vector<vector<double>> A(Num_of_nodes, vector<double>(3));
    vector<double> B(Num_of_nodes);

}


//Test
/*
int main(int argc, char **argv){
    using namespace initialization;
    //double re = dr();
    //cout << re << endl;
    define_vars();
    cout << heat_flux(30.0) << endl;
    cout << Num_of_nodes << endl;
    cout << dr << endl;
    return 0;
}
*/

