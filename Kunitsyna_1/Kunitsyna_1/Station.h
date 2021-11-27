#pragma once
#include <vector>
#include <string>

class station {

public:
	static int id;
	string name;
	int workshops;
	int WorkshopsInOperation;
	int efficiency;
	int NotWorkingWorkshops;
	bool checkId(int& Id, vector<station>& stations);
	void AddStations(vector<station>& stations);
	void SearchStation(vector<station>& stations);
	void EditStations(vector<station>& stations);
};
