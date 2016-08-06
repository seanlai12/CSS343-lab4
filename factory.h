/*
 * Lab4
 * file factory.h
 * Author:  Sean Lai and Sai Badey
 * Date:    June 6, 2014
 * Class:   CSS343 - Dr. Carol Zander
 *
 * This class contains all the functions that creates is used to create
 * new Transaction and Products and Mediatype chars.
 *
 * ---------------------------------------------------------------------------
 *  Implementation and assumptions:
 *    -- This is the main factory class for Hashing
 *    -- Max size of inventory is 26
 * ---------------------------------------------------------------------------
 */

#ifndef FACTORY_H
#define FACTORY_H
#include "classic.h"
#include "drama.h"
#include "comedy.h"
#include "transaction.h"
#include "borrow.h"
#include "return.h"
#include "history.h"
#include <iostream>
#include <string>

class Movie; //for creating movie
class Transaction; //for creating transaction

using namespace std;

class Factory
{
public:
      Factory(); //default constructor
      ~Factory(); //destructor

      Product* createProduct(char, istream&); //create new Product
      Transaction* createTransaction(char, istream&); //create new Transaction

    
      string getMediaType(char); //get mediatype from letter
      int getSubscript(char); //get array subscript for hash
    
      static const int MAX_LETTERS = 26; //Maximum size for inventory

private:
      Product* productInventory[MAX_LETTERS];
      Transaction* transactionInventory[MAX_LETTERS];
      string mediaType[MAX_LETTERS];

      int hash(char); //returns hash subscript using a char
      void initInventory(); //set initial values for arrays
};
#endif
