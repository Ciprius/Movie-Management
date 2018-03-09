#include "Movie.h"
#include <Windows.h>
#include <shellapi.h>
#include <vector>
#include <iostream>
#include <string>
#include "Utils.h"
using namespace std;

Movie::Movie() : name(""), gender(""), trailer(""), year(0), likes(0) {}

bool Movie::operator==(Movie& m)
{
	if (this->getName() == m.getName())
		return 1;
	return 0;
}

Movie::Movie(const std::string & name, const std::string & gender, int  year, int  likes, const std::string & trailer)
{
	this->name = name;
	this->gender = gender;
	this->year = year;
	this->likes = likes;
	this->trailer = trailer;
}

void Movie::Play()
{
	ShellExecuteA(NULL, NULL, "chrome.exe", this->getTrailer().c_str(), NULL, SW_SHOWMAXIMIZED);
}

std::istream & operator >> (std::istream & is, Movie & s)
{
	string line;
	getline(is, line);

	vector<string> tokens = tokenize(line, ',');
	if (tokens.size() != 5)
		return is;
	s.name = tokens[0];
	s.gender = tokens[1];
	s.trailer = tokens[4];
	s.year = stoi(tokens[2]);
	s.likes = stoi(tokens[3]);

	return is;
}

std::ostream & operator<<(std::ostream & os, const Movie & s)
{
	os << s.name << "," << s.gender << "," << s.year << "," << s.likes << "," << s.trailer << "\n";
	return os;
}
