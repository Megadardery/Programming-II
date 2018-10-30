// Course:  CS213 - Programming II  - 2018
// Title:   Assignment II - Task 2
// Program: Movie.h for problem 4
// Purpose: implementing a movie class that supports rating
// Author:  Ahmed Nasr Eldardery
// Date:    30 October 2018
// Version: 1.0
#ifndef _MOVIE_H
#define _MOVIE_H
#include <string>
enum MPAA_Rating {
	G, PG, PG13, R
};

class Movie {
private:
	static const int MAX_RATING = 5;

	std::string name;
	MPAA_Rating mpaa;
	int nRatings[MAX_RATING];
public:
	Movie(std::string n, MPAA_Rating rat);
	void set_name(std::string n);
	std::string get_name();
	MPAA_Rating get_MPAArating_int();
	std::string get_MPAArating();
	void set_MPAA_rating(MPAA_Rating rat);
	void add_rating(int rating, int n = 1);
	double get_average();
};
#endif
