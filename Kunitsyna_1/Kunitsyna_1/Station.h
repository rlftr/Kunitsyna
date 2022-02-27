#pragma once
#include <unordered_map>
#include <string>
using namespace std;

class station {

public:
	int id;
	static int ID;
	string name;
	int workshops;
	int WorkshopsInOperation;
	int efficiency;
	int NotWorkingWorkshops;
	istream& operator>> (station& s);
	void SearchStation(unordered_map<station, int>& stations);
	void EditStations(unordered_map<station, int>& stations);
	void DeleteStations(unordered_map<station, int>& stations);
};

