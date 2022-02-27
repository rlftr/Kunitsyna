#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <Pipe.h>

using namespace std;

int rightvalue();
int pipe::ID = 0;

pipe::pipe()
{
	this->id = ++ID;
	this->name = "";
	this->diametr = 0;
	this->length = 0;
	this->repair = 0;
}

istream& operator>> (pipe& p) {
	istream in;
	pipe::id++;
	pipe p;
	cout << "Enter the name: ";
	in.ignore(32767, '\n');
	getline(in, p.name);

	cout << "Enter the diametr: ";
	p.diametr = rightValue();

	while (p.diametr <= 0) {
		cout << "The value must be > 0. Try again: ";
		p.diametr = rightValue();
		continue;
	}

	cout << "Enter the length: ";
	p.length = rightValue();

	while (p.length <= 0) {
		cout << "The value must be > 0. Try again: ";
		p.length = rightValue();
		continue;
	}

	cout << "Is the pipe under repair? ('yes'- 1 or 'no'- 2):  ";
	p.repair = rightValue();

	while (p.repair < 1 || p.repair > 2) {
		cout << "Please enter 1(yes) or 2(no): ";
		p.repair = rightValue();
		continue;
	}
	return in;
	cout << "\nPipe was added.\n";
}

ostream& operator<< (ostream& out) {
	const unordered_map<pipe, int> pipes;
	out << "\nAll pipes:\n";
	if (pipes.size() != 0) {
		for (auto& i : pipes) {
			out << "\nId: " << i.first;
			out << "\nName: " << i.second.name;
			out << "\nDiametr: " << i.second.diametr;
			out << "\nLength: " << i.second.length;
			out << "\nRepair ('yes' - 1, 'no' - 2): " << i.second.repair << "\n";
			continue;
		}
	}
	return out;
}

void pipe::SearchPipe(unordered_map<pipe, int>& pipes) {
	int input;
	string* pipesName = StringArray(pipes.size());
	int* pipesRepair = IntArray(pipes.size());
	cout << "Choose the filter:\n";
	cout << "1 - Name, 2 - Repair: ";
	input = rightValue();
	while (input < 1 || input > 2) {
		cout << "Please enter 1(name) or 2(repair): ";
		break;
	}
	switch (input) {
	case 1:
		if (pipes.size() != 0) {
			for (auto& i : pipes) {
				cout << "\nEnter the name of pipe: ";
				cin.ignore(32767, '\n');
				cin >> pipesName[i];

				while (i.second.name == pipesName[i]) {
					cout << "\nId: " << i.first;
					cout << "\nName: " << i.second.name;
					cout << "\nDiametr: " << i.second.diametr;
					cout << "\nLength: " << i.second.length;
					cout << "\nRepair: " << i.second.repair;
					break;
				}
				if (i.second.name != pipesName[i]) {
					cout << "No pipes with this name.\n";
					break;
				}

			}
			break;
		}
		else {
			cout << "Pipes wasn't added.\n";
		}
		break;
	case 2:
		if (pipes.size() != 0) {
			for (auto& i : pipes) {
				cout << "\nIs pipe under repair? (1 - yes, 2 - no): ";
				pipesRepair[i] = rightValue();
				while (pipesRepair[i] < 1 || pipesRepair[i] > 2) {
					cout << "\nPlease enter 1 - yes or 2 - no: ";
					continue;
				}
				while (i.second.repair == pipesRepair[i]) {
					cout << "\nId: " << pipes[i].id;
					cout << "\nName: " << pipes[i].name;
					cout << "\nDiametr: " << pipes[i].diametr;
					cout << "\nLength: " << pipes[i].length;
					cout << "\nRepair: " << pipes[i].repair;
					break;
				}
				if (i.second.repair != pipesRepair[i]) {
					cout << "No pipes with this under repair sign";
					break;
				}
			}
		}
		else {
			cout << "Pipes wasn't added.\n";
		}
		break;
	default:
		break;
	}
}


void pipe::DeletePipes(unordered_map<pipe, int>& pipes) {
	int ID;
	cout << "Enter the id of pipe you want to delete: \n";
	ID = rightValue();
	for (auto& i : pipes) {
		if (pipes.count(ID) != 0) {
			while (ID != -1 && pipes.count(ID) != 0) {
				stations.erase(pipes.find(ID));
			}
		}
		else {
			cout << "No pipe with this id.\n";
		}
	}
}
}

