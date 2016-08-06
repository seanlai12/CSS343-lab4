/*
 * Lab4
 * file borrow.h
 * Author:  Sean Lai and Sai Badey
 * Date:    June 6, 2014
 * Class:   CSS343 - Dr. Carol Zander
 *
 * borrow.h inherits transaction. 
 * Contains data setters and display for borrow objects.
 */

#ifndef BORROW_H
#define BORROW_H
#include <iostream>
#include "product.h"
#include "transaction.h"

using namespace std;

//forward reference
class Customer;

//inherting transaction
class Borrow : public Transaction
{
public:
   Borrow(); //default constructor
   
   virtual ~Borrow(); //destructor

   virtual Transaction* create(); //Create Borrow object for factory

   //set data based off of transaction file information
   virtual bool setData(string, Product*, Customer*);
   
   virtual void display() const;
};
#endif
