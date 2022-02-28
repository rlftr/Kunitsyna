
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <istream>
#include <string>
#include <unordered_map>
#include "Station.h"
#include "Pipe.h"

using namespace std;
int pipe::id = 0;
int station::id = 0;

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
		<< "10. Delete Pipes\n"
		<< "11. Delete Stations\n"
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
	ofstream file;
	int id;
	int diametr;
	int length;
	int repair;
	string name;
	int workshops;
	int WorkshopsInOperation;
	int efficiency;
	int NotWorkingWorkshops;
	file.open("data.txt");
	if (file.good()) {
		if (pipes.size() != 0) {
		for (auto& i : pipes) {
				file << "\nPipes\n";
				file << i.first << "\n";
				file << i.second.name << "\n";
				file << i.second.diametr << "\n";
				file << i.second.length << "\n";
				file << i.second.repair << "\n";
			}
		}

			if (stations.size() != 0) {
				for (auto& i : stations) {
				file << "\nStations\n";
				file << i.first << "\n";
				file << i.second.name << "\n";
				file << i.second.workshops << "\n";
				file << i.second.WorkshopsInOperation << "\n";
				file << i.second.NotWorkingWorkshops << "\n";
				file << i.second.efficiency << "\n";
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
	pipe p1, p;
	station s1, s;
	int a;
	bool While = true;
	while (While) {
		menu();
		cin >> a;
		switch (a) {
		case 1:
			p1.AddPipe(p);
			continue;
		case 2:
			s1.AddStation(s);
			continue;
		case 3:
			cout << p1.pipes;
			cout << s1.stations;
			continue;
		case 4:
			p1.EditPipes(pipes);
			continue;
		case 5:
			s1.EditStations(stations);
			continue;
		case 6:
			Save(pipes, stations);
			continue;
		case 7:
			Load(pipes, stations);
			continue;
		case 8:
			p1.SearchPipe(pipes);
		case 9:
			s1.SearchStation(stations);
		case 10:
			p1.DeletePipes(pipes);
		case 11:
			s1.DeleteStations(stations);
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




