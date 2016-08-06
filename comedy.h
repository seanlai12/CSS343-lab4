/*
 * Lab4
 * file comedy.h
 * Author:  Sean Lai and Sai Badey
 * Date:    June 6, 2014
 * Class:   CSS343 - Dr. Carol Zander
 *
 * Inherits Product. Contains Data setters and displays.
 * Contains movie objects with it's own genre
 * Contains overloaded class that applies to comedy, inheritting from Movie
 */

#ifndef Comedy_H
#define Comedy_H
#include <string>
#include "movie.h"

using namespace std;

class Comedy: public Movie //inherits movie
{
   
public:
   Comedy(); //constructor
   ~Comedy(); //destructor
   Comedy(const Comedy&);

   virtual void setData(istream&); //set movie data
   virtual void setDataTransactions(istream&);
   virtual Product* create(); //create new Comedy object
   virtual void displayHeader() const; //displays header
    
    
   virtual bool operator==(const Product&) const;
   virtual bool operator<(const Product&) const;
   virtual bool operator>(const Product&) const;

private:
   string genre; //genre set to comedy
};
#endif
