#include <vector>
#include <Pipe.h>
using namespace std;

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
	cin >> p.name;

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

void SearchPipe(vector<pipe>& pipes) {
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
				if (pipes[i].name != pipesName[i]) {
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
				if (pipes[i].repair != pipesRepair[i]) {
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

void EditPipes(vector<pipe>& pipes) {
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
			for (vector<pipe>::size_type i = 0; i < pipes.size(); i++) {

				if (pipes[i].repair == 1) {
					pipes[i].repair == 2;
				}
				else {
					pipes[i].repair == 1;
				}
			}
			cout << "Under repair sign of pipes was edited.\n" << endl;
		}
		else {
			cout << "Pipes wasn't added.\n";
		}
		break;
	case 2:
		if (pipes.size() != 0) {
			for (vector<pipe>::size_type i = 0; i < pipes.size(); i++) {
				cout << "\nEnter the name of pipe you would edit: ";
				cin.ignore(32767, '\n');
				cin >> Name[i];
				while (pipes[i].name != Name[i]) {
					cout << "No pipes with this name. Try again: ";
					cin.ignore(32767, '\n');
					cin >> Name[i];
					continue;
				}
				while (pipes[i].name == Name[i]) {
					cout << "Is the pipe under repair? ('yes'- 1 or 'no'- 2): ";
					pipes[i].repair = rightValue();

					while (pipes[i].repair < 1 || pipes[i].repair > 2) {
						cout << "Please enter 1(yes) or 2(no): ";
						pipes[i].repair = rightValue();
						continue;
					}
					cout << "\nPipes was edited.";
					break;
				}
			}
		}
		break;
	default:
		break;
	}
}

void DeletePipes(vector<pipe>& pipes) {

}