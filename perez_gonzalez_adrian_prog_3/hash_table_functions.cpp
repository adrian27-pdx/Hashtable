// Adrian Perez Gonzalez
// CS 163 Spring 2019
// 5/17/19 
// This file will hold all the functions for my Hash Table. 

#include "hash_table.h" 

using namespace std; 

ifstream file_in;
ofstream file_out;

// This is the constructor. 
Hash_Table::Hash_Table() 
{
	hash_table = new node * [size]; // Create the hash table
	key = 0; // Set the key to 0. 

	int count = 0; // Make a counter 

	while(count < size) // Set the hash table to NULL.
	{
		hash_table[count] = NULL; // Set the pointer to NULL. 
		count++; // Increase the counter by one. 
	}
}

// This is the destructor.
Hash_Table::~Hash_Table()
{
	destroy_all(); // Call the function to deallocate everything. 
	hash_table = NULL; // Set the pointer to NULL. 
}
jkkj
// This fucntion will return the key to the user. 
int Hash_Table::function(char * character)
{
	key = 1; // Reset the key to 1. 

	int count = 0; // Set the counter to 0. 

	while(character[count] != '\0') 
	{
		key = key * character[count]; // Multiply the key by the asci value of the character. 
		count++; // Add one to the counter. 
	}

	key = key % size; // Mod key by the size of the array. 

	if(key < 0) // Check to see that key is not negative. 
		key = key * -1; // Make key positive if it is negative. 
	return 1;
}

//This function will add a movie to the hash table. 
int Hash_Table::add_movie(char * title, int n_characters, char * character, int n_actors, char * actor)
{
	if(!hash_table[key]) // Check to see if there is a somthing in that index already. 
	{
		hash_table[key] = new node; // Allocate memory for a new node. 
		hash_table[key]->movie.create(title, n_characters, character, n_actors, actor); // Call the funciton to store the data. 
		hash_table[key]->next = NULL; // Set the next pointer to NULL. 
	}

	else
	{
		node * temp = hash_table[key]; // Have temp hold onto the chain. 
		hash_table[key] = new node; // Allocate memory for a new node. 
		hash_table[key]->movie.create(title, n_characters, character, n_actors, actor); // Call the function to store the data. 
		hash_table[key]->next = temp; // Reconnect the chain. 
	}

	return 1;
}

// This function will allow the user to add a character to a movie.
int Hash_Table::add_character(char * look_for, char * og_character, char * to_add)
{
	if(!hash_table)
		return 0; // Return 0 to the client to report failure. 
	
	node * current = hash_table[key]; // Set current to the start of the chain. 
	
	while(current)
	{
		if(current->movie.check_title(look_for)) // Check to see if its the movie i am looking for. 
		{
			current->movie.add_character(to_add); // Call the function to all a character. 
			return 1;
		}
		current = current->next; // Move current to the next node. 
	}
	
	return 0; // Return 0 to the client to report failure. 
}

// This function will allow ther user to adda a actor to a movie. 
int Hash_Table::add_actor(char * look_for, char * og_actor, char * to_add)
{
	if(!hash_table)
		return 0; // Return 0 to the client to report failure. 
	
	node * current = hash_table[key]; // Set current to the start of the chian. 
	
	while(current)
	{
		if(current->movie.check_title(look_for)) // Check to see if its the movie the user is looking for. 
		{
			current->movie.add_actor(to_add); // Call the function to add a actor. 
			return 1; // Return 1 to the client to report succes. 
		}
		current = current->next; // Move current to the next node. 
	}
	
	return 0; // Return 0 to the client to report failure. 
}

// This function will allow the user to search for a character and display the movie that match. 
int Hash_Table::search_character(char * character)
{
	if(!hash_table) // Check if there is a hash table to remove from. 
		return 0; // Return 0 to report failure to the client. 

	node * current = hash_table[key]; // Set current to the correct index. 
		
	while(current)
	{
		current->movie.display(); // Call the display function for the class. 
		current = current->next; // Move current to the next node. 
	}
	return 1;
}

// This function will allow the user to search for actro and display the movies that match. 
int Hash_Table::search_actor(char * actor)
{
	if(!hash_table) // Check if there is a hash table to remove from. 
		return 0; // Return 0 to report failure to the client. 

	node * current = hash_table[key]; // Set current to the correct index. 
		
	while(current)
	{
		current->movie.display(); // Call the display function for the class. 
		current = current->next; // Move current to the next node. 
	}
	return 1;
}

// This function will allow the user to search for a character and remove movies with it in the movie. j
int Hash_Table::remove_character(char * character)
{
	if(!hash_table) // See if there is a hash table to remove from. 
		return 0; // Return 0 to the client to report failure. 

	node * current = hash_table[key]; // Set current to the start of the chain. 
	node * temp = current; // Set temp to current.
	
	while(current)
	{
		current = current->next; // Move current to the next node. 
		temp->movie.destroy(); // Deallocate the memory in the class. 
		delete temp; // Deallocate the node itself. 
		temp = current; // Move temp to the next node. 
	}
	
	hash_table[key] = NULL; // Reset the index to null. 

	return 1; // Return 1 to report success to the client.
}

