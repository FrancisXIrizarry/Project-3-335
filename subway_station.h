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
#include <math.h>
 
#define R 6372.8
#define TO_RAD (3.1415926536 / 180)
#define killDistance 0.28
using namespace std;
template<class typeUnion>
class DisjSets
{
  public:
  DisjSets ();
  void unionT(typeUnion, typeUnion);
  void addElementToSet(typeUnion x);
  typeUnion find (typeUnion x);
  typeUnion getElement(int root){cout << s.size() << endl; return s.at(root);}
  int getSizeOfVec() { return s.size(); }
    private:vector < typeUnion >s;
};
/* Construct the disjoint sets object .
* @param numElements is the initial number of disjoint sets .
*/
template<class typeUnion>
DisjSets<typeUnion>::DisjSets ()
{
  //for (int i = 0; i < s.size (); i++)
 //   s[i] = -1;
}

/* * Union two disjoint sets .
* Assume root1 and root2 are distinct and represent set names .
* @param root1 is the root of set 1.
* @param root2 is the root of set 2.
*/
template<class typeUnion>
void DisjSets<typeUnion>::addElementToSet(typeUnion x){
    s.push_back(x);
    s.at(s.size() - 1).setRoot(-1);
}
template<class typeUnion>
void DisjSets<typeUnion>::unionT(typeUnion root1, typeUnion root2)
{
  if (root1.getRoot() != root2.getRoot())
    {
      if (s[root2.getRoot()].getRoot() < s[root1.getRoot()].getRoot())
	{
// root2 is deeper
	  s[root2.getRoot()].addToRoot(s[root1.getRoot()].getRoot());
	  s[root1.getRoot()].setRoot(root2.getRoot());
	}
      else
	{
// root1 is deeper
	  s[root1.getRoot()].addToRoot(s[root2.getRoot()].getRoot());
	  s[root2.getRoot()].setRoot(root1.getRoot());
	}
    }
}

/* *
* Perform a recursive find with path compression .
* Error checks omitted again for simplicity .
* @param x is the element to be found
* @return the set containing x .
*/
template<class typeUnion>
typeUnion DisjSets<typeUnion>::find (typeUnion x)
{
  if (s[x.getRoot()] < 0)
    return x;
  else
    return s[x.getRoot()] = find (s[x.getRoot()]);
}

class subwayEntrance {

public:
    subwayEntrance() {}
    subwayEntrance(const string& subwayInfo);
    string subwayName() { return Name; }
    void getObjectFixLine();
    void getObjectFixGeom();
    
    string getLineStr()
    {
        string str;
        return subwayLines.getLineObjS(str);
    }
    friend bool operator==(const subwayEntrance & t1, const subwayEntrance t2);
    friend ostream& operator<<(ostream& os, const subwayEntrance& t);
    struct LineObj {
        vector<string> LineStrE;
        string getLineObjS(string& trueString)
        {
            for (int i = 0; i < LineStrE.size(); ++i) {
                trueString += LineStrE[i];
                if (i != LineStrE.size() - 1)
                    trueString += "-";
            }
        }
        friend ostream& operator<<(ostream& os,
            const LineObj& t)
        {

            os << setw(1) << right << "[" << setw(1);
            for (int i = 0; i < t.LineStrE.size(); ++i) {
                os << left << t.LineStrE[i];
                if (i != t.LineStrE.size() - 1)
                    os << left << "-";
            }
            os << "]";
        }
    } subwayLines;
    LineObj getLineObj() { return subwayLines; }
    struct GeoObj {
        //GeomObj(){}
        string geoPointB = "POINT( ";
        string geoPointE = ")";
        double longitude;
        double latitude;
        double getGeoLong() { return longitude; }
        double getGeoLat() { return latitude; }
        friend ostream& operator<<(ostream& os,
            const GeoObj& t)
        {
            os << setw(7) << left << t.geoPointB << left << t.longitude << setw(2) << left << " , " << setw(2) << left << t.latitude << left << t.geoPointE;
        }

    } GeomObj; //Struct called GeoObj, and a variable for the class called GeomObj
    GeoObj getGeoObjPrv() { return GeomObj; }
    void setRoot(int x){ root = x;}
    int getRoot(){ return root;}
    void addToRoot(int x){ root += x;}
private:
    double ObjectId;
    string URL, Name, Line, The_Geom;
    int root;
   
};

class subwayStation {
public:
    subwayStation() {}
    bool addSubwayEntrance(subwayEntrance t)
    {
     
            allEntrances.push_back(t);
            entranceSets.addElementToSet(t);
            return true;
     
       /* for (int i = 0; i < allEntrances.size(); i++) {
            // cout << allEntrances.at(i).GeomObj.getGeoLat() << " and " <<  t.GeomObj.getGeoLat() << " and total size" << allEntrances.size()<< i << " in for loop subway add station entrance " <<  endl;
            //if((allEntrances.at(i).GeomObj.getGeoLat() == t.GeomObj.getGeoLat()) && (allEntrances.at(i).GeomObj.getGeoLong() == t.GeomObj.getGeoLong())) cout << "What the fuck? " << endl;
            if (haversine(allEntrances.at(i).GeomObj.getGeoLat(), allEntrances.at(i).GeomObj.getGeoLong(), t.GeomObj.getGeoLat(), t.GeomObj.getGeoLat()) < killDistance) {
                inEntrance = true;
                break;
            }
        }*/

        //cout << "inEntrance" << inEntrance << endl;
      

        return false;
    }
    double haversine(double lat1, double lon1, double lat2, double lon2);
    int getVecSize(){ return entranceSets.getSizeOfVec();}
   // void unionTest(subwayStation root1, subwayStation root2, int intRoot1, int intRoot2){ entranceSets.unionT(root1.getEntraces.at(intRoot1), root2.getEntraces.at(intRoot2));}
   // subwayEntrance getEntrance(int x){ return allEntrance
      void unionFunc(int root1, int root2){entranceSets.unionT(entranceSets.getElement(root1), entranceSets.getElement(root2));}
    int getSetSize(){ return entranceSets.getSizeOfVec();}//getSizeOfVec(); if I wanted to return a specific set size
private:
    vector<subwayEntrance> allEntrances;
    DisjSets<subwayEntrance> entranceSets;

    //subwayStation(const string & subwayInfo);

    // subwayEntranceObj getsubEntranceObj() { return subwayEntranceObj

    //inline ostream &operator<< (ostream & os, const GeomObj & t){}
};

/*

subway_station.h //with entrance  + hashing
subway_station.cpp //with entrance + hashing for line and station
subway_system.h
subway_system.cpp
*/

#endif 
