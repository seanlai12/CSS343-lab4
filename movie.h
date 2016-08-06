/*
 * Lab4
 * file movie.h
 * Author:  Sean Lai and Sai Badey
 * Date:    June 6, 2014
 * Class:   CSS343 - Dr. Carol Zander
 *
 * Inherits Product. Contains Data setters and displays for movies.
 * Contains Director, title and the year for movies.
 * Contains abstract functions for each of the movie categories.
 * Inherit from movie categories
 *
 * ---------------------------------------------------------------------------
 *  Implementation and assumptions:
 *    -- Abstract class for Drama, comedy and classic
 * ---------------------------------------------------------------------------
 */

#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>
#include <iomanip>
#include <string>
#include "product.h"

using namespace std;

class Movie: public Product
{
public:

    Movie();
    Movie(const Movie&);
    virtual ~Movie();

    virtual void setData(istream&); //set movie data
    virtual void setDataTransactions(istream&) = 0;
    virtual void display() const; //display movie data
    virtual void displayHeader() const; //display header for inherited classes
    //equality operators must be overriden to determine sort order
    virtual Product* create() = 0; //create new movie object
    virtual string getItem() const;
    
    
    virtual bool operator==(const Product&) const = 0;
    virtual bool operator<(const Product&) const = 0;
    
    //get methods for data that all movies have
    string getDirector();
    string getTitle();
    int getYear();
protected:
   //data that all movies have
    string director;
    string title;
    int year;
};

#endif
