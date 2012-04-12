// Main.cpp : Defines the entry point for the simple test application.
//

#include <iostream>
#include "SimpleHashMap.h"

int main()
{
	HashMap hmap;

	hmap.Put(3, 10);
	hmap.Put(4, 15);
	hmap.Put(5, 20);

	// expect to see 15 on output
	std::cout << hmap.Get(4) << std::endl;

	hmap.Remove(4);

	// expect to see -1 on output
	std::cout << hmap.Get(4) << std::endl;

	return 0;
}

