#ifndef __INT_HASH_FUNCTION_H__
#define __INT_HASH_FUNCTION_H__

#include "hash_function.h"

class int_hash_function : public hash_function<int>
{
public:
	virtual int hash(int key, int table_size) const ;
};

#endif
