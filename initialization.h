#include<vector>
using namespace std;

namespace initialization {
    // functions
    double heat_flux(int layup);
    double alpha(double r, int layup);
    void define_vars();
    void formA(int layup);
    void formB(int layup,int v);
    void TDMA(int layup);
    
    // vars
    extern double dr;
    extern int Num_of_nodes;
    extern int N;
    extern double dt;
    extern vector<vector<double>> T; //(Num_of_nodes, vector<double>(8));
    extern vector<vector<double>> Told; //(Num_of_nodes, vector<double>(8));
    extern vector<vector<double>> A; //(Num_of_nodes, vector<double>(3));
    extern vector<double> B; //(Num_of_nodes);


} 
