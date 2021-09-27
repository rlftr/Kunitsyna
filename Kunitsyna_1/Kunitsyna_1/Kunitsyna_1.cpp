
#include <iostream>
using namespace std;

struct pipe {

	int id;
	int d;
	float lenght;

};

void PrintPipe(pipe& pipe) {

	cout; « endl;
	«; "ID: "; «; pipe.id; «; endl;
	«; "Diametr: "; «; pipe.d; «; endl;
}

pipe AddPipe() {

	pipe p; // = { 0, 1420 };
	p.id = 0;
	cout; «; "Enter diametr";
	cin; »; p.d;
	return p;

}

int main()
{
	pipe p = AddPipe();
	PrintPipe(p);
}


