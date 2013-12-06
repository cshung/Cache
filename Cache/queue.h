#ifndef __QUEUE_H__
#define __QUEUE_H__

template<class T>
class queue_node
{
public:
	queue_node(T data) : data(data)
	{
		this->prev = NULL;
		this->next = NULL;
	}
	
	T data;
	queue_node<T>* prev;
	queue_node<T>* next;
};

template<class T>
class queue
{
public:
	int size()
	{
		return _size;
	}
	queue()
	{
		this->head = NULL;
		this->tail = NULL;
		this->_size = 0;
	}

	queue_node<T>* enqueue(T item)
	{
		// Step 1: Construct new node
		queue_node<T>* newNode = new queue_node<T>(item);
		
		// Step 2: Concatenate it to the tail
		if (tail != NULL)
		{
			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;
		}
		else
		{
			head = tail = newNode;
		}

		_size++;
		return newNode;
	}

	T dequeue()
	{
		T result = head->data;
		if (head->next == NULL)
		{
			delete head;
			head = tail = NULL;
		}
		else
		{
			queue_node<T>* new_head = head->next;
			new_head->prev = NULL;
			delete head;
			head = new_head;
		}

		_size--;
		return result;
	}

	void move_to_end(queue_node<T>* queue_node)
	{
		if (head == tail)
		{
			return;
		}
		else
		{
			// Removing queue_node from the chain
			if (queue_node->prev != NULL)
			{
				queue_node->prev->next = queue_node->next;
			}
			if (queue_node->next != NULL)
			{
				queue_node->next->prev = queue_node->prev;
			}

			// Adjust head and tail as needed
			if (queue_node == head)
			{
				head = head->next;
			}
			if (queue_node == tail)
			{
				tail = tail->prev;
			}

			// Append queue_node to the end
			queue_node->prev = tail;
			queue_node->next = NULL;
			tail->next = queue_node;
			tail = queue_node;
		}
	}

	~queue()
	{
		while(_size > 0)
		{
			dequeue();
		}
	}
private:
	queue_node<T>* head;
	queue_node<T>* tail;
	int _size;
};

#endif
