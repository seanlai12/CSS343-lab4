One store of a local chain, "Many Overzealous Videos Ignite & Entertain" (MOVIE), wishes to automate the process of tracking movies.  This task is simplified by the fact that MOVIE has only three types of movies/videos (only DVD media currently) — comedy, drama, and classics — each sorted differently as described below.
 
MOVIE wishes to be able to allow customers to borrow and return items, and to display the contents of the business (all three categories) and its customers' history of rentals at any time. For the business contents, movies are displayed by category, sorted within the category. Output must be formatted for easy reading with data in columns. For the customer history, movies that have been or are borrowed and movies returned are displayed in the order of the occurrence.
 
Design and write a program that will
–  Initialize the contents of each of the three categories of videos
–  Process an arbitrary sequence of borrows, returns, business displays, and customer history
 
Notes
– Director, title, and date are stored for each movie.  Classics include the major actor. The business stores the
·         comedy movies sorted by title, then date
·         dramas are sorted by director, then title
·         classics are sorted by date, then famous actor
Assume each piece of data is uniquely identified by its sorting criteria (other information not used when sorting or retrieving).
 
A data file is used for initializing the business.  One line in the file contains information on one item.  To facilitate processing, comedy movies are marked with an 'F' (for funny), drama movies are marked with a 'D', and classics are marked with a 'C'.  The first character of each line indicates this movie type.  After this char key is director (comma terminated), title (comma terminated), additional information (e.g., actor, always formatted as two strings, first name and last name), and then the date (ints, only year except for classics 
which have month and year).  For example,
 
        F Gore Verbinski, Pirates of the Caribbean, 2003
        D Steven Spielberg, Schindler's List, 1993
        C George Cukor, Holiday, Katherine Hepburn 9 1938
        C George Cukor, Holiday, Cary Grant 9 1938
        Z Hal Ashby, Harold and Maude, Ruth Gordon 2 1971
        D Phillippe De Broca, King of Hearts, 1967
 
You can assume the format is correct, but codes may be invalid; e.g., the 'Z' code says the line of data is not valid.  The chain owns 10 copies of DVDs for each movie in the datafile.  (Note that for this data, assume there are 20 copies of "Holiday" by George Cukor.) While the data for an item is minimal, do not assume (i.e., design and implement) that is the case. Design and implement as though there may be much more data for an item. Everything, including the output, could vary greatly if there was more data. Your design and implementation should work for any amount of information. Do not store data in long strings; everything is an object.
 
–  MOVIE customer information will also be found in a data file, one line per customer.  Sample data includes a unique 4-digit ID number, last name, first name.  A blank separates fields.  For example:
        1234 Mouse Mickey
You can assume correctly formatted data. The assumption about more information applies also to a customer.
 
–  While normally you would expect a program like this to be interactive, to test your program, another data file is used.  It contains an arbitrary sequence of commands, one per line.  The first char of each line ('B' for  borrow, 'R' for return, 'H' to display a customer’s history) indicates the desired action for a customer, or 'S' for displaying the three categories of the business (by category, sorted within the category).  After this char key is a blank, the customer ID, type of media (currently only 'D' for DVD), and movie data based on the sorting criteria above.  A comma is after director and/or title (commas terminate in the same place as in the movie datafile described previously).  For example:
        B 1234 D C 9 1938 Katherine Hepburn
        B 1234 D F Pirates of the Caribbean, 2003
        R 1234 D C 9 1938 Katherine Hepburn
        B 1234 D D Steven Spielberg, Schindler's List,
        S
        H 1234
        X 1234 Z C 9 1938 Katherine Hepburn
        B 1234 D Y 2 1971 Ruth Gordon
        B 9999 D F Pirates of the Caribbean, 2003
        B 1234 D C 2 1975 Blah Blah
 
The data is correctly formatted, but you must handle an invalid action code, an incorrect customer ID (not found), invalid media code, and invalid movie (not found).  For example, the 'X' is an invalid action code; 9999 is not a valid customer ID (not a data item from the customer data file); ‘Z’ is an invalid media type; the 'Y' is an invalid movie code; and there is no classic movie in month 2 of 1975 with a "Blah Blah" actor. For bad data, get (read from the data file) and ignore the rest of the line of data.
 
–  You must handle errors, any invalid data as stated above: incorrect codes, invalid movie or customer, and incorrect commands (a return command when a movie was not borrowed).  Display error messages, but do NOT display anything when a successful command is performed.
 
–  When printing, conserve paper.  Use one line per item (some information may be truncated).  Displays are to be nicely formatted, in easily read columns, printed in portrait mode.  For a show of business contents, show each movie category (all data for that type) with how many DVDs are borrowed and how many remain.  For a display of customer history, show a list of the customer (whether an item is currently borrowed or not). Show a list of every DVD transaction in the order they occur and specify whether borrowed or returned.
 
–  A requirement of this assignment is that you use at least one hash table.  Note that in the design you do not include details of hash functions and hash tables.  To remind you about hashing: A hash function maps a value to an element in an array, the hash table.  If it is a unique mapping, there is no need for searching so an insert or look-up is a O(1) operation. 
 
–  A requirement of this assignment is to use inheritance. In general, avoid templates for your primary data structures.  If you find you’re using templates a lot, run it by me, as this assignment is designed for you to practice using inheritance. There are no other specific requirements for this assignment, but as always it should be well designed (not violate the basic design principles), easily extensible, efficiently coded, well documented, etc.
 
–  You must design beyond the specifications (although you will only implement as specified above). Design so that the answer to all these questions is yes (maintaining good design principles).  Could you easily add more DVDs to your design?  Can you easily add other categories of movies? Could you easily add other kinds of formats, for example, blu-ray?  Could you easily add new categories of media to your design, for example, music?  Could you expand to borrow other kinds of items, for example, DVD players?  Could you easily add new operations to your design, for example, buy? Could you incorporate time, for example, a due date for borrowed items?  Could you easily add an additional store, or handle a chain of stores? And so on.
 
– For your design document, turn in (in this order):
    1. UML class diagram (only class names must be included in diagram)
    2. Picture of data structures (visual of memory organization, the actual memory of your primary data structures)
    3. Explanation of how classes interact  (Show the program flow -- a sequence diagram -- the methods invoked, for standard Use Cases such as insert or borrow. )
      4. The main:  What objects do you have?  It is usually very short as all the actual work is done in class functions.
    5. The .h files, with clear/complete descriptions of all base/derived classes.  (Since this is a design, you might not include all, or any, parameters in methods.  Or they might change.  That's okay, but overall the design is to be sound. You do not need to include .h files of classes you will not implement, of the extensions beyond the assignment specifications, but you must include a description of those classes.) Please order the files as a hierarchy.
