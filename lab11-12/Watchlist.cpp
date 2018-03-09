#include "Watchlist.h"
#include <iostream>
using namespace std;

Watchlist::Watchlist()
{
	this->current = 0;
}

void Watchlist::addMovie(const Movie & mo)
{
	this->moviewatch.push_back(mo);
}

void Watchlist::delMovie(std::string& name)
{
	this->current = 0;
	while (this->current < this->moviewatch.size())
	{
		Movie m = this->moviewatch[this->current];
		if (m.getName() == name)
		{
			moviewatch.erase(moviewatch.begin() + this->current);	
		}
		this->current++;
	}

}

Movie Watchlist::getCurrentMovie()
{
	if (this->current == this->moviewatch.size())
		this->current = 0;


	if (this->moviewatch.size() != 0)
		return this->moviewatch[this->current];

	return Movie{};
}

void Watchlist::play()
{
	if (this->moviewatch.size() == 0)
		return;
	this->current = 0;
	Movie currmov = this->getCurrentMovie();
	currmov.Play();
}

void Watchlist::next()
{
	if (this->moviewatch.size() == 0)
		return;
	this->current++;
	Movie currmov = this->getCurrentMovie();
	currmov.Play();
}

bool Watchlist::isEmpty()
{
	return this->moviewatch.size() == 0;
}
