#pragma once
#include <vector>
#include <string>

class pipe {

public:
	static int id;
	int diametr;
	int length;
	int repair;
	string name;
	bool checkId(int& Id, vector<pipe>& pipes);
	void AddPipes(vector<pipe>& pipes);
	void SearchPipe(vector<pipe>& pipes);
	void EditPipes(vector<pipe>& pipes);
};