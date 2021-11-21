
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <istream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void menu()
{
	std::cout << "\n   Menu." << endl;
	std::cout << "1. Add Pipe\n"
		<< "2. Add Station\n"
		<< "3. Viewing all objects\n"
		<< "4. Edit Pipe\n"
		<< "5. Edit Station\n"
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

struct pipe {
	int id;
	int diametr;
	int length;
	int repair;
	string name;
};

bool checkId(int& Id, vector<pipe>& pipes) {
	for (int i = 0; i < pipes.size(); ++i)
	{
		if (Id == pipes[i].id)
		{
			return false;
		}
	}
	return true;
}


void PipeEdit(pipe& p) {
	 if (p.id < 0) {
		 cout << "Pipe wasn't added. Please add pipe.\n";
	 }
	 else {
		 std::cout << "Is the pipe under repair? ('yes'- 1 or 'no'- 2): ";
		 p.repair = rightValue();

		 while (p.repair < 1 || p.repair > 2) {
			 std::cout << "Please enter 1(yes) or 2(no): ";
			 p.repair = rightValue();
			 continue;
		 }
		 cout << "\nPipe was edited.";
		 
	 }
}

int random(int r, int l) {
	srand(time(NULL));
	return l + (rand() % (r - l) + 1);
}

void AddPipes(vector<pipe>& pipes) {
	pipe p;
	int pipesId;
		while (true) {
			pipesId = random(1, 99);
			if (checkId(pipesId, pipes)) {
				p.id = pipesId;
				break;
			}
		}
		std::cout << "Pipe's id: " << p.id << "\n";

		cout << "Enter the name: ";
		cin.ignore(32767, '\n');
		getline(cin, p.name);

		std::cout << "Enter the diametr: ";
		p.diametr = rightValue();

		while (p.diametr <= 0) {
			std::cout << "The value must be > 0. Try again: ";
			p.diametr = rightValue();
			continue;
		}

		std::cout << "Enter the length: ";
		p.length = rightValue();

		while (p.length <= 0) {
			std::cout << "The value must be > 0. Try again: ";
			p.length = rightValue();
			continue;
		}

		std::cout << "Is the pipe under repair? ('yes'- 1 or 'no'- 2):  ";
		p.repair = rightValue();

		while (p.repair < 1 || p.repair > 2) {
			std::cout << "Please enter 1(yes) or 2(no): ";
			p.repair = rightValue();
			continue;
		}
		std::cout << "\nPipe was added.\n";
		pipes.push_back(p);
}

struct station {
	int id;
	string name;
	int workshops;
	int WorkshopsInOperation;
	int efficiency;
	int NotWorkingWorkshops;
};

bool checkId(int& Id, vector<station>& stations) {
	for (int i = 0; i < stations.size(); ++i)
	{
		if (Id == stations[i].id)
		{
			return false;
		}
	}
	return true;
}

void StationEdit(station& s) {
		std::cout << "Enter the number of workshops in operation: ";
		s.WorkshopsInOperation = rightValue();

		while (s.WorkshopsInOperation < 0) {
			std::cout << "The value must be >= 0. Try again: ";
			s.WorkshopsInOperation = rightValue();
			continue;
		}
		
		while (s.WorkshopsInOperation > s.workshops) {
			int enter;
			std::cout << "The value must be <= number of workshops. Maybe you didn't add station.\n";
			std::cout << "Please enter 1(menu) or 2(try again): \n";
			enter = rightValue();
			while (enter < 1 || enter > 2) {
				cout << "Please enter 1(menu) or 2(try again): \n";
				enter = rightValue();
			}
			if (enter == 1) {
				break;
			}
			if (enter == 2) {
				std::cout << "Enter the number of workshops in operation: ";
				s.WorkshopsInOperation = rightValue();
				continue;
			}
			while (enter < 1 || enter > 2) {
				cout << "Please enter 1(menu) or 2(try again): ";
				enter = rightValue();
			}

		}
		cout << "\nStation was edited.\n";
}

void AddStations(vector<station>& stations) {
	station s;
	int stationsId;
	while (true) {
		stationsId = random(1, 99);
		if (checkId(stationsId, stations)) {
			s.id = stationsId;
			break;
		}
	}
	std::cout << "Station id: " << s.id << "\n";
	std::cout << "Enter the name: ";
	cin.ignore(32767, '\n');
	getline(cin, s.name);
	std::cout << "Enter the number of workshops: ";
	s.workshops = rightValue();

	while (s.workshops < 0) {
		std::cout << "The value must be > 0. Try again: ";
		s.workshops = rightValue();
		continue;
	}

	std::cout << "Enter the number of workshops in operation: ";
	s.WorkshopsInOperation = rightValue();

	while (s.WorkshopsInOperation < 0) {
		std::cout << "The value must be >= 0. Try again: ";
		s.WorkshopsInOperation = rightValue();
		continue;
	}

	while (s.WorkshopsInOperation > s.workshops) {
		std::cout << "Number of working workshops can't be > number of workshops. Try again: ";
		s.WorkshopsInOperation = rightValue();
		continue;
	}

	std::cout << "Enter the efficiency (%): ";
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


	cout << "\nStation was added.\n";
	stations.push_back(s);
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

void Output(vector<pipe>& pipes, vector<station>& stations) {
	cout << "\nAll objects:\n";
	cout << "\nPipes: \n";
	if (pipes.size() != 0) {
	    for (vector<pipe>::size_type i = 0; i < pipes.size(); i++) {
			cout << "\nId: " << pipes[i].id;
			cout << "\nName: " << pipes[i].name;
			cout << "\nDiametr: " << pipes[i].diametr;
			cout << "\nLength: " << pipes[i].length;
			cout << "\nRepair ('yes' - 1, 'no' - 2): " << pipes[i].repair << "\n";
			continue;
		}
	}
	cout << "\nStations: \n";
	if (stations.size() != 0) {
	    for (vector<station>::size_type i = 0; i < stations.size(); i++) {
			cout << "\nId: " << stations[i].id;
			cout << "\nName: " << stations[i].name;
			cout << "\nWorkshops: " << stations[i].workshops;
			cout << "\nWorkshops In Operation: " << stations[i].WorkshopsInOperation;
			cout << "\nNumber of not working workshops: " << stations[i].NotWorkingWorkshops;
			cout << "\nEfficiency: " << stations[i].efficiency << "\n";
			continue;
		}
	}
}

void Save(vector<pipe>& pipes, vector<station>& stations) {
	ofstream file;
	file.open("data.txt");
	if (file.good()) {
		for (vector<pipe>::size_type i = 0; i < pipes.size(); i++) {
		    if (pipes.size() != 0) {
				file << "\nPipes: \n";
				file << "\nId: " << pipes[i].id;
				file << "\nName: " << pipes[i].name;
				file << "\nDiametr: " << pipes[i].diametr;
				file << "\nLength: " << pipes[i].length;
				file << "\nRepair ('yes' - 1, 'no' - 2): " << pipes[i].repair << "\n";
			}
		}

		for (vector<station>::size_type i = 0; i < stations.size(); i++) {
		    if (stations.size() != 0) {
				file << "\nStations: \n";
				file << "\nId: " << stations[i].id;
				file << "\nName: " << stations[i].name;
				file << "\nWorkshops: " << stations[i].workshops;
				file << "\nWorkshops In Operation: " << stations[i].WorkshopsInOperation;
				file << "\nNumber of not working workshops: " << stations[i].NotWorkingWorkshops;
				file << "\nEfficiency: " << stations[i].efficiency << "\n";
			}
		}
		file.close();
		cout << "Saved\n";
	}
}

int Load(vector<pipe>& pipes, vector<station>& stations) {
	ifstream inf("data.txt");
	if (!inf) {
		cerr << "data.txt couldn't be opened" << endl;
		exit(1);
	}

	while (inf) {
		string strInput;
		getline(inf, strInput);
		cout << strInput << endl;
	}
	return 0;
}

void SearchPipe(vector<pipe>& pipes) {
	if (pipes.size() != 0) {
		int input;
		string* pipesName = StringArray(pipes.size());
		int* pipesRepair = IntArray(pipes.size());
		cout << "Choose the filter:\n";
		cout << "1 - Name, 2 - Repair: ";
		input = rightValue();
		while ((input > 0 && input < 1) || input > 2) {
			cout << "Please enter 1(name) or 2(repair): ";
			continue;
		}
		bool While = true;
		while (While) {
			switch (input) {
			case 1: {
				for (vector<pipe>::size_type i = 0; i < pipes.size(); i++) {
				cout << "\nEnter the name of pipe: ";
				cin.ignore(32767, '\n');
				cin >> pipesName[i];
				
					while (pipes[i].name == pipesName[i]) {
						cout << "\nId: " << pipes[i].id;
						cout << "\nName: " << pipes[i].name;
						cout << "\nDiametr: " << pipes[i].diametr;
						cout << "\nLength: " << pipes[i].length;
						cout << "\nRepair: " << pipes[i].repair;
						break;
					}

				}
				continue;
			}
			case 2: {
				for (vector<pipe>::size_type i = 0; i < pipes.size(); i++) {
				cout << "\nIs pipe under repair? (1 - yes, 2 - no): ";
				pipesRepair[i] = rightValue();
				while (pipesRepair[i] < 1 || pipesRepair[i] > 2) {
					cout << "\nPlease enter 1 - yes or 2 - no: ";
					continue;
				}
					while (pipes[i].repair == pipesRepair[i]) {
						cout << "\nId: " << pipes[i].id;
						cout << "\nName: " << pipes[i].name;
						cout << "\nDiametr: " << pipes[i].diametr;
						cout << "\nLength: " << pipes[i].length;
						cout << "\nRepair: " << pipes[i].repair;
						break;
					}
				}
				continue;
			}
			default: {
				cout << "Error\n\n";
				continue;
			}
			}
		}
	}
	else {
		cout << "\nPipes wasn't added.";
	}
}

void SearchStation(vector<station>& stations) {
	if (stations.size() != 0) {
		int input;
		string* stationsName = StringArray(stations.size());
		int* stationsNotWorkingWorkshops = IntArray(stations.size());
		bool While = true;
		while (While) {
			cout << "Choose the filter:\n";
			cout << "1 - Name, 2 - Number of not working workshops: ";
			input = rightValue();
			while (input < 1 || input > 2) {
				cout << "\nPlease enter 1(name) or 2(number of not working workshops): ";
				continue;
			}
			switch (input) {
			case 1:
				for (vector<station>::size_type i = 0; i < stations.size(); i++) {
				cout << "\nEnter the name of station: ";
				cin.ignore(32767, '\n');
				cin >> stationsName[i];
					while (stations[i].name == stationsName[i]) {
						cout << "\nId: " << stations[i].id;
						cout << "\nName: " << stations[i].name;
						cout << "\nNumber of workshops: " << stations[i].workshops;
						cout << "\nNumber of workshops in operation: " << stations[i].WorkshopsInOperation;
						cout << "\nNumber of not working workshops: " << stations[i].NotWorkingWorkshops;
						cout << "\nEfficiency: " << stations[i].efficiency;
						break;
					}
				}
			case 2:
				for (vector<station>::size_type i = 0; i < stations.size(); i++) {
				cout << "\nEnter the number of not working workshops: ";
				stationsNotWorkingWorkshops[i] = rightValue();
					while (stations[i].NotWorkingWorkshops == stationsNotWorkingWorkshops[i]) {
						cout << "\nId: " << stations[i].id;
						cout << "\nName: " << stations[i].name;
						cout << "\nNumber of workshops: " << stations[i].workshops;
						cout << "\nNumber of workshops in operation: " << stations[i].WorkshopsInOperation;
						cout << "\nNumber of not working workshops: " << stations[i].NotWorkingWorkshops;
						cout << "\nEfficiency: " << stations[i].efficiency;
						break;
					}
				}
			default: 
				cout << "Error\n\n";
				continue;
			}
		}
	}
	else {
		cout << "Stations wasn't added.";
	}
}

void EditPipes(vector<pipe>& pipes) {
	if (pipes.size() != 0) {
		int choose;
		cout << "What whould you do?\n";
		cout << "1 - edit all pipes, 2 - edit several pipes: ";
		choose = rightValue();
		while (choose < 1 || choose > 2) {
			cout << "\nPlease enter 1(edit all pipes) or 2(edit several pipes): ";
			choose = rightValue();
		}

		bool While = true;
		while (While) {
			switch (choose) {
			case 1:
				
			case 2:
				
			default:
				cout << "Error\n\n";
				continue;
			}
		}
	}
	else {
		cout << "Pipes wasn't added.";
	}
}

void EditStations(vector<station>& stations) {
	if (stations.size() != 0) {
		int choose;
		cout << "What whould you do?\n";
		cout << "1 - edit all stations, 2 - edit several stations: ";
		choose = rightValue();
		while (choose < 1 || choose > 2) {
			cout << "\nPlease enter 1(edit all stations) or 2(edit several stations): ";
			choose = rightValue();
		}

		bool While = true;
		while (While) {
			switch (choose) {
			case 1:

			case 2:

			default:
				cout << "Error\n\n";
				continue;
			}
		}
	}
	else {
		cout << "Stations wasn't added.";
	}
}

int main()
{
	vector <pipe> pipes;
	vector <station> stations;
	int i;
	pipe p{};
	station s{};
	int a;
	bool While = true;
	while (While) {
		menu();
		cin >> a;
		switch (a) {
		case 1:
			AddPipes(pipes);
			continue;
		case 2:
			AddStations(stations);
			continue;
		case 3:
			Output(pipes, stations);
			continue;
		case 4:
			PipeEdit(p);
			continue;
		case 5:
			StationEdit(s);
			continue;
		case 6:
			Save(pipes, stations);
			continue;
		case 7:
			Load(pipes, stations);
			continue;
		case 8:
			SearchPipe(pipes);
		case 9:
			SearchStation(stations);
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





