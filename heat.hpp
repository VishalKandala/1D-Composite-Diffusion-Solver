// 11/22 Vishal Indivar Kandala
// MEEN 689 Computing Concepts Project 3
// Edited by: Thomas Firsich
// Last Edited: 11/29

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
    void Form_A(int layup,int v);
    void Form_B(int layup,int v);
    void Solve_T(int layup,int v);
    void Advance_dt(int layup,int v);
    void Push_T(int layup);
    
    
    // vars
    //Structure for the file reading operation
    /*typedef struct information{
        int count;
        vector <string> headers;
        vector <string> vals;
    }inf;
    void File_Read(inf* info, string filename);*/
    
    typedef struct{
        int v, N, outfreq;
        double dt, ft;
        string filename;
    } userParams;
    extern userParams solverParams;
    userParams askUserParams();
    extern double dr;
    extern int Num_of_nodes;
    extern int v;
    extern int outfreq;
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

