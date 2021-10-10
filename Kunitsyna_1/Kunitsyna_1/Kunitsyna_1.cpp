
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <istream>
using namespace std;


struct pipe {

	int id;
	int diametr;
	int length;
	string repair;
};


pipe AddPipe() {

	pipe p; // = { 0, 1420 };
	p.id = 0;
	std::cout << "Enter the diametr: ";
	std::cin >> p.diametr;
	std::cout << "Enter the length: ";
	std::cin >> p.length;
	std::cout << "Is the pipe under repair? ('yes' or 'no'):  ";
	std::cin >> p.repair;

	while (p.diametr <= 0) {
	    std::cin >> p.diametr;
	    std::cout << "The value must be > 0";
	    continue;
	}

	while (p.length <= 0) {
		std::cin >> p.length;
		std::cout << "The value must be > 0";
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
	std::cout << "Enter the number of workshops in operation: ";
	std::cin >> s.WorkshopsInOperation;
	std::cout << "Enter the efficiency (%): ";
	std::cin >> s.efficiency;

	while (s.workshops < 0) {
		std::cin >> s.workshops;
		std::cout << "The value must be > 0";
		continue;
	}

	while (s.WorkshopsInOperation <= 0) {
		std::cin >> s.WorkshopsInOperation;
		std::cout << "The value must be > 0";
		continue;
	}

	while (s.efficiency < 0) {
		std::cin >> s.efficiency;
		std::cout << "The value must be >= 0 and <= 100";
		continue;
	}

	while (s.efficiency > 100) {
		std::cin >> s.efficiency;
		std::cout << "The value must be >= 0 and <= 100";
		continue;
	}

	return s;
	
}


void PipeEdit(pipe p) {
	std::cin >> "Is the pipe under repair? ('yes' or 'no'): ";
	std::cout << p.repair;
}

void StationEdit(station s) {
	std::cin >> "Enter the number of workshops in operation : ";
	std::cout << s.WorkshopsInOperation;
}

void Output(pipe p, station s) {
	cout << "\nAll objects:\n";
	if (p.length > 0 && p.diametr > 0) {
		cout << "\n1. Pipe p";
		cout << "\nId: " << p.id;
		cout << "\nDiameter: " << p.diametr;
		cout << "\nLength: " << p.length << "\n";
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
			file << "\nDiameter: " << p.diametr;
			file << "\nLength: " << p.length << "\n";
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

void Load(pipe p, station s) {
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

int menu()
{
	int variant;
	cout << "Menu\n" << endl;
	cout << "1. Add Pipe\n"
		<< "2. Add Station\n"
		<< "3. Viewing all objects\n"
		<< "4. Edit Pipe\n"
		<< "5. Edit Station\n"
		<< "6. Save\n"
		<< "7. Load\n"
		<< "0. Exit\n";
	cin >> variant;
	return variant;
}



int main(int argc, char* argv[])
{
	pipe p = AddPipe();
	station s = AddStation();
	int variant = menu();
	switch (variant) {
	case 0:
		cout << "\nExit\n";
		return 0;
	case 1:
		p = AddPipe();
		break;
	case 2:
		s = AddStation();
		break;
	case 3:
		Output(p, s);
		break;
	case 4:
		PipeEdit(p);
		break;
	case 5:
		StationEdit(s);
		break;
	case 6:
		Save(p, s);
		break;
	case 7:
		Load(p, s);
		break;
	default:
		break;
	}
	return 0;
}


