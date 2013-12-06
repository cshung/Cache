#include "stdafx.h"
#include "cache.h"
#include "queue.h"
#include "pair.h"
#include "int_hash_function.h"

cache::cache(int capacity) : capacity(capacity)
{
	this->hash_function = new int_hash_function();
	this->keys = new queue<int>();
	this->values = new hash_table<int, pair<int, queue_node<int>*>>(capacity, hash_function);
}

cache::~cache()
{
	delete this->keys;
	delete this->values;
	delete this->hash_function;
}

void cache::add(int key, int value)
{	
	queue_node<int>* new_queue_node = this->keys->enqueue(key);
	this->values->add(key, pair<int, queue_node<int>*>(key, new_queue_node));
	if (this->keys->size() > capacity)
	{
		int evict_key = this->keys->dequeue();
		this->values->remove(evict_key);
	}
}

bool cache::get(int key, int& value)
{
	pair<int, queue_node<int>*>* result = NULL;
	bool found = this->values->get(key, result);
	if (found)
	{
		this->keys->move_to_end(result->second);
		value = result->first;
	}

	return found;
}
