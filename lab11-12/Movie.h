#pragma once
#include <iostream>

class Movie
{
public:
	//default constructor
	Movie();

	//constructor with parameters
	Movie(const std::string& name, const std::string& gender, int year, int likes, const std::string& trailer);

	//Returns the name of the movie
	std::string getName() { return name; }

	//Returns the gender of the movie
	std::string getGender() { return gender; }

	//Returns the trailer of the movie
	std::string getTrailer() { return trailer; }

	//Returns the year of the movie
	int getYear() { return year; }

	//Returns the number of likes of the movie
	int getLikes() { return likes; }

	//Sets a new value for the year
	void setYear(int newyear) { this->year = newyear; }

	//Sets a new value for the number of likess
	void setLikes(int newlike) { this->likes = newlike; }

	//Sets a new gender of the movie
	void setGender(std::string newgender) { this->gender = newgender; }

	//Updates the number of likes
	void setLikesWithValue(int like) { this->likes += like; }

	void Play();

	bool operator==(Movie& m);

	friend std::istream& operator >> (std::istream& is, Movie& s);
	friend std::ostream& operator<<(std::ostream& os, const Movie& s);

private:
	std::string name;
	std::string gender;
	std::string trailer; //youtube link
	int year;
	int likes;



};

