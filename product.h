/*
 * Lab4
 * file product.h
 * Author:  Sean Lai and Sai Badey
 * Date:    June 6, 2014
 * Class:   CSS343 - Dr. Carol Zander
 *
 * product.h has functions to create and modify the objects. Contains functions
 * to modify stock count of the products.
 *
 * ---------------------------------------------------------------------------
 *  Implementation and assumptions:
 *    -- This is a abstract base class. Functions must be overwritten
 * ---------------------------------------------------------------------------
 */

#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>
using namespace std;

class Product
{
public:
	Product(); //default constructor
    virtual ~Product(); //virtual destructor
    
    virtual void setData(istream&) = 0; //pure virtual setData for Products
    virtual void setDataTransactions(istream&) = 0; //pure virtual setData for transactions
    virtual void display() const = 0; //display the products
    virtual void displayHeader() const= 0; //displays header
    virtual string getItem() const = 0; //item getter
    
    void setMaxStock(const int); //sets the max stock
    void incrementStock(); // stock ++
    void decrementStock(); // stock --
    
    int getStock(); // get the current stock
    int getStockBorrowed(); //get the # of stock being borrowed

    virtual bool operator==(const Product&) const = 0;
    virtual bool operator<(const Product&) const = 0;
    virtual bool operator>(const Product&) const = 0;
    virtual Product* create() = 0; //creates a product

private:
	int maxStock; // max stock size allowed
    int stock; // current stock size
};

#endif
