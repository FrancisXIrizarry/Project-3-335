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
#include <math.h>
 
#define R 6372.8
#define TO_RAD (3.1415926536 / 180)
const int DEFAULT_TABLE_SIZE = 512;

using namespace std;

 template < class myType >
   class LinkedHashEntry {
     private:
       int key;
     myType value;
     LinkedHashEntry < myType > * next;
     public:
       LinkedHashEntry (int key, myType value) {
         this -> key = key;
         this -> value = value;
         this -> next = NULL;
       }

     int getKey() {
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
     int maxSize;
     int tableSize;
     int size;
     LinkedHashEntry < myType > * * table;

     void resize() {
       int oldTableSize = tableSize;
       tableSize *= 2;
       maxSize = (int)(tableSize * threshold);
       LinkedHashEntry < myType > * * oldTable = table;
       table = new LinkedHashEntry < myType > * [tableSize];
       for (int i = 0; i < tableSize; i++)
         table[i] = NULL;
       size = 0;
       for (int hash = 0; hash < oldTableSize; hash++)
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
         maxSize = 96;
         tableSize = DEFAULT_TABLE_SIZE;
         size = 0;
         table = new LinkedHashEntry < myType > * [tableSize];
         for (int i = 0; i < tableSize; i++)
           table[i] = NULL;
       }

     void setThreshold(float threshold) {
       this -> threshold = threshold;
       maxSize = (int)(tableSize * threshold);
     }
     LinkedHashEntry < myType > * * returnTable(){ return table; }
     int getSize(){ return size; }
     myType get(int key) {
       int hash = (key % tableSize);
       if (table[hash] == NULL)
         return -1;
       else {
         LinkedHashEntry < myType > * entry = table[hash];
         while (entry != NULL && entry -> getKey() != key)
           entry = entry -> getNext();
         if (entry == NULL)
           return -1;
         else
           return entry -> getValue();
       }
     }

     void add(int key, myType value) {
       int hash = (key % tableSize);
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

     void remove(int key) {
       int hash = (key % tableSize);
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
       for (int hash = 0; hash < tableSize; hash++)
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

   void addToVec(subwayStation newsubwayStation) {
     //allSubwayStations.push_back(newsubwayStation);
       StationHash.add(StationHash.getSize(), newsubwayStation);
   }
   double haversine(double lat1, double lon1, double lat2, double lon2);

   void hashStation() {}
   void hashLine() {}
   void printAllHashStation(){
     for(int i = 0; i < StationHash.getSize(); i++){
        cout << StationHash.get(int key) << endl; // StationHash.returnTable()[i]
     }
   }

   private:
     string inputFile;
     HashMap<subwayStation> StationHash;
     HashMap<subwayStation::LineObj>LineHash;
   //vector < subwayStation > allSubwayStations;

   //vector < subwayStation::LineObj > LineContainer;

   //vector

 };

 /*
 const int DEFAULT_TABLE_SIZE = 128;
 class LinkedHashEntry {
 private:
       int key;
       int value;
       LinkedHashEntry *next;
 public:
       LinkedHashEntry(int key, int value) {
             this->key = key;
             this->value = value;
             this->next = NULL;
       }
  
       int getKey() {
             return key;
       }
  
       int getValue() {
             return value;
       }
  
       void setValue(int value) {
             this->value = value;
       }
  
       LinkedHashEntry *getNext() {
             return next;
       }
  
       void setNext(LinkedHashEntry *next) {
             this->next = next;
       }
 }; 
 class HashMap {
 private:
       float threshold;
       int maxSize;
       int tableSize;
       int size;
       LinkedHashEntry **table;
  
       void resize() {
             int oldTableSize = tableSize;
             tableSize *= 2;
             maxSize = (int) (tableSize * threshold);
             LinkedHashEntry **oldTable = table;
             table = new LinkedHashEntry*[tableSize];
             for (int i = 0; i < tableSize; i++)
                   table[i] = NULL;
             size = 0;
             for (int hash = 0; hash < oldTableSize; hash++)
                   if (oldTable[hash] != NULL) {
                         LinkedHashEntry *oldEntry;
                         LinkedHashEntry *entry = oldTable[hash];
                         while (entry != NULL) {
                              add(entry->getKey(), entry->getValue());
                              oldEntry = entry;
                              entry = entry->getNext();
                              delete oldEntry;
                         }
                   }
             delete[] oldTable;
       }
  
 public:
       HashMap() {
             threshold = 0.75f;
             maxSize = 96;
             tableSize = DEFAULT_TABLE_SIZE;
             size = 0;
             table = new LinkedHashEntry*[tableSize];
             for (int i = 0; i < tableSize; i++)
                   table[i] = NULL;
       }
      // friend ostream& operator<< (ostream & os,  HashMap & t);
       void setThreshold(float threshold) {
             this->threshold = threshold;
             maxSize = (int) (tableSize * threshold);
       }
  
       int get(int key) {
             int hash = (key % tableSize);
             if (table[hash] == NULL)
                   return -1;
             else {
                   LinkedHashEntry *entry = table[hash];
                   while (entry != NULL && entry->getKey() != key)
                         entry = entry->getNext();
                   if (entry == NULL)
                         return -1;
                   else
                         return entry->getValue();
             }
       }
  
       void add(int key, int value) {
             int hash = (key % tableSize);
             if (table[hash] == NULL) {
                   table[hash] = new LinkedHashEntry(key, value);
                   size++;
             } else {
                   LinkedHashEntry *entry = table[hash];
                   while (entry->getNext() != NULL)
                         entry = entry->getNext();
                   if (entry->getKey() == key)
                         entry->setValue(value);
                   else {
                         entry->setNext(new LinkedHashEntry(key, value));
                         size++;
                   }
             }
             if (size >= maxSize)
                   resize();
       }
  
       void remove(int key) {
             int hash = (key % tableSize);
             if (table[hash] != NULL) {
                   LinkedHashEntry *prevEntry = NULL;
                   LinkedHashEntry *entry = table[hash];
                   while (entry->getNext() != NULL && entry->getKey() != key) {
                         prevEntry = entry;
                         entry = entry->getNext();
                   }
                   if (entry->getKey() == key) {
                         if (prevEntry == NULL) {
                              LinkedHashEntry *nextEntry = entry->getNext();
                              delete entry;
                              table[hash] = nextEntry;
                         } else {
                              LinkedHashEntry *next = entry->getNext();
                              delete entry;
                              prevEntry->setNext(next);
                         }
                         size--;
                   }
             }
       }
  
       ~HashMap() {
             for (int hash = 0; hash < tableSize; hash++)
                   if (table[hash] != NULL) {
                         LinkedHashEntry *prevEntry = NULL;
                         LinkedHashEntry *entry = table[hash];
                         while (entry != NULL) {
                              prevEntry = entry;
                              entry = entry->getNext();
                              delete prevEntry;
                         }
                   }
             delete[] table;
       }
 };
  */

 #endif
