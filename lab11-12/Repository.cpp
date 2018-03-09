#include "Repository.h"
#include <string>
#include <stdexcept>
#include <fstream>
#include "Exception.h"
using namespace std;

Repository::Repository(const std::string & filename)
{
	this->filename = filename;
	this->readFromFile();
}

void Repository::readFromFile()
{
	ifstream file(this->filename);

	if (!file.is_open())
		throw FileException("The file could not be opened!");

	Movie m;
	while (file >> m)
	{

		this->movielist.push_back(m);
	}
	file.close();
}

void Repository::writeToFile()
{
	ofstream file(this->filename);
	if (!file.is_open())
		throw FileException("The file could not be opened!");
	for (auto m : this->movielist)
	{
		file << m;
	}
	file.close();
}


int Repository::find(const std::string& name)
{
	if (this->movielist.size() == 0)
		return 1;

	for (auto s : this->movielist)
	{
		if (s.getName() == name)
		{
			return 0;
		}
	}
	return 1;
}

Movie Repository::findByGender(std::string & gender)
{

	if (this->movielist.size() == 0)
		return Movie{};

	for (auto s : this->movielist)
	{
		if (s.getGender() == gender)
			return s;
	}

	return Movie{};
}

void Repository::likeMovie(std::string& name, int& like)
{

	if (this->find(name) == 0)
		for (int i = 0;i < this->movielist.size();i++)
		{
			Movie s = this->movielist[i];
			if (s.getName() == name)
				this->movielist[i].setLikesWithValue(like);
		}
	this->writeToFile();
}

/*
void Repository::sortRepo()
{
DynamicVector<Movie> movieSort{ movies };
this->movies.sort(movieSort);
}

size_t Repository::seeCount()
{
return this->movies.getCount();
}*/




void Repository::deleteR(std::string & name)
{
	if (this->find(name) == 1)
		throw ExistentialException();
	for (int i = 0;i < this->movielist.size();i++)
	{
		Movie s = this->movielist[i];
		if (s.getName() == name)
		{
			movielist.erase(movielist.begin() + i);
			//return;
		}
	}
	this->writeToFile();
}

void Repository::updateR(std::string & name, std::string & gender, int & year, int & likes)
{
	if (this->find(name) == 1)
		throw ExistentialException();
	for (int i = 0;i < this->movielist.size();i++)
	{
		Movie s = this->movielist[i];
		if (s.getName() == name)
		{
			this->movielist[i].setGender(gender);
			this->movielist[i].setLikes(likes);
			this->movielist[i].setYear(year);
			//return;
		}
	}
	this->writeToFile();
}

void Repository::add(Movie &m)
{
	if (find(m.getName()) == 0)
		throw DuplicateException();
	this->movielist.push_back(m);
	this->writeToFile();
}


