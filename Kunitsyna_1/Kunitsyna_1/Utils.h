#pragma once
#include <iostream>
using namespace std;

template <typename T>
T rightValue(T min, T max)
{
	T x;
	while ((cin >> x).fail() || x < min || x > max || std::cin.peek() != '\n')
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Error. Enter number (" << min << "-" << max << ") again:";
	}
	return x;

}

