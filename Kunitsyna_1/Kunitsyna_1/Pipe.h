#pragma once
#include <vector>
#include <string>
using namespace std;

class pipe {

public:
	int id;
	int diametr;
	int length;
	int repair;
	string name;
	bool checkId();
	void AddPipes();
	void SearchPipe();
	void EditPipes();
	void DeletePipes();
};