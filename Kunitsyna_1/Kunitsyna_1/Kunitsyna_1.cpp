

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
#include "Station.h"
#include "Pipe.h"
#include "Utils.h"

using namespace std;

void menu()
{
	cout << "\n   Menu." << endl;
	cout << "1. Add Pipe\n"
		<< "2. Add Station\n"
		<< "3. Viewing all objects\n"
		<< "4. Edit Pipes\n"
		<< "5. Edit Stations\n"
		<< "6. Save\n"
		<< "7. Load\n"
		<< "8. Search pipes and stations\n"
		<< "9. Delete Pipes\n"
		<< "10. Delete Stations\n"
		<< "0. Exit\n";
}

void findPipeMenu()
{
	cout << "\n   Menu." << endl
		<< "1. Find pipe by name" << endl
		<< "2. Find pipe by repair" << endl
		<< "0. Back to menu" << endl;
}

void findStationMenu()
{
	cout << "\n   Menu." << endl
		<< "1. Find station by name" << endl
		<< "2. Find station by percent of not working workshops" << endl
		<< "0. Back to menu" << endl;
}



string inputFileName()
{
	string fileName;
	cout << "Enter the file name: ";
	cin.clear();
	cin.ignore(10000, '\n');
	cin >> fileName;
	fileName = fileName + ".txt";
	return fileName;
}

void EditStation(station& s)
{
	cout << "Enter the new number of working workshops: \n";
	s.workingWorkshops = rightValue(1, s.workshops);
}

void EditPipe(pipe& p)
{
	cout << "Is the pipe under repair? (1 - yes; 2 - no) : ";
	p.repair = rightValue(1, 2);
}

pipe& SelectPipe(unordered_map <int, pipe>& pipes)
{
	cout << "Enter the index of pipe: ";
	unsigned int i = rightValue(1u, pipes.size());
	return pipes[i];
}

station& SelectStation(unordered_map <int, station>& stations)
{
	cout << "Enter the index of station: ";
	unsigned int i = rightValue(1u, stations.size());
	return stations[i];
}


template <typename T>
using stationFilter = bool(*)(const station& s, T param);

bool CheckByName(const station& s, string param)
{
	return s.name == param;
}

bool CheckByPercent(const station& s, int param)
{
	int percent = int(s.workshops - s.workingWorkshops) / s.workshops * 100;
	return percent == param;
}

template <typename T>
using pipeFilter = bool(*)(const pipe& p, T param);

bool CheckByPipeName(const pipe& p, string param)
{
	return p.name == param;
}

bool CheckByRepair(const pipe& p, int param)
{
	return p.repair <= param;
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

template <typename T>
vector <int> FindStationsByFilter(const unordered_map <int, station>& map, stationFilter <T> f, T param)
{
	vector <int> res;
	for (auto& i : map)
	{
		if (f(i.second, param))
			res.push_back(i.first);
	}
	if (res.size() == 0)
	{
		cout << "Stations not found." << endl;
	}
	return res;
}

void EditPipes(vector <int>& v, unordered_map <int, pipe>& pipes) {
	vector <int> vEdit;
	cout << "What would you do?\n";
	cout << "1 - Edit all pipes, 0 - Edit few pipes: ";
	if (rightValue(0, 1))
	{
		vEdit = v;
	}
	else
	{
		while (true)
		{
			cout << "Error. Try again: ";
			int i = rightValue(0, (int)size(v));
			if (i)
			{
				vEdit.push_back(v[i - 1]);
			}
			else
			{
				break;
			}
		}
	}
	cout << "All selected: under repair - 1, not under repair - 2, back to menu - 0: ";
	int input1 = rightValue(0, 2);
	if (input1 == 0) {
		for (int id : vEdit)
		{
			auto search = pipes.find(id);
			if (search != pipes.end())
				pipes.erase(search);
		}
	}
	else
	{
		for (int i : vEdit)
			pipes[i].repair = (int)input1;
	}
}

template <typename typeElement>
void printMapElements(unordered_map <int, typeElement>& map, const vector <int>& v)
{
	for (int i : v)
	{
		cout << map[i];
	}
}


void Search(unordered_map <int, station>& stations, unordered_map <int, pipe>& pipes)
{
	cout << "What search? (0 - station, 1 - pipe): \n";
	if (rightValue(0, 1))
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
				cout << "Find pipe by name:  \n";
				cin.ignore(10000, '\n');
				getline(cin, pName);
				result = FindPipesByFilter(pipes, CheckByPipeName, pName);
				break;
			}
			case 2:
			{
				cout << "Find pipe by repair (1 - under repair, 2 - not under repair):  \n";
				int repair = rightValue(1, 2);
				result = FindPipesByFilter(pipes, CheckByRepair, repair);
				break;
			}

			case 0:
			{
				return;
			}
			default:
			{
				cout << "Error" << endl;
				break;
			}
			}
			if (size(result))
			{
				printMapElements(pipes, result);
				EditPipes(result, pipes);
			}
		}
	}
	else
	{
		while (true)
		{
			findStationMenu();
			vector <int> result;
			switch (rightValue(0, 2))
			{
			case 1:
			{
				string sName;
				cout << "Find station by name: \n";
				cin.ignore(10000, '\n');
				getline(cin, sName);
				result = FindStationsByFilter(stations, CheckByName, sName);
				break;
			}
			case 2:
			{
				cout << "Find station by percent of not working workshops: \n";
				int percent = rightValue(0, 100);
				result = FindStationsByFilter(stations, CheckByPercent, percent);
				break;
			}
			case 0:
			{
				return;
			}
			default:
			{
				cout << "Error" << endl;
				break;
			}
			}
			if (size(result))
			{
				printMapElements(stations, result);
			}
		}
	}
}


