// Course:  CS213 - Programming II  - 2018
// Title:   Assignment II - Task 2
// Program: main.cpp for problem 4
// Purpose: implementing a movie class that supports rating
// Author:  Ahmed Nasr Eldardery
// Date:    30 October 2018
// Version: 1.0

#include <iostream>
#include "Movie.h"
int main() {
	Movie movie1("Inception", PG);
	Movie movie2("Twilight", G);
	movie1.add_rating(1);
	movie1.add_rating(3, 3);
	movie1.add_rating(4, 23);
	movie1.add_rating(5, 15);

	movie2.add_rating(1, 33);
	movie2.add_rating(2, 40);
	movie2.add_rating(3, 25);
	movie2.add_rating(4, 13);
	movie2.add_rating(5, 2);

	std::cout << movie1.get_name() << " - " << movie1.get_MPAArating() << std::endl;
	std::cout << "Average: " << movie1.get_average() << std::endl;
	std::cout << movie2.get_name() << " - " << movie2.get_MPAArating() << std::endl;
	std::cout << "Average: " << movie2.get_average() << std::endl;


}
/*
 Consider a class Movie that contains information about a movie. The class has the following attributes:
■ The movie name
■ The MPAA rating (for example, G, PG, PG-13, r)
■ The number of people that have rated this movie as a 1 (Terrible)
■ The number of people that have rated this movie as a 2 (Bad)
■ The number of people that have rated this movie as a 3 (oK)
■ The number of people that have rated this movie as a 4 (Good)
■ The number of people that have rated this movie as a 5 (Great)
Implement the class with accessor and mutator functions for the movie name and MPAA rating.
Write a function addRating that takes an integer as an input parameter.
The function should verify that the parameter is a number between 1 and 5, and if so,
increment the number of people rating the movie that match the input parameter. For example, if 3 is the input parameter,
then the number of people that rated the movie as a 3 should be incremented by 1.
Write another function, getAverage, that returns the average value for all of the movie ratings.
Finally, add a constructor that allows the programmer to create the object with a specified name and MPAA rating.
The number of people rating the movie should be set to 0 in the constructor.
Test the class by writing a main function that creates at least two movie objects,
adds at least five ratings for each movie, and outputs the movie name, MPAA rating, and average rating for each movie object.

 */
