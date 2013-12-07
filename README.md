Basic Hash Map Implementation in C++
------------------------------------

Basic Usage:

Define hash function by implementing operator()

	struct MyKeyHash {
    	unsigned long operator()(const int& k) const
    	{	
        	return k % 10;
    	}
	};
	
Declare a hashmap with integer type key and string type value

	HashMap<int, string, MyKeyHash> hmap;

Put a key-value pair

	hmap.put(1, "1");

Get the value by key; returns true if successful with value updated

	string value;
	bool result = hmap.get(2, value);
