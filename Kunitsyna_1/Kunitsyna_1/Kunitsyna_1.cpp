
#include <iostream>
using namespace std;

struct pipe {

	int id;
	int diametr;
	int length;

};


pipe AddPipe() {

	pipe p; // = { 0, 1420 };
	p.id = 0;
	std::cout << "Enter the diametr: ";
	std::cin >> p.diametr;
	std::cout << "Enter the length: ";
	std::cin >> p.length;

	while (p.diametr < 0) {
	    std::cin >> p.diametr;
	    std::cout << "The value must be > 0";
	    continue;
	}

	while (p.length < 0) {
		std::cin >> p.diametr;
		std::cout << "The value must be > 0";
		continue;
	}

	return p;

}

int main()
{
	pipe p = AddPipe();
}


