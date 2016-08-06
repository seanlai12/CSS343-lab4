/*
 * Lab4
 * file movie.cpp
 * Author:  Sean Lai and Sai Badey
 * Date:    June 6, 2014
 * Class:   CSS343 - Dr. Carol Zander
 *
 * Inherits Product. Contains Data setters and displays for movies.
 * Contains Director, title and the year for movies.
 * Contains abstract functions for each of the movie categories.
 * Inherit from movie categories
 */

#include "movie.h"

//-----------------------------------------------------------------------------
// Movie
// default constructor
Movie::Movie() : Product()
{
    year = 0;
    title = "";
    director = "";
}
//-----------------------------------------------------------------------------
// ~Movie
// destructor
Movie::~Movie()
{
}

//-----------------------------------------------------------------------------
// setData
// takes an istream as parameter
// reads the file and sets the data to the movie accordingly to the format
void Movie::setData(istream& infile)
{

   infile.get();
   getline(infile, director, ',');
   
   infile.get();
   getline(infile, title, ',');
   
   infile.get();
   infile >>  year;

}

//-----------------------------------------------------------------------------
// getYear
// return year
int Movie::getYear()
{
    return year;
}


//-----------------------------------------------------------------------------
// getTitle
// return title
string Movie::getTitle()
{
    return title;
}

//-----------------------------------------------------------------------------
// getDirector
// return director
string Movie::getDirector()
{
   return director;
}

//-----------------------------------------------------------------------------
// getItem
// return item name
string Movie::getItem() const
{
    return title;
}

//-----------------------------------------------------------------------------
// displayHeader
// displays the header for the Movie when printing
void Movie::displayHeader() const
{
   cout << "Stock" << setw(15) << "Title" << setw(18) << "Director" <<
    setw(18) << "Year" << endl;
}

//-----------------------------------------------------------------------------
// display
// display the movie information
void Movie::display() const
{
   cout << left << setw(23) << title.substr(0, 15)
      << setw(17) << director.substr(0, 15)
      <<  setw(5) << year << endl;
}
