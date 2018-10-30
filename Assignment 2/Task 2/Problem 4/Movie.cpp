// Course:  CS213 - Programming II  - 2018
// Title:   Assignment II - Task 2
// Program: Movie.cpp for problem 4
// Purpose: implementing a movie class that supports rating
// Author:  Ahmed Nasr Eldardery
// Date:    30 October 2018
// Version: 1.0
#include "Movie.h"

//constructor for movie class, sets inital ratings to zero
Movie::Movie(std::string n, MPAA_Rating rat) {
	name = n;
	mpaa = rat;
	for (int i = 0; i < MAX_RATING; ++i)
		nRatings[i] = 0;
}
void Movie::set_name(std::string n) {
	name = n;
}
std::string Movie::get_name() {
	return name;
}
MPAA_Rating Movie::get_MPAArating_int() {
	return mpaa;
}
//returns MPAA rating in string format
std::string Movie::get_MPAArating() {
	const std::string arr[] = { "G","PG","PG-13","r" };
	return arr[mpaa];
}
void Movie::set_MPAA_rating(MPAA_Rating rat) {
	mpaa = rat;
}
//add one or more ratings to the movie
void Movie::add_rating(int rating, int n) {
	if (rating > 0 && rating <= MAX_RATING)
		nRatings[rating - 1] += n;
}
//gets average of all ratings on the movie
double Movie::get_average() {
	double sum = 0;
	long long count = 0;
	for (int i = 0; i < MAX_RATING; ++i) {
		sum += (nRatings[i] * (i + 1));
		count += nRatings[i];
	}
	return sum / count;
}
