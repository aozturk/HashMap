Basic Hash Map implementation in C++
====================================

Basic Usage:

	struct MyKeyHash {
    	unsigned long operator()(const int& k) const
    	{	
        	return k % 10;
    	}
	};
	
	HashMap<int, string, MyKeyHash> hmap;

	hmap.put(1, "1");

	string value;
	bool result = hmap.get(2, value);
