#pragma once

template <class Value>
class Stack
{
	Stack* next;
	Value meaning;
public:
	Stack();
	void init();
	bool is_empty(Stack* head);

	void push(Stack*& head,const Value userdate);
	Value pop(Stack*& head);

	void clear(Stack*& head);
	void print(Stack* head);
};


template<class Value>
inline Stack<Value>::Stack()
{
	init();
}


template <class Value>
inline void Stack<Value>::init()
{
	next = nullptr;
	meaning = 0;
}

template <class Value>
inline bool Stack<Value>::is_empty(Stack* head)
{
	return head == nullptr ? 1 : 0;
}


template <class Value>
void Stack<Value>::push(Stack*& head, const Value userdate)
{
	Stack* add = new Stack;

	add->meaning = userdate;
	add->next = head;
	head = add;

	add = nullptr;
}

template<class Value>
Value Stack<Value>::pop(Stack*& head)
{	
	Value delMeaning = meaning;
	Stack* now = head;

	head = head->next;
	delete now;
	now = nullptr;
	
	return delMeaning;
}



template<class Value>
void Stack<Value>::clear(Stack*& head)
{
	if (!is_empty(head))
	{
		Stack* now = nullptr;

		while (head != nullptr)
		{
			now = head;
			head = head->next;
			delete now;
			now = nullptr;
		}
	}
}

template<class Value>
void Stack<Value>::print(Stack* head)
{
	if (!is_empty())
	{
		Stack* now = head;

		while (now != nullptr)
		{
			std::cout << "\n" << now->meaning;
			now = now->next;
		}
	}
	else std::cout << "Stack is empty!";
}


