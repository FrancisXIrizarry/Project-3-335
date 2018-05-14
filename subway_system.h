#ifndef __subway_system_h__
#define __subway_system_h__
#pragma once

/*******************************************************************************
  Title          : main.cpp
  Author         : Francis Irizarry
  Created on     : Feb 26, 2018
  Description    : Linker file, (Point access for other files, pulls the inadd of command line
  Purpose        : Handling nodes and keeping together similar to a linked list
  Usage          : Include this file with client code
  Build with     : No building 
  Modifications  : 
 
*******************************************************************************/


#include <iostream>
#include <sstream>
#include <fstream>
#include "subway_station.h"


 class subwaySystem {

   public:
     void newSubWaySystem();

   void hashStation(subwayEntrance newsubwayEntrance) {
        allSubwayEntrances.push_back(newsubwayEntrance);//For all Entrances
        
        
      //  cout << newsubwayStation << "\t " << StationHash.hashFun(newsubwayStation.subwayName()) << endl;
      // StationHash.add(StationHash.hashFun(newsubwayStation.subwayName()), newsubwayStation); //StationHash.hashFun(newsubwayStation.subwayName())  StationHash.getSize() For Quick finding station
      //string str = newsubwayStation.getLineStr();
     // LineHash.add(LineHash.getSize(), newsubwayStation.getLineObj());
   }
   int getSetSize(int x){ return currentStations.at(x).getSetSize();}
   //void testUnionFunc(int root1, int root2){ currentStations.at(root1).unionTest(currentStations.at(root1), currentStations.at(root2), root1, root2);}
     
   void printAllHashStation(){
     //for(int i = 0; i < StationHash.getSize(); i++){
       // cout << StationHash.get(i) << endl; // StationHash.returnTable()[i]
    // }
    // for(int i = 0; i < LineHash.getSize(); i++){
     //  cout << LineHash.get(i) << endl; // StationHash.returnTable()[i]
    // }
     //int y = StationHash.getSize();
    // int x = LineHash.getSize();
    // cout << StationHash.hashFun("Woodhaven Blvd & Queens Blvd at SW corner") << endl;
     //cout << StationHash.hashFun("Woodhaven Blvd & Queens Blvd at SW corner") << endl; StationHash.returnTable()[32587595529594132 % 512]->getNext() << << StationHash.get(32587595529594132) << "\n"
    // LinkedHashEntry<subwayStation> *next =  StationHash.returnTable()[32587595529594132 % 512]->getNext();
    // cout << StationHash.getSize() << endl;
    //  cout << StationHash.returnTable()[32587595529594132 % 512]->getValue() << " Prev and Next " << next->getValue() <<   "\ntest " << LineHash.get(x-1);
   }
   vector<subwayStation> getcurrentStation(){ return currentStations; }
   void push_backFunc(subwayStation newsubwayStation){ currentStations.push_back(newsubwayStation); }
   void unionTestFunc(int root1, int root2, int loc){ currentStations.at(loc).unionFunc(root1, root2);}
   int findFunc(int x){ return currentStations.at(0).findElementSet(x);}
   void testMask(){ int tempSize = currentStations.at(0).getAllEntranceSize(); 
	for(int x = 0; x < tempSize; x++){currentStations.at(0).testEntranceMask(x);} 
   }
   private:
     string inputFile;
    // HashMap<subwayStation> StationHash;
    // HashMap<subwayEntrance::LineObj>LineHash;
     vector < subwayEntrance> allSubwayEntrances;
     vector<subwayStation> currentStations;
     vector<subwayStation> realSubwayStations;
   //vector < subwayStation::LineObj > LineContainer;

   //vector

 };

 
 #endif
