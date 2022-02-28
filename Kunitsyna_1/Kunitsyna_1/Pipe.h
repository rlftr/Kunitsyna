#pragma once
#include <unordered_map>
#include <string>
using namespace std;

class pipe {

public:
	unordered_map <int, pipe> pipes;
	pipe();
	static int id;
	int diametr;
	int length;
	int repair;
	string name;
	friend ostream& operator<< (ostream&, const unordered_map <int, pipe>&);
	void AddPipe(pipe& p);
	void SearchPipe(unordered_map<pipe, int>& pipes);
	void EditPipes(unordered_map<pipe, int>& pipes);
	void DeletePipes(unordered_map<pipe, int>& pipes);
};
