#pragma once
#include <unordered_map>
#include <string>
using namespace std;

class pipe {

public:
	int id;
	static int ID;
	int diametr;
	int length;
	int repair;
	string name;
	istream& operator>> (pipe& p);
	void SearchPipe(unordered_map<pipe, int>& pipes);
	void EditPipes(unordered_map<pipe, int>& pipes);
	void DeletePipes(unordered_map<pipe, int>& pipes);
};
