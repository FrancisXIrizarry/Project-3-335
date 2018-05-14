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
#include "command.h"
using namespace std;
void inputFileData(stringstream & iFile, stringstream & oFile);
int main(int argc, char * argv[]) {

  ifstream fin;
  ifstream fout;

  //(Not enough arguments/too many, tells user and fails
  if (argc != 3) {
    cerr << "Usage: " << argv[0] << " input_file commandFile\n";
    exit(1);
  }
  fin.open(argv[1], ios:: in );
  if (!fin) {
    cerr << "Could not open" << argv[1] << " for reading.\n";
    exit(1);
  }
  fout.open(argv[2], ios:: in );
  if (fout.fail()) {
    cerr << "Could not open " << argv[2] << " for reading.\n";
    exit(1);
  }
  fout.close();

  // cout << "What " << endl;

  stringstream arg1(argv[1]);
  stringstream arg2(argv[2]);
  inputFileData(arg1, arg2);

}
void inputFileData(stringstream & iFile, stringstream & oFile) {
  Command command;
  string line_id;
  string station_name;
  double longitude;
  double latitude;
  double distance;
  bool result;
  subwaySystem newSubWay;
  subwayStation newsubwayStation;
  string inputFile;
  iFile >> inputFile;
  ifstream inputFileHandling;
  inputFileHandling.open(inputFile.c_str());
  bool endofFile = false;
  int count = 0;
  bool inList = false;
  while (endofFile != true) {

    string subwayInfo = "";

    getline(inputFileHandling, subwayInfo);
    if (inputFileHandling.bad() || inputFileHandling.eof()) {
      cout << "break?" << endl;
      endofFile = true;
    } else {
        //cout << " new sub size " << newSubWay.getcurrentStation().size() << endl;
         if(newSubWay.getcurrentStation().size() == 0){
	         // subwayStation newsubwayStation;
              subwayEntrance newsubwayEntrance(subwayInfo);
             
              newsubwayEntrance.getObjectFixGeom();
              newsubwayEntrance.getObjectFixLine();
              newsubwayStation.addSubwayEntrance(newsubwayEntrance);
              //newSubWay.push_backFunc(newsubwayStation);
              // newSubWay.hashStation(newsubwayStation);
              // cout << newsubwayStation << endl;
             // cout << "Hmm " << newSubWay.getcurrentStation().size() << endl;
         }
         else{
            int tempsize = newSubWay.getcurrentStation().size();
            bool addedToStation = false;
            subwayEntrance newsubwayEntrance(subwayInfo);
            newsubwayEntrance.getObjectFixGeom();
            newsubwayEntrance.getObjectFixLine();
            newsubwayStation.addSubwayEntrance(newsubwayEntrance);
            /*for(int x = 0; x < tempsize; x++){
                cout << newSubWay.getcurrentStation().at(x).addSubwayEntrance(newsubwayEntrance) << endl;
                if(newSubWay.getcurrentStation().at(x).addSubwayEntrance(newsubwayEntrance) == true){ addedToStation = true; break;}
            }
                if(addedToStation == false){
                    subwayStation newsubwayStation;
                    newsubwayStation.addSubwayEntrance(newsubwayEntrance);
                    newSubWay.push_backFunc(newsubwayStation);
                }
           */
            //subwayStation newsubwayStation;
           // newsubwayStation.addSubwayEntrance(newsubwayEntrance);
           // newSubWay.push_backFunc(newsubwayStation);
         }
    }
  }
   newSubWay.push_backFunc(newsubwayStation);
  cout << "Hmmx " << newSubWay.getcurrentStation().size() << " ann d " << newSubWay.getcurrentStation().at(newSubWay.getcurrentStation().size()-1).getVecSize() << endl;
    newSubWay.unionTestFunc(0,1, 0);
  //newSubWay.unionTestFunc(0,1);
  //cout << newSubWay.getSetSize(0) << endl;
  newSubWay.printAllHashStation();
  bool exit = false;
  string commandFile;

  oFile >> commandFile;
  ifstream inputCommandHandling;
  string commandString;

  inputCommandHandling.open(commandFile.c_str(), ios:: in );
  while (!inputCommandHandling.eof()) {
    if (!command.get_next(inputCommandHandling)) {
      if (!inputCommandHandling.eof())
        cerr << "Could not get next command.\n";
      return;
    }
    command.get_args(line_id, station_name, longitude, latitude, result);
    switch (command.type_of()) {
    case list_line_stations_cmmd:
      cout << "list_line_stations_cmmd " << endl;
      break;
    case list_all_stations_cmmd:
      cout << "list_all_stations_cmmd " << endl;
      break;
    case list_entrances_cmmd:
      cout << "list_entrances_cmmd " << " " << station_name << endl;
      break;
    case nearest_station_cmmd:
      cout << "nearest_station_cmmd " << " " << longitude << " " << distance << endl;
      break;
    case nearest_lines_cmmd:
      cout << "nearest_lines_cmmd " << " " << longitude << " " << distance << endl;
      break;
    case nearest_entrance_cmmd:
      cout << "nearest_entrance_cmmd " << " " << longitude << " " << distance << endl;
      break;
    case bad_cmmd:
      cout << "bad command " << endl;
      break;
    default:
      break;
    }
  }
  inputCommandHandling.close();

}




















