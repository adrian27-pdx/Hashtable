// Adrian Perez Gonzalez
// CS 163 Spring 2019
// 5/17/19 

// This is a parcial declaration.
struct m_node;

// This is my movie class. 
class Movie
{
	public: 
		Movie(); // This is the constructor. 
		~Movie(); // This is the destructor. 
		int create(char * film, int n_characters, char * character, int n_actors, char * actor); // This functon will store the data in the class.  
		int add_character(char * to_add); // This function will add a character. 
		int add_actor(char * to_add); // This function will add a actor.
		int check_title(char * look_for); // This fucntion will check to see if the movie title match. 
		int display(); // This function will display the data. 
		int destroy(); // This function will deallocate all the dynamic memory. 
	private:
		char * title; // This will be the title of the movie. 
		int num_characters; // This will be the number of characters in the movie. 
		m_node * characters; // This will be a LLL to hold the characters in the movie. 
		int num_actors; // This will be the number of actors in the movie. 
		m_node * actors; // This will be a LLL to hold the actors in the movie. 
};
