/*
 * Lab4
 * file inventorymanager.cpp
 * Author:  Sean Lai and Sai Badey
 * Date:    June 6, 2014
 * Class:   CSS343 - Dr. Carol Zander
 *
 * inventorymanager.cpp has functions to initialize products, customers,
 * and process transactions.
 * Contains functions to display contents of the inventory.
 * Also prints the histories of customer transactions.
 */
 
 
#include "inventorymanager.h"

//-----------------------------------------------------------------------------
// Transaction
// default constructor
// initializes the data
InventoryManager::InventoryManager()
{
    businessName = "";
}

//-----------------------------------------------------------------------------
// Transaction
// destructor
// deletes the contents of the customer array
InventoryManager::~InventoryManager()
{
    Customer* temp = NULL;
    for (int i=0;i < CUSTOMER_MAX;i++)
    {
        if(customerArray[i] != *temp)
        delete &customerArray[i];
    }
}

//-----------------------------------------------------------------------------
// initializeCustomers
// Customer Initialization
// Takes in a file instream from which it gathers data for a new customer.
// After the customer is created, it is handed the file instream to fill in
// the missing data. Then, this customer is handed to the array to be inserted
// Deletion also occurs to ensure no memory is leaked.
void InventoryManager::initializeCustomers(string customerList)
{
    ifstream input(customerList);
   while(!input.eof())
   {
      Customer* newCustomer = new Customer();
      newCustomer->setData(input);

      if (input.eof())
      {
         delete newCustomer;
         newCustomer = NULL;
         break;
      }
      customerArray[newCustomer->getCustomerID()] = *newCustomer;
      delete newCustomer;
      newCustomer = NULL;
   }
}

//-----------------------------------------------------------------------------
// initializeProducts
// movie initializer
// Takes in a file instream from which it gathers data for a new movie.
// Uses factory to create a movie (if data is valid)
// After the movie is created, it is handed the file instream to fill in
// the missing data. Then, this movie is handed to the array to be inserted
// Deletion also occurs to ensure no memory is leaked.
void InventoryManager::initializeProducts(string moviesInStock)
{
    ifstream input1(moviesInStock);
    
    char movieCode = '\0';

   while(!input1.eof())
   {
      input1 >> movieCode;

      if (input1.eof())
      {
          break;
      }

      Product* moviePtr = factory.createProduct(movieCode, input1);

      if (moviePtr != NULL)
      {
         moviePtr->setData(input1);

         if(!movieTree[factory.getSubscript(movieCode)].
            insert(moviePtr, PRODUCT_MAX))
         {
            delete moviePtr;
         }
      }
      
      moviePtr = NULL;
      delete moviePtr;
   }
}



void InventoryManager::dumpLine(ifstream& input)
{
    string dump;
    getline(input, dump, '\n');
}

//-----------------------------------------------------------------------------
// processTransactions
// read the commands from a file which determine transactions and display.
// B- Borrow, R - Return, S - Dislay all categories of business, H - display
// customer data.
void InventoryManager::processTransactions(string transactionList)
{

    ifstream input(transactionList);
   int customerID = 0;
   bool found = false;
   string mediaType = "";
   char EOL = '\n'; //end of line
   Product* movieLocation = NULL;
   Customer* tempCustomer = NULL;
   Product *tempMoviePtr = NULL;
   char transactionType = '\0';
   char movieFormat = '\0';
   char genreType = '\0';

   while(!input.eof())
   {
      input >> transactionType;
      if (input.eof()) break;

      if(transactionType == 'S')
      {
         display();
         transactionType = ' ';
      }
      else if(input.get() == EOL)
      {
         transactionType = ' ';
      }
      else
      {
         Transaction* newTransactionPtr = 
            factory.createTransaction(transactionType, input); 

         if (newTransactionPtr != NULL)
         {
            input >> customerID;
            if (input.eof())
            {
                break;
            }

            if(customerFound(customerID))
            {
               tempCustomer = &customerArray[customerID];
               bool isHistory = newTransactionPtr->setData
                  (mediaType, movieLocation, tempCustomer);
                
               if(input.get() != EOL && isHistory)
               {
                  input >> genreType;
                  mediaType = factory.getMediaType(genreType);

                  if(mediaType != "")
                  {
                     input >> movieFormat;

                     tempMoviePtr = factory.createProduct(movieFormat, input);

                     if (tempMoviePtr != NULL)
                     {
                        tempMoviePtr->setDataTransactions(input);
                        found = movieTree[factory.getSubscript(movieFormat)]
                        .retrieve(*tempMoviePtr, movieLocation);

                        delete tempMoviePtr;
                        tempMoviePtr = NULL;

                        newTransactionPtr->setData(mediaType, 
                           movieLocation, tempCustomer);

                        if (found && mediaType != "") 
                        {
                           customerArray[customerID].addTransaction
                              (*newTransactionPtr);
                        }
                     }
                  }
               }
            }
         }
          dumpLine(input);
          if (newTransactionPtr != NULL)
             delete newTransactionPtr;
          newTransactionPtr = NULL;
          delete tempMoviePtr;
          tempMoviePtr = NULL;
      }
       
       found = false;
   customerID = 0;
   movieLocation = NULL;
   tempCustomer = NULL;
   tempMoviePtr = NULL;
   }  
} 

//-----------------------------------------------------------------------------
// display
// prints out the contents of the inventory
// Prints out the store name.
// Prints out the movies available
void InventoryManager::display() const
{
   if(businessName != "")
   {
      cout << "Inventory for " << businessName << endl << endl;
   }

   for (int i = 0; i < COMMANDS_MAX; i++)
   {
      if (!movieTree[i].isEmpty())
      {
         cout << movieTree[i];
      }
   }
}

//-----------------------------------------------------------------------------
// getBusinessName
// store name accessor
string InventoryManager::getBusinessName() const
{
   return businessName;
}

//-----------------------------------------------------------------------------
// customerFound
// A checker function to determine if customer truly exists
// Used in transaction processing to determine if transaction is valid or not.
// Attempts to locate customer in customer array. Returns true located.
bool InventoryManager::customerFound(int numberIn) const
{
	if(customerArray[numberIn].getCustomerID() == 0)
		return false;
	else
		return true;
}
