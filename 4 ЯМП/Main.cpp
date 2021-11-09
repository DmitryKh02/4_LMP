#include <iostream>
#include "Stack.h"


//template <class Value>
int main()
{
	Stack <char> task;
	char elem;

	std::cout << "Please, enter construction: ";
	do
	{
		std::cin >> elem;
		std::cout << "\nLitera is " << elem;
	}
	while (elem != '\n');

	std::cin.ignore().get();

	return 0;
}