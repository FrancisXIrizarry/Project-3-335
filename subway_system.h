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

const int DEFAULT_TABLE_SIZE = 512;

using namespace std;

 template < class myType >
   class LinkedHashEntry {
     private:
       unsigned int long key;
     myType value;
     LinkedHashEntry < myType > * next;
     public:
       LinkedHashEntry (unsigned int long key, myType value) {
         this -> key = key;
         this -> value = value;
         this -> next = NULL;
       }

     int long getKey() {
       return key;
     }

     myType getValue() {
       return value;
     }

     void setValue(myType value) {
       this -> value = value;
     }

     LinkedHashEntry < myType > * getNext() {
       return next;
     }

     void setNext(LinkedHashEntry < myType > * next) {
       this -> next = next;
     }
   };

 template < class myType >
   class HashMap {
     private:
       float threshold;
     int long maxSize;
     int long tableSize;
     int  size;
     LinkedHashEntry < myType > * * table;

     void resize() {
       int long oldTableSize = tableSize;
       tableSize *= 2;
       maxSize = (int long)(tableSize * threshold);
       LinkedHashEntry < myType > * * oldTable = table;
       table = new LinkedHashEntry < myType > * [tableSize];
       for (int long i = 0; i < tableSize; i++)
         table[i] = NULL;
       size = 0;
       for (unsigned int long hash = 0; hash < oldTableSize; hash++)
         if (oldTable[hash] != NULL) {
           LinkedHashEntry < myType > * oldEntry;
           LinkedHashEntry < myType > * entry = oldTable[hash];
           while (entry != NULL) {
             add(entry -> getKey(), entry -> getValue());
             oldEntry = entry;
             entry = entry -> getNext();
             delete oldEntry;
           }
         }
       delete[] oldTable;
     }

     public:
       HashMap() {
         threshold = 0.75f;
         maxSize = DEFAULT_TABLE_SIZE-1;
         tableSize = DEFAULT_TABLE_SIZE;
         size = 0;
         table = new LinkedHashEntry < myType > * [tableSize];
         for (int long i = 0; i < tableSize; i++)
           table[i] = NULL;
       }

     void setThreshold(float threshold) {
       this -> threshold = threshold;
       maxSize = (int long)(tableSize * threshold);
     }
     LinkedHashEntry < myType > * * returnTable(){ return table; }


     int long getSize(){ return size; }


     myType get(unsigned int long key) {
       unsigned int long hash = (key % tableSize);
       if (table[hash] == NULL){}
       else {
         LinkedHashEntry < myType > * entry = table[hash];
         while (entry != NULL && entry -> getKey() != key)
           entry = entry -> getNext();
         if (entry == NULL){}   
         else
           return entry -> getValue();
       }
     }

     void add(unsigned int long key, myType value) {
       unsigned int long hash = (key % tableSize);
       if (table[hash] == NULL) {
         table[hash] = new LinkedHashEntry < myType > (key, value);
         size++;
       } else {
         LinkedHashEntry < myType > * entry = table[hash];
         while (entry -> getNext() != NULL)
           entry = entry -> getNext();
         if (entry -> getKey() == key)
           entry -> setValue(value);
         else {
           entry -> setNext(new LinkedHashEntry < myType > (key, value));
           size++;
         }
       }
       if (size >= maxSize)
         resize();
     }
     unsigned long int hashFun(string preHash){
         
         unsigned long int preHashInt = 5381 ;
         int long c = preHash.size();
         for(int long i = 0; i < c; i++){
            preHashInt = ((preHashInt << 5)+ preHashInt) + preHash[i];}
         return preHashInt;
     }
     void remove(unsigned int long key) {
       unsigned int long hash = (key % tableSize);
       if (table[hash] != NULL) {
         LinkedHashEntry < myType > * prevEntry = NULL;
         LinkedHashEntry < myType > * entry = table[hash];
         while (entry -> getNext() != NULL && entry -> getKey() != key) {
           prevEntry = entry;
           entry = entry -> getNext();
         }
         if (entry -> getKey() == key) {
           if (prevEntry == NULL) {
             LinkedHashEntry < myType > * nextEntry = entry -> getNext();
             delete entry;
             table[hash] = nextEntry;
           } else {
             LinkedHashEntry < myType > * next = entry -> getNext();
             delete entry;
             prevEntry -> setNext(next);
           }
           size--;
         }
       }
     }

     ~HashMap() {
       for (unsigned int long hash = 0; hash < tableSize; hash++)
         if (table[hash] != NULL) {
           LinkedHashEntry < myType > * prevEntry = NULL;
           LinkedHashEntry < myType > * entry = table[hash];
           while (entry != NULL) {
             prevEntry = entry;
             entry = entry -> getNext();
             delete prevEntry;
           }
         }
       delete[] table;
     }

   };

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
     for(int i = 0; i < StationHash.getSize(); i++){
       // cout << StationHash.get(i) << endl; // StationHash.returnTable()[i]
     }
     for(int i = 0; i < LineHash.getSize(); i++){
     //  cout << LineHash.get(i) << endl; // StationHash.returnTable()[i]
     }
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
   private:
     string inputFile;
     HashMap<subwayStation> StationHash;
     HashMap<subwayEntrance::LineObj>LineHash;
     vector < subwayEntrance> allSubwayEntrances;
     vector<subwayStation> currentStations;
   //vector < subwayStation::LineObj > LineContainer;

   //vector

 };

 
 #endif
