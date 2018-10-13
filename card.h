/**
 * Team: fitsmu
 * Jason Fitch
 * Sam Smucny
 *
 * card.h: Contains the declarations for the card class, including member
 *         methods and data members
 */

#include <iostream>

class card
{

public:

	// Constructors
	card(const int value, const std::string suit)
		: value(value), suit(suit) {}

	// Getters and Setters
	int getValue() const { return value; }
	void setValue(const int& value) { this->value = value; }

   std::string getSuit() const { return suit; }
	void setSuit(const std::string& suit) { this->suit = suit; }

	// Overloaded operators
	friend std::ostream& operator <<(std::ostream& out, const card& card);


private:

	// Rank of the card
	// 1(Ace) through 13(King)
	int value;

	// Suit of the card
	// Club, Diamond, Heart, Spade
   std::string suit;

};
