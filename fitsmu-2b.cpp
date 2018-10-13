#include <iostream>
#include <random>
#include <time.h>
#include <vector>
#include "deck.h"

void playFlip();
int newScore(const int& prevScore, const card& selection);
bool cardsRemain(const std::vector<bool>& status);
card selectCard(std::vector<bool>& status, const deck& playerDeck);
bool stop();

int main()
{
	srand(time(NULL));

	playFlip();

	std::cin.get();
}

void playFlip()
{
	// Welcome to game
	std::cout << "Welcome to Flip" << std::endl;

	// Generate cards and shuffle 3 times
	deck mainDeck;

	mainDeck.shuffle();
	mainDeck.shuffle();
	mainDeck.shuffle();

	// create a player deck with 24 cards
	deck playerDeck(NULL);
	for (int i = 0; i < 25; i++)
		playerDeck.replace(mainDeck.deal());



	int score(0);
	std::vector<bool> selectedCards = std::vector<bool>(24, false);
	deck playerHand(NULL);
	while (cardsRemain(selectedCards))
	{
		std::cout << "Current score: " << score << std::endl;
		std::cout << "Current hand: " << std::endl;
		std::cout << playerHand;

		// ask if player wants to continue
		if (stop())
			break;

		// select a card from the 24
		card selected = selectCard(selectedCards, playerDeck);
		std::cout << "You selected:" << std::endl << selected;
		playerDeck.replace(selected);

		// update score
		score = newScore(score, selected);
	}

	std::cout << "Final Score: " << score << std::endl 
		<< "Thanks for Playing." << std::endl;
}

bool stop()
{
	std::string input;
	while (true)
	{
		std::cout << "Would you like to continue? (y/n): ";

		std::cin >> input;

		if (input == "y" || input == "Y" || input == "Yes")
		{
			return false;
		}
		else if (input == "n" || input == "N" || input == "No")
		{
			return true;
		}
		else
		{
			std::cout << "Sorry, I didn't quite catch that. I'll ask again." << std::endl;
		}
	}
}

int newScore(const int& prevScore, const card& selection)
{
	int v = selection.getValue();
	std::string s = selection.getSuit();
	int score = prevScore;
	if (v == 1) // A
	{
		score += 10;
	}
	else if (v >= 11) // J, Q, K
	{
		score += 5;
	}
	else if (v == 7) // 7
	{
		score = (score / 2) + (score % 2);
	}
	else if (v >= 2 && v <= 6) // 2, 3, 4, 5, 6
	{
		score = 0;
	}
	// No effect for 8, 9, 10

	if (s == "Heart") score++; // Heart

	return score;
}

bool cardsRemain(const std::vector<bool>& status)
{
	for (int i(0); i < status.size(); i++)
		if (status.at(i) == false) return true;

	return false;
}

card selectCard(std::vector<bool>& status, const deck& playerDeck)
{
	while (true)
	{
		std::cout << "Please select a card number (1-24): ";
		int number;
		std::cin >> number;

		if (number < 1 || number > 24)
		{
			std::cout << "Your number was not in the correct range." << std::endl;
		}
		else if (status.at(number-1))
		{
			std::cout << "That card has already been selected." << std::endl;
		}
		else
		{
			status.at(number-1) = true;
			return playerDeck.getCardValue(number-1);
		}
	}
}
