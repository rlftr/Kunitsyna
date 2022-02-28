#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <unordered_map>
#include "Station.h"
using namespace std;

int rightValue();

station::station()
{
	id++;
	this->name = "";
	this->workshops = 0;
	this->WorkshopsInOperation = 0;
	this->efficiency = 0;
}


void station::AddStation(station& s) {
	station::id++;
	cout << "Enter the name: ";
	cin.ignore(32767, '\n');
	getline(cin, s.name);
	cout << "Enter the number of workshops: ";
	s.workshops = rightValue();

	while (s.workshops < 0) {
		cout << "The value must be > 0. Try again: ";
		s.workshops = rightValue();
		continue;
	}

	cout << "Enter the number of workshops in operation: ";
	s.WorkshopsInOperation = rightValue();

	while (s.WorkshopsInOperation < 0) {
		cout << "The value must be >= 0. Try again: ";
		s.WorkshopsInOperation = rightValue();
		continue;
	}

	while (s.WorkshopsInOperation > s.workshops) {
		cout << "Number of working workshops can't be > number of workshops. Try again: ";
		s.WorkshopsInOperation = rightValue();
		continue;
	}

	cout << "Enter the efficiency (%): ";
	s.efficiency = rightValue();

	while (s.efficiency < 0 || s.efficiency > 100) {
		cout << "The value must be >= 0 and <= 100. Try again: ";
		s.efficiency = rightValue();
		continue;
	}

	if ((s.workshops != 0) && (s.WorkshopsInOperation >= 0)) {
		s.NotWorkingWorkshops = s.workshops - s.WorkshopsInOperation;
		cout << "Number of not working workshops: ";
		cout << s.NotWorkingWorkshops;
	}
	return s;

	cout << "\nStation was added.\n";
}

ostream& operator<< (ostream& out, const unordered_map<station, int>& stations) {
	out << "\nAll stations: \n";
	if (stations.size() != 0) {
		for (auto& i : stations) {
			out << "\nId: " << i.first << endl;
			out << "\nName: " << i.second.name;
			out << "\nWorkshops: " << i.second.workshops;
			out << "\nWorkshops In Operation: " << i.second.WorkshopsInOperation;
			out << "\nNumber of not working workshops: " << i.second.NotWorkingWorkshops;
			out << "\nEfficiency: " << i.second.efficiency << "\n";
			continue;
		}
	}
	return out;
}

void station::EditStations(unordered_map<station, int>& stations) {
	int input;
	int input1;
	int input2;
	string* Name = StringArray(stations.size());
	int* NotWorkingWorkshops = IntArray(stations.size());
	cout << "What would you do?\n";
	cout << "1 - Edit all stations, 2 - Edit few stations: ";
	input = rightValue();
	while (input > 2 || input < 1) {
		cout << "Please enter 1(edit all stations) or 2(edit few stations): ";
		input = rightValue();
	}
	switch (input) {
	case 1:
		cout << "\nChoose the filter:\n";
		cout << "1 - Name, 2 - Number of not working workshops: ";
		input1 = rightValue();
		while ((input1 < 1) || (input1 > 2)) {
			cout << "\nPlease enter 1(name) or 2(number of not working workshops): ";
			break;
		}
		switch (input1) {
		case 1:
			if (stations.size() != 0) {
				for (auto& i : stations) {
					cout << "\nEnter the name of station: ";
					cin.ignore(32767, '\n');
					cin >> Name[i];
					while (Name[i] == i.second.name) {
						cout << "Enter the new number of working workshops: ";
						i.second.WorkshopsInOperation = rightValue();
						while (i.second.WorkshopsInOperation < 0) {
							std::cout << "The value must be >= 0. Try again: ";
							i.second.WorkshopsInOperation = rightValue();
							break;
						}
						while (i.second.WorkshopsInOperation > i.second.workshops) {
							std::cout << "Number of working workshops can't be > number of workshops. Try again: ";
							i.second.WorkshopsInOperation = rightValue();
							break;
						}
						break;
					}
					if (Name[i] != i.second.name) {
						cout << "No stations with this name.\n";
						break;
					}
				}
			}
			break;
		case 2:
			if (stations.size() != 0) {
				for (auto& i : stations) {
					cout << "\nEnter the number of not working workshops: ";
					NotWorkingWorkshops[i] = rightValue();
					while (NotWorkingWorkshops[i]< 0) {
						std::cout << "The value must be >= 0. Try again: ";
						NotWorkingWorkshops[i] = rightValue();
						continue;
					}
					while (NotWorkingWorkshops[i] > i.second.workshops) {
						std::cout << "Number of working workshops can't be > number of workshops. Try again: ";
						NotWorkingWorkshops[i] = rightValue();
						continue;
					}
					while (i.second.NotWorkingWorkshops == NotWorkingWorkshops[i]) {
						cout << "Enter the new number of working workshops: ";
						i.second.WorkshopsInOperation = rightValue();
						while (i.second.WorkshopsInOperation < 0) {
							cout << "The value must be >= 0. Try again: ";
							i.second.WorkshopsInOperation = rightValue();
							continue;
						}
						while (i.second.WorkshopsInOperation > i.second.workshops) {
							cout << "Number of working workshops can't be > number of workshops. Try again: ";
							i.second.WorkshopsInOperation = rightValue();
							continue;
						}
						break;
					}
					if (i.second.NotWorkingWorkshops != NotWorkingWorkshops[i]) {
						cout << "No stations with this name.\n";
						break;
					}
				}
			}
			else {
				cout << "Stations wasn't added.\n";
			}
			break;
		default:
			break;
		}
	case 2:
		if (stations.size() != 0) {
			for (auto& i : stations) {
				cout << "\nChoose the filter:\n";
				cout << "1 - Name, 2 - Number of not working workshops: ";
				input2 = rightValue();
				while ((input2 < 1) || (input2 > 2)) {
					cout << "\nPlease enter 1(name) or 2(number of not working workshops): ";
					break;
				}
				switch (input2) {
				case 1:
					cout << "\nEnter the name of station: ";
					cin.ignore(32767, '\n');
					cin >> Name[i];
					if (i.second.name == Name[i]) {
						cout << "Enter the new number of worling workshops: ";
						i.second.WorkshopsInOperation = rightValue();
						while (i.second.WorkshopsInOperation < 0) {
							std::cout << "The value must be >= 0. Try again: ";
							i.second.WorkshopsInOperation = rightValue();
							continue;
						}
						while (i.second.WorkshopsInOperation > i.second.workshops) {
							std::cout << "Number of working workshops can't be > number of workshops. Try again: ";
							i.second.WorkshopsInOperation = rightValue();
							continue;
						}
						break;
					}
					if (i.second.name != Name[i]) {
						cout << "No stations with this name.\n";
						break;
					}
					break;
				case 2:
					cout << "\nEnter the number of not working workshops: ";
					NotWorkingWorkshops[i] = rightValue();
					while (NotWorkingWorkshops[i] < 0) {
						std::cout << "The value must be >= 0. Try again: ";
						NotWorkingWorkshops[i] = rightValue();
						continue;
					}
					while (NotWorkingWorkshops[i] > i.second.workshops) {
						std::cout << "Number of working workshops can't be > number of workshops. Try again: ";
						NotWorkingWorkshops[i] = rightValue();
						continue;
					}
					if (i.second.NotWorkingWorkshops == NotWorkingWorkshops[i]) {
						cout << "Enter the new number of working workshops: ";
						i.second.WorkshopsInOperation = rightValue();
						while (i.second.WorkshopsInOperation < 0) {
							std::cout << "The value must be >= 0. Try again: ";
							i.second.WorkshopsInOperation = rightValue();
							continue;
						}
						while (i.second.WorkshopsInOperation > i.second.workshops) {
							std::cout << "Number of working workshops can't be > number of workshops. Try again: ";
							i.second.WorkshopsInOperation = rightValue();
							continue;
						}
						break;
					}
					if (i.second.NotWorkingWorkshops != NotWorkingWorkshops[i]) {
						cout << "No stations with this name.\n";
						break;
					}
					break;
				default:
					break;
				}
			}
		}
		else {
			cout << "Stations wasn't added.\n";
		}
		break;
	default:
		break;
	}
}

