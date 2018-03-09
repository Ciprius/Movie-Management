#pragma once
//#include "DynamicVector.h"
#include<vector>
#include "Movie.h"

class Watchlist
{
protected:
	std::vector<Movie> moviewatch;
	int current;

public:
	Watchlist();

	/*
	This function adds a new movie to the watch list
	Input:mo- the movie to be added
	*/
	void addMovie(const Movie& mo);

	/*
	This function deletes a movie from the watch list
	Input:mane-the name of the movie
	*/
	void delMovie(std::string& name);

	/*
	This function returns the current movie form the watch list
	*/
	Movie Watchlist::getCurrentMovie();

	/*
	This function plays the first movie
	*/
	void play();

	std::vector<Movie> getAll() { return moviewatch; }

	/*
	This function play the next movie
	*/
	void next();
	bool isEmpty();
};
