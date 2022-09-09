#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <unordered_map>
#include "Station.h"
using namespace std;

int station::stationMaxID = 0;
station::station()
{
	stationID = ++stationMaxID;
}

int station::stationGetID() const
{
	return stationID;
}

ostream& operator << (ostream& out, const station& s)
{
	out << "\nId: " << s.stationID << endl;
	out << "\nName: " << s.name;
	out << "\nWorkshops: " << s.workshops;
	out << "\nWorking Workshops: " << s.workingWorkshops;
	out << "\nEfficiency: " << i.second.efficiency << "\n";
	return out;
}


istream& operator >> (istream& in, station& s) {
	cout << "Enter the name: ";
	cin.ignore(32767, '\n');
	getline(cin, s.name);
	cout << "Enter the number of workshops: ";
	s.workshops = rightValue(1, 1000);
	cout << "Enter the number of working workshops: ";
	s.WorkshopsInOperation = rightValue(0, s.workshops);
	cout << "Enter the efficiency (%): ";
	s.efficiency = rightValue(1, 100);
	return in;
	cout << "\nStation was added.\n";
}

ifstream& operator >> (ifstream& fin, CS& cs)
{
	fin >> s.stationID
		>> s.name
		>> s.workshops
		>> s.workingWorkshops
		>> s.efficiency;
	return fin;
}

ofstream& operator << (ofstream& fout, const station& s)
{
	fout << "Station: " << endl
		<< s.stationID << endl
		<< s.name << endl
		<< s.workshops << endl
		<< s.workingWorkshops << endl
		<< s.efficiency << endl;
	return fout;
}

void EditStation(station& s)
{
	cout << "Enter the new number of working workshops: \n";
	workingWorkshops = rightValue(1, s.workshops);
}

station& SelectStation(unordered_map <int, station>& stations)
{
	cout << "Enter the index of station: ";
	unsigned int index = rightValue(1, stations.size());
	return stations[index];
}

template <typename T>
using stationFilter = bool(*)(const station& s, T param);

bool CheckByName(const station& s, string param)
{
	return s.name == param;
}

bool CheckByPercent(const station& s, int param)
{
	int percent = int(cs.count_of_workshops - cs.working_workshops) / cs.count_of_workshops * 100;
	return percent == param;
}

template <typename T>
vector <int> FindStationsByFilter(const unordered_map <int, station>& map, stationFilter <T> f, T param)
{
	vector <int> res;
	for (auto& i : map)
	{
		if (f(i.second, param))
			res.push_back(i.first);
	}
	if (res.size() == 0)
	{
		cout << "Stations not found." << endl;
	}
	return res;
}

void SearchStation(unordered_map <int, station>& stations) {
	while (true)
	{
		findStationMenu();
		vector <int> result;
		switch (rightValue(0, 2))
		{
		case 1:
		{
			string sName;
			cout << "Find station by name: ";
			cin.ignore(10000, '\n');
			getline(cin, sName);
			result = FindStationsByFilter(stations, CheckByName, sName);
			cout << result;
			break;
		}
		case 2:
		{
			cout << "Find station by number of not working workshops : ";
			int percent = rightValue(0, 100);
			result = FindStationsByFilter(stations, CheckByPercent, percent);
			cout << result;
			break;
		}
		case 0:
		{
			return;
		}
		default:
		{
			cout << "Error. Try again: " << endl;
			break;
		}
		}
	}
}

void DeleteStation(unordered_map<station, int>& stations) {

	cout << "Enter the index of station: ";
	int index = rightValue(1, stations.size());
	stations.erase(index);
}

