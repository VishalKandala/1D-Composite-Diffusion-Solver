//Vishal Indivar Kandala
// Meen 689 Project 3
#include<iostream>
using namespace std
using namespace initialization

void print_to_file(int interactive);

void print_to_file(int interactive){
	ofstream outputfile;
	string ofilename;
	if(interactive){
	cout<<"Name of output file:"<<endl;
	cin>>ofilename;
	}
	ofilename = "t_profile.csv"
	outputfile.open(ofilename);
	int length = T.size();
	int count = T[0].size();
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
				outputfile << T[i][j] << endl;
			}
			else{
				outputfile << T[i][j] << ',';
			}
		}
	}
outputfile.close();
}
}
