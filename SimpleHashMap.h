// Really simple, yet working hash map implementation
//

// Configurable table size constant
const int TABLE_SIZE = 128;

// Hash node class
class HashNode {
public:
	HashNode(int key, int value) :
		_key(key), _value(value), _next(0) {
	}

	int key() {
		return _key;
	}
	int value() {
		return _value;
	}
	HashNode* next() {
		return _next;
	}
	void set_value(int value) {
		_value = value;
	}
	void set_next(HashNode* next) {
		_next = next;
	}

private:
	// Key-value pair
	int _key;
	int _value;

	HashNode* _next;
};

// Hash map class
class HashMap {
public:
	HashMap() {
		_table = new HashNode*[TABLE_SIZE];
		for (int i = 0; i < TABLE_SIZE; ++i)
			_table[i] = 0;
	}
	~HashMap() {
		for (int i = 0; i < TABLE_SIZE; ++i) {
			HashNode* entry = _table[i];
			while (entry != 0) {
				HashNode* prev = entry;
				entry = entry->next();
				delete prev;
			}
		}
	}

	// Should be optimized according to specific needs
	int HashFunc(int key) {
		return key % TABLE_SIZE;
	}

	int Get(int key) {
		int hash_val = HashFunc(key);
		HashNode* entry = _table[hash_val];

		while (entry != 0) {
			if (entry->key() == key) {
				return entry->value();
			}
			entry = entry->next();
		}
		return -1;
	}

	void Put(int key, int value) {
		int hash_val = HashFunc(key);
		HashNode* prev = 0;
		HashNode* entry = _table[hash_val];

		while (entry != 0 && entry->key() != key) {
			prev = entry;
			entry = entry->next();
		}

		if (entry == 0) {
			entry = new HashNode(key, value);
			if (prev == 0) {
				_table[hash_val] = entry;
			} else {
				prev->set_next(entry);
			}
		} else {
			entry->set_value(value);
		}
	}

	void Remove(int key) {
		int hash_val = HashFunc(key);
		HashNode* entry = _table[hash_val];

		HashNode* prev = 0;
		while (entry != 0) {
			if (entry->key() == key) {
				break;
			}
			prev = entry;
			entry = entry->next();
		}
		if (entry == 0)
			return;
		else {
			if (prev == 0) {
				_table[hash_val] = entry->next();
			} else {
				prev->set_next(entry->next());
			}
			delete entry;
		}
	}

private:
	// Hash table
	HashNode** _table;
};