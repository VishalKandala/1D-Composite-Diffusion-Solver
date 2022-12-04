//Vishal Indivar Kandala
// MEEN 689 Computing Concepts Project 3
#include<iostream>
#include<fstream>
#include<sstream>
#include "heat.hpp"

using namespace std;

void heat::File_Read(string filename){
	string line;
	vector<string> ROW
	int rows = 0;
	int cols = 2; //There will ALWAYS only be 2 columns (one for variable name and one for value)
	// Open the file
	ifstream myfile (filename);
	if (myfile.is_open()){
		// Get the first line
		getline(myfile, line);
		// Calculate the number of rows
		while (getline(myfile, line)){
			rows = rows + 1;
		}
		myfile.clear();
		myfile.seekg(0);

		cout << "# of rows: " << rows << endl;
		cout << "# of cols: " << cols << endl;
		// Parse through the lines of the config file and assign the variables 
		for (int i = 0; i <= rows; i++){
		getline(myfile, line);
		stringstream tempstring1(line);
		cout << "Row #: " << i << endl;
			for (int j = 0; j < cols; j++){
				cout << "looping through line: " << j << endl;
				string temp;
				getline(tempstring1, temp, ',');
				cout << "Reading: " << temp << endl;
				//heat::Assign_MatConfig(i, temp);
			}

		cout << "Variable: " << tempstring1 << endl;
		//cout << "Value: " << tempstring1[1] << endl;
		}
	}
}


void heat::Assign_MatConfig(int config_it, string variable){

}

heat::userParams heat::askUserParams(){
	//Define the structure to be populated in this function
	userParams s;
	//define the string for the BC answer
	string answer = "n";
	
	//verbose output
	cout << "Please select how verbose you would like the solver output:" << endl;
	cout << "1: Basic information." << endl;
	cout << "2: Output matrix A." << endl;
	cout << "3: Output vector B at every timestep." << endl;
	cin >> s.v;
	//number of grid points
	cout << "How many grid points would you like? (More points equals a finer mesh)" << endl;
	cin >> s.N;
	//time step size for solver 
	cout << "How small would you like your time step size? (seconds)" << endl;
	cin >> s.dt;
	//final time that the solver will stop at
	cout << "How long would you like to run the solver? (seconds)" << endl;
	cin >> s.ft;
	//output frequency of the solver data saving
	cout << "How often would you like the solver to save the data? (Save every X iterations)" << endl;
	cin >> s.outfreq;
	//ask the user for the filename of the config file of material properties 
	cout << "What is the name of the config file containing the necessary material properties?" << endl;
	cin >> s.filename;
	//create some space to break up the command line 
	cout << "" << endl;
	cout << "" << endl;
	//figure out which material layup the user wants to check
	cout << "Which material layup would you like to check? (1-4)" << endl;
	cin >> s.layup;
	//Check what boundary condition is being tested
	cout << "What boundary condition are you testing?" << endl;
	cout << "BC1: Heat flux applied to one boundary." << endl;
	cout << "BC2: Symmetric heat flux along the surface." << endl;
	cout << "Input 1 for BC1 and 2 for BC2..." << endl;
	cin >> s.BC;
	//Check if BC2, then ask if they would like to add felt
	if (s.BC == 2){
		cout << "Would you like to add more felt insulation? (y/n)" << endl;
		cin >> answer;
		if ((answer == "y") || (answer == "Y") || (answer == "yes")){
		cout << "Specify the thickness of felt insulation to be added. (meters)" << endl;
		cin >> s.felt_Add;
		}
	}
	return s;
}

void heat::Print_Rfile(){
	ofstream outputfile;
	string ofilename = "data/r.csv";
	outputfile.open(ofilename);
	int length = heat::r.size();
	if(outputfile.is_open()){

// Print values
	for(int i = 0; i<length; i++){
			if(i == ((length)-1)){
				outputfile << heat::r[i] << endl;
			}
			else{
				outputfile << heat::r[i] << ',';
			}
		}
outputfile.close();
}
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


