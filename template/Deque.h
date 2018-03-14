#pragma once

template <typename T>
class Deque
{
private:
	struct Node
	{
		T value;
		Node * next;
		Node * prev;
	};
	Node * _head;
	Node * _tail;
	int count;
public:
	Deque(): _head(NULL), _tail(NULL), count(0) {};
	bool empty() 
	{
		return count == 0;
	}

	void PushFront(T element)
	{	
		Node * tmp = new Node;
		tmp->value = element;
		tmp->next = NULL;
		tmp->prev = NULL;

		if (empty()) 
		{	
			_tail = _head = tmp;
		}
		else
		{
			tmp->prev = _head;
			_head->next = tmp;
			_head= tmp;
		}

		count++;
	}

	T PopFront()
	{
		if (empty())
		{
			cout << "empty";
		}

		T t = _head->value;

		Node * tmp = _head;
		if (_head->prev != NULL)
		{
			_head = _head->prev;
			_head->next = NULL;
		}
		else
		{
			_head = NULL;
		}
		
		delete tmp;
		count--;
		return t;
	}

	void PushBack(T element)
	{
		Node * tmp = new Node;
		tmp->value = element;
		tmp->next = NULL;
		tmp->prev = NULL;

		if (empty())
		{
			_tail = _head = tmp;
		}
		else
		{
			tmp->next = _tail;
			_tail->prev = tmp;
			_tail = tmp;
		}

		count++;
	}

	T PopBack()
	{
		if (empty)
		{
			cout << "empty";
		}

		T t = _tail->value;

		Node * tmp = _tail;
		if (_tail->next != NULL)
		{
			_tail = _tail->next;
			_tail->prev = NULL;
		}
		else
		{
			_tail = NULL;
		}

		delete tmp;
		count--;
		return t;
	}

	int Size()
	{
		return count;
	}

	~Deque() {};
};

