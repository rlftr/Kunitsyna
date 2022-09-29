#include <fstream>
#include "Station.h"
#include "Utils.h"
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
	out << "\nEfficiency: " << s.efficiency << "\n";
	return out;
}


istream& operator >> (istream& in, station& s) {
	cout << "Enter the name: ";
	cin.ignore(32767, '\n');
	getline(cin, s.name);
	cout << "Enter the number of workshops: ";
	s.workshops = rightValue(1, 1000);
	cout << "Enter the number of working workshops: ";
	s.workingWorkshops = rightValue(0, s.workshops);
	cout << "Enter the efficiency (%): ";
	s.efficiency = rightValue(1, 100);
	cout << "\nStation was added.\n";
	return in;
}

ifstream& operator >> (ifstream& fin, station& s)
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
	fout << s.stationID << "\n"
		<< s.name << "\n"
		<< s.workshops << "\n"
		<< s.workingWorkshops << "\n"
		<< s.efficiency << "\n";
	return fout;
}






