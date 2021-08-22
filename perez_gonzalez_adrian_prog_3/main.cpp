K// Adrian Perez Gonzalez
// CS 163 Spring 2019
// 5/17/19 
// This will be the main for program 3. 

#include "hash_table.h" 

using namespace std; 

int read_file();

int main ()
{
	int flag = 1; // This will be the flag to control when to stop the program. 
	int responce; // This will be used to track what the user want to do. 
	char title[size], character[size], actor[size], temp[size]; // These are temperary arrays. 
	int n_character, n_actor;

	Hash_Table table; // This is the hash table sorted by character. 
	Hash_Table table2; // This is a hash table sorted by actors. 

	table.from_file(); // Store the data from the text file.
	table2.from_file2(); // Store the data from the text file. 

	while(flag)
	{
		// Prompt the user for input. 
		cout<< endl << "1. To add a movie." << endl
		    << "2. To add a character to a movie." << endl
		    << "3. To add a actor to a movie." << endl
		    << "4. To search for movies with a certain character." << endl
		    << "5. To search for movies with a certain actor." <<  endl 
		    << "6. To remove movies with a certain character." << endl
		    << "7. To display all the movies with a certain character." << endl
		    << "8. To display everything." << endl
		    << "0. To exit the program." << endl;

		cin>> responce; // Read in the useres responce. 
		cin.ignore(100, '\n'); // Clear the input buffer. 
		cin.clear();

		switch(responce) // Call the proper function. 
		{
			case 1: cout<< "Enter the name of the movie:" << endl; // Prompt the user for input. 
				cin.get(title,size,'\n'); // Read in input. 
				cin.ignore(100,'\n'); // Clear the input stream. 

				cout<< "Enter the number of characters in the movie:" << endl; // Prompt the user for input.
				cin>> n_character; // Read in the input. 
				cin.ignore(100,'\n'); // Clear the input buffer. 
				
				cout<< "Enter a characters name:" << endl; // Prompt the user for input. 
				cin.get(character,size,'\n'); // Read in the input. 
				cin.ignore(100,'\n'); // Clear the input stream. 
		
				cout<< "Enter the number of actors of the movie:" << endl; // Prompt the user for input. 
				cin>> n_actor; // Read in the input. 
				cin.ignore(100,'\n'); // Clear the input stream. 
			
				cout<< "Enter the name of a actor:" << endl; // Prompt the user for input. 
				cin.get(actor,size,'\n'); // Read in the input. 
				cin.ignore(100,'\n'); // Clear the input buffer. 
				
				table.function(character); // Set the key. 

				table.add_movie(title,n_character,character,n_actor,actor); // Call the function. 

				table2.function(actor); // Set the key. 

				table2.add_movie(title,n_character,character,n_actor,actor); // Call the function. 

				break;

			case 2: cout<< "Enter the name of the movie: " << endl; // Prompt for input. 
				cin.get(title,size,'\n'); // Read in the input. 
				cin.ignore(100,'\n'); // Clear the input stream. 

				cout<< "Enter the name of the original character: " << endl; // Prompt for input. 
				cin.get(character,size,'\n'); // Read in the input. 
				cin.ignore(100,'\n'); // Clear the input stream. 
			
				cout<< "Enter the name of the original actor: " << endl; // Prompt for input. 
				cin.get(temp,size,'\n'); // Read in the input. 
				cin.ignore(100,'\n'); // Clear the input stream. 
				
				cout<< "Enter the name of the character that you want to add: " << endl; // Prompt for input. 
				cin.get(actor,size,'\n'); // Read in the input. 
				cin.ignore(100,'\n'); // Clear the input stream. 

				table.function(character); // Set the key. 
				table.add_character(title,character,actor); // Call the function. 
			
				table2.function(temp); // Set the key. 
				table2.add_character(title,temp,actor); // Call the function. 				

				break;

			case 3: cout<< "Enter the name of the movie: " << endl; // Prompt for input. 
				cin.get(title,size,'\n'); // Read in the input. 
				cin.ignore(100,'\n'); // Clear the input stream. 
				
				cout<< "Enter the original actor of the movie: " << endl; // Prompt for input. 
				cin.get(character,size,'\n'); // Read in the input. 
				cin.ignore(100,'\n'); // Clear the input stream. 
		
				cout<< "Enter the name of the original actor: " << endl; // Prompt for input. 
				cin.get(temp,size,'\n'); // Read in the input. 
				cin.ignore(100,'\n'); // Clear the input stream. 

				cout<< "Enter the name of the actor you would like to add: " << endl; // Prompt for input. 
				cin.get(actor,size,'\n'); // Read in the input. 
				cin.ignore(100,'\n'); // Clear the input stream. 

				table.function(character); // Set the key. 
				table.add_actor(title,character,actor); // Call the function. 

				table2.function(temp); // Set the key. 
				table2.add_actor(title,temp,actor); // Call the function. 

				break;

			case 4: cout<< "Enter the characters name: " << endl; // Prompt for input. 
				cin.get(title,size,'\n'); // Read in the input. 
				cin.ignore(100,'\n'); // Clear the input stream. 

				table.function(title); // Set the key. 
				table.search_character(title); // Call the function. 

				break;

			case 5: cout<< "Enter the actors name: " << endl; // Prompt the input. 
				cin.get(title,size,'\n'); // Read in the input. 
				cin.ignore(100,'\n'); // Clear the input stream. 

				table.function(title); // Set the key. 
				table.search_actor(title); // Call the function. 

				break;

			case 6: cout<< "Enter the characters name: " << endl; // Prompt for input. 
				cin.get(title,size,'\n'); // Read in the input. 
				cin.ignore(100,'\n'); // Clear the input stream. 

				table.function(title); // Set the key. 
				table.remove_character(title); // Call the function. 

				break;

			case 7: cout<< "Enter the name of the character:" << endl; // Prompt for input. 
				cin.get(title,size,'\n'); // Read in the input. 
				cin.ignore(100,'\n'); // Clear the input stream. 
		
				table.function(title); // Set the key. 
				table.display_character(title); // Call the function. 
			
				break;
			
			case 8: table.display_all(); // Call the function. 
				break;

			case 0: flag = 0; // Set flag to 0. 
				break;

			default: cout<< endl << "You provided invalid data. Please try again!" << endl;
		}
	}
	return 0;
}
