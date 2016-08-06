/*
 * Lab4
 * file product.h
 * Author:  Sean Lai and Sai Badey
 * Date:    June 6, 2014
 * Class:   CSS343 - Dr. Carol Zander
 *
 * product.cpp has functions to create and modify the objects. Contains functions
 * to modify stock count of the products.
 */

#include "product.h"

//---------------------------------------------------------------------------
// Product
// default constructor
// Initializes and sets stock sizes to 0
Product::Product()
{
    stock = 0;
    maxStock = 0;
}

//-----------------------------------------------------------------------------
// ~Product
// destructor
Product::~Product()
{}

//-----------------------------------------------------------------------------
// decrementStock
// take one off the stock
void Product::decrementStock()
{
	if (stock > 0)
    {
        stock--;
    }
}

//-----------------------------------------------------------------------------
// incrementStock
// add one to the stock
void Product::incrementStock()
{
	if (stock < maxStock)
    {
        stock++;
    }
}

//-----------------------------------------------------------------------------
// getStock
// returns the stock
int Product::getStock()
{
   return stock;
}

//-----------------------------------------------------------------------------
// getStockBorrowed
// returns the # of stock borrowed
int Product::getStockBorrowed()
{
   return maxStock - stock;
}

//-----------------------------------------------------------------------------
// setMaxStock
// sets the max stock amount
void Product::setMaxStock(const int max)
{
   maxStock = max;

   if(stock <= 0) //check if copies have been previously set
      stock = maxStock;
}
