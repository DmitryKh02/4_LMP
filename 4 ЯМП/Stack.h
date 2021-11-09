#pragma once

template <class Value>
class Stack
{
	Stack* head = nullptr;
	Stack* next;
	Value meaning;
public:
	Stack();
	~Stack();

	void init();
	bool is_empty();

	void push(const Value userdate);
	Value pop();

	void clear();
	void print();
};

template<class Value>
inline Stack<Value>::Stack()
{
	init();
}

template<class Value>
inline Stack<Value>::~Stack()
{
	if (!is_empty()) clear();
}


template <class Value>
void Stack<Value>::init()
{
	head = nullptr;
}

template <class Value>
bool Stack<Value>::is_empty()
{
	return head == nullptr ? 1 : 0;
}


template <class Value>
void Stack<Value>::push(const Value userdate)
{
	Stack* add = new Stack;

	add->meaning = userdate;
	add->next = head;
	head = add;

	add = nullptr;
}

template<class Value>
inline Value Stack<Value>::pop()
{
	Stack* now = head;
	Value delMeaning = meaning;
	
	head = head->next;
	delete now;
	now = nullptr;

	return delMeaning;
}

template<class Value>
inline void Stack<Value>::clear()
{
	if (!is_empty())
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
inline void Stack<Value>::print()
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


