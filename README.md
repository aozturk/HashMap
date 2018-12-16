# HashMap [![Build Status](https://travis-ci.org/aozturk/HashMap.svg?branch=master)](https://travis-ci.org/aozturk/HashMap) [![Coverage Status](https://coveralls.io/repos/aozturk/HashMap/badge.svg?branch=master&service=github)](https://coveralls.io/github/aozturk/hashMap?branch=master)

Basic Hash Map Implementation in C++
------------------------------------

## Usage

### Example

Define a hash function by overloading operator() for integer typed key

```c++
struct MyKeyHash {
	unsigned long operator()(const int& key) const
	{
		return key % 10;
    	}
};
```
	
Declare a hash map with integer typed key and string type value pair

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

## Build

This is a header only library, so no compile step is required.
To use the functionality below however, you must use cmake to generate
the makefiles.

```bash
mkdir build
cd build
cmake ..
```

## Install

```bash
make install
```

(Optional) You can also create packages in the build directory.
See cpack for details, here is an example for ubuntu.

```bash
cpack -G DEB
sudo dpkg -i *.deb
```

### Test

From build directory, run tests:

```bash
make test
```

You can also check the test coverage:

```bash
make coverage
```

## License

Licensed under [the Apache 2.0 license](LICENSE). 
