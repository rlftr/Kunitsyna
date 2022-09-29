#pragma once
#include <string>
#include <iostream>

class pipe {

	int pipeID;
public:
	static int pipeMaxID;
	int diametr;
	int length;
	bool repair;
	std::string name;

	pipe();
	int pipeGetID() const;
	friend std::ostream& operator<< (std::ostream& out, const pipe& p);
	friend std::istream& operator >> (std::istream& in, pipe& p);
	friend std::ifstream& operator >> (std::ifstream& fin, pipe& p);
	friend std::ofstream& operator << (std::ofstream& fout, const pipe& p);
};
