#include<vector>
using namespace std;

namespace initialization {
    double dt;
    double heat_flux(int layup);
    double alpha(double r, int layup);
    //double dr(); 
    double dr;
    int Num_of_nodes;
    int N;
    void define_vars();
    void formA(int layup);
    void formB(int layup,int v);
    void TDMA(int layup);
   // void formA(int layup, int v);
    vector<vector<double>> T(Num_of_nodes, vector<double>(8));
    vector<vector<double>> Told(Num_of_nodes, vector<double>(8));
    vector<vector<double>> A(Num_of_nodes, vector<double>(3));
    vector<double> B(Num_of_nodes);


} 
