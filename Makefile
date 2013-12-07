all:
	g++ -o hashtest test/HashMapTest.cpp -Isrc; ./hashtest; rm hashtest

