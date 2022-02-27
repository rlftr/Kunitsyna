
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <istream>
#include <string>
#include <unordered_map>
#include "Station.h"
#include "Pipe.h"


using namespace std;

void menu()
{
	cout << "\n   Menu." << endl;
	cout << "1. Add Pipe\n"
		<< "2. Add Station\n"
		<< "3. Viewing all objects\n"
		<< "4. Edit Pipes\n"
		<< "5. Edit Stations\n"
		<< "6. Save\n"
		<< "7. Load\n"
		<< "8. Search Pipe\n"
		<< "9. Search Station\n"
		<< "0. Exit\n";
}

int rightValue() {
	int enter;
	while (true) {
		std::cin >> enter;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(32767, '\n');
			std::cout << "Error. Try again: ";
		}
		else {
			return enter;
		}
	}
}

string* StringArray(int lines)
{
	string* array = new string[lines];
	return array;
}

int* IntArray(int lines)
{
	int* array = new int[lines];
	return array;
}

void Save(unordered_map<pipe, int>& pipes, unordered_map<station, int>& stations) {
	static int id;
	int diametr;
	int length;
	int repair;
	string name;
	int workshops;
	int WorkshopsInOperation;
	int efficiency;
	int NotWorkingWorkshops;
	ofstream file;
	file.open("data.txt");
	if (file.good()) {
		for (auto& i : pipes) {
			if (pipes.size() != 0) {
				file << "\nPipes\n";
				file << id << "\n";
				file << name << "\n";
				file << diametr << "\n";
				file << length << "\n";
				file << repair << "\n";
			}
		}

		for (auto& i : stations) {
			if (stations.size() != 0) {
				file << "\nStations\n";
				file << id << "\n";
				file << name << "\n";
				file << workshops << "\n";
				file << WorkshopsInOperation << "\n";
				file << NotWorkingWorkshops << "\n";
				file << efficiency << "\n";
			}
		}
		file.close();
		cout << "Saved\n";
	}
	else {
		cout << "Could't save to file";
	}
}

void Load(unordered_map<pipe, int>&pipes, unordered_map<station, int>&stations) {
	ifstream file;
	int id;
	int diametr;
	int length;
	int repair;
	string name;
	int workshops;
	int WorkshopsInOperation;
	int efficiency;
	file.open("data.txt");
	if (file.good()) {
		for (auto& i : pipes) {
			if (pipes.size() != 0) {
				while (!file.eof()) {
					string type;
					file >> type;
					if (type == "Pipe") {
						file >> id;
						file >> diametr;
						file >> length;
						file >> repair;
					}
				}
			}
		}
		for (auto& i : stations) {
			if (stations.size() != 0) {
				while (!file.eof()) {
					string type;
					file >> type;
					if (type == "Station") {
						file >> id;
						file >> name;
						file >> workshops;
						file >> WorkshopsInOperation;
						file >> efficiency;
					}
				}
			}
		}
		cout << "Loaded\n";
		file.close();
	}
	else {
		cout << "data.txt can't be opened.\n";
	}
}

int main(unordered_map<pipe, int>& pipes, unordered_map<station, int>& stations) {
	int i;
	pipe p;
	station s;
	int a;
	bool While = true;
	while (While) {
		menu();
		cin >> a;
		switch (a) {
		case 1:
			istream & operator>> (istream & in, pipe & p);
			continue;
		case 2:
			istream & operator>> (istream & in, station & s);
			continue;
		case 3:
			ostream & operator<< (ostream & out, const unordered_map<pipe, int>&pipes);
			continue;
		case 4:
			ostream & operator<< (ostream & out, const unordered_map<station, int>&stations);
		case 5:
			EditPipes(pipes);
			continue;
		case 6:
			EditStations(stations);
			continue;
		case 7:
			Save(pipes, stations);
			continue;
		case 8:
			Load(pipes, stations);
			continue;
		case 9:
			SearchPipe(pipes);
		case 10:
			SearchStation(stations);
		case 11: 
			DeletePipes(pipes);
		case 12:
			DeleteStations(stations);
		case 0:
			While = false;
			break;
		default:
			cout << "Error\n\n";
			continue;
		}
		return 0;
	}
}





