#include <cmath>
#include <iostream>

using namespace std;

namespace initialization {
    double dt = 0.001;
    double heat_flux(double theta);
    int layup_det(double theta);
    double alpha(double r, double theta);

}

double initialization::heat_flux(double theta){
    int layup = layup_det(theta);
    if(layup==1){
        return 2e4/0.15;
    }else if(layup==2){
        return 4e4/0.15;
    }
}

int layup_det(double theta){
    if(theta>=0 && theta<90){
        return 1;
    }else if
}
