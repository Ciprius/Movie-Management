#pragma once
#include "Movie.h"
#include "Repository.h"


class UndoAction
{
public:
	virtual void executeUndo() = 0;
	// virtual destructor!
	virtual ~UndoAction() {};
};

class UndoAdd : public UndoAction
{
private:
	Movie addedMovie;
	Repository& repo;	// we keep a reference to the repository to be able to undo the action
public:
	UndoAdd(Repository& _repo, const Movie& s) : repo{ _repo }, addedMovie{ s } {}

	/*
	For the add operation, the reverse operation that must be executed is "remove".
	*/
	void executeUndo() override
	{
		this->repo.deleteR(addedMovie.getName());
	}
};

class UndoRemove : public UndoAction
{
private:
	Movie deletedMovie;
	Repository& repo;
public:
	UndoRemove(Repository& _repo, const Movie& s) : repo{ _repo }, deletedMovie{ s } {}

	void executeUndo() override
	{
		this->repo.add(deletedMovie);
	}
};

class UndoUpdate : public UndoAction
{
private:
	Movie updatedMovie;
	Repository& repo;
public:
	UndoUpdate(Repository& _repo,const Movie& s) : repo{ _repo }, updatedMovie{ s } {}

	void executeUndo() override
	{
		int a = updatedMovie.getYear(),b= updatedMovie.getLikes();
		this->repo.updateR(updatedMovie.getName(),updatedMovie.getGender(),a,b);
	}
};