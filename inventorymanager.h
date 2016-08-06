/*
 * Lab4
 * file inventorymanager.h
 * Author:  Sean Lai and Sai Badey
 * Date:    June 6, 2014
 * Class:   CSS343 - Dr. Carol Zander
 *
 * inventorymanager.h has functions to initialize products, customers,
 * and process transactions.
 * Contains functions to display contents of the inventory.
 * Also prints the histories of customer transactions.
 *
 * ---------------------------------------------------------------------------
 *  Implementation and assumptions:
 *    -- Main class which does most of the work.
 * ---------------------------------------------------------------------------
 */

#ifndef InventoryManager_H
#define InventoryManager_H
#include "customer.h"
#include "bintree.h"
#include "movie.h"
#include "factory.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
const int COMMANDS_MAX = 26; //Max Letters for Genre
const int CUSTOMER_MAX = 10007; //Max Customer Accounts
const int PRODUCT_MAX = 10; //Max of each VideoStoreItem

   
class InventoryManager 
{
public:
   InventoryManager(); //default constructor
   virtual ~InventoryManager(); //virtual destructor

   void initializeProducts(string); //initializing products
   void initializeCustomers(string); //initializing customers
   void processTransactions(string); //processing transactions
   
   void display() const; //display contents of inventory (movies)
   
   string getBusinessName() const; //Store name accessor

private:
   bool customerFound(int) const; //used to determine if customer exists
   void dumpLine(ifstream&);
   
   string businessName; //Store name
   Factory factory; //instantiates all of the movie & transaction objects
   Customer customerArray[CUSTOMER_MAX]; //array of customer accounts
   BinTree movieTree[COMMANDS_MAX]; //array which uses trees to hold movies
};
#endif
