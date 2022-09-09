#pragma once
#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;

class pipe {

	int pipeID;
public:
	pipe();
	static int pipeMaxID;
	int diametr;
	int length;
	bool repair;
	string name;
	int pipeGetID() const;
	friend ostream& operator<< (ostream& out, const pipe& p);
	friend istream& operator >> (istream& in, pipe& p);
	friend ifstream& operator >> (ifstream& fin, pipe& p);
	friend ofstream& operator << (ofstream& fout, const pipe& p);
};
