#pragma once
#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;

class station {

	int stationID;
public:
	station();
	static int stationMaxID;
	string name;
	int workshops;
	int workingWorkshops;
	int efficiency;
	int stationGetID() const;
	friend ostream& operator<< (ostream& out, const station& s);
	friend istream& operator >> (istream& in, station& s);
	friend ofstream& operator << (ofstream& fout, const station& s);
	friend ifstream& operator >> (ifstream& fin, station& s);
};

