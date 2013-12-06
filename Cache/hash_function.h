#ifndef __HASH_FUNCTION_H__
#define __HASH_FUNCTION_H__

template<class TKey>
class hash_function
{
public:
	virtual int hash(TKey key, int table_size) const = 0;
};

#endif
