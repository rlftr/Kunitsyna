#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include "Pipe.h"

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
	out << "\nRepair: " << ((p.repair == 0) ? "in work" : "in repair") << "\n";
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
	return in;
	cout << "\nPipe was added.\n";
}

ifstream& operator >> (ifstream& fin, pipe& p) {

	fin >> p.pipeID
		>> p.name
		>> p.length
		>> p.diameter
		>> p.repair;
	return fin;
}

ofstream& operator << (ofstream& fout, const pipe& p)
{
	fout << "Pipe: " << endl
		<< p.pipeID << endl
		<< p.name << endl
		<< p.length << endl
		<< p.diameter << endl
		<< p.repair << endl;
	return fout;
}

void EditPipe(pipe& p)
{
	cout << "Is the pipe under repair? (1 - yes; 2 - no) : ";
	p.repair = rightValue(1, 2);
}

pipe& SelectPipe(unordered_map <int, pipe>& pipes)
{
	cout << "Enter the index of pipe: ";
	int index = rightValue(1, pipes.size());
	return pipes[index];
}

template <typename T>
using pipeFilter = bool(*)(const pipe& p, T param);

bool CheckByPipeName(const pipe& p, string param)
{
	return p.name == param;
}

bool CheckByLength(const pipe& p, double param)
{
	return p.length >= param;
}
bool CheckByDiameter(const pipe& p, int param)
{
	return p.diametr >= param;
}
bool CheckByRepair(const pipe& p, bool param)
{
	return p.repair == param;
}

template <typename T>
vector <int> FindPipesByFilter(const unordered_map <int, pipe>& map, pipeFilter <T> f, T param)
{
	vector <int> res;

	for (auto& i : map)
	{
		if (f(i.second, param))
			res.push_back(i.first);

	}
	if (res.size() == 0)
	{
		cout << "Pipes not found." << endl;
	}
	return res;
}


void EditPipes(vector <int>& v, unordered_map <int, pipe>& pipes) {
	vector <int> vEdit;
	cout << "What would you do?\n";
	cout << "1 - Edit all pipes, 2 - Edit few pipes: ";

	if (rightValue(1, 2))
	{
		vEdit = v;
	}

	else
	{
		while (true)
		{
			cout << "Error. Try again: ";
			int input = rightValue(1, (int)size(v));
			if (input)
			{
				vEdit.push_back(v[i - 1]);
			}
			else
			{
				break;
			}
		}
	}

	cout << "Which pipes to select? (under repair - 1, not under repair - 2: ";
	int input1 = rightValue(1, 2);
	if (input1 != 1 || input1 != 2){

		cout << "Error/ Try again: ";
		input1 = rightValue(1, 2);
	}
	else
	{
		for (int i : vEdit)
			pipes[i].repair = (bool)input1;
	}
}

void SearchPipe(unordered_map <int, pipe>& pipes)
{
        while (true)
        {
            findPipeMenu();
            vector <int> result;
            switch (rightValue(0, 2))
            {
            case 1:
            {
                string pName;
                cout << "Find pipe by name:  ";
                cin.ignore(10000, '\n');
                getline(cin, pName);
                result = FindPipesByFilter(pipes, CheckByPipeName, pName);
				cout << result;
                break;
            }
            
            case 2:
            {
                cout << "Find pipe by repair (1 - under repair; 2 - not under repair) :  ";
                bool repair = rightValue(1, 2);
                result = FindPipesByFilter(mapPipe, CheckByStatus, status);
				cout << result;
                break;
            }
            case 0:
            {
                return;
            }
            default:
            {
                cout << "Error. Try again: " << endl;
                break;
            }
            }
        }
}

void DeletePipe(unordered_map<pipe, int>& pipes) {
	cout << "Enter the index of pipe: ";
	int index = rightValue(1, pipes.size());
	pipes.erase(index);
}
