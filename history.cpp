/*
 * Lab4
 * file history.cpp
 * Author:  Sean Lai and Sai Badey
 * Date:    June 6, 2014
 * Class:   CSS343 - Dr. Carol Zander
 *
 * history.cpp has functions which track and process the transactions
 * by the customers
 * Stores the number of transactions
 *
 * ---------------------------------------------------------------------------
 *  Implementation and assumptions:
 *    -- Max 10 transactions per customer
 * ---------------------------------------------------------------------------
 */
 
#include "history.h"
#include "customer.h"

//-----------------------------------------------------------------------------
// History
// default constructor
// initializes the array size and contents
History::History() :Transaction()
{
    transactionHistory = new Transaction[10];
    transactionType = "History";
    size = 0;
}


//-----------------------------------------------------------------------------
// History
// copy constructor
// Copies transaction type, mediatype, and store from handed history
History::History(const History& other)
{
   transactionType = other.transactionType;
   mediaType = other.mediaType;
   storeItem = other.storeItem;
}


//-----------------------------------------------------------------------------
// ~History
// destructor
// Deletes array of transactions of customer
History::~History()
{
    for(int i = 0; i < size; i++)
    {
        delete &transactionHistory[i];
    }
    delete [] transactionHistory;
}


//-----------------------------------------------------------------------------
// setData
// display function which calls helper displayAllHistory
bool History::setData(string media, Product* newMovie, Customer* customer)
{
   if (customer != NULL)
   {
      customer->displayAllHistory();
   }
   return false;
}


//-----------------------------------------------------------------------------
// displayAllHistory
// Helper function which prints out contents of history for a customer
void History::displayAllHistory()
{
    if (size > 0)
    {
        for(int i = 0; i < size; i++)
        {
            transactionHistory[i].display();
            transactionHistory[i].getItem()->display();
        }
        cout << endl;
    }
}

//-----------------------------------------------------------------------------
// create
// Instantiator called by factory
Transaction* History::create()
{
   return new History();
}


//-----------------------------------------------------------------------------
// addTransaction
// Includes another transaction at the end of array.
// Tracks number of transactions for customer
void History::addTransaction(Transaction nextTransaction)
{
   if(size < maxSize)
   {
      transactionHistory[size] = nextTransaction;
      size++;
   }
}
