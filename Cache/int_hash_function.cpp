#include "stdafx.h"
#include "int_hash_function.h"

int int_hash_function::hash(int key, int table_size) const 
{
	return key % table_size;
}