
#include <iostream>
#include <fstream>
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
	std::cout << "Is the pipe under repair? ('yes' or 'no') ";
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


int main()
{
	pipe p = AddPipe();
	station s = AddStation();
}


