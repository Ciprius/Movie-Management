#pragma once
#include "FileWatchlist.h"
#include <string>

class HTMLFile :public FileWatchlist
{
public:
	void writeToFile() override;
	void displayWatchlist() const override;
};