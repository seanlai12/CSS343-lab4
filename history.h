/*
 * Lab4
 * file history.h
 * Author:  Sean Lai and Sai Badey
 * Date:    June 6, 2014
 * Class:   CSS343 - Dr. Carol Zander
 *
 * history.h has functions which track and process the transactions
 * by the customers
 * Stores the number of transactions
 *
 * ---------------------------------------------------------------------------
 *  Implementation and assumptions:
 *    -- Max 10 transactions per customer
 * ---------------------------------------------------------------------------
 */

#ifndef HISTORY_H
#define HISTORY_H
#include <iostream>

#include "product.h"
#include "transaction.h"

using namespace std;

class Customer; //forward reference

class History : public Transaction
{

public: 
   History(); //default constructor
   History(const History&); //copy constructor
   virtual ~History(); //destructor
   
   //display history
   virtual bool setData(string, Product*, Customer*);
   //secondary display
   void displayAllHistory();

   //function called by factory to instantiate object
   virtual Transaction* create();
    
    //add transaction to array
   void addTransaction(Transaction newTrans);

    
private:
   // vector<Transaction>transactionHistory; //Transaction History
    Transaction* transactionHistory;
    
    //track array size
    int size;
    //track max size of transactions
    static const int maxSize = 10;
};
#endif
