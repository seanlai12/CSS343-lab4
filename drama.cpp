/*
 * Lab4
 * file drama.cpp
 * Author:  Sean Lai and Sai Badey
 * Date:    June 6, 2014
 * Class:   CSS343 - Dr. Carol Zander
 *
 * Inherits Product. Contains Data setters and displays.
 * Contains movie objects with it's own genre
 * Contains overloaded class that applies to drama, inheritting from Movie
 */

#include "drama.h"

//-----------------------------------------------------------------------------
// Drama
// Default constructor
Drama::Drama() :Movie()
{
    genre = "Drama";
}

//-----------------------------------------------------------------------------
// ~Drama
// destructor
Drama::~Drama()
{
}

//-----------------------------------------------------------------------------
// setData
// takes an istream as parameter
// reads the file and sets the data to the movie accordingly to the format
void Drama::setData(istream& infile)
{
    infile.get();
    getline(infile, director, ',');
   
    infile.get();
    getline(infile, title, ',');
   
    infile.get();
    infile >>  year;
}

//-----------------------------------------------------------------------------
// setDataTransactions
// Sets the data from file to transactions accordingly to the format
void Drama::setDataTransactions(istream& infile)
{
    infile.get();
    getline(infile, director, ',');
    infile.get();
    getline(infile, title, ',');
}

//-----------------------------------------------------------------------------
// operator<
// takes a Product object as parameter
// return true if other object is larger, false if otherwise
bool Drama::operator<(const Product& other) const
{
    const Drama& otherDrama = static_cast<const Drama&>(other);

    if (director < otherDrama.director)
    {
       return true;
    }
    else if (director == otherDrama.director)
    {
       return (title < otherDrama.title);
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
bool Drama::operator>(const Product& other) const
{
    const Drama& otherDrama = static_cast<const Drama&>(other);
    
    if (director < otherDrama.director)
    {
        return false;
    }
    else if (director == otherDrama.director)
    {
        return (title > otherDrama.title);
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
bool Drama::operator==(const Product& other) const
{
    const Drama& otherDrama = static_cast<const Drama&>(other);

    return (title == otherDrama.title && director == otherDrama.director);
}

//-----------------------------------------------------------------------------
// create
// return a new Drama object
Product* Drama::create()
{
    return new Drama();
}

//-----------------------------------------------------------------------------
// displayHeader
// display header for Drama with infos
void Drama::displayHeader() const
{
    cout << genre << ":" << endl;
    cout << "  I  O" << " Title" << "                  Director" <<
    "         Year" << endl;
}

