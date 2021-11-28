#pragma once
#include <vector>
#include <string>
using namespace std;

class station {

public:
	int id;
	string name;
	int workshops;
	int WorkshopsInOperation;
	int efficiency;
	int NotWorkingWorkshops;
	bool checkId();
	void AddStations();
	void SearchStation();
	void EditStations();
};