void station::SearchStation(unordered_map<station, int>& stations) {
	int input;
	string* stationsName = StringArray(stations.size());
	int* stationsNotWorkingWorkshops = IntArray(stations.size());
	cout << "\nChoose the filter:\n";
	cout << "1 - Name, 2 - Number of not working workshops: ";
	input = rightValue();
	while ((input < 1) || (input > 2)) {
		cout << "\nPlease enter 1(name) or 2(number of not working workshops): ";
		break;
	}
	switch (input) {
	case 1:
		for (auto& i : stations) {
			if (stations.size() != 0) {
				cout << "\nEnter the name of station: ";
				cin.ignore(32767, '\n');
				cin >> stationsName[i];
				while (i.second.name == stationsName[i]) {
					cout << "\nId: " << i.first;
					cout << "\nName: " << i.second.name;
					cout << "\nNumber of workshops: " << i.second.workshops;
					cout << "\nNumber of workshops in operation: " << i.second.WorkshopsInOperation;
					cout << "\nNumber of not working workshops: " << i.second.NotWorkingWorkshops;
					cout << "\nEfficiency: " << i.second.efficiency;
					break;
				}
				if (i.second.name != stationsName[i]) {
					cout << "No stations with this name.\n";
					break;
				}
			}
			else {
				cout << "Stations wasn't added.\n";
			}
		}
		break;
	case 2:
		for (auto& i : stations) {
			if (stations.size() != 0) {
				cout << "\nEnter the number of not working workshops: ";
				stationsNotWorkingWorkshops[i] = rightValue();
				while (i.second.NotWorkingWorkshops == stationsNotWorkingWorkshops[i]) {
					cout << "\nId: " << i.second.id;
					cout << "\nName: " << i.second.name;
					cout << "\nNumber of workshops: " << i.second.workshops;
					cout << "\nNumber of workshops in operation: " << i.second.WorkshopsInOperation;
					cout << "\nNumber of not working workshops: " << i.second.NotWorkingWorkshops;
					cout << "\nEfficiency: " << i.second.efficiency;
					break;
				}
				if (i.second.NotWorkingWorkshops != stationsNotWorkingWorkshops[i]) {
					cout << "No stations with this number of not worling workshops.\n";
					break;
				}
			}
			else {
				cout << "Stations wasn't added.\n";
			}
		}
		break;
	}
}

void station::DeleteStations(unordered_map<station, int>& stations) {
	int ID;
	cout << "Enter the id of station you want to delete: \n";
	ID = rightValue();
	for (auto& i : stations) {
		if (stations.count(ID) != 0) {
			while (ID != -1 && stations.count(ID) != 0) {
				stations.erase(stations.find(ID));
			}
		}
		else {
			cout << "No station with this id.\n";
		}
	}
}

