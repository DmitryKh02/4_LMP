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

		int round = 0, square = 0, curly = 0;
		int i = 0, j = 0;

		while(i != countSymbol)
		{
			elem = oldSubsequence[i];

			switch (elem)
			{
			case '(': round ++;
				break;
			case '[': square ++;
				break;
			case '{': curly ++;
				break;
			case ')': round--;
				break;
			case ']': square--;
				break;
			case '}': curly--;
				break;
			default:
			{	
				if (round == 0 && square == 0 && curly == 0)
				{
					newSubsequence[j] = elem;
					j++;
				}
				else task->push(task, elem);
			}break;
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