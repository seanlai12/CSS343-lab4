/*
 * Lab4
 * file store.h
 * Author:  Sean Lai and Sai Badey
 * Date:    June 6, 2014
 * Class:   CSS343 - Dr. Carol Zander
 *
 * store.h has a function to start the store processes.
 * The store relies on the inventory manager to handle the tasks.
 * Store hands inventory manager files on the movies, customers, 
 * and transactions
 *
 * ---------------------------------------------------------------------------
 *  Implementation and assumptions:
 *    -- No assumptions
 *    -- Contains 
 * ---------------------------------------------------------------------------
 */

#ifndef STORE_H
#define STORE_H

#include "inventorymanager.h"

class Store {

public:
   //constructor
    Store();
   //destructor
    ~Store();
   
    // initialize and run the store
    void runStore(string customerFile, 
                  string inventoryFile, 
                  string businessFile);

private:
    InventoryManager* inventory; // manages inventory and customers
};

#endif