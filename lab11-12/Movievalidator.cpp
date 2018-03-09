#include "Movievalidator.h"

using namespace std;

MovieException::MovieException(std::vector<std::string> _errors) : errors{ _errors }
{
}

std::vector<std::string> MovieException::getErrors() const
{
	return this->errors;
}

std::string MovieException::getErrorsAsString() const
{
	string err;
	for (auto e : this->errors)
		err += e;
	return err;
}

void MovieValidator::validate(Movie & s)
{
	vector<string> errors;
	if (s.getName().size() < 3)
		errors.push_back("The title name cannot be less than 3 characters!\n");
	if (!isupper(s.getName()[0]))
		errors.push_back(string("The name of the movie must start with a capital letter!\n"));

	// search for "www" or "http" at the beginning of the source string
	int posWww = s.getTrailer().find("www");
	int posHttp = s.getTrailer().find("http");
	if (posWww != 0 && posHttp != 0)
		errors.push_back("The youtube source must start with one of the following strings: \"www\" or \"http\"");

	if (errors.size() > 0)
		throw MovieException(errors);
}
