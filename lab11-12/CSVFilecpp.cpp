#include "CSVFile.h"
#include <fstream>
#include <Windows.h>
#include "Exception.h"

using namespace std;

void CSVFile::writeToFile()
{
	ofstream f(this->filename);

	if (!f.is_open())
		throw FileException("The file could not be opened!");
	for (auto s : this->moviewatch)
		f << s;
	f.close();

}

void CSVFile::displayWatchlist() const
{
	string aux = "\"" + this->filename + "\"";
	ShellExecuteA(NULL, NULL, "C:\\Program Files (x86)\\Kingsoft\\WPS Office\\10.2.0.5811\\office6\\et.exe", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
}
