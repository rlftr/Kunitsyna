#pragma once
#include <string>
#include <iostream>

class station {

	int stationID;
public:
	static int stationMaxID;
	std::string name;
	int workshops;
	int workingWorkshops;
	int efficiency;

	station();
	int stationGetID() const;
	friend std::ostream& operator<< (std::ostream& out, const station& s);
	friend std::istream& operator >> (std::istream& in, station& s);
	friend std::ofstream& operator << (std::ofstream& fout, const station& s);
	friend std::ifstream& operator >> (std::ifstream& fin, station& s);
};
