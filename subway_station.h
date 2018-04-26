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
#ifndef __subway_station_h__
#define __subway_station_h__
#pragma once 
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <iomanip>
using namespace std;
class subwayStation{
	public:
	subwayStation(const string& subwayInfo);
	void getObjectFixLine();
	void getObjectFixGeom();
	friend ostream& operator<< (ostream & os, const subwayStation & t);
	private:
	double ObjectId;
	string URL, Name, Line, The_Geom;
	struct GeoObj {
	  //GeomObj(){}
	  string geoPointB = "POINT( ";
	  string geoPointE = ")";
	  double longitude;
	  double latitude;
	  friend ostream& operator<< (ostream & os, const GeoObj & t){
	 	os << setw(8) << left << t.geoPointB << left << t.longitude << left << " , " << left << t.latitude << left << t.geoPointE;
	  } 
	   
	 } GeomObj; //Struct called GeoObj, and a variable for the class called GeomObj
	 struct LineObj {
	   vector<string> LineStrE;
	   friend ostream& operator<< (ostream & os, const LineObj & t){
		//cout << "What\n\t" << t.LineStrE.size() << endl;
		os << setw(10) << right <<  "[" << setw(1);
		 for (int i = 0; i < t.LineStrE.size(); ++i) {
       		 	os << left << t.LineStrE[i];
			if (i != t.LineStrE.size() - 1)
      			      os << left <<  "-";
    		 }
    		 os << "]";
	   } 
	 } subwayLines;
	
	//inline ostream &operator<< (ostream & os, const GeomObj & t){}	
};

#endif 
