#include "subway_station.h"

subwayStation::subwayStation(const string & subwayInfo){ 
	//cout << "The fuck " << endl;
	 string allInfo = subwayInfo;
	 stringstream iss(subwayInfo);
	 vector<string> splitString;
	 string quote = "\"";
	 
	
   	    string singlePart; 
 	   while(getline(iss,singlePart)){
 	    const char *stringStart = singlePart.c_str();
 	    bool instring{false};
 	    for(const char* start = stringStart; *start; start++){
		if(*start == '"') instring = !instring; 
		else if (*start == ',' && !instring) { splitString.push_back(string(stringStart, start-stringStart)); stringStart = start + 1;}
	    
	    }
	    splitString.push_back(string(stringStart));
	   }
	int splitStringSize = splitString.size();
	/*for(int x = 0; x < splitStringSize; x++){
		cout << splitString.at(x) << endl;
	}*/
	//stringstream(splitString[0]) >> tree_id ;
	stringstream(splitString[0]) >> ObjectId;
	The_Geom = splitString.at(3);
	URL = splitString.at(1); 
	Name = splitString.at(2); 
	Line = splitString.at(4);
	//getObjectFix("hi");
	
	//cout << ObjectId << "\t" << The_Geom << "\t" << URL << "\t" << Name << "\t" << Line << endl;
	
	
	
}
void subwayStation::getObjectFixLine(){
	string tempStr;
	istringstream iss(Line);
	while ( getline ( iss, tempStr, '-')){
		subwayLines.LineStrE.push_back(tempStr);
	}
	for (std::vector<string>::const_iterator i = subwayLines.LineStrE.begin(); i != subwayLines.LineStrE.end(); ++i){
    		//cout << *i;
	}
}

void subwayStation::getObjectFixGeom(){
	string tempString = The_Geom;
	//cout << tempString << endl;
	tempString.erase(0,7);
	tempString.erase(tempString.size()-1, tempString.size());
	string tempGet;
	istringstream iss(tempString);
	double value;
	getline( iss, tempGet, ' ');
	stringstream(tempGet) >> value;
	GeomObj.longitude = value;		
	getline( iss, tempGet, ' ');
	stringstream(tempGet) >> value;
	GeomObj.latitude = value;
	//cout <<  " geo obj " << GeomObj << endl;

}

ostream& operator<< (ostream & os, const subwayStation & t){
	os << t.ObjectId << "\t" << t.GeomObj << "\t" << t.URL << "\t" << setw(60) << t.Name << t.subwayLines;
}








