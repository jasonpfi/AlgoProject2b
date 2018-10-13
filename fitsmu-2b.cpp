#include <iostream>
#include <random>
#include <time.h>
#include "deck.h"
#include <vector>

// Friend of Deck / Global method to play the game
int playFlip()
{
   // Current player's points; the full deck; vector of already flipped cards;
   // Card chosen to be flipped
   int points = 0;
   deck fullDeck = deck();
   std::vector<int> flippedCards;
   int chosenCard;

   // Shuffle full deck 3 times
   for (int i = 0; i < 3; i++)
   {
      fullDeck.shuffle();
   }

   // The player's current hand; instantiate with first card from the deck
   deck currentHand = deck(fullDeck.deal());

   // Add an additional 23 cards from the deck to the player's hand
   // Place added cards at the back of the player's hand
   for (int i = 0; i < 23; i++)
   {
      currentHand.replace(fullDeck.deal());
   }

   do
   {
      do
      {
         std::cout << "Pick a card to flip: ";
         std::cin  >> chosenCard;
      } while (chosenCard > 24)

      // Make sure this card has not been chosen before
      for (int i = 0; i < flippedCards.size(); i++)
      {
         if (flippedCards.at(i) == chosenCard)
         {
            std::cout << "You've already chosen this card!\n";
            std::cout << "Pick another card: ";
            std::cin  >> chosenCard;

            // Restart the loop for new input
            i = 0;
         }
      }
      if (chosenCard != 0)
      {
         node<card>* curr = currentHand.first;

         for (int i = 0; i < chosenCard; i++)
         {
            curr = curr->next;
         }

         std::cout << curr->value << ", " << curr->suit;
         flippedCards.push_back(chosenCard);
      }
   } while (chosenCard != 0)

   std::cout << "You've ended the game!";
   return 0;
}

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
