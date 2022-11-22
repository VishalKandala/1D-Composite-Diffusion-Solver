// Vishal Indivar Kandala
// MEEN 689 Computing Concepts Project 3

#include <stdlib.h>
#include<math.h>
#include "init.c"
using namespace std
using namespace initialization
// 
// A in:  A*u(n+1) = B
void formA(A);
// B in:  A*u(n+1) = B
void formB();

void formA(int layup,int v){
// Boundary condition at center
A[0][0] = 1 + 2*(dt/pow(dr,2))*alpha(0,layup); // The thermal diffusivity of steel is used here as steel is always the
A[0][1] = 2*(dt/pow(dr,2))*alpha(0,layup); 
// Interior points
for(int i=1;i<N-1;i++){
A[i][0] = (dt/pow(dr,2))*alpha(i,layup); 
A[i][1] = 1 + 2*(dt/pow(dr,2))*alpha(i,layup);        	
A[i][2] = (dt/pow(dr,2))*alpha(i,layup); 
}	
// Boundary condition at edge
A[N-1][1] =  1 + 2*(dt/pow(dr,2))*alpha(N-1,layup);
A[N-1][2] =  2*(dt/pow(dr,2))*alpha(N-1,layup);
// Visualize the A matrix.
if(v){
cout<<"A matrix --layup:"<<layup<<endl;
for(int i = 0;i<N;i++){
cout<<A[i][0]<<"\t"<<A[i][1]<<"\t"<<A[i][2]<<endl;
}
}
}

void formB(int layup,int v){
for(int i =0;i<N-1;i++){
B[i] = Told[i,layup]
}	
// Boundary condition
B[N-1] = Told[N-1,layup] + heat_flux(layup)*2*dr;
//Visualize the B vector
if(v){
cout<<"B vector --layup:"<<layup<<endl;
for(int i = 0;i<N;i++){
cout<<B[i]<<endl;
}
}
}

