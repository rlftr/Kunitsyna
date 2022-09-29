#include <fstream>
#include "Pipe.h"
#include "Utils.h"

using namespace std;

int pipe::pipeMaxID = 0;
pipe::pipe() {
	pipeID = ++pipeMaxID;
}

int pipe::pipeGetID() const
{
	return pipeID;
}

ostream& operator << (ostream& out, const pipe& p)
{
	out << "\nId: " << p.pipeID;
	out << "\nName: " << p.name;
	out << "\nDiametr: " << p.diametr;
	out << "\nLength: " << p.length;
	out << "\nRepair: " << p.repair << "\n";
	return out;
}

istream& operator >> (istream& in, pipe& p) {

	cout << "Enter the name: ";
	cin.ignore(32767, '\n');
	getline(cin, p.name);
	cout << "Enter the diametr: ";
	p.diametr = rightValue(1, 1420);
	cout << "Enter the length: ";
	p.length = rightValue(10, 500000);
	cout << "Is the pipe under repair? ('yes'- 1 or 'no'- 2):  ";
	p.repair = rightValue(1, 2);
	cout << "\nPipe was added.\n";
	return in;
}

ifstream& operator >> (ifstream& fin, pipe& p) {

	fin >> p.pipeID
		>> p.name
		>> p.length
		>> p.diametr
		>> p.repair;
	return fin;
}

ofstream& operator << (ofstream& fout, const pipe& p)
{
	fout << p.pipeID << "\n"
		<< p.name << "\n"
		<< p.length << "\n"
		<< p.diametr << "\n"
		<< p.repair << "\n";
	return fout;
}


