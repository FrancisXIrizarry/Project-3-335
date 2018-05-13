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
class subwayStation {
  public:
    subwayStation(){}
    subwayStation(const string & subwayInfo);
    string subwayName(){ return Name; }
  void getObjectFixLine();
  void getObjectFixGeom();
  string getLineStr(){ string str; return subwayLines.getLineObjS(str);}
  
  friend ostream & operator << (ostream & os, const subwayStation & t);
  struct LineObj {
    vector < string > LineStrE;
    string getLineObjS(string &trueString){
     for (int i = 0; i < LineStrE.size(); ++i) {
        trueString += LineStrE[i];
        if (i != LineStrE.size() - 1)
          trueString += "-";
      }
    }
    friend ostream & operator << (ostream & os,
      const LineObj & t) {
      //cout << "What\n\t" << t.LineStrE.size() << endl;
      os << setw(1) << right << "[" << setw(1);
      for (int i = 0; i < t.LineStrE.size(); ++i) {
        os << left << t.LineStrE[i];
        if (i != t.LineStrE.size() - 1)
          os << left << "-";
      }
      os << "]";
    }
  }
  subwayLines;
  LineObj getLineObj(){ return subwayLines; }
  private:
    double ObjectId;
  string URL, Name, Line, The_Geom;
  struct GeoObj {
    //GeomObj(){}
    string geoPointB = "POINT( ";
    string geoPointE = ")";
    double longitude;
    double latitude;
    friend ostream & operator << (ostream & os,
      const GeoObj & t) {
      os << setw(7) << left << t.geoPointB << left << t.longitude << setw(2) << left << " , " << setw(2) << left << t.latitude << left << t.geoPointE;
    }

  }
  GeomObj; //Struct called GeoObj, and a variable for the class called GeomObj

  //inline ostream &operator<< (ostream & os, const GeomObj & t){}	
};

/*

subway_station.h //with entrance  + hashing
subway_station.cpp //with entrance + hashing for line and station
subway_system.h
subway_system.cpp
*/

#endif 