void printPipes(const unordered_map <int, pipe>& pipes)
{
	for (auto const& i : pipes)
	{
		cout << i.second;
	}
}

void printStations(const unordered_map <int, station>& stations)
{
	for (auto const& i : stations)
	{
		cout << i.second;
	}
}

void DeleteStation(unordered_map<int, station>& stations) {
	cout << "Enter the index of station: ";
	unsigned int i = rightValue(1u, stations.size());
	stations.erase(i);
}

void DeletePipe(unordered_map<int, pipe>& pipes) {
	cout << "Enter the index of pipe: ";
	unsigned int i = rightValue(1u, pipes.size());
	pipes.erase(i);
}


int main() {
	bool pipeExists = false;
	bool stationExists = false;
	unordered_map <int, pipe> pipes = {};
	unordered_map <int, station> stations = {};
	while (1) {
		menu();
		switch (rightValue(0, 11)) {
		case 1: {
			pipe p;
			cin >> p;
			pipeExists = true;
			pipes.insert({ p.pipeGetID(), p });
			continue;
		}
		case 2: {
			station s;
			cin >> s;
			stationExists = true;
			stations.insert({ s.stationGetID(), s });
			continue;
		}
		case 3: {
			if (pipes.size())
			{
				cout << "\nPipes";
				printPipes(pipes);
			}
			if (stations.size())
			{
				cout << "\nStations";
				printStations(stations);
			}
			if (!pipeExists && !stationExists)
				cout << "Stations and pipes not found." << endl;
			continue;
		}
		case 4: {
			if (pipeExists)
			{
				EditPipe(SelectPipe(pipes));
			}
			else
			{
				cout << "Pipes not found." << endl;
			}
			continue;
		}
		case 5: {
			if (stationExists)
			{
				EditStation(SelectStation(stations));
			}
			else
			{
				cout << "Stations not found." << endl;
			}
			continue;
		}
		case 6: {
			ofstream fout;
			if (pipeExists && stationExists)
			{
				string FileName = inputFileName();
				fout.open(FileName, ios::out);
				if (fout.is_open())
				{
					fout << pipe::pipeMaxID << endl;
					fout << station::stationMaxID << endl;
					for (auto const& i : pipes)
						fout << i.second;
					for (auto const& i : stations)
						fout << i.second;
					pipeExists = true;
					stationExists = true;
				}
				else
				{
					cout << "Error" << endl;
				}
				fout.close();
			}
			else if (pipeExists && !stationExists)
			{
				string FileName = inputFileName();
				fout.open(FileName, ios::out);
				if (fout.is_open())
				{
					fout << pipe::pipeMaxID << endl;
					for (auto const& i : pipes)
						fout << i.second;
					pipeExists = true;
				}
				else
				{
					cout << "Error" << endl;
				}
				fout.close();
			}
			else if (!pipeExists && stationExists)
			{
				string FileName = inputFileName();
				fout.open(FileName, ios::out);
				if (fout.is_open())
				{
					fout << station::stationMaxID << endl;
					for (auto const& i : stations)
						fout << i.second;
					stationExists = true;
				}
				else
				{
					cout << "Error" << endl;
					stationExists = false;
					pipeExists = false;
				}
				fout.close();
			}
			else
			{
				cout << "Pipes and stations not found." << endl;
			}
			cout << "Saved.\n";
			continue;
		}
		case 7: {
			pipe p;
			station s;
			int a = 0, b = 0;
			int l = 0;
			string strr = {};
			ifstream fin;
			string fileName = inputFileName();
			fin.open(fileName, ios::in);
			if (fin.is_open())
			{
				pipes.clear();
				stations.clear();
				string str = {};
				while (!fin.eof())
				{
					getline(fin, str);
					if (str == "Pipe")
					{
						fin >> p;
						pipes.insert({ p.pipeGetID(), p });
						pipeExists = true;
						a++;
					}
					else if (str == "Station")
					{
						fin >> s;
						stations.insert({ s.stationGetID(), s });
						stationExists = true;
						b++;
					}
				}
			}
			else
			{
				cout << "Error" << endl;
			}
			fin.close();
			fin.open(fileName, ios::in);
			if (a > 0 && b > 0)
			{
				while (l != 2 && getline(fin, strr))
				{
					++l;
					if (l == 1)
						pipe::pipeMaxID = stoi(strr);
					if (l == 2)
						station::stationMaxID = stoi(strr);
				}
			}
			if (a > 0 && b == 0)
			{
				getline(fin, strr);
				pipe::pipeMaxID = stoi(strr);
			}
			if (a == 0 && b > 0)
			{
				getline(fin, strr);
				station::stationMaxID = stoi(strr);
			}
			cout << "Loaded.\n";
			continue;
		}
		case 8: {
			Search(stations, pipes);
			continue;
		}
		case 9: {
			if (pipeExists)
			{
				DeletePipe(pipes);
				cout << "Deleted.\n";
			}
			else
			{
				cout << "Pipes not found." << endl;
			}
			continue;
		}
		case 10: {
			if (stationExists)
			{
				DeleteStation(stations);
				cout << "Deleted.\n";
			}
			else
			{
				cout << "Stations not found." << endl;
			}
			continue;
		}
		case 0:
			return 0;
			break;
		default:
			cout << "Error. Try again: \n\n";
			continue;
		}
		return 0;
	}
}










