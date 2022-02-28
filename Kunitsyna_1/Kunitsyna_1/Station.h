#pragma once
#include <unordered_map>
#include <string>
using namespace std;

class station {

public:
	unordered_map <int, station> stations;
	station();
	static int id;
	string name;
	int workshops;
	int WorkshopsInOperation;
	int efficiency;
	int NotWorkingWorkshops;
	friend ostream& operator<< (ostream&, const unordered_map <int, station>&);
	void AddStation(station& s);
	void SearchStation(unordered_map<station, int>& stations);
	void EditStations(unordered_map<station, int>& stations);
	void DeleteStations(unordered_map<station, int>& stations);
};

