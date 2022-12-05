# Working Title
This C++ code is written by Team Nebule for Project 3 of MEEN 689 Computing Concepts course.

This code simulates the heat conduction in a spherical body with multiple layers of different material compositions of varying thicknesses.

This code is based on the Implicit Solution of the Backward in Time- Central in Space (BTCS) discretization of the One Dimensional heat equation.

$$\frac{\partial T}{\partial t } = \alpha\frac{\partial^{2} T}{\partial x^{2} }$$

$$-{\lambda T_{i+1}^{n+1}}  - \lambda T_{i-1}^{n+1} + (1 + 2\lambda)(T_{i+1}^{n}) = T_{n}^{i}$$

With Neumann Boundary conditions applied at both boundaries. 

$$ Q=-k\frac{\partial T}{\partial x}$$

Discretizing the boundaries using ghost points, we get the following linear system.
$$ A*T^{n+1} = T_{n} + B$$
$$
A 
-2\lambda , 1 +2 , 3 
4 , 5 , 6 
7 , 8 , 9
$$
and $B = [2*Q[0]*\alpha[0]*\Delta x]$


The Linear system obtained from BTCS formulation is solved using an optimized Tridiagonal Matrix Solver based on Thomas Algorithm (TDMA).

  
## Dependencies

- Compiler: g++
- Python3
  - matplotlib
  - Numpy

## Installation

Clone the current git repository and compile using the following commands.
```bash
make all
```
This will output the following, which confirms installation
```bash
g++ -c -o main.o main.cpp
g++ -c -o setup.o setup.cpp
g++ -c -o solver.o solver.cpp
g++ -c -o data.o data.cpp
g++ -o 1dheat main.o setup.o solver.o data.o
rm -f *.o
```
If you want to keep the object files you can use
```bash
make 1dheat
```
## Usage
To run a simulation, type in the following:
```bash
./1dheat
```
This would first prompt you to enter how verbose your terminal output would be.
```bash
Please select how verbose you would like the solver output:
```
You could enter the following values:


Input Output
1: which will output  Basic Information such as Config file name, Lambda(Von Neumann Number) of grid points, 
2. 




## Contributing

Pull requests are welcome. For major changes, please open an issue first
to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License

[MIT](https://choosealicense.com/licenses/mit/)
