#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include "Controller.h"
#include "Exception.h"


using namespace std;


void Controller::addController(const std::string & name, const std::string & gender, const std::string & trailer, int& year, int& likes)
{
	Movie m{ name,gender,year,likes,trailer };
	this->val.validate(m);
	this->repo.add(m);
	this->undoActions.push_back(std::make_unique<UndoAdd>(this->repo, m));
}

void Controller::deleteController(std::string & name)
{
	for (auto s:this->repo.getMovies())
		if (s.getName() == name)
		{
			this->undoActions.push_back(std::make_unique<UndoRemove>(this->repo, s));
			break;
		}
	this->repo.deleteR(name);
}

void Controller::updateController(std::string & name, std::string & gender, int & year, int & likes)
{
	for (auto s : this->repo.getMovies())
		if (s.getName() == name)
		{
			this->undoActions.push_back(std::make_unique<UndoUpdate>(this->repo, s));
			break;
		}
	this->repo.updateR(name, gender, year, likes);
}

void Controller::Undo()
{
	if (undoActions.empty())
	{
		throw RepositoryException{ "There are no more actions to undo." };
	}


	undoActions.back()->executeUndo();
	//std::unique_ptr<UndoAction> last = std::move(undoActions.back());
	//last->executeUndo();

	undoActions.pop_back();
}

std::vector<Movie> Controller::filterGender(const std::string & gender)
{
	std::vector<Movie> newmovies;
	for (auto s : this->repo.getMovies())
		if (s.getGender() == gender)
			newmovies.push_back(s);
	return newmovies;
}

void Controller::addWatchController(const Movie& m)
{
	this->watchlist.addMovie(m);
}

void Controller::delWatchController(std::string & name,int& like)
{
	this->watchlist.delMovie(name);
	this->repo.likeMovie(name, like);
}

void Controller::startWatchlist()
{
	this->watchlist.play();
}

void Controller::nextWatchlist()
{
	this->watchlist.next();
}
void Controller::saveWatchlist(const std::string & filename)
{
	if (this->watchlist.getAll().size() == 0)
		return;
	this->watchlist.setFilename(filename);
	this->watchlist.writeToFile();
}
void Controller::openWatchlist() const
{
	if (this->watchlist.getAll().size() == 0)
		return;
	this->watchlist.displayWatchlist();
}
/*
void Controller::sortController()
{
this->repo.sortRepo();
}

size_t Controller::seeCount()
{
return this->repo.seeCount();
}
*/