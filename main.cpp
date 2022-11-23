#include<iostream>
#include<cmath>
#include "init.h"
using namespace std;
int main(int argc, char **argv){
    // v for verbose: when v = 1, basic info
    // v = 2
    using namespace heat;

    int temp = atoi(argv[1]); 
    int v = atoi(argv[2]);
    int layup;
    layup = 1;
    //double re = dr();
    //cout << re << endl;
    define_vars(temp);
    //-------------------
    if(v){
    cout << heat_flux(layup) << endl;
    cout << Num_of_nodes << endl;
    cout << dr << endl;
    cout<<N<<endl;
    }
    //-------------------
    formA(layup,v);


return 0;
}
