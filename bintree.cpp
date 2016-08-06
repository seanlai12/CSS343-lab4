/*
 * Lab4
 * file bintree.cpp
 * Author:  Sean Lai and Sai Badey
 * Date:    June 6, 2014
 * Class:   CSS343 - Dr. Carol Zander
 *
 * bintree.cpp has functions to store products inside
 * Primary purpose is to serve as a container
 *
 */
 
#include "bintree.h"
#include <iomanip>

//-----------------------------------------------------------------------------
// BinTree
// default constructor
// initializes the data
BinTree::BinTree()
{ 
   root = NULL;
}

//-----------------------------------------------------------------------------
// ~BinTree
// default destructor
// Calls makeEmpty() to help delete contents of the tree.
BinTree::~BinTree()
{
   if (!isEmpty())
      makeEmpty(); 
}

//-----------------------------------------------------------------------------
// isEmpty
// checks to see if tree contains anything
// Helper function mostly.
bool BinTree::isEmpty() const
{
   return (root == NULL);
}

//-----------------------------------------------------------------------------
// makeEmpty()
// Helper function to destructor
// Calls makeEmptyHelper() to help delete contents of the tree.
void BinTree::makeEmpty()
{
   makeEmptyHelper(root);
}

//-----------------------------------------------------------------------------
// makeEmptyHelper
// helper function that destroy tree postOrder
// Recursively calls itself on its left and right children
void BinTree::makeEmptyHelper(Node *& subTree)
{
   if (subTree != NULL)
   {  
      makeEmptyHelper(subTree->leftChildPtr);
      makeEmptyHelper(subTree->rightChildPtr);

		delete subTree->theMovie;
      subTree->theMovie = NULL;
		delete subTree;
      subTree = NULL;
   }
}

//-----------------------------------------------------------------------------
// insert
// Function to insert new products
// Standard insert function which inserts at head if the tree is empty.
// Otherwise, inserts at left or right subtree
bool BinTree::insert(Product* moviePtr,const int movieCount) 
{

   //creates a new node for the tree based on incoming product
   Node* ptr = new Node;
   ptr->theMovie = moviePtr;
   ptr->theMovie->setMaxStock(movieCount);
   
   moviePtr = NULL;
   ptr->leftChildPtr = NULL;
   ptr->rightChildPtr = NULL;

   if (isEmpty()) //case for empty tree
   {
      root = ptr;
   }
   else //case for nonempty tree
   {
      Node* current = root;
      bool inserted = false;


      while (!inserted) 
      {
         //case for inserting right
         if (*ptr->theMovie > *current->theMovie)
         {
            if (current->rightChildPtr == NULL) //insert right
            {             
               current->rightChildPtr = ptr;
               return true;
            }
            else                                //step right
            {
               current = current->rightChildPtr;
            }
         }
         
         //case for inserting left
         else if (*ptr->theMovie < *current->theMovie) 
         {
            if (current->leftChildPtr == NULL)  //insert left
            {            
               current->leftChildPtr = ptr;
               return true;
            }
            else
               current = current->leftChildPtr; //step left
         }
         
         //case for already inserted
         else 
         {
            delete ptr; //Handle duplicate properly
            ptr = NULL;
            return false;
         }
      }
   }
   return true;
}


//-----------------------------------------------------------------------------
// retrieve
// Function to extract product
// Standard retrieve function which contains a leash and product to be found
// Uses helper function to search tree to find the product
bool BinTree::retrieve(const Product& target, Product*& leash) const
{
   retrieveHelper(root, target, leash); //call recursive helper

   if (leash != NULL)
   {
      return true;
   }
   else
   {
      return false;
   }
}

//-----------------------------------------------------------------------------
// retrieveHelper
// Helper function which searches tree recursively pre-order
void BinTree::retrieveHelper(Node* current, 
                             const Product& target, 
                             Product*& leash) const
{

   if (current == NULL)
      leash = NULL;

   else if (target == *current->theMovie) //Found case
   {
      leash = current->theMovie;
   }
   else if(target < *current->theMovie)   //Step Left
   {
      retrieveHelper(current->leftChildPtr, target, leash);
   }
   else                                    //Step Right
   {
      retrieveHelper(current->rightChildPtr, target, leash);
   }
}

//-----------------------------------------------------------------------------
// <<operator overload
// Display function which relies of inorderDisplay
ostream& operator<<(ostream& output, const BinTree& tree)
{
   tree.inOrderDisplay(tree.root);
   return output;
}

//-----------------------------------------------------------------------------
// inOrderDisplay
// Helper function which recurses tree inOrder to display contents
void BinTree::inOrderDisplay(Node *current) const
{
   if (current == root)
   {
      current->theMovie->displayHeader();
   }

   if (current != NULL)
   {
      inOrderDisplay(current->leftChildPtr); //recurse left
      
      cout << right << setw(3) 
           << current->theMovie->getStock() << setw(3) 
           << current->theMovie->getStockBorrowed() << " ";
      
      current->theMovie->display();
      
      inOrderDisplay(current->rightChildPtr); //recurse right
   }
}
