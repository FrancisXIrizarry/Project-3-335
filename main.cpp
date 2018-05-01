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
#include <vector>
#include "subway_system.h"
#include "subway_station.h"
using namespace std;
void inputFileData(stringstream& iFile, stringstream& oFile);
int main(int argc, char* argv[])
{
	ifstream  fin;    
    	ifstream  fout;
	//(Not enough arguments/too many, tells user and fails
		 if ( argc != 3 ) {
      		   cerr << "Usage: " << argv[0] << " input_file \n";
       		  exit(1);
    		 }  
		 fin.open( argv[1], ios::in);
		 if ( !fin ) {
			cerr << "Could not open" << argv[1] << " for reading.\n";
			exit(1);
		 }  
		 fout.open(argv[2], ios::in);
   		 if ( fout.fail() ) {
    		    cerr << "Could not open " << argv[2] << " for reading.\n";
   		     exit(1);
   		 }
		fout.close();
		
	// cout << "What " << endl;
	 
	 stringstream arg1(argv[1]);
	 stringstream arg2(argv[2]);	
	 inputFileData(arg1,arg2);
	 

  
}
void inputFileData(stringstream& iFile, stringstream& oFile){
	 	 subwaySystem newSubWay;
	  	 string inputFile;
	  	 iFile >> inputFile;
		 ifstream inputFileHandling;
		 inputFileHandling.open(inputFile.c_str());
		 bool endofFile = false;
		 int count = 0;
		 bool inList = false;
		 while(endofFile != true){
				
				string subwayInfo = "";
				
				getline(inputFileHandling, subwayInfo);
				if(inputFileHandling.bad()  || inputFileHandling.eof()){cout << "break?" << endl;endofFile = true;}
		 		else{	
				
					subwayStation newsubwayStation(subwayInfo);
					//cout << "Before what" << endl;
					newsubwayStation.getObjectFixGeom();
					newsubwayStation.getObjectFixLine();
					newSubWay.addToVec(newsubwayStation);
					cout << newsubwayStation << endl;
					//cout << "Hmm " << endl;
				}
		}
		bool exit = false;
		string commandFile;
		oFile >> commandFile;
		ifstream inputCommandHandling;
		string commandString;
		inputCommandHandling.open(commandFile.c_str());
		
		while(!inputCommandHandling.eof()){
			getline(inputCommandHandling, commandString);
			cout << commandString << endl;
			//break;
		}


}























