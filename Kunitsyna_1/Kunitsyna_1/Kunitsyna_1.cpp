
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
		std::cout << "Pipe id: " << p.id << "\n";

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
	int percentWNIO;
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
			int e;
			std::cout << "The value must be <= number of workshops. Maybe you didn't add station.\n";
			std::cout << "Please enter 1(menu) or 2(try again): \n";
			e = rightValue();
			if (e == 1) {
				break;
			}
			if (e == 2) {
				std::cout << "Enter the number of workshops in operation: ";
				s.WorkshopsInOperation = rightValue();
				continue;
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

	std::cout << "Percent of not working workshops: ";
	s.percentWNIO = ((s.workshops - s.WorkshopsInOperation) / s.workshops) * 100;
	std::cout << s.percentWNIO << endl;

	while (s.efficiency < 0 || s.efficiency > 100) {
		std::cout << "The value must be >= 0 and <= 100. Try again: ";
		s.efficiency = rightValue();
		continue;
	}

	cout << "\nStation was added.\n";
	stations.push_back(s);
}

void Output(vector<pipe>& pipes, vector<station>& stations) {
	cout << "\nAll objects:\n";
	cout << "\nPipes: \n";
	for (int i = 1; i < pipes.size() + 1; ++i) {
		if (pipes.size() != 0) {
			cout << "\nId: " << pipes[i - i].id;
			cout << "\nName: " << pipes[i - i].name;
			cout << "\nDiametr: " << pipes[i - i].diametr;
			cout << "\nLength: " << pipes[i - i].length;
			cout << "\nRepair ('yes' - 1, 'no' - 2): " << pipes[i - i].repair << "\n";
			continue;
		}
	}
	cout << "\nStations: \n";
	for (int i = 1; i < stations.size() + 1; ++i) {
		if (stations.size() != 0) {
			cout << "\nId: " << stations[i - i].id;
			cout << "\nName: " << stations[i - i].name;
			cout << "\nWorkshops: " << stations[i - i].workshops;
			cout << "\nWorkshops In Operation: " << stations[i - i].WorkshopsInOperation;
			cout << "\nPercent of not working workshops: " << stations[i - i].percentWNIO;
			cout << "\nEfficiency: " << stations[i - i].efficiency << "\n";
			continue;
		}
	}
}

void Save(vector<pipe>& pipes, vector<station>& stations) {
	ofstream file;
	file.open("database.txt");
	if (file.good()) {
		for (int i = 1; i < pipes.size() + 1; i++) {
		    if (pipes.size() != 0) {
				file << "\nPipes: \n";
				file << "\nId: " << pipes[i - i].id;
				file << "\nName: " << pipes[i - i].name;
				file << "\nDiametr: " << pipes[i - i].diametr;
				file << "\nLength: " << pipes[i - i].length;
				file << "\nRepair ('yes' - 1, 'no' - 2): " << pipes[i - i].repair << "\n";
			}
		}

		for (int i = 1; i < stations.size() + 1; i++) {
		    if (stations.size() != 0) {
				file << "\nStations: \n";
				file << "\nId: " << stations[i - i].id;
				file << "\nName: " << stations[i - i].name;
				file << "\nWorkshops: " << stations[i - i].workshops;
				file << "\nWorkshops In Operation: " << stations[i - i].WorkshopsInOperation;
				file << "\nPercent of not working workshops: " << stations[i - i].percentWNIO;
				file << "\nEfficiency: " << stations[i - i].efficiency << "\n";
			}
		}
		file.close();
		cout << "Saved\n";
	}
}

int Load(vector<pipe>& pipes, vector<station>& stations) {
	ifstream inf("database.txt");
	if (!inf) {
		cerr << "database.txt couldn't be opened" << endl;
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
		int choose;
		string pipesName;
		int pipesRepair;
		cout << "Choose the filter:\n";
		cout << "1 - Name, 2 - Repair: ";
		choose = rightValue();
		while (choose < 1 || choose > 2) {
			cout << "Please enter 1(name) or 2(repair): ";
			continue;
		}

		switch (choose) {
		case 1: 
			cout << "Enter the name of pipe: ";
			cin.ignore(32767, '\n');
			getline(cin, pipesName);
			for (int i = 1; i < pipes.size() + 1; i++) {
				if (pipes[i - i].name == pipesName) {
					cin >> pipes[i - i].id;
					cin >> pipes[i - i].name;
					cin >> pipes[i - i].diametr;
					cin >> pipes[i - i].length;
					cin >> pipes[i - i].repair;
				}
			}
		case 2: 
			cout << "Is pipe under repair? (1 - yes, 2 - no): ";
			pipesRepair = rightValue();
			while (pipesRepair < 1 || pipesRepair > 2) {
				cout << "Please enter 1 - yes or 2 - no: ";
				continue;
			}
			for (int i = 1; i < pipes.size() + 1; i++) {
				if (pipes[i - i].repair == pipesRepair) {
					cin >> pipes[i - i].id;
					cin >> pipes[i - i].name;
					cin >> pipes[i - i].diametr;
					cin >> pipes[i - i].length;
					cin >> pipes[i - i].repair;
				}
			}
		}
	}
	else {
		cout << "Pipes wasn't added.";
	}
}

void SearchStation(vector<station>& stations) {
	if (stations.size() != 0) {
		int choose;
		string stationsName;
		int percent;
		cout << "Choose the filter:\n";
		cout << "1 - Name, 2 - Percent of not working workshops: ";
		choose = rightValue();
		while (choose < 1 || choose > 2) {
			cout << "Please enter 1(name) or 2(percent of not working percent): ";
			continue;
		}

		switch (choose) {
		case 1:
			cout << "Enter the name of station: ";
			cin.ignore(32767, '\n');
			getline(cin, stationsName);
			for (int i = 1; i < stations.size() + 1; i++) {
				if (stations[i - i].name == stationsName) {
					cin >> stations[i - i].id;
					cin >> stations[i - i].name;
					cin >> stations[i - i].workshops;
					cin >> stations[i - i].WorkshopsInOperation;
					cin >> stations[i - i].percentWNIO;
					cin >> stations[i - i].efficiency;
				}
			}
		case 2:
			cout << "Enter the percent of not working workshops: ";
			percent = rightValue();
			while (percent < 0 || percent > 100) {
				cout << "The value must be >=0 and <=100. Try again: ";
				continue;
			}
			for (int i = 1; i < stations.size() + 1; i++) {
				if (stations[i - i].percentWNIO == percent) {
					cin >> stations[i - i].id;
					cin >> stations[i - i].name;
					cin >> stations[i - i].workshops;
					cin >> stations[i - i].WorkshopsInOperation;
					cin >> stations[i - i].percentWNIO;
					cin >> stations[i - i].efficiency;
				}
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





