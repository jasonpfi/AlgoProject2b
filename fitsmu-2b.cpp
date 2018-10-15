#include <iostream>
#include <random>
#include <time.h>
#include <vector>
#include "deck.h"
#include <vector>

// Global methods needed to play game
void playFlip();
void newScore(int& prevScore, const card& selection);
bool cardsRemain(const std::vector<bool>& status);
card selectCard(std::vector<bool>& status, const deck& playerDeck);
bool stop();

int main()
// Main method, entry point of execution
{
	srand(time(NULL));

	playFlip();

	std::cin.get();
	return 0;
}

void playFlip()
// Plays the flip game
{
	// Welcome to game
	std::cout << "Welcome to Flip!" << std::endl;

	// Generate cards and shuffle 3 times
	deck mainDeck;

	// Shuffle full deck 3 times
	for (int i = 0; i < 3; i++)
	{
		mainDeck.shuffle();
	}

	// create a player deck with 24 cards
	deck playerDeck;
	for (int i = 0; i < 25; i++)
   {
		playerDeck.replace(mainDeck.deal());
   }

   // Print out top 24 cards and remaining deck
   std::cout << "Top 24 Cards: " << playerDeck << "Remaining Cards: "
             << mainDeck;

	int score(0);
	std::vector<bool> selectedCards = std::vector<bool>(24, false);

   // Loop depends on if there are cards that haven't been chosen, and if
   //  the player still wants to play
   while (cardsRemain(selectedCards) && !stop())
	{
		// select a card from the 24
		card selected = selectCard(selectedCards, playerDeck);
		std::cout << "You selected:" << std::endl << selected;

      // Put the card at the end of the player's hand
      playerDeck.replace(selected);

		// update score
		newScore(score, selected);

      // Print player's hand and the score
      std::cout << "Current score: " << score << std::endl;
		std::cout << "Current hand: " << std::endl;
		std::cout << playerDeck;
	} // End While

	std::cout << "Final Score: " << score << std::endl
		<< "Thanks for Playing." << std::endl;
} // End PlayFlip()

bool stop()
// Determines if the player wants to stop playing
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
			std::cout << "Sorry, I didn't quite catch that. I'll ask again."
            << std::endl;
		}
	} // End While
} // End Stop

void newScore(int& score, const card& selection)
// Determines player's new score depending on previous score and input
//
// prevScore: integer representing the players current score
// selection: the card that has been selected
{
	int v = selection.getValue();
	std::string s = selection.getSuit();

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

   // Increment Score by 1 for heart
	if (s == "Heart") score++; // Heart
} // End newScore

bool cardsRemain(const std::vector<bool>& status)
// Checks if cards remain in the deck by examining the status vector
//
// status: Vector of booleans, where true means the card of the hand at that
//          index has already been picked
{
	for (int i = 0; i < status.size(); i++)
		if (status.at(i) == false) return true;

	return false;
}

card selectCard(std::vector<bool>& status, const deck& playerDeck)
// Selects a card from the player's hand if that card has not already been
//  chosen
//
// status: Vector of booleans, where true means the card of the hand at that
//          index has already been picked
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
		else if (status.at(number - 1))
		{
			std::cout << "That card has already been selected." << std::endl;
		}
		else
		{
			status.at(number - 1) = true;
			return playerDeck.getCardValue(number - 1);
		}
	} // End While
} // End SelectCard()
