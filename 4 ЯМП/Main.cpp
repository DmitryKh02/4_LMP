#include <iostream>
#include "Stack.h"

bool isBracket(char elem);

int main()
{
	Stack<char> *task = new Stack<char>;

	char elem = 0;

	char* newSubsequence, *oldSubsequence = new char[256] {};
	int countLetters = -1, countSymbol = -1;

	std::cout << "Please, enter construction: ";

	do
	{
		std::cin.get(elem);
		countSymbol++;
		if (!isBracket(elem)) countLetters++;
		
		oldSubsequence[countSymbol] = elem;

	} while (elem != '\n');


	if (countLetters != 0)
	{
		newSubsequence = new char[countLetters] {};

		bool round = false, square = false, curly = false;
		int i = 0, j = 0;

		while(i != countSymbol)
		{
			elem = oldSubsequence[i];

			if (!round && !square && !curly)
			{
				switch (elem)
				{
				case '(': round = true;
					break;
				case '[': square = true;
					break;
				case '{': curly = true;
					break;
				default:
				{	
					newSubsequence[j] = elem;
					j++;
				}break;
				}
			}
			else
			{
				if (round)
				{
					if (!isBracket(elem)) task->push(task,elem);
					else 
						if(elem == ')') round = false;
				}
				if (square)
				{
					if (!isBracket(elem)) task->push(task,elem);
					else
						if (elem == ']') square = false;
				}
				if (curly)
				{
					if (!isBracket(elem)) task->push(task,elem);
					else
						if (elem == '}') curly = false;
				}
			}
			i++;
		}


		for (; j < countLetters; j++)
		{
			elem = task->pop(task);
			newSubsequence[j] = elem;
		}

		for (size_t i = 0; i < countLetters; i++)
		{
			std::cout << newSubsequence[i];
		}
	}
	else std::cout << "Subsequence include only {,[,( or },]<) !";

	std::cin.ignore().get();

	return 0;
}

bool isBracket(char elem)
{
	return  ((elem == '(') || (elem == '[') || (elem == '{') || (elem == '}') || (elem == ']') || (elem == ')')) ? 1 : 0;
}