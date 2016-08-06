/*
 * Lab4
 * file store.cpp
 * Author:  Sean Lai and Sai Badey
 * Date:    June 6, 2014
 * Class:   CSS343 - Dr. Carol Zander
 *
 * store.h has a function to start the store processes.
 * The store relies on the inventory manager to handle the tasks.
 * Store hands inventory manager files on the movies, customers, 
 * and transactions
 */


#include "store.h"


//-----------------------------------------------------------------------------
// Store
// default constructor
// initializes the inventory manager
Store::Store()
{
    inventory = new InventoryManager();
}

//-----------------------------------------------------------------------------
// ~Store
// destructor
Store::~Store()
{
    delete inventory;
}

//-----------------------------------------------------------------------------
// runStore
// Takes in the files from the main and hands it to the inventory
void Store::runStore(string moviesInStock,
                     string customerList,
                     string transactionList)
{
    //hands the files to manager
    inventory->initializeProducts(moviesInStock);
    inventory->initializeCustomers(customerList);
    inventory->processTransactions(transactionList);
}
//SEAN YOU NEED TO CHANGE THIS!!!!!
//basically, take the first three lines of creating ifstreams and send them into
//the first lines of the inventory manager functions