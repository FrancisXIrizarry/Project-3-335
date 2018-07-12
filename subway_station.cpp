#include "subway_station.h"

subwayEntrance::subwayEntrance(const string & subwayInfo){ 
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
	stringstream(splitString[0]) >> ObjectId;
	The_Geom = splitString.at(3);
	URL = splitString.at(1); 
	Name = splitString.at(2); 
	Line = splitString.at(4);
}
void subwayEntrance::getObjectFixLine(){
	string tempStr;
	istringstream iss(Line);
	while ( getline ( iss, tempStr, '-')){
		subwayLines.LineStrE.push_back(tempStr);
	}
}

void subwayEntrance::getObjectFixGeom(){
	string tempString = The_Geom;
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
	
}
bool operator==(const subwayEntrance & t1, const subwayEntrance & t2)
{
}
double subwayStation::haversine(double lat1, double lon1, double lat2, double lon2) {
  lat1 = TO_RAD * lat1;
  lat2 = TO_RAD * lat2;
  lon1 = TO_RAD * lon1;
  lon2 = TO_RAD * lon2;
  double dLat = (lat2 - lat1) / 2;
  double dLon = (lon2 - lon1) / 2;
  double a = sin(dLat);
  double b = sin(dLon);
  return 2 * R * asin(sqrt(a * a + cos(lat1) * cos(lat2) * b * b));
}



ostream& operator<< (ostream & os, const subwayEntrance & t){
	os << t.ObjectId << "\t" << t.GeomObj << "\t" << t.URL << "\t" << setw(60) << t.Name << t.subwayLines;
}





SmallSet::SmallSet(bitstring j)
{
	//cout << "test" << endl;
    for (int i = 0; i < WORD_BIT; i++) {
        mask[i] = 1 << i;
	//cout << mask[i] << " Why " << endl;
    }
    set = j;
    size = __builtin_popcount (j); // only in GNU
}


bitstring do_union(SmallSet s, SmallSet t)
{
    return s.set | t.set;
}

bitstring intersection(SmallSet s, SmallSet t)
{
    return s.set & t.set;
}


bitstring SmallSet::complement()
{
    return  set ^ (unsigned)(-1);  // xor with 111...1
}

void SmallSet::add(int i)
{
    if ( 0 <= i && i < WORD_BIT ) {
        if (! contains(i) ) {
            set = set | mask[i];
            size++;
        }
    }
}


bool SmallSet::contains(int i)
{
    if ( 0 <= i && i < WORD_BIT ){
	cout << "Set " << set << " mask [i] " << mask[i] << " " << i << endl;
        return( set & mask[i] )? true: false;
	}
    else
        return false;
}

void SmallSet::print(std::ostream & out)
{
    out << "{ ";
    for (int i = 0; i < WORD_BIT; i++) {
        if (set & mask[i])
            out << i << " ";
    }
    out << "}\n";

}





