#include<iostream>
#include<cmath>
//#include "initialization.cpp"
//#include "solver.cpp"
//using namespace std;
//using namespace initialization;

int main(int argc, char **argv){
    using namespace initialization;
    //double re = dr();
    //cout << re << endl;
    define_vars();
    cout << heat_flux(1) << endl;
    cout << Num_of_nodes << endl;
    cout << dr << endl;
return 0;
}
