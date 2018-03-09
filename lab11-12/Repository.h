#pragma once
#include "Movie.h"
#include <vector>




class Repository
{
private:
	//DynamicVector<Movie> movies;
	std::vector<Movie> movielist;
	std::string filename;
	void readFromFile();
	void writeToFile();

public:
	Repository(const std::string& filename);

	/*
	This function deletes a movie from the array
	Input:name-the name of the movie to be removed
	*/
	void deleteR(std::string& name);

	/*
	This function updates a movie from the array
	Input:name, gender, year, likes-the field of the movie
	*/
	void updateR(std::string & name, std::string & gender, int & year, int & likes);

	/*
	This function adds a new movie to the array
	Input:m- the movie to be added
	*/
	void add(Movie &m);

	/*
	This function finds if there exit a movie with the same name
	Input:name-the name of the movie
	Output:returns 1 if there is no movie with the same name,otherwise 0
	*/
	int find(const std::string& name);

	/*
	This function finds all the movies with aa specific gender
	Input:gender-the gender to check
	*/
	Movie findByGender(std::string& gender);

	//This function updates the number of likes
	void likeMovie(std::string& name, int& like);

	//This function returns the hole array
	std::vector<Movie> getMovies() { return movielist; }

	void sortRepo();
	size_t seeCount();

};
