// 11/22 Vishal Indivar Kandala
// MEEN 689 Computing Concepts Project 3
#ifndef INIT_H
#define INIT_H
#include<vector>
// Naming convention for functions:
// 	Action_Changedvariable()
using namespace std;

namespace heat {
    // functions
    void Print_File(int it,int interactive);
    double Define_Q(int layup);
    double Define_Alpha(double r, int layup);
    void Define_Vars(int temp,double temp2,double temp3);
    void Print_Rfile();
    void Form_A(int layup,int v);
    void Form_B(int layup,int v, int it);
    void Solve_T(int layup,int v,int it);
    void Advance_dt(int layup,int v,int it);
    void Push_T(int layup);
    // vars
    extern double dr;
    extern int Num_of_nodes;
    extern int N;
    extern int Nt;
    extern double ft;
    extern double dt;
    extern double t;
    extern double avgcput;
    extern vector<vector<double>> T; 
    extern vector<vector<double>> Told; 
    extern vector<vector<double>> A; 
    extern vector<double> B; 
    extern vector<double> r;

}

#endif

