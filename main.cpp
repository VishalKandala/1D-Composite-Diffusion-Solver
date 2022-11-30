// 11/22 Vishal Indivar Kandala
// MEEN 689 Computing Concepts Project 3
// Last Edited: 11/29 Thomas Firsich
// Edits: Replaced the input file reading and use the command line terminal to ask 
//			user what the solver configuration should be.


#include<iostream>
#include<cmath>
#include "heat.hpp"
using namespace std;
int main(int argc, char **argv){
    

    // Interface with the user for solver configuration using the terminal command line.
    
    //Attempt to create the user interface function
    heat::userParams solverParams;
    solverParams = heat::askUserParams();

    //define the variables that will be received for the solver
    int v = solverParams.v;  //verbose variable for solver output
    int N = solverParams.N; //Number of grid points. The larger the points, the finer the mesh for the solver
    double dt = solverParams.dt;    //Time step size for the solver (seconds)
    double ft = solverParams.ft;    //Final time that the solver will run to (seconds)
    int outfreq = solverParams.outfreq; //Frequency of output for solver iterations.
    string filename = solverParams.filename; //File name of the config file for material properties

    int layup;
    layup = 1;

    // Run the file read function that will read the input file to assign the variables for the solver
    // No longer needed to define variables!!
    heat::Define_Vars(N,dt,ft);
    //Read the file name from the command line input
    //string filename = argv[1];
    //Call function to read the file, sending the filename...
    //heat::File_Read(filename);

    //-------------------
    if(v==1){
    // Print out basic info when v = 1
    cout << "Number of Nodes: "<<heat::Num_of_nodes << endl;
    cout << "Grid size: "<<heat::dr << endl;
    cout<<"Time step: "<<heat::dt<<endl;
    cout<<"Final time: "<<heat::ft<<endl;
    cout<<"No.of Time steps: "<<heat::Nt<<endl;
    cout << "Heat Flux: "<<heat::Define_Q(layup) << endl;
    }


    //-------------------
    // Time loop
    heat::Print_File(0,0);
    heat::Form_A(layup,v); 
    for(int it = 1;it<=heat::Nt;it++){
    // Advance the solution by one Timestep(dt)	    
    heat::Advance_dt(layup,v);
    // Update solution monitor time t.
    heat::t+=heat::dt;
    // If statement for outputting to file
    if(it%outfreq == 0){
    // Print solution at t to file.
    heat::Print_File(it,0);
    // Print the simulation monitor time.
    cout<<"t = "<<heat::t<<endl;
    	}
    }
    if(v==1){
    cout<<"Average CPU Time for T_Solve in ms: "<<heat::avgcput/heat::Nt<<endl;
    }
  

return 0;
}
