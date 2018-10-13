#include <iostream>
#include <random>
#include <time.h>
#include "deck.h"

int main()
{
	srand(time(NULL));

	deck fullDeck;

	std::cout << "Printing sorted deck:" << std::endl;
	std::cout << fullDeck;

	fullDeck.shuffle();

	std::cout << "Printing shuffled deck:" << std::endl;
	std::cout << fullDeck;

	std::cin.get();
}
