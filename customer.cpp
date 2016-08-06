/*
 * Lab4
 * file customer.cpp
 * Author:  Sean Lai and Sai Badey
 * Date:    June 6, 2014
 * Class:   CSS343 - Dr. Carol Zander
 *
 * customer.cpp has functions to track and process customer information. 
 * Stores customer name, id, and history
 *
 * ---------------------------------------------------------------------------
 *  Implementation and assumptions:
 *    -- Customers are equal based on ID
 * ---------------------------------------------------------------------------
 */
 
#include "customer.h"

//-----------------------------------------------------------------------------
// Customer
// default constructor
// initializes the data
Customer::Customer()
{
    customerID = 0;
    firstName = "";
    lastName = "";
    customerHistory = new History();
}

//-----------------------------------------------------------------------------
// Customer
// copy constructor
// initializes the data based on other customer's data
Customer::Customer(const Customer& other)
{
   customerID = other.customerID;
   firstName = other.firstName;
   lastName = other.lastName;
}

//-----------------------------------------------------------------------------
// Customer
// constructor based on instream
// Calls set data to initialize customer information
Customer::Customer(istream& input)
{
   setData(input);
}


//-----------------------------------------------------------------------------
// ~Customer
// destructor
Customer::~Customer()
{
//    if(customerHistory != NULL)
//    delete customerHistory;
}

//-----------------------------------------------------------------------------
// setData
// Set customer's data based on instream
void Customer::setData(istream& input)
{
   input >> customerID;
   if (input.eof()) return; //error check
   input.get();
   input >> lastName;
   input.get();
   input >> firstName;
}
//-----------------------------------------------------------------------------
// getCustomerID
// Accessor for customer's ID
int Customer::getCustomerID() const
{
   return customerID;
}

//-----------------------------------------------------------------------------
// getFirstName
// Accessor for first name
string Customer::getFirstName() const
{
   return firstName;
}

//-----------------------------------------------------------------------------
// getLastName
// Accessor for last name
string Customer::getLastName() const
{
   return lastName;
}

//-----------------------------------------------------------------------------
// ==operator
// Check equality based on ID of customers
bool Customer::operator==(const Customer& other) const
{
   if(&other != NULL && this != NULL)
       return (customerID == other.customerID);
   else
       return false;
}

//-----------------------------------------------------------------------------
// !=operator
// Check inequality based on ID of customers
bool Customer::operator!=(const Customer& other) const
{
    if(&other != NULL && this != NULL)
        return (customerID != other.customerID);
    else
        return false;
}

//-----------------------------------------------------------------------------
// addTransaction
// Adds transaction to the array
// Calls upon the transaction function of history to update
void Customer::addTransaction(Transaction nextTransaction)
{
    customerHistory->addTransaction(nextTransaction);
}

//-----------------------------------------------------------------------------
// displayAllHistory
// Display function
// Prints customer name and ID
// Follows with customer's history (calls upon history's display function)
void Customer::displayAllHistory() const
{
    cout << customerID << " " << lastName << " "
    << firstName << endl;
    customerHistory->displayAllHistory();
}
