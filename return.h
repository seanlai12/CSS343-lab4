/*
 * Lab4
 * file return.h
 * Author:  Sean Lai and Sai Badey
 * Date:    June 6, 2014
 * Class:   CSS343 - Dr. Carol Zander
 *
 * return.h inherits transaction. Contains data setters and display for
 * return objects.
 */

#ifndef RETURN_H
#define RETURN_H
#include "product.h"
#include "transaction.h"
using namespace std;

class Customer; //forward reference
class Return : public Transaction //inherits transaction
{
public:
    
   Return(); // default constructor
   Return(const Return&); // copy constructor
   virtual ~Return(); //destructor
    
   virtual bool setData(string, Product*, Customer*); //sets data
   virtual void display() const; //display mediatype and transaction type
   virtual Transaction* create(); //creates return
    
};
#endif
