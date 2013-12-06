#ifndef __PAIR_H__
#define __PAIR_H__

template <class T, class U>
struct pair
{
public:
	pair(T first, U second) : first(first), second(second)
	{
	}

	T first;
	U second;
};

#endif
