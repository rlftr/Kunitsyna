
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <istream>
#include <string>
#include <unordered_map>
#include "Station.h"
#include "Pipe.h"

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
		<< "8. Search Pipe\n"
		<< "9. Search Station\n"
		<< "10. Delete Pipes\n"
		<< "11. Delete Stations\n"
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
		<< "2. Find station by number of not working workshops"  << endl
		<< "0. Back to menu" << endl;
}

template <typename T>
T rightValue(T min, T max)
{
	T x;
	while ((cin >> x).fail() || x < min || x > max)
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Error. Enter number (" << min << "-" << max << ") again:";
	}
	return x;

}


int main(unordered_map<pipe, int>& pipes, unordered_map<station, int>& stations) {
	bool pipeExists = false;
	bool stationExists = false;
	unordered_map <int, pipe> pipes = {};
	unordered_map <int, station> stations = {};
	while (1) {
		menu();
		switch (rightValue(0, 11)) {
		case 1:
			pipe p = {};
			cin >> p;
			pipeExists = true;
			pipes.insert({ p.pipeGetID(), p });
			continue;
		case 2:
			station s = {};
			cin >> s;
			stationExists = true;
			stations.insert({ s.stationGetID(), s });
			continue;
		case 3:
			if (pipes.size())
			{
				cout << "Pipe's MaxID: " << pipe::pipeMaxID << endl;
				for (auto const& i : pipes)
				{
					cout << i.second;
				}
			}
			if (stations.size())
			{
				cout << "Station's MaxID: "<< station::stationMaxID << endl;
				for (auto const& i : stations)
				{
					cout << i.second;
				}
			}
			if (!pipeExists && !stationExists)
				cout << "Stations and pipes not found." << endl;
			continue;
		case 4:
			if (pipeExists)
			{
				EditPipes(SelectPipe(pipes));
			}
			else
			{
				cout << "Pipes not found." << endl;
			}
			continue;
		case 5:
			if (stationExists)
			{
				EditStations(SelectStation(stations));
			}
			else
			{
				cout << "Stations not found." << endl;
			}
			continue;
		case 6:
			Save(pipes, stations);
			continue;
		case 7:
			Load(pipes, stations);
			continue;
		case 8:
			p1.SearchPipe(pipes);
		case 9:
			s1.SearchStation(stations);
		case 10:
			if (pipeExists)
			{
				DeletePipe(pipes);
			}
			else
			{
				cout << "Pipes not found." << endl;
			}
			break;
		case 11:
			if (stationExists)
			{
				DeleteStation(stations);
			}
			else
			{
				cout << "Stations not found." << endl;
			}
			break;
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




