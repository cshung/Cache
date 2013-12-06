#ifndef __CACHE_H__
#define __CACHE_H__

#include "pair.h"
#include "hash_table.h"
#include "int_hash_function.h"
#include "queue.h"

class cache
{
public:
	cache(int capacity);
	~cache();
	void add(int key, int value);
	bool get(int key, int& value);
private:
	const int capacity;
	hash_table<int, pair<int, queue_node<int>*>>* values;
	queue<int>* keys;
	int_hash_function* hash_function;
};

#endif
