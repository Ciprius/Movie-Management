#include "HTMLFile.h"
#include "Exception.h"
#include <iostream>
#include <Windows.h>
#include <fstream>

using namespace std;

void HTMLFile::writeToFile()
{
	ofstream f(this->filename);
	f << "<!DOCTYPE html>\n<html>\n\t<head>\n\t\t<title>Movie List</title>\n\t</head>\n\t<body>\n\t\t<table border=\"1\">\n\t\t<tr>\n\t\t\t<td>Name</td>\n\t\t\t<td>Gender</td>\n\t\t\t<td>Year</td>\n\t\t\t<td>link</td>\n\t\t</tr>";
	for (auto d : this->moviewatch)
		f << "\t\t<tr>\n\t\t\t<td>" << d.getName() << "</td>\n\t\t\t<td>" << d.getGender() << "</td>\n\t\t\t<td>" << d.getYear() << "</td>\n\t\t\t<td><a href = \"" << d.getTrailer() << "\">Link</a></td></tr>";
	f << "\t\t</table>\n\t</body>\n</html>";
	f.close();
}

void HTMLFile::displayWatchlist() const
{
	string aux = this->filename;
	ShellExecuteA(NULL, NULL, "chrome.exe", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
}
