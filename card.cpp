/**
 * Team: fitsmu
 * Jason Fitch
 * Sam Smucny
 *
 * card.cpp: The cpp file for the card class. Since all member methods were
 *           defined inline, this file only contains the implementation for
 *           the operator overload functions.
 */

#include "card.h"

std::ostream& operator << (std::ostream& out, const card& card)
// Overloaded output operator
{
   return out << "Suit: " << card.suit << "\nValue: " <<
          card.value << std::endl;
}

card& card::operator= (const card& rhsCard)
// Overloaded assignment operator
{
   this->value = rhsCard.value;
   this->suit  = rhsCard.suit;
   return *this;
}