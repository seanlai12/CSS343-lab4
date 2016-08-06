/*
 * Lab4
 * file factory.cpp
 * Author:  Sean Lai and Sai Badey
 * Date:    June 6, 2014
 * Class:   CSS343 - Dr. Carol Zander
 *
 * This class contains all the functions that creates is used to create
 * new Transaction and Products and Mediatype chars.
 */

#include "factory.h"

//-----------------------------------------------------------------------------
// Factory
// default constructor
// creates objects for factory
Factory::Factory()
{
   initInventory();
   productInventory[2] = new Classic();
   productInventory[3] = new Drama();
   productInventory[5] = new Comedy();

   transactionInventory[1] = new Borrow();
   transactionInventory[7] = new History();
   transactionInventory[17] = new Return();

   mediaType[3] = "DVD";
}

//-----------------------------------------------------------------------------
// ~Factory
// destructor
// allocates memory
Factory::~Factory()
{
   for (int i = 0; i < MAX_LETTERS; i++)
   {
      if (productInventory[i] != NULL)
         delete productInventory[i];
         productInventory[i] = NULL;

      if (transactionInventory[i] != NULL)
         delete transactionInventory[i];
         transactionInventory[i] = NULL;
       
       if (mediaType[i] != "")
       {
            mediaType[i] = "";
       }
   }
    
    
}

//-----------------------------------------------------------------------------
// initInventory
// initialize the inventories and set them to NULL
void Factory::initInventory()
{
   for(int i = 0; i < MAX_LETTERS; i++)
   {
      productInventory[i] = NULL;
      transactionInventory[i] = NULL;
      mediaType[i] = "";
   }
}

//-----------------------------------------------------------------------------
// hash
// Takes char as parameter.
// hash the char alphabet and returns the subscript
int Factory::hash(char ch)
{
   return ch - 'A';
}

//-----------------------------------------------------------------------------
// getSubscript
// Takes char as parameter
// Hash the char and return the int subscript
int Factory::getSubscript(char ch)
{
   return hash(ch);
}

//-----------------------------------------------------------------------------
// getMediaType
// takes a char as its parameter
// returns the mediaType at the subscript
string Factory::getMediaType(char ch)
{
    return mediaType[hash(ch)];
}

//-----------------------------------------------------------------------------
// createMovie
// takes a char and istream reference as parameter
// checks if subcript is not NULL. Then creates a Product object to that
// subscript.
Product* Factory::createProduct(char ch, istream& infile)
{
   string temp;
   int subscript = hash(ch);
   if (productInventory[subscript] == NULL)
       {
          getline(infile, temp, '\n'); // Goes to next line
          return NULL;
       }
   else
       {
          return productInventory[subscript]->create(); //Create Movie Object
       }
}

//-----------------------------------------------------------------------------
// createTransaction
// takes a char and istream reference as parameter
// checks if subcript is not NULL. Then creates a Transaction object to that
// subscript.
Transaction* Factory::createTransaction(char ch, istream& infile)
{
   string temp;
   int subscript = hash(ch); 
   if (transactionInventory[subscript] == NULL)
   {
      getline(infile, temp, '\n'); // Goes to next line
      return NULL;
   }
   else
   {
      return transactionInventory[subscript]->create();
   }
}



