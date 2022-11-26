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
    double temp3 = stod(argv[3]);
    int v = stoi(argv[3]);
    int layup;
    layup = 1;
    //double re = dr();
    //cout << temp2 << endl;
    heat::Define_Vars(temp,temp2,temp3);
    //-------------------
    if(v==1){
    cout << "Number of Nodes: "<<heat::Num_of_nodes << endl;
    cout << "Grid size: "<<heat::dr << endl;
    cout<<"Time step: "<<heat::dt<<endl;
    cout<<"Final time: "<<heat::ft<<endl;
    cout<<"No.of Time steps: "<<heat::Nt<<endl;
    cout << "Heat Flux: "<<heat::Define_Q(layup) << endl;
    }
    //-------------------
    // Time loop
    for(int it = 0;it<heat::Nt;it++){
    heat::Advance_dt(layup,v);
    heat::t+=heat::dt;
    cout<<"t = "<<heat::t<<endl;
    }

return 0;
}
