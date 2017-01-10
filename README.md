# HashMap [![Build Status](https://travis-ci.org/aozturk/HashMap.svg?branch=master)](https://travis-ci.org/aozturk/HashMap) [![Coverage Status](https://coveralls.io/repos/aozturk/HashMap/badge.svg?branch=master&service=github)](https://coveralls.io/github/oazturk/hashMap?branch=master)

Basic Hash Map Implementation in C++
------------------------------------

## Install

This is a header only library, so no build step is required.

## Usage

### Example

Define a hash function by overloading operator() for integer type key

```c++

	struct MyKeyHash {
    	unsigned long operator()(const int& k) const
    	{	
        	return k % 10;
    	}
	};
```
	
Declare a hashmap with integer type key and string type value pair

```c++
	size_t tableSize = 10;
	HashMap<int, string, tableSize, MyKeyHash> hmap;
```

Put a key-value pair into the hashmap

```c++
	hmap.put(1, "1");
```

Get the value by key; returns true if successful with value updated

```c++
	string value;
	bool result = hmap.get(2, value);
```

### Testing

Starting in the root directory of the repository:

```bash
	mkdir bulid
	cd build
	cmake ..
	make
```

From build directory:

```bash
	make test
```

You can also check test coverage:

```bash
	make coverage
```

## License

Licensed under [the Apache 2.0 license](LICENSE). 
