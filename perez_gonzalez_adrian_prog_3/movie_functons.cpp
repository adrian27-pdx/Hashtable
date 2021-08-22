// Adrian Perez Gonzalez
// CS 163 Spring 2019
// 5/17/19 
// This will be the main for program 3. 

#include "hash_table.h" 

using namespace std; 

// This is the constructor. 
Movie::Movie()
{
	title =  NULL; // Set the pointer to NULL. 
	num_characters = 0; // Set the integer to 0. 
	characters = NULL; // Set the pointer to NULL. 
	num_actors = 0; // Set the integer to 0. 
	actors = NULL; // Set the pointer to NULL. 
}

// This is the destructor. 
Movie::~Movie()
{
	destroy(); // Call the function to deallocate everything. 
	title =  NULL; // Set the pointer to NULL. 
	num_characters = 0; // Set the integer to 0. 
	characters = NULL; // Set the pointer to NULL. 
	num_actors = 0; // Set the integer to 0. 
	actors = NULL; // Set the pointer to NULL. 
}

// This function will store the data in the class. 
int Movie::create(char * film, int n_characters, char * character, int n_actors, char * actor)
{
	title = new char [strlen(film)+1]; // Allocate memory for the movies title. 
	strcpy(title,film); // Copy the data for the title. 

	num_characters = n_characters; // Update the number of characters. 

	characters = new m_node; // Make a new node. 
	characters->data = new char [strlen(character)+1]; // Allocate memory for the character. 
	strcpy(characters->data,character); // Copy the data into the node. 
	characters->next = NULL; // Set the next pointer to NULL. 

	num_actors = n_actors; // Update the number of actors in the movie. 

	actors = new m_node; // Make a new node. 
	actors->data = new char [strlen(actor)+1]; // Allocate memory for the actor. 
	strcpy(actors->data,actor); // Copy the into the node. 
	actors->next=NULL; // Set the next pointer to NULL. 
	
	return 1; // Report success to the client. 
}

// This function will add a character. 
int Movie::add_character(char * to_add)
{
	if(!characters) 
		return 0; // Report failure back to the client. 
	else
	{	
		m_node * current = characters; // Set current to the begining of the list.

		// Move current to the last node. 
		while(current->next)
			current = current->next;
		
		current->next = new m_node; // Make a new node. 
		current = current->next; // Move current to the new node. 
		current->data = new char [strlen(to_add)+1]; // Make the new array. 
		strcpy(current->data,to_add); // Copy the data into the node. 
		current->next = NULL; // Set the next to NULL. 
		num_characters++; // Increase the number of characters. 
		
		return 1;
	}
}

// This function will add a actor.
int Movie::add_actor(char * to_add)
{
	if(!actors)
		return 0; // Report failure back to the client.  
	else
	{	
		m_node * current = actors; // Set current to to the begining of the list.

		// Move current to the last node. 
		while(current->next)
			current = current->next;
		
		current->next = new m_node; // Make a new node. 
		current = current->next; // Move current to the new node. 
		current->data = new char [strlen(to_add)+1]; // Make the new array. 
		strcpy(current->data,to_add); // Copy the data into the node. 	
		current->next = NULL; // Set the next pointer to NULL. 
		num_actors++; // Increase the number of actors. 
		
		return 1;
	}
}

// This function will check to see if the titles of the movies match. 
int Movie::check_title(char * look_for)
{
	if(!title)
		return 0; // Return 0 to the client to report failure. 
	
	if(strcmp(look_for,title) == 0) // Check to see if the movie title are the same. 
		return 1; // Return 1 to the client to report success. 
	else
		return 0; // Return 0 to the client to report failure. 
}

// This function will display the data. 
int Movie::display()
{
	m_node * current = characters; // Set current to the start of the list of characters.
 
	cout<< "Name of the movie: " << endl << title << endl // Display the name of the film.
	    << "Number of characters in the movie: " << endl << num_characters << endl // Display the number of characters in the film. 
	    << "Characters: " << endl; 

	// Display the characters in the movie. 
	while(current)
	{
		cout<< current->data; // Display the data. 
		if(!current->next) 
			cout<< endl;
		else
			cout<< ", "; 
		current= current->next; // Move current to the next node. 
	} 
	
	cout<< "Number of actors in the movie: " << endl << num_actors << endl // Display the number of actors in the movie. 
	    << "Actors: " << endl; 

	current = actors; //Set current to the start of the list of characters. 	
	
	// Display the actors in the movie. 
	while(current)
	{
		cout<< current->data; // Display the data.  
		if(!current->next)
			cout<< endl;
		else 
			cout<< ", ";
		current= current->next; // Move current to the next node. 
	}
 
	return 1; // Report success back to the client. 
}

// This function will deallocate all the dynamic memory. 
int Movie::destroy()
{
	m_node * current = characters; // Set current to the start of the list of charactors. 
	m_node * temp = NULL; // Set temp to NULL.

	if(title)
		delete [] title; // Deallocate the memory for title. 
	title = NULL; 

	while(current)
	{
		temp = current; // Set temp equal to current. 
		current = current->next; // Set current to the next node. 
		delete [] temp->data; // Deallocate the data from the node. 
		delete temp; // Deallocate the node. 
		
	}
 	characters = NULL; 
	
	current = actors; // Set current to the start of the list of actors.
	
	while(current)
	{
		temp = current; // Set temp equal to current. 
		current = current->next; // Set current to the next node. 
		delete [] temp->data; // Deallocate the data from the node. 
		delete temp; // Deallocate the node. 
	}

	actors = NULL;
	return 1;
}
