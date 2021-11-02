
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <istream>
#include <string>
#include <vector>
#include <map>

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
};


 pipe PipeEdit(pipe& p) {
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
		 return p;
		 
	 }
}


pipe AddPipe(vector<pipe>& pipesVector) {

	pipe p;
	p.id = 1;
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
	return p;
}

struct station {
	int id;
	string name;
	int workshops;
	int WorkshopsInOperation;
	int efficiency;
};

station StationEdit(station& s) {
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
		return s;
}

; station AddStation() {
	station s;
	s.id = 1;
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
		std::cout << "The value must be >= 0 and <= 100. Try again: ";
		s.efficiency = rightValue();
		continue;
	}
	cout << "\nStation was added.\n";
	return s;
}


void Output(pipe p, station s) {
	cout << "\nAll objects:\n";
	if (p.length > 0 && p.diametr > 0) {
		cout << "\n1. Pipe p";
		cout << "\nId: " << p.id;
		cout << "\nDiametr: " << p.diametr;
		cout << "\nLength: " << p.length;
		cout << "\nRepair ('yes' - 1, 'no' - 2): " << p.repair << "\n";
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
			file << "\nRepair ('yes' - 1, 'no' - 2): " << p.repair << "\n";
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

int Load(pipe& p, station& s) {
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
			// p = AddPipe();
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





