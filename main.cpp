#include<iostream>
#include<cmath>
#include "init.hpp"
using namespace std;
int main(int argc, char **argv){
    // v for verbose: when v = 1, basic info
    // v = 2
//    using namespace heat;

    int temp = stoi(argv[1]); 
    double temp2 = stod(argv[2]);
    int v = stoi(argv[3]);
    int layup;
    layup = 1;
    //double re = dr();
    //cout << temp2 << endl;
    heat::define_vars(temp,temp2);
    //-------------------
    if(v==1){
    cout << "Number of Nodes: "<<heat::Num_of_nodes << endl;
    cout << "Grid size: "<<heat::dr << endl;
    cout<<"Time step: "<<heat::dt<<endl;
    cout << "Heat Flux: "<<heat::heat_flux(layup) << endl;
    }
    //-------------------
    heat::formA(layup,v);
    heat::formB(layup,v);
    heat::TDMA(layup);

return 0;
}
