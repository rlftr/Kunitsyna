#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <unordered_map>
#include "Pipe.h"

using namespace std;

int rightvalue();

pipe::pipe()
{
	id++;
	this->name = "";
	this->diametr = 0;
	this->length = 0;
	this->repair = 0;
}

void pipe::AddPipe(pipe& p) {
	pipe::id++;
	cout << "Enter the name: ";
	cin.ignore(32767, '\n');
	getline(cin, p.name);

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
	return p;
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

void pipe::EditPipes(unordered_map<pipe, int>& pipes) {
	int input;
	string* Name = StringArray(pipes.size());
	int* Repair = IntArray(pipes.size());
	cout << "What would you do?\n";
	cout << "1 - Edit all pipes, 2 - Edit few pipes: ";
	input = rightValue();
	while (input > 2 || input < 1) {
		cout << "Please enter 1(edit all pipes) or 2(edit few pipes): ";
		input = rightValue();
	}
	switch (input) {
	case 1:
		if (pipes.size() != 0) {
			for (auto& i : pipes) {
				if (i.second.repair == 1) {
					i.second.repair == 2;
				}
				else {
					i.second.repair == 1;
				}
			}
			cout << "Under repair sign of pipes was edited.\n" << endl;

		}
	}
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
