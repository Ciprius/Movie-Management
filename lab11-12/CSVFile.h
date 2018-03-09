#pragma once
#include "FileWatchlist.h"
#include <string>

class CSVFile : public FileWatchlist
{
public:
	void writeToFile() override;
	void displayWatchlist() const override;
};