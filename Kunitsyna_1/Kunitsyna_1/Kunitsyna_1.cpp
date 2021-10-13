
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <istream>
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
		<< "0. Exit\n";
}

struct pipe {
	int id;
	int diametr;
	int length;
	int repair;
};

pipe AddPipe() {

	pipe p; 
	p.id = 0;
	std::cout << "Enter the diametr: ";
	std::cin >> p.diametr;

	while (p.diametr <= 0) {
		std::cout << "The value must be > 0. Try again: ";
		std::cin >> p.diametr;
		continue;
	} 

	std::cout << "Enter the length: ";
	std::cin >> p.length;

	while (p.length <= 0) {
		std::cout << "The value must be > 0. Try again: ";
		std::cin >> p.length;
		continue;
	}

	std::cout << "Is the pipe under repair? ('yes'- 1 or 'no'- 2):  ";
	std::cin >> p.repair;

	while (p.repair < 1 || p.repair > 2) {
		std::cout << "Please enter 1(yes) or 2(no): ";
		std::cin >> p.repair;
		continue;
	}
	return p;
}

struct station {

	string name;
	int workshops;
	int WorkshopsInOperation;
	int efficiency;
	int id;
}

; station AddStation() {

	station s;
	s.id = 1;
	std::cout << "Enter the name: ";
	std::cin >> s.name;
	std::cout << "Enter the number of workshops: ";
	std::cin >> s.workshops;

	while (s.workshops < 0) {
		std::cout << "The value must be > 0. Try again: ";
		std::cin >> s.workshops;
		continue;
	}

	std::cout << "Enter the number of workshops in operation: ";
	std::cin >> s.WorkshopsInOperation;

	while (s.WorkshopsInOperation < 0) {
		std::cout << "The value must be >= 0. Try again: ";
		std::cin >> s.WorkshopsInOperation;
		continue;
	}

	while (s.WorkshopsInOperation > s.workshops) {
		std::cout << "Number of working workshops can't be > number of workshops. Try again: ";
		std::cin >> s.WorkshopsInOperation;
		continue;
	}

	std::cout << "Enter the efficiency (%): ";
	std::cin >> s.efficiency;

	while (s.efficiency < 0 || s.efficiency > 100) {
		std::cout << "The value must be >= 0 and <= 100. Try again: ";
		std::cin >> s.efficiency;
		continue;
	}

	return s;
	
}

pipe PipeEdit(pipe &p) {
	std::cout << "Is the pipe under repair? ('yes'- 1 or 'no'- 2): ";
	std::cin >> p.repair;

	while (p.repair < 1 || p.repair > 2) {
		std::cout << "Please enter 1(yes) or 2(no): ";
		std::cin >> p.repair;
		continue;
	}
	return p;
}

station StationEdit(station &s) {
	std::cout << "Enter the number of workshops in operation: ";
	std::cin >> s.WorkshopsInOperation;

	while (s.WorkshopsInOperation < 0) {
		std::cout << "The value must be >= 0. Try again: ";
		std::cin >> s.WorkshopsInOperation;
		continue;
	}

	while (s.WorkshopsInOperation > s.workshops) {
		std::cout << "Number of working workshops can't be > number of workshops. Try again: ";
		std::cin >> s.WorkshopsInOperation;
		continue;
	}
	return s;

}

void Output(pipe p, station s) {
	cout << "\nAll objects:\n";
	if (p.length > 0 && p.diametr > 0) {
		cout << "\n1. Pipe p";
		cout << "\nId: " << p.id;
		cout << "\nDiametr: " << p.diametr;
		cout << "\nLength: " << p.length;
		cout << "\nRepair ('yes' - 1, 'no' - 2)" << p.repair << "\n";
	}

	if (s.name != "") {
		cout << "\n2. Station s";
		cout << "\nId: " << s.id;
		cout << "\nName: " << s.name;
		cout << "\nWorkshops: " << s.workshops;
		cout << "\nWorkshops In Operation: " << s.WorkshopsInOperation;
		cout << "\nEfficiency: " << s.efficiency << "\n";
	}
}

void Save(pipe p, station s) {
	ofstream file;
	file.open("database.txt");
	if (file.good()) {
		if (p.length > 0 && p.diametr > 0) {
			file << "\n1. Pipe p";
			file << "\nId: " << p.id;
			file << "\nDiametr: " << p.diametr;
			file << "\nLength: " << p.length;
			file << "\nRepair ('yes' - 1, 'no' - 2)" << p.repair << "\n";
		}

		if (s.name != "") {
			file << "\n2. Station s";
			file << "\nId: " << s.id;
			file << "\nName: " << s.name;
			file << "\nWorkshops: " << s.workshops;
			file << "\nWorkshops In Operation: " << s.WorkshopsInOperation;
			file << "\nEfficiency: " << s.efficiency << "\n";
		}
		file.close();
		cout << "Saved\n";
	}
}

void Load(pipe &p, station &s) {
	ifstream file;
	file.open("database.txt");
	if (file.good()) {
		while (!file.eof()) {
			string type;
			file >> type;
			if (type == "Pipe:") {
				file >> p.id;
				file >> p.diametr;
				file >> p.length;
				file >> p.repair;
			}
			if (type == "Station:") {
				file >> s.id;
				file >> s.name;
				file >> s.workshops;
				file >> s.WorkshopsInOperation;
				file >> s.efficiency;
			}
		}
	}
	cout << "Loaded\n";
}

int main()
{
	pipe p;
	p.length = -1;  
	station s;
	s.name = "";
	int a;
	bool While = true;
	while (While) {
		menu();
		cin >> a;
		switch (a) {
		case 1:
			p = AddPipe();
		continue;
		case 2:
			s = AddStation();
		continue;
		case 3:
			Output(p, s);
		continue;
		case 4:
			PipeEdit(p);
	    continue;
		case 5:
			StationEdit(s);
		continue;
		case 6:
			Save(p, s);
		continue;
		case 7:
			Load(p, s);
		continue;
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






