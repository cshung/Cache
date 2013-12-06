#ifndef __PREDICATE_H__
#define __PREDICATE_H__

template <class T>
class predicate
{
public:
	virtual bool is_true(const T& item) = 0;
};

#endif
