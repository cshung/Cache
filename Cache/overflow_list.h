#ifndef __LIST_H__
#define __LIST_H__

#include "predicate.h"

template <class T>
class overflow_list
{
public:
	overflow_list()
	{
		head = NULL;
	}
	~overflow_list()
	{
		while (head != NULL)
		{
			overflow_list_node* temp = head->next;
			delete head;
			head = temp;
		}
	}

	void add(T data)
	{
		overflow_list_node* newNode = new overflow_list_node(data);
		newNode->next = head;
		head = newNode;
	}

	T* find_first(predicate<T>* match)
	{
		overflow_list_node* temp = head;
		while (temp != NULL)
		{
			if (match->is_true(temp->data))
			{
				return &temp->data;
			}
			temp = temp->next;
		}

		return NULL;
	}

	bool remove_first(predicate<T>* match)
	{
		overflow_list_node* prev = NULL;
		overflow_list_node* temp = head;
		while (temp != NULL)
		{
			if (match->is_true(temp->data))
			{
				if (prev == NULL)
				{
					head = temp->next;
					delete temp;
				}
				else
				{
					prev->next = temp->next;
					delete temp;
				}

				return true;
			}

			prev = temp;
			temp = temp->next;
		}

		return false;
	}
private:
	class overflow_list_node
	{	
	public:
		overflow_list_node(T data) : data(data)
		{
			// Rule 1: Always initialize pointer to NULL to avoid random values leading to hard to debug
			next = NULL;
		}

		T data;
		overflow_list_node* next;
	};
	overflow_list_node* head;
};

#endif
