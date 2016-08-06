/*
 * Lab4
 * file bintree.h
 * Author:  Sean Lai and Sai Badey
 * Date:    June 6, 2014
 * Class:   CSS343 - Dr. Carol Zander
 *
 * bintree.h has functions to store products inside
 * Primary purpose is to serve as a container
 * ---------------------------------------------------------------------------
 *  Implementation and assumptions:
 *    -- 
 * ---------------------------------------------------------------------------
 */
 
#ifndef BINTREE_H
#define BINTREE_H
#include "product.h"

class BinTree 
{ 
   //overloaded for displaying contents of the tree
   friend ostream& operator<<(ostream&, const BinTree&); 
   struct Node; //forward reference

public:
   BinTree(); //constructor
   
   ~BinTree(); //destructor
   void makeEmpty(); //deletes contents of the tree
   bool isEmpty() const; //returns true if tree is empty
   
   
   bool insert(Product*,const int); //input a new product

   //function to grab product from tree
   bool retrieve(const Product&, Product*&) const;
   

private:

   struct Node
   {
      Product* theMovie;
      Node* leftChildPtr;
      Node* rightChildPtr;
   };
   Node *root;
   
    //helper function to help grab object
   void retrieveHelper(Node*, const Product&,
                        Product*&) const;
   bool isEqual(Node*, Node*) const;   //node equality checker

   //function for inorder traversal & displaying
   void inOrderDisplay(Node*) const;
   //postorder function to clear tree, helper function to makeEmpty()
   void makeEmptyHelper(Node*&);
};
#endif
