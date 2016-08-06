/*
 * Lab4
 * file borrow.cpp
 * Author:  Sean Lai and Sai Badey
 * Date:    June 6, 2014
 * Class:   CSS343 - Dr. Carol Zander
 *
 * borrow.cpp inherits transaction. Contains data setters and display for
 * borrow objects.
 */

#include "borrow.h"

//-----------------------------------------------------------------------------
// Borrow
// default constructor
Borrow::Borrow() :Transaction()
{
   transactionType = "Borrow";
}

//-----------------------------------------------------------------------------
// ~Borrow
// Destructor
Borrow::~Borrow()
{}


//-----------------------------------------------------------------------------
// setData
// takes string, Product, and Customer as parameter
// sets the mediatype, storeitem
// decrease the stock if product borrowed
// returns true if stored
bool Borrow::setData(string media, Product* newItem, Customer* customer)
{
   if (newItem != NULL)
   {
      mediaType = media;
      storeItem = newItem;
      
      if (mediaType != "") //if valid, decrease stock
      {
         storeItem->decrementStock();
      }
   }
   return true; //transaction stored
}

//-----------------------------------------------------------------------------
// display
// displays mediaType and transactionType
void Borrow::display() const
{
  cout << mediaType << " " << transactionType << " ";
}

//-----------------------------------------------------------------------------
// create
// return new borrow object for factory
Transaction* Borrow::create()
{
   return new Borrow();
}
