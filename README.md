Basic Hash Map Implementation in C++
------------------------------------

Compile and run tests

	make

### Example Usage

Define a hash function by overloading operator() for integer type key

	struct MyKeyHash {
    	unsigned long operator()(const int& k) const
    	{	
        	return k % 10;
    	}
	};
	
Declare a hashmap with integer type key and string type value pair

	HashMap<int, string, MyKeyHash> hmap;

Put a key-value pair into the hashmap

	hmap.put(1, "1");

Get the value by key; returns true if successful with value updated

	string value;
	bool result = hmap.get(2, value);
