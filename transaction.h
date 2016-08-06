/*
 * Lab4
 * file transaction.h
 * Author:  Sean Lai and Sai Badey
 * Date:    June 6, 2014
 * Class:   CSS343 - Dr. Carol Zander
 *
 * transaction.h has functions to create and modify the objects. 
 * Contains functions to modify stock count of the transcations.
 * Stores type of transaction, media type, and item.
 *
 * ---------------------------------------------------------------------------
 *  Implementation and assumptions:
 *    -- Used as a base abstract class for borrow and return.
 * ---------------------------------------------------------------------------
 */

#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <iostream>
#include "movie.h"
using namespace std;


class Customer; //forward reference
class Transaction
{

public:
   
    Transaction(); //default constructor
    Transaction(const Transaction&); //copys a transaction
    
    virtual ~Transaction(); //virtual destructor
    virtual bool setData(string, Product*, Customer*); //sets the data
    virtual void display() const; //display data
    virtual Transaction* create(); //create new transaction

    string getMediaTye(); //Get type of media
    string getTransType(); //default transType is transaction
    Product* getItem() const; //Pointer to Product

protected:
    string transactionType;
    string mediaType;
    Product* storeItem;
};
#endif
