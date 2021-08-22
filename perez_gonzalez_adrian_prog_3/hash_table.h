// Adrian Perez Gonzalez
// CS 163 Spring 2019
// 5/17/19 
// This is the .h file for program 3. 

#include <iostream>
#include <cstring> 
#include <cctype> 
#include <fstream>
#include <cstdlib>
#include <sys/time.h>
#include "movie.h"

// This is a globel constant. 
const int size = 500;

// This is a node for move data. 
struct m_node
{
	char * data;
	m_node * next;
};

// This is the struct for a node.
struct node
{
	Movie movie;
	node * next;
};

// This will be the class for the Hash Table. 
class Hash_Table
{
	public:
		Hash_Table(); // This is the constructor. 
		~Hash_Table(); // Ths is the destructor. 
		int function(char * character); // This function will return the key. 
		int add_movie(char * title, int n_characters, char * character, int n_actors, char * actor); // This functon will make the movie. 
		int add_character(char * look_for, char * og_character, char * to_add); // This function will allow the user to add a character  to a movie. 
		int add_actor(char * look_for, char * og_actor, char * to_add); // This function will allow the usr to adda an actor to a movie. 
		int search_character(char * character); // This function will allow the user to search for a character and display the movies. 
		int search_actor(char * actor); // This function will allow the user to search for a actor and display the movies.
		int remove_character(char * character); // This function will allow the user to search for a character and remove movies with it in it. 
		int copy_info(Movie matches[]); // This function will copy the matches that the user would want to see. 
		int display_character(char * character); // This function will display all the movies that have a certain character. 
		int display_all(); // This function will display everything in the hash table. 
		int from_file(); // This function will read in data from the text file and store it by character. 
		int from_file2(); // This function will read in data from the text file and store it by actor.
		int destroy_all(); // This function will deallocate all the information. 
	private:
		node ** hash_table; // This will be my hash table.	
		int key; // This is the key for the hash table. 
};
