/*
 * Lab4
 * file drama.h
 * Author:  Sean Lai and Sai Badey
 * Date:    June 6, 2014
 * Class:   CSS343 - Dr. Carol Zander
 *
 * Inherits Product. Contains Data setters and displays.
 * Contains movie objects with it's own genre
 * Contains overloaded class that applies to drama, inheritting from Movie
 */

#ifndef Drama_H
#define Drama_H
#include <string>
#include "movie.h"

using namespace std;

class Drama: public Movie //inherits movie
{
public:
    Drama(); //default constructor
    ~Drama(); //destructor
    Drama(const Drama&); //copy constructor

    virtual void setData(istream&); //set movie data
    virtual void setDataTransactions(istream&); //set data determined by transaction
    virtual Product* create(); //create new Drama
    virtual void displayHeader() const; //display header for drama
    
    
    virtual bool operator==(const Product&) const;
    virtual bool operator<(const Product&) const;
    virtual bool operator>(const Product&) const;
private:
    string genre; //DRAMA
};
#endif