// This function will display all the movies that have a certain character. 
int Hash_Table::display_character(char * character)
{
	if(!hash_table) // Check if there is a hash table to remove from. 
		return 0; // Return 0 to report failure to the client. 

	node * current = hash_table[key]; // Set current to the correct index. 
		
	while(current)
	{
		current->movie.display(); // Call the display function for the class. 
		current = current->next; // Move current to the next node. 
	}
	return 1;
}

// This function will display everything in the hash table. 
int Hash_Table::display_all()
{
	if(!hash_table) // Check to see if there is a hash table. 
		return 0; 

	int count = 0; // This is a counter. 
	node * current = NULL; // This is a pointer. 
	
	while(count < size)
	{
		if(!hash_table[count])
			count++; // Add one to the counter. 
		else
		{
			current = hash_table[count]; // Set current to the beginning of the chain. 

			while(current)
			{
				current->movie.display(); // Display the data in the class. 
				cout<< endl; // Display a new line. 
				current = current->next; // Move current to the next node.
			}
			count++; // Add one to the counter. 
		}
	} 	
	return 1; // Return 1 to the client to report success. 
}

// This function will read in and store data from a file by character. 
int Hash_Table::from_file()
{
	char title[size],characters[size],actors[size];
	int n_characters, n_actors; 

	file_in.open("data.txt"); // Opens the file.
	while(!file_in) // Check to see if the file is open. 
	{
		cout<< "Error in opening the file!" << endl
		    << "Trying again!" << endl;
		file_in.open("data.txt");
	}
	file_in.get(title,size,':'); // Read in the title of the movie again. 
	file_in.ignore(); // Clear one item from the input stream. 
	while(file_in && !file_in.eof()) // This function reads in data from the text file. 
	{
		file_in>> n_characters; // Read in the number of characters from the text file. 
		file_in.ignore(); // Clear on item in the input stream.
		file_in.get(characters,size,':'); // Read in the characters in the movie. 
		file_in.ignore(); // Clear one item from the input stream. 
		file_in>> n_actors; // Read in the number of actors. 
		file_in.ignore(); // Clear on item from the input stream. 
		file_in.get(actors,size,'\n'); // Read in the acrors in the movie. 
		file_in.ignore(); // Clear one item from the input stream. 

		function(characters); // Set the key to the correct value. 
		add_movie(title,n_characters,characters,n_actors,actors); // Call the function to add it. 
		
		file_in.get(title,size,':'); //Try to read in from the file again. 
		file_in.ignore(); // Clear one item from the input stream. 
	}
	file_in.close(); // Close the connecton to the text file. 
	
	return 1;
}

// This function will sore data from a file by actor. 
int Hash_Table::from_file2()
{
	char title[size],characters[size],actors[size];
	int n_characters, n_actors; 

	file_in.open("data.txt"); // Opens the file.
	while(!file_in) // Check to see if the file is open. 
	{
		cout<< "Error in opening the file!" << endl
		    << "Trying again!" << endl;
		file_in.open("data.txt");
	}
	file_in.get(title,size,':'); // Read in the title of the movie again. 
	file_in.ignore(); // Clear one item from the input stream. 
	while(file_in && !file_in.eof()) // This function reads in data from the text file. 
	{
		file_in>> n_characters; // Read in the number of characters from the text file. 
		file_in.ignore(); // Clear on item in the input stream.
		file_in.get(characters,size,':'); // Read in the characters in the movie. 
		file_in.ignore(); // Clear one item from the input stream. 
		file_in>> n_actors; // Read in the number of actors. 
		file_in.ignore(); // Clear on item from the input stream. 
		file_in.get(actors,size,'\n'); // Read in the acrors in the movie. 
		file_in.ignore(); // Clear one item from the input stream. 

		function(actors);
		add_movie(title,n_characters,characters,n_actors,actors); // Call the function to add it. 
		
		file_in.get(title,size,':'); //Try to read in from the file again. 
		file_in.ignore(); // Clear one item from the input stream. 
	}
	file_in.close(); // Close the connecton to the text file. 
	
	return 1;
}

// This function will deallocate all the memory. 
int Hash_Table::destroy_all()
{
	if(!hash_table) // See if there is a hash table to remove from. 
		return 0; // Return 0 to the client to report failure. 

	int count = 0; // Set a counter to 0. 
	node * current = NULL; // Set current to the start of the chain. 
	node * temp = NULL; // Set temp to current.
	
	while(count < size)
	{
		if(!hash_table[count]) // See if there is anything to deallocate. 
			count++; // Add one to the counter. 
		else
		{
			current = hash_table[count]; // Set current to the start of the chain. 
			temp = current; // Set current to current. 

			while(current)
			{
				current = current->next; // Move current to the next node. 
				temp->movie.destroy(); // Deallocate the memory in the class. 
				delete temp; // Deallocate the node itself. 
				temp = current; // Move temp to the next node. 
			}
			count++; // Add one to the count variable. 
		}
	}
	//delete [] hash_table; // Deallocate the memory for the hash table. 
	return 1; // Return 1 to report success to the client.
}
