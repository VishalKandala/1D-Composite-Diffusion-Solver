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
    //define the variables that will be received for the solver

    int v = 0;  //verbose variable for solver output
    int N = 10; //Number of grid points. The larger the points, the finer the mesh for the solver
    double dt = 0.1;    //Time step size for the solver (seconds)
    double ft = 600;    //Final time that the solver will run to (seconds)
    int outfreq = 1000; //Frequency of output for solver iterations.
    string filename = "temp";	//Filename of the config file

    //verbose output?
    cout << "Please select the how verbose you would like the solver output:" << endl;
    cout << "1: Basic information." << endl;
    cout << "2: A matrix otput." << endl;
    cout << "3: B vector a every timestep." << endl;
    cin >> v;
    //number of grid points 
    cout << "How many grid points would you like? (More points equals a finer mesh.)" << endl;
    cin >> N;
    //time step size of solver
    cout << "How small would you like your time step size, in seconds?" << endl;
    cin >> dt;
    //final time that the solver stops at
    cout << "How long would you like to run the solver?, in seconds" << endl;
    cin >> ft;
    //outut frequency of the solver data saving 
    cout << "How often would you like the solver to save the data? (Save every X iterations.)" << endl;
    cin >> outfreq;
    //ask the user for the filename of the config file for material properties!
    cout << "What is the name of the config file of material properties?" << endl;
    cin >> filename;


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
