
#include <iostream>

struct Pipe
{
    int id;
    int d;
};

int main()
{
    Pipe p = { 0, 1400 };
    p.id = 0;
    std::cout<<"Enter diametr" ;
    std::cin >> p.d;
    std::cout << "";
}


