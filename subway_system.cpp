#include "subway_system.h"

	void subwaySystem::newSubWaySystem(stringstream& iFile){
		 iFile >> inputFile;
		 ifstream inputFileHandling;
		 inputFileHandling.open(inputFile.c_str());
		 bool endofFile = false;
		 int count = 0;
		 bool inList = false;
		 //instance of stupid treecontainer then use it below
		 while(endofFile != true){
				
				string subwayInfo = "";
				
				getline(inputFileHandling, subwayInfo);
				if(inputFileHandling.bad()  || inputFileHandling.eof()){cout << "break?" << endl;endofFile = true;}
		 		else{	
				
					subwayStation newsubwayStation(subwayInfo);
					//cout << "Before what" << endl;
					newsubwayStation.getObjectFixGeom();
					newsubwayStation.getObjectFixLine();
					allSubwayStations.push_back(newsubwayStation);
					cout << newsubwayStation << endl;
					//cout << "Hmm " << endl;
				}
			
			count++;
		//if(count == 10) break;
		}

	}//End of Func

	


