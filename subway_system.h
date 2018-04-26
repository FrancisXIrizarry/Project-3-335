#ifndef __subway_system_h__
#define __subway_system_h__
#pragma once

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
#include <fstream>
#include "subway_station.h"
using namespace std;	

class subwaySystem{

	public:
		void newSubWaySystem();
		void addToVec(subwayStation newsubwayStation){
			allSubwayStations.push_back(newsubwayStation);
		}

	private:
		string inputFile;
		vector<subwayStation> allSubwayStations;
		vector<subwayStation::LineObj> LineContainer;
		//vector


};

#endif 
