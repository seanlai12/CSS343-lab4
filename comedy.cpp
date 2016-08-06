/*
 * Lab4
 * file comedy.cpp
 * Author:  Sean Lai and Sai Badey
 * Date:    June 6, 2014
 * Class:   CSS343 - Dr. Carol Zander
 *
 * Inherits Product. Contains Data setters and displays.
 * Contains movie objects with it's own genre
 * Contains overloaded class that applies to comedy, inheritting from Movie
 */

#include "comedy.h"

//-----------------------------------------------------------------------------
// Comedy
// default constructor
Comedy::Comedy() :Movie()
{
    genre = "Comedy";
}

//-----------------------------------------------------------------------------
// Comedy
// destructor
Comedy::~Comedy()
{
}

//-----------------------------------------------------------------------------
// setData
// takes an istream as parameter
// reads the file and sets the data to the movie accordingly to the format
void Comedy::setData(istream& infile)
{
   infile.get();                      // get (and ignore) blank before director
   getline(infile, director, ',');     // input director
   
   infile.get();                       // get (and ignore) blank before title
   getline(infile, title, ',');        // input title
   
   infile.get();                       // get (and ignore) blank before year
   infile >>  year;                   // input year
}

//-----------------------------------------------------------------------------
// operator<
// takes a Product object as parameter
// return true if other object is larger, false if otherwise
bool Comedy::operator<(const Product& other) const
{
   const Comedy& otherComedy = static_cast<const Comedy&>(other);

   if (title < otherComedy.title)
   {
      return true;
   }
   else if (title == otherComedy.title)
   {
      return year < otherComedy.year;
   }
   else
   {
      return false;
   }
}

//-----------------------------------------------------------------------------
// operator>
// takes a Product object as parameter
// return true if other object is larger, false if otherwise
bool Comedy::operator>(const Product& other) const
{
    const Comedy& otherComedy = static_cast<const Comedy&>(other);
    
    if (title < otherComedy.title)
    {
        return false;
    }
    else if (title == otherComedy.title)
    {
        return year > otherComedy.year;
    }
    else
    {
        return true;
    }
}

//-----------------------------------------------------------------------------
// operator==
// takes a Product object as parameter
// return true if the two compared are equal
bool Comedy::operator==(const Product& other) const
{
   const Comedy& otherComedy = static_cast<const Comedy&>(other);
   return (title == otherComedy.title && year == otherComedy.year);
}

//-----------------------------------------------------------------------------
// create
// return a new Comedy
Product* Comedy::create()
{
   return new Comedy();
}


//-----------------------------------------------------------------------------
// setDataTransactions
// Sets the data from file to transactions accordingly to the format
void Comedy::setDataTransactions(istream& infile)
{
   infile.get();
   getline(infile, title, ',');
   infile >> year;
}

//-----------------------------------------------------------------------------
// displayHeader
// displays header for Comedy
void Comedy::displayHeader() const
{
   cout << genre << ":" << endl;
    cout << "  I  O" << " Title" << "                  Director" <<
    "         Year" << endl;
}
