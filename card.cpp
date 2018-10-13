/**
 * Team: fitsmu
 * Jason Fitch
 * Sam Smucny
 *
 * card.cpp: The cpp file for the card class. Since all member methods were
 *           defined inline, this file only contains the implementation for
 *           the friend operator overload function to output the value and suit
 *           of the card
 */

#include "card.h"

std::ostream& operator << (std::ostream& out, const card& card)
// Overloaded output operator
{
   return out << "Suit: " << card.suit << "\nValue: " <<
          card.value << std::endl;
}

