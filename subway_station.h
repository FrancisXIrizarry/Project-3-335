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
#include <limits.h>
#define R 6372.8
#define TO_RAD (3.1415926536 / 180)
#define killDistance 0.28

const int DEFAULT_TABLE_SIZE = 512;

using namespace std;
// A bitstring is an integer whose value is irrelevant to us but whose
// bits define which elements are in the set that it represents: if the ith
// bit is 1, it is in the set, and if it is 0, it is not. 
typedef  int bitstring;


/** SmallSet represents a small set, not more than the wordsize of the
 *  machine on which it is compiled.
 *  It uses bitstrings to represent sets, and bitwise operations on them
 *  with masks and bitstrings.
 */
class SmallSet
{
public:
    /** Constructor
     *  Initializes a set to contain the members represented by the positions
     *  of the 1-bits in integer j. 
     */
    SmallSet(bitstring j=0);

    /** complement() returns an integer bitstring representing the complement
     *  of the set.
     */
    bitstring   complement();

    
    void  add(int i);


    bool  contains(int i);
    void  print(std::ostream& out);
    friend bitstring   do_union(SmallSet s, SmallSet t);
    friend bitstring   intersection(SmallSet s, SmallSet t);
    

private:
    bitstring mask[WORD_BIT];
    bitstring set;
    int size;
};

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
template<class typeUnion>
class DisjSets
{
  public:
  DisjSets ();
  void unionT(int, int);
  bool addElementToSet(typeUnion x);
  int find (int x);
  typeUnion getElement(int root){return s.at(root);}
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
bool DisjSets<typeUnion>::addElementToSet(typeUnion x){
    //If(x.geo location = s.geo location && x.line = s.line) x.setParent(parent location)
    s.push_back(x);
    s.at(s.size() - 1).setRoot(-1);
}
template<class typeUnion>
void DisjSets<typeUnion>::unionT(int root1, int root2)
{
  if (root1 != root2)
    {
      if (s[root2].getRoot() < s[root1].getRoot())
	{
	  if(s[root1].getRoot() > 0){
	     s[root2].setRoot(root1);
	  }
 	  else{
// root2 is deeper
	  s[root2].addToRoot(s[root1].getRoot());
	  s[root1].setRoot(root2);
	  }
	}
      else
	{
// root1 is deeper
	if(s[root2].getRoot() > 0){
	     s[root1].setRoot(root2);
	}
	  s[root1].addToRoot(s[root2].getRoot());
	  s[root2].setRoot(root1);
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
int DisjSets<typeUnion>::find (int x)
{
   /*cout << " testa roo " << s.size() << " x " << x << endl;
   cout << s[x].getRoot() << endl;
   cout << " testa 11111" << endl;*/
  if (s[x].getRoot() < 0){
    //cout << " if wow " << endl;
    return x;
  }
  else{
    s[x].setRoot(find (s[x].getRoot()));
   // cout << " else wow " << endl;
    return s[x].getRoot();
    }
}

class subwayEntrance {

public:
    subwayEntrance() {}
    subwayEntrance(const string& subwayInfo);
    string subwayName() { return Name; }
    void getObjectFixLine();
    void getObjectFixGeom();
    void maskLine(){ 
        string OriString = getLineStr();
        //cout << temp << endl;
        SmallSet s1;
        istringstream ss(OriString);

        while(getline(ss, OriString, '-')){
         // cout << "Ori String " << OriString << endl;
          istringstream RealString(OriString);
          string stringIntConv;
          RealString >> stringIntConv;
          if(OriString == "GS"){ s1.add(34); }
          else if(OriString == "SIR"){s1.add(35); }
          else{
          for(int x = 1; x < 8; x++){
		    //cout << "wot " << stringIntConv << " and x " << x <<  endl;
            if(stringIntConv[0] == x){ s1.add(x); }//cout << "wot " << stringIntConv << endl;
          }
          for(int y = 0; y < 27; y++){
            
            if(stringIntConv[0] == ('A'+y)){ s1.add((stringIntConv[0] - 'A') + 8); cout << "stringIntConv[0]" << stringIntConv[0] << " and val " << stringIntConv[0] - 'A' + 8 << endl; }
          }
          }
      
         
        }
        std::cout << "s1 = ";
        s1.print(std::cout);
    //setLineMask(
    }

    string getLineStr()
    {
        string str;
        return subwayLines.getLineObjS(str);
    }
    friend bool operator==(const subwayEntrance & t1, const subwayEntrance t2);
    friend ostream& operator<<(ostream& os, const subwayEntrance& t);
    struct LineObj {
        vector<string> LineStrE;
        string getLineObjS(string trueString)
        {
            for (int i = 0; i < LineStrE.size(); ++i) {
                trueString += LineStrE[i];
                if (i != LineStrE.size() - 1)
                    trueString += "-";
            }
           return trueString;
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
    int getLineMask(){ return lineMask;}
    void setLineMask(int mask){ lineMask = mask; }
private:
    double ObjectId;
    string URL, Name, Line, The_Geom;
    int root;
    int lineMask;
   
};

class subwayStation {
public:
    subwayStation() {}
    bool addSubwayEntrance(subwayEntrance t)
    {
     
            allEntrances.push_back(t);
	       
            if(entranceSets.addElementToSet(t)){ return true;}
            else { return true;}
     
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
      void unionFunc(int root1, int root2){entranceSets.unionT(root1, root2);}
      int findElementSet(int x){ return entranceSets.find(x);}
    int getAllEntranceSize(){ return allEntrances.size();}
    int getSetSize(){ return entranceSets.getSizeOfVec();}//getSizeOfVec(); if I wanted to return a specific set size
    void testEntranceMask(int x){ allEntrances.at(x).maskLine();}//allEntrances.size() - 1
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
