#ifndef __HASH_TABLE_H__
#define __HASH_TABLE_H__

#include "hash_function.h"
#include "overflow_list.h"
#include "pair.h"
#include "predicate.h"

template <class TKey, class TValue>
class hash_table
{
public:
	hash_table(int table_size, const hash_function<TKey>* hash_function) : table_size(table_size)
	{
		this->hash_function = hash_function;
		this->table = new overflow_list<pair<TKey, TValue>>[table_size];
	}

	void add(TKey key, TValue value)
	{
		int hash_value = this->hash_function->hash(key, table_size);
		this->table[hash_value].add(pair<TKey, TValue>(key, value));
	}

	bool get(TKey key, TValue*& value)
	{
		int hash_value = this->hash_function->hash(key, table_size);
		key_match_predicate match(key);
		pair<TKey, TValue>* found = this->table[hash_value].find_first(&match);
		if (found == NULL)
		{
			return false;
		}
		else
		{
			value = &(found->second);
			return true;
		}
	}

	bool remove(int key)
	{
		int hash_value = this->hash_function->hash(key, table_size);
		key_match_predicate match(key);
		return this->table[hash_value].remove_first(&match);
	}

	~hash_table()
	{
		delete[] this->table;
		// Rule 2: Just good practice, set NULL after deletion can ease debugging
		this->table = NULL;
	}

	class key_match_predicate : public predicate<pair<TKey, TValue>>
	{
	public:
		key_match_predicate(TKey key)
		{
			this->key = key;
		}

		virtual bool is_true(const pair<TKey, TValue>& item)
		{
			return item.first == key;
		}
	private:
		TKey key;
	};
private:
	const int table_size;
	const hash_function<TKey>* hash_function;
	overflow_list<pair<TKey, TValue>>* table;
};

#endif
