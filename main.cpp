#include<iostream>
#include<cmath>
#include "init.h"

int main(int argc, char **argv){
    using namespace heat;
    //double re = dr();
    //cout << re << endl;
    define_vars();
    cout << heat_flux(2) << endl;
    cout << Num_of_nodes << endl;
    cout << dr << endl;

return 0;
}
