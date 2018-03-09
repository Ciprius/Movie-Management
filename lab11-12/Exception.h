#pragma once
#include <exception>
#include <string>

class FileException : public std::exception
{
protected:
	std::string message;
public:
	FileException(const std::string& message);
	virtual const char* what();
};


class RepositoryException : public std::exception
{
protected:
	std::string message;
public:
	RepositoryException();
	RepositoryException(const std::string& msg);
	virtual ~RepositoryException() {}
	virtual const char* what();
};

class DuplicateException : public RepositoryException
{
	const char* what();
};

class ExistentialException : public RepositoryException
{
	const char* what();
};