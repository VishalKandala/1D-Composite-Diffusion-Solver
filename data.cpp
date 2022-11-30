//Vishal Indivar Kandala
// MEEN 689 Computing Concepts Project 3
// Last Edited: 11/29 Thomas Firsich
// Edits: Remove the file read function. Using command line to get solver parameters now. 

#include<iostream>
#include<fstream>
#include<sstream>
#include "heat.hpp"

using namespace std;

// This file is used to read an input file for the user to run the solver
// Please follow the structure of the file to ensure the code runs as intended!!
/*
void heat::File_Read(inf* info, string filename){
	//Verbose meaning how much you want to know about your output
	//int v;
	//N for grid size
	//int N;
	//dt for time step size
	//double dt;
	//ft for simulation interval
	//double ft;
	//outfreq for frequency to output to a file for post-processing
	//int outfreq;


	//Initialize a string variable for the line that will be read
	string line;
	//open the file
	ifstream myfile (filename);
	
	if (myfile.is_open()){
		//Get the first line
		getline(myfile, line);
		//Calculate the number of columsn, which should equal the number of variables assigned for the solver
		int count = 0;
		for(int i = 0; i < line.size(); i++){
			if(line[i] == ','){
				count = count + 1;
			}
		}
		//Number of columns is more than the number of commas
		count = count + 1;
		info->count = count;
		//Reset the ifstream back to the first line
		myfile.clear();
		myfile.seekg(0);
		//Loop through the columns of the first row to read the variables in the header
		getline(myfile,line);
		stringstream tempstring1(line);
		for (int i = 0; i < count; i++){
			string temp;
			getline(tempstring1, temp, ',');
			info->headers.push_back(temp);
		}
		//Loop through the columns of the second row for assigning the correct variables
		getline(myfile, line);
		stringstream tempstring2(line);
		for (int i = 0; i < info->count; i++){
			string temp2;
			getline(tempstring2, temp2, ',');
			info->vals.push_back(temp2);
		}
		//Now that we have the array of headers, assign the variables accordingly 
		for (int i = 0; i <= (info->count); i++){
			if (info->headers[i] == "v"){
				v = stoi(info->vals[i]);
			} 
			else if(info->headers[i] == "N"){
				N = stoi(info->vals[i]);
			}
			else if(info->headers[i] == "dt"){
				dt = stod(info->vals[i]);
			}
			else if(info->headers[i] == "ft"){
				ft = stod(info->vals[i]);
			}
			else if(info->headers[i] == "outfreq"){
				outfreq = stoi(info->vals[i]);
			}
			//else if(info->headers[i] == "layup"){
			//	layup = info->vals[i];
			//}
			else{
				cout << "Error reading in the solver variabels from file " << filename << endl;
			}
		}
	}
}
*/


Struct heat::askUserParams(){
	Struct s;

	//verbose output?
    cout << "Please select the how verbose you would like the solver output:" << endl;
    cout << "1: Basic information." << endl;
    cout << "2: A matrix otput." << endl;
    cout << "3: B vector a every timestep." << endl;
    cin >> s.v;
    //number of grid points 
    cout << "How many grid points would you like? (More points equals a finer mesh.)" << endl;
    cin >> s.N;
    //time step size of solver
    cout << "How small would you like your time step size, in seconds?" << endl;
    cin >> s.dt;
    //final time that the solver stops at
    cout << "How long would you like to run the solver?, in seconds" << endl;
    cin >> s.ft;
    //outut frequency of the solver data saving 
    cout << "How often would you like the solver to save the data? (Save every X iterations.)" << endl;
    cin >> s.outfreq;
	//ask the user for the filename of the config file for material properties!
	cout << "What is the name of the config file of material properties?" << endl;
	cin >> s.filename;

	return s;
}


void heat::Print_File(int it,int interactive){
	ofstream outputfile;
	string ofilename;
	stringstream ss;
	ss << it;
	if(interactive){
	cout<<"Name of output file:"<<endl;
	cin>>ofilename;
	}
	else{
	ofilename = "data/t_profile_" + ss.str()+".csv";
	}
	outputfile.open(ofilename);
	int length = heat::T.size();
	int count = heat::T[0].size();
	string print;
	if(outputfile.is_open()){

// Print Headers
	for(int j=0;j<count;j++){
		if(j == (count-1)){
			outputfile<<j<<endl;
		}
		else{
			outputfile<<j<<",";
		}
	}


//Ask if user wants to print subheaders to file
//cout<<"Print Subheaders?(y/n)"<<endl;
//cin>>print;
//if(print == "y" || print == "yes" || print =="Y"){
// Print subeaders
//	for(int i=0;i<count;i++){
//		if(i == (count-1)){
//			outputfile<<info->subheaders[i]<<endl;
//		}
//		else{
//			outputfile<<info->subheaders[i]<<",";
//		}
//	}
//}


// Print values
	for(int i = 0; i<length; i++){
		for(int j = 0;j<count;j++){
			if(j == ((count)-1)){
				outputfile << heat::T[i][j] << endl;
			}
			else{
				outputfile << heat::T[i][j] << ',';
			}
		}
	}
outputfile.close();
}
}


