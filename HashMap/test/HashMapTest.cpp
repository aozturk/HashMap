#include <iostream>
#include <string>
#include <assert.h>
#include "../src/HashMap.h"

using namespace std;

struct MyKeyHash {
    unsigned long operator()(const int& k) const
    {
        return k % 10;
    }
};

int main() 
{
	HashMap<int, string, MyKeyHash> hmap;
	hmap.put(1, "1");
	hmap.put(2, "2");
	hmap.put(3, "3");
 
	string value;
	bool result = hmap.get(2, value);
	assert(result);
	assert(value == "2");

	result = hmap.get(3, value);
	assert(result);
	assert(value == "3");

	hmap.remove(3);
	result = hmap.get(3, value);
	assert(!result);

	cout << "All tests passed!" << endl;
}
