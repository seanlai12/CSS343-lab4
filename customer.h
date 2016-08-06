/*
 * Lab4
 * file customer.h
 * Author:  Sean Lai and Sai Badey
 * Date:    June 6, 2014
 * Class:   CSS343 - Dr. Carol Zander
 *
 * customer.h has functions to track and process customer information. 
 * Stores customer name, id, and history
 *
 * ---------------------------------------------------------------------------
 *  Implementation and assumptions:
 *    -- Customers are equal based on ID
 * ---------------------------------------------------------------------------
 */
 
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "movie.h"
#include <iostream>
#include "transaction.h"
#include "history.h"

#include <string>

using namespace std;

class Customer 
{
public:
   Customer(); //default constructor
   Customer(const Customer&); //copy constructor
   Customer(istream&); //constructor based on instream
   void setData(istream&); //initialize constructor with instream
   
   ~Customer(); //destructor


   void displayAllHistory() const; //display function
   
   void addTransaction(Transaction); //update customer history
   
   int getCustomerID() const; //ID acessor
   string getFirstName() const; //name accessor
   string getLastName() const; //name accessor
   
   //equality operators (based on customer ID)
   virtual bool operator==(const Customer&) const;
   virtual bool operator!=(const Customer&) const;

private:
   string firstName;
   string lastName;
   int customerID;
   History* customerHistory;

};
#endif
