/*
 * Lab4
 * file classic.cpp
 * Author:  Sean Lai and Sai Badey
 * Date:    June 6, 2014
 * Class:   CSS343 - Dr. Carol Zander
 *
 * Inherits Product. Contains Data setters and displays.
 * Contains movie objects with it's own genre
 * Contains overloaded class that applies to classic, inheritting from Movie
 */

#include "classic.h"

//-----------------------------------------------------------------------------
// Classic
// Default constructor
Classic::Classic() :Movie()
{
    firstName = "";
    lastName = "";
    month = 0;
    genre = "Classic";
}

//-----------------------------------------------------------------------------
// ~Classic
// destructor
Classic::~Classic()
{
}

//-----------------------------------------------------------------------------
// setData
// takes an istream as parameter
// reads the file and sets the data to the movie accordingly to the format
void Classic::setData(istream& infile)
{
   infile.get();
   getline(infile, director, ',');
   
   infile.get();
   getline(infile, title, ',');
   
   infile.get();
   infile >> firstName >> lastName;
   infile >> month >> year;
}

//-----------------------------------------------------------------------------
// setDataTransactions
// Sets the data from file to transactions accordingly to the format
void Classic::setDataTransactions(istream& infile)
{
    //Format
   infile >> month;
   infile >> year;
   infile >> firstName;
   infile >> lastName;
}

//-----------------------------------------------------------------------------
// display
// displays information
void Classic::display() const
{
   cout
    << left << setw(23) << title.substr(0, 15)
    
    << setw(17) << director.substr(0, 15)
    
    <<  setw(5) << year << right << setw(2) << month <<  "   "
    
    << firstName << " " << lastName << endl;
}

//-----------------------------------------------------------------------------
// operator<
// takes a Product object as parameter
// return true if other object is larger, false if otherwise
bool Classic::operator<(const Product& other) const
{
   const Classic& otherClassic = static_cast<const Classic&>(other);

   if (year < otherClassic.year)
   {
      return true;
   }
   else if (year == otherClassic.year)
   {
      if (firstName < otherClassic.firstName)
      {
         return true;
      }
      else if (firstName == otherClassic.firstName)
      {
         return (lastName < otherClassic.lastName);
      }
      else
      {
         return false;
      }
   }
   else
   {
      return false;
   }
}

//-----------------------------------------------------------------------------
// operator>
// takes a Product object as parameter
// return true if other object is smaller, false if otherwise
bool Classic::operator>(const Product& other) const
{
    const Classic& otherClassic = static_cast<const Classic&>(other);
    
    if (year < otherClassic.year)
    {
        return false;
    }
    else if (year == otherClassic.year)
    {
        if (firstName < otherClassic.firstName)
        {
            return false;
        }
        else if (firstName == otherClassic.firstName)
        {
            return (lastName > otherClassic.lastName);
        }
        else
        {
            return true;
        }
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
bool Classic::operator==(const Product& other) const
{
   const Classic& otherClassic = static_cast<const Classic&>(other);

   return (year == otherClassic.year && month == otherClassic.month &&
      firstName == otherClassic.firstName &&
      lastName == otherClassic.lastName);
}

//-----------------------------------------------------------------------------
// create
// returns new Classic
Product* Classic::create()
{
   return new Classic();
}

//-----------------------------------------------------------------------------
// displayHeader
// display header for Classic
void Classic::displayHeader() const
{
    cout << genre << ":" << endl;
    cout << "  I  O" << " Title" << "                  Director" <<
    "         Year" << "  M" << "   F.Actor" << endl;
}
