/*
 * Lab4
 * file classic.h
 * Author:  Sean Lai and Sai Badey
 * Date:    June 6, 2014
 * Class:   CSS343 - Dr. Carol Zander
 *
 * Inherits Product. Contains Data setters and displays.
 * Contains movie objects with it's own genre
 * Contains overloaded class that applies to classic, inheritting from Movie
 */

#ifndef Classic_H
#define Classic_H
#include <string>
#include "movie.h"

using namespace std;

class Classic: public Movie //inherits movie
{
public:
   Classic();
   ~Classic();
   Classic(const Classic&);

   virtual void setData(istream&); //set movie data
   virtual void setDataTransactions(istream&);
   virtual void display() const; //displays data

   virtual Product* create(); //create Classic object
   virtual void displayHeader() const; //display header
    
   virtual bool operator==(const Product&) const;
   virtual bool operator<(const Product&) const;
   virtual bool operator>(const Product&) const;
   

private:
   string firstName;
   string lastName;
   int month;
   string genre;
};
#endif
