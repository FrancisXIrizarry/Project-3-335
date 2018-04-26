/*******************************************************************************
  Title          : main.cpp
  Author         : Francis Irizarry
  Created on     : Feb 26, 2018
  Description    : Linker file, (Point access for other files, pulls the input of command line
  Purpose        : Handling nodes and keeping together similar to a linked list
  Usage          : Include this file with client code
  Build with     : No building 
  Modifications  : 
 
*******************************************************************************/
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <fstream>
#include "subway_system.h"

using namespace std;
int main(int argc, char* argv[])
{
	ifstream  fin;    
    	//ofstream  fout;
	//(Not enough arguments/too many, tells user and fails
		 if ( argc != 2 ) {
      		   cerr << "Usage: " << argv[0] << " input_file \n";
       		  exit(1);
    		 }  
		 fin.open( argv[1], ios::in);
		 if ( !fin ) {
			cerr << "Could not open" << argv[1] << " for reading.\n";
			exit(1);
		 }  
		 /*fout.open(argv[2], ios::in);
   		 if ( fout.fail() ) {
    		    cerr << "Could not open " << argv[2] << " for reading.\n";
   		     exit(1);
   		 }
		//fout.close();*/
		
	// cout << "What " << endl;
	 subwaySystem newSubWay;
	 stringstream arg1(argv[1]);
	 //stringstream arg2(argv[2]);
	 newSubWay.newSubWaySystem(arg1);

	
	 //newCensus.newCensusSystem(arg1, arg2); 

  
}

