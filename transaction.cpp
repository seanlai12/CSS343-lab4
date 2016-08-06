/*
 * Lab4
 * file transaction.cpp
 * Author:  Sean Lai and Sai Badey
 * Date:    June 6, 2014
 * Class:   CSS343 - Dr. Carol Zander
 *
 * transaction.cpp has functions to create and modify the objects.
 * Contains functions to modify stock count of the transcations.
 * Stores type of transaction, media type, and item.
 */

#include "transaction.h"

//-----------------------------------------------------------------------------
// Transaction
// default constructor
// initializes the data
Transaction::Transaction()
{
    transactionType = "Transaction";
    mediaType = "";
    storeItem = NULL;
}

//-----------------------------------------------------------------------------
// Transaction
// copy constructor
// takes a transaction object as parameter
// creates a transaction copy.
Transaction::Transaction(const Transaction& other)
{
   transactionType = other.transactionType;
   mediaType = other.mediaType;
   storeItem = other.storeItem;
}

//-----------------------------------------------------------------------------
// ~Transaction
// destructor
Transaction::~Transaction()
{
}

//-----------------------------------------------------------------------------
// setData
// takes string, Product and Customer as parameters
// Sets the media and item and returns true;
bool Transaction::setData(string media, Product* newItem, Customer* theCustomer)
{
   mediaType = media;
   storeItem = newItem;
   return true; //return true to indicate stored transaction
}

//-----------------------------------------------------------------------------
// display
// display the mediaType and transactionType
void Transaction::display() const
{
   cout << mediaType << " " << transactionType << " ";
}

//-----------------------------------------------------------------------------
// create
// return a transaction
Transaction* Transaction::create()
{
   return new Transaction();
}

//-----------------------------------------------------------------------------
// getMediaType
// return the media type
string Transaction::getMediaTye()
{
   return mediaType;
}

//-----------------------------------------------------------------------------
// getTransType
// return the transaction type
string Transaction::getTransType()
{
   return transactionType;
}

//-----------------------------------------------------------------------------
// getItem
// return store item
Product* Transaction::getItem() const
{
   return storeItem;
}
