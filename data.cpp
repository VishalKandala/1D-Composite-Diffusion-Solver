//Vishal Indivar Kandala
// Meen 689 Project 3
#include<iostream>
#include<fstream>
#include<sstream>
#include "heat.hpp"

using namespace std;

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


