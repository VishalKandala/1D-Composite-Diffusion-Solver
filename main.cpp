// 11/22 Vishal Indivar Kandala
// MEEN 689 Computing Concepts Project 3
#include<iostream>
#include<cmath>
#include "heat.hpp"
using namespace std;
int main(int argc, char **argv){


	// Interface with the user for solver configuration using the terminal command line
	
	// create the structure that stores the solver parameters
	heat::userParams solverParams;
	// call the function that gets user inputs on the command line and will return the solver parameters to run
	solverParams = heat::askUserParams();

	// define the variables that will be received for the solver
	int v = solverParams.v;
	int N = solverParams.N;
	double dt = solverParams.dt;
	double ft = solverParams.ft;
	int outfreq = solverParams.outfreq;
	string filename = solverParams.filename;
	int layup = solverParams.layup;
	int BC = solverParams.BC;
	double felt_Add = solverParams.felt_Add;
	
	//config file check (temporary, remove later!)
	cout << "Config file name: " << filename << endl;
    
    heat::Define_Vars(N,dt,ft,felt_Add,layup);
    //-------------------
    if(v==1){
    // Print out basic info when v = 1
    cout<<"Lambda: "<<heat::Define_Lambda(heat::r[50],layup)<<endl;
    cout << "Number of Nodes: "<<heat::Num_of_nodes << endl;
    cout << "Grid size: "<<heat::dr << endl;
    cout<<"Time step: "<<heat::dt<<endl;
    cout<<"Final time: "<<heat::ft<<endl;
    cout<<"No.of Time steps: "<<heat::Nt<<endl;
    cout << "Heat Flux/Conductivity at boundary: "<<heat::Define_Q(heat::r[0],layup,BC) << endl;
    }
    //-------------------
    // Time loop
    heat::Print_File(0,0);
    heat::Form_A(layup,v);
    int it2 = 0; 
    for(int it = 1;it<=heat::Nt;it++){
    if(heat::Crystal_Flag == false){
    // Advance the solution by one Timestep(dt)	   
    heat::Advance_dt(layup,v,it,BC);
    // Update solution monitor time t.
    heat::t+=heat::dt;
    // If statement for outputting to file
    //cout<<it2<<endl;
    if(it%outfreq == 0){
    // Print solution at t to file.
    heat::Print_File(it,0);
    // Print the simulation monitor time.
    cout<<"t = "<<heat::t<<endl;
    	}
    }
    it2 = it;
    if(heat::Crystal_Flag == true){break;}
    }
    if(heat::Crystal_Flag == true){
	   if(v==1){ 
	    cout<<"Crystallization Temperature reached at time:"<<heat::t<<endl;
	   }
	   heat::Print_File(it2,0);
    }
    else{
    if(v==1){
    cout<<"Average CPU Time for T_Solve in ms: "<<heat::avgcput/heat::Nt<<endl;
    }
    }
  

return 0;
}
