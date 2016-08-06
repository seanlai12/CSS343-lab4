/*
 * Lab4
 * file return.cpp
 * Author:  Sean Lai and Sai Badey
 * Date:    June 6, 2014
 * Class:   CSS343 - Dr. Carol Zander
 */

#include "return.h"

//-----------------------------------------------------------------------------
// Return
// default constructor
Return::Return() :Transaction()
{
   transactionType = "Return";
}

//-----------------------------------------------------------------------------
// Return
// copy constructor
// takes a return object as parameter
// creates a copy return object
Return::Return(const Return& other)
{
   transactionType = other.transactionType;
   mediaType = other.mediaType;
   storeItem = other.storeItem;
}

//-----------------------------------------------------------------------------
// ~Return
// destructor
Return::~Return()
{
}

//-----------------------------------------------------------------------------
// setData
// takes string, Product, and Customer as parameter
// sets the mediatype, storeitem
// increase the stock if product returned.
// returns true if stored
bool Return::setData(string media, Product* newMovie, Customer* customer)
{
   if(newMovie != NULL)
   {
      mediaType = media;
      storeItem = newMovie;

      if (mediaType != "") //if valid, update stock
      {
         storeItem->incrementStock();
      }
   }
   return true; //return true to indicate stored transaction
}

//-----------------------------------------------------------------------------
// display
// displays mediaType and transactionType
void Return::display() const
{
   cout << mediaType << " " << transactionType << " ";
}

//-----------------------------------------------------------------------------
// create
// return new return object for factory
Transaction* Return::create()
{
   return new Return();
}
