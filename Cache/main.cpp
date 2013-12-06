// Cache.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "cache.h"
#include <iostream>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int value = 0;
	cache c(2);
	c.add(1, 2);
	c.add(3, 4);
	cout << "Found 1 ? "  << (c.get(1, value) ? "True" : "False") << endl;
	cout << value << endl;
	c.add(5, 6);
	cout << "Found 1 ? "  << (c.get(1, value) ? "True" : "False") << endl;
	cout << value << endl;
	cout << "Found 3 ? "  << (c.get(3, value) ? "True" : "False") << endl;
	cout << value << endl;
	cout << "Found 5 ? "  << (c.get(5, value) ? "True" : "False") << endl;
	cout << value << endl;
	cout << "Found 2 ? "  << (c.get(2, value) ? "True" : "False") << endl;
	cout << value << endl;
	return 0;
}
