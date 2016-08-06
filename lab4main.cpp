/*
 * Lab4
 * file lab4main.cpp
 * Author:  Sean Lai and Sai Badey
 * Date:    June 6, 2014
 * Class:   CSS343 - Dr. Carol Zander
 *
 * main class for lab4. HashTable assignment for a movie store.
 * Able to hash customer keys and returns the information such as movie 
 * borrowed, returned, and type of movie.
 */

#include "store.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

//-----------------------------------------------------------------------------
int main()
{
    Store business;
    // Runs the store accordingly to the data.
    business.runStore("data4movies.txt", "data4customers.txt",
                     "data4commands.txt");

	return 0;
}
