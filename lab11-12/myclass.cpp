#include "myclass.h"
#include <vector>
#include "Movie.h"
#include "Utils.h"
#include <QMessageBox>
#include "Exception.h"
#include <string>

MovieQt::MovieQt(Controller& c, QWidget *parent) : ctrl{ c }, QWidget{ parent }
{
	this->initGUI();
	this->currentMoviesInRepoList = this->ctrl.getRepo().getMovies();
	this->populateRepoList();
}

MovieQt::~MovieQt()
{

}

void MovieQt::initGUI()
{
	//General layout of the window
	QHBoxLayout* layout = new QHBoxLayout{ this };

	// Prepare left side components - vertical layout with: 
	// - list
	// - form layout with the movie data
	// - grid layout with buttons: add, delete, update, filter

	QWidget* leftWidget = new QWidget{};
	QVBoxLayout* leftSide = new QVBoxLayout{ leftWidget };

	QWidget* ButtonsWidget = new QWidget{};
	QGridLayout* GridLayout = new QGridLayout{ ButtonsWidget };
	this->sort = new QRadioButton("Sort");
	this->normal = new QRadioButton("Normal");
	GridLayout->addWidget(sort, 0, 0);
	GridLayout->addWidget(normal, 0, 1);

	// list
	this->repoList = new QListWidget{};
	// set the selection model
	this->repoList->setSelectionMode(QAbstractItemView::SingleSelection);

	// movie data
	QWidget* movieDataWidget = new QWidget{};
	QFormLayout* formLayout = new QFormLayout{ movieDataWidget };
	this->nameEdit = new QLineEdit{};
	this->genderEdit = new QLineEdit{};
	this->yearEdit = new QLineEdit{};
	this->likesEdit = new QLineEdit{};
	this->trailerEdit = new QLineEdit{};
	formLayout->addRow("&Name:", nameEdit);
	formLayout->addRow("&Gender:", genderEdit);
	formLayout->addRow("&Year:", yearEdit);
	formLayout->addRow("&Likes:", likesEdit);
	formLayout->addRow("&Trailer:",trailerEdit);

	// buttons
	QWidget* buttonsWidget = new QWidget{};
	QGridLayout* gridLayout = new QGridLayout{ buttonsWidget };
	this->addButton = new QPushButton("Add");
	this->deleteButton = new QPushButton("Delete");
	this->updateButton = new QPushButton("Update");
	this->filterButton = new QPushButton("Filter");
	this->clearButton = new QPushButton("Clear Filter");
	this->undo = new QPushButton("Undo");

	gridLayout->addWidget(addButton, 0, 0);
	gridLayout->addWidget(deleteButton, 0, 1);
	gridLayout->addWidget(updateButton, 0, 2);
	gridLayout->addWidget(filterButton,1,1);
	gridLayout->addWidget(clearButton,1,2);
	gridLayout->addWidget(undo,1,0);

	// add everything to the left layout
	leftSide->addWidget(new QLabel{ "All movies" });
	leftSide->addWidget(ButtonsWidget);
	leftSide->addWidget(repoList);
	leftSide->addWidget(movieDataWidget);
	leftSide->addWidget(buttonsWidget);
	

	// middle component: just two button - to add the songs from the reposiotory to the playlist
	QWidget* middleWidget = new QWidget{};
	QVBoxLayout* vLayoutMiddle = new QVBoxLayout{ middleWidget };
	this->moveOneMovieButton = new QPushButton{ ">> Move one movie" };
	this->moveAllMoviesButton = new QPushButton{ ">> Move all Movies" };
	QWidget* upperPart = new QWidget{};
	QWidget* lowerPart = new QWidget{};
	QVBoxLayout* vLayoutUpperPart = new QVBoxLayout{ upperPart };
	vLayoutUpperPart->addWidget(this->moveOneMovieButton);
	vLayoutUpperPart->addWidget(this->moveAllMoviesButton);
	vLayoutMiddle->addWidget(upperPart);
	vLayoutMiddle->addWidget(lowerPart);

	// right component: the Watchlist
	QWidget* rightWidget = new QWidget{};
	QVBoxLayout* rightSide = new QVBoxLayout{ rightWidget };

	// watchlist
	watchList = new QListWidget{};
	this->watchList->setSelectionMode(QAbstractItemView::SingleSelection);

	//watchlist data
	QWidget* watchlistDataWidget = new QWidget{};
	QFormLayout* FormLayout = new QFormLayout{ watchlistDataWidget };
	this->nameWatch = new QLineEdit{};
	this->genderWatch = new QLineEdit{};
	this->LikesWatch = new QLineEdit{};
	FormLayout->addRow("&NameMov:",nameWatch);
	FormLayout->addRow("&GenderMov:",genderWatch);
	FormLayout->addRow("&LikesMov:", LikesWatch);

	// two buttons
	QWidget* watchlistButtonsWidget = new QWidget{};
	QHBoxLayout* watchlistButtonsLayout = new QHBoxLayout{ watchlistButtonsWidget };
	this->play = new QPushButton("Play");
	this->next = new QPushButton("Next");
	this->deleteBut = new QPushButton("Delete Movie");
	this->html = new QPushButton("Save to HTML file");
	this->save = new QPushButton("Open file");
	watchlistButtonsLayout->addWidget(this->play);
	watchlistButtonsLayout->addWidget(this->next);
	watchlistButtonsLayout->addWidget(this->deleteBut);
	watchlistButtonsLayout->addWidget(this->html);
	watchlistButtonsLayout->addWidget(this->save);

	// add everything to the right layout
	rightSide->addWidget(new QLabel{ "Watchlist" });
	rightSide->addWidget(watchList);
	rightSide->addWidget(watchlistDataWidget);
	rightSide->addWidget(watchlistButtonsWidget);

	// add the three layouts to the main layout
	layout->addWidget(leftWidget);
	layout->addWidget(middleWidget);
	layout->addWidget(rightWidget);

	// connect the signals and slots
	this->connectSignalsAndSlots();
}

void MovieQt::connectSignalsAndSlots()
{
	// add a connection: function listItemChanged() will be called when an item in the list is selected
	QObject::connect(this->repoList, SIGNAL(itemSelectionChanged()), this, SLOT(listItemChanged()));
	QObject::connect(this->watchList, SIGNAL(itemSelectionChanged()), this, SLOT(listItemChanged2()));

	// add button connections
	QObject::connect(this->sort, SIGNAL(clicked()), this, SLOT(SortVector()));
	QObject::connect(this->normal, SIGNAL(clicked()), this, SLOT(Normal()));
	QObject::connect(this->addButton, SIGNAL(clicked()), this, SLOT(addNewMovie()));
	QObject::connect(this->deleteButton, SIGNAL(clicked()), this, SLOT(deleteMovie()));
	QObject::connect(this->updateButton, SIGNAL(clicked()), this, SLOT(updateMovie()));
	QObject::connect(this->filterButton, SIGNAL(clicked()), this, SLOT(filterRepoMovie()));
	QObject::connect(this->clearButton,SIGNAL(clicked()),this,SLOT(clearMovie()));

	QObject::connect(this->play,SIGNAL(clicked()),this,SLOT(Play()));
	QObject::connect(this->undo, SIGNAL(clicked()), this, SLOT(Undo()));
	QObject::connect(this->next, SIGNAL(clicked()), this, SLOT(Next()));
	QObject::connect(this->html,SIGNAL(clicked()),this,SLOT(htmlfile()));
	QObject::connect(this->save, SIGNAL(clicked()), this, SLOT(openFile()));
	QObject::connect(this->deleteBut, SIGNAL(clicked()), this, SLOT(deleteMovieFromWatchlist()));
	QObject::connect(this->moveOneMovieButton, SIGNAL(clicked()), this, SLOT(moveMoviesToWatchlist()));
	QObject::connect(this->moveAllMoviesButton, SIGNAL(clicked()), this, SLOT(moveAllMovies()));
}

void MovieQt::populateRepoList()
{
	// clear the list, if there are elements in it
	if (this->repoList->count() > 0)
		this->repoList->clear();
	for (auto s : this->currentMoviesInRepoList)
	{
		QString itemInList = QString::fromStdString(s.getName() + " - " + s.getGender() + "-" + std::to_string(s.getYear()) + " - " + std::to_string(s.getLikes()));
		QListWidgetItem *item3 = new QListWidgetItem(itemInList);
		//QFont font("Courier", 20, 10, true);
		//item3->setFont(font);
		this->repoList->addItem(item3);
	}

	// set the selection on the first item in the list
	if (this->currentMoviesInRepoList.size() > 0)
		this->repoList->setCurrentRow(0);
}

void MovieQt::populateWatchlist()
{
	// clear the list, if there are elements in it
	if (this->watchList->count() > 0)
		this->watchList->clear();

	for (auto s : this->ctrl.getMovieFromWatchlist())
	{
		QString itemInList = QString::fromStdString(s.getName() + " - " + s.getGender() + " - " + std::to_string(s.getYear()) );
		this->watchList->addItem(itemInList);
	}
}

int MovieQt::getRepoListSelectedIndex()
{
	if (this->repoList->count() == 0)
		return -1;

	// get selected index
	QModelIndexList index = this->repoList->selectionModel()->selectedIndexes();
	if (index.size() == 0)
	{
		this->nameEdit->clear();
		this->genderEdit->clear();
		this->yearEdit->clear();
		this->likesEdit->clear();
		this->trailerEdit->clear();
		return -1;
	}

	int idx = index.at(0).row();
	return idx;
}

int MovieQt::getRepoListSelectedIndex2()
{
	if (this->repoList->count() == 0)
		return -1;

	// get selected index
	QModelIndexList index = this->watchList->selectionModel()->selectedIndexes();
	if (index.size() == 0)
	{
		this->nameWatch->clear();
		this->genderWatch->clear();
		this->LikesWatch->clear();
		return -1;
	}

	int idx = index.at(0).row();
	return idx;
}

void MovieQt::listItemChanged()
{
	int idx = this->getRepoListSelectedIndex();
	if (idx == -1)
		return;

	std::vector<Movie> movies = this->currentMoviesInRepoList;

	// get the song at the selected index
	if (idx >= movies.size())
		return;
	Movie s = movies[idx];

	this->nameEdit->setText(QString::fromStdString(s.getName()));
	this->genderEdit->setText(QString::fromStdString(s.getGender()));
	this->yearEdit->setText(QString::fromStdString(std::to_string(s.getYear())));
	this->likesEdit->setText(QString::fromStdString(std::to_string(s.getLikes())));
	this->trailerEdit->setText(QString::fromStdString(s.getTrailer()));
}

void MovieQt::listItemChanged2()
{
	int idx = this->getRepoListSelectedIndex2();
	if (idx == -1)
		return;

	std::vector<Movie> movies = this->currentMoviesInWatchList;

	// get the song at the selected index
	if (idx >= movies.size())
		return;
	Movie s = movies[idx];
	int b = 0;
	this->nameWatch->setText(QString::fromStdString(s.getName()));
	this->genderWatch->setText(QString::fromStdString(s.getGender()));
	this->LikesWatch->setText(QString::fromStdString(std::to_string(b)));
}

void MovieQt::addNewMovie()
{
	std::string name = this->nameEdit->text().toStdString();
	std::string gender = this->genderEdit->text().toStdString();
	std::string trailer = this->trailerEdit->text().toStdString();
	std::string year = this->yearEdit->text().toStdString();
	int year1 = stoi(year);
	std::string likes = this->likesEdit->text().toStdString();
	int likes1 = stoi(likes);
	try
	{
		this->ctrl.addController(name,gender,trailer,year1,likes1);
		// refresh the list
		this->currentMoviesInRepoList = this->ctrl.getRepo().getMovies();
		this->populateRepoList();
	}
	catch (MovieException& e)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", QString::fromStdString(e.getErrorsAsString()));
	}
	catch (RepositoryException& e)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", e.what());
	}
}

void MovieQt::deleteMovie()
{
	std::string name = this->nameEdit->text().toStdString();

	try
	{
		this->ctrl.deleteController(name);
		// refresh the list
		this->currentMoviesInRepoList = this->ctrl.getRepo().getMovies();
		this->populateRepoList();
	}
	catch (RepositoryException& e)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", e.what());
	}
}

void MovieQt::updateMovie()
{
	std::string name = this->nameEdit->text().toStdString();
	std::string gender = this->genderEdit->text().toStdString();
	std::string year = this->yearEdit->text().toStdString();
	int year1 = stoi(year);
	std::string likes = this->likesEdit->text().toStdString();
	int likes1 = stoi(likes);

	try
	{
		this->ctrl.updateController(name,gender,year1,likes1);
		this->currentMoviesInRepoList = this->ctrl.getRepo().getMovies();
		this->populateRepoList();
	}
	catch (RepositoryException& e)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", e.what());
	}
}

void MovieQt::clearMovie()
{
	if (this->backup2.size() != 0)
		this->currentMoviesInRepoList = this->backup2;
	this->populateRepoList();
}

void MovieQt::deleteMovieFromWatchlist()
{
	std::string name = this->nameWatch->text().toStdString();
	std::string liks = this->LikesWatch->text().toStdString();
	int like = stoi(liks);
	this->ctrl.delWatchController(name,like);
	this->currentMoviesInRepoList = this->ctrl.getRepo().getMovies();
	this->populateRepoList();
	this->currentMoviesInWatchList = this->ctrl.getMovieFromWatchlist();
	this->populateWatchlist();
}

void MovieQt::SortVector()
{
	this->backup = this->currentMoviesInRepoList;
	std::vector<Movie> movie = this->currentMoviesInRepoList;
	Movie aux;
	
	for (int i=0; i<movie.size()-1;i++)
		for(int j=i+1;j<movie.size();j++)
			if (movie[i].getName() > movie[j].getName())
			{
				aux = movie[i];
				movie[i] = movie[j];
				movie[j] = aux;
			}
	this->currentMoviesInRepoList = movie;
	this->populateRepoList();
}

void MovieQt::Normal()
{
	if (this->backup.size() != 0)
		this->currentMoviesInRepoList = this->backup;
	this->populateRepoList();
}

void MovieQt::Undo()
{
	try
	{
		this->ctrl.Undo();
	}
	catch (RepositoryException& e)
	{
		QMessageBox msg;
		msg.critical(0,"ERROR",e.what());
	}

	this->currentMoviesInRepoList = this->ctrl.getRepo().getMovies();
	this->populateRepoList();
}

void MovieQt::filterRepoMovie()
{
	this->backup2 = this->currentMoviesInRepoList;
	std::string gender = this->genderEdit->text().toStdString();
	if (gender == "")
	{
		this->currentMoviesInRepoList = this->ctrl.getRepo().getMovies();
		this->populateRepoList();
		return;
	}

	this->currentMoviesInRepoList = this->ctrl.filterGender(gender);
	this->populateRepoList();

}

void MovieQt::Play()
{
	if (this->ctrl.getWatchlist().isEmpty() == 1)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "The Watchlis is empty!");
	}
	else
	{
		this->ctrl.startWatchlist();
	}
}

void MovieQt::Next()
{
	if (this->ctrl.getWatchlist().isEmpty() == 1)
	{
		QMessageBox messageBox;
		messageBox.critical(0, "Error", "The Watchlis is empty!");
	}
	else
	{
		this->ctrl.nextWatchlist();
	}
}

void MovieQt::htmlfile()
{
	this->ctrl.saveWatchlist("watchlist");
}

void MovieQt::openFile()
{
	this->ctrl.openWatchlist();
}

void MovieQt::moveMoviesToWatchlist()
{
	int idx = this->getRepoListSelectedIndex();
	if (idx == -1 || idx >= this->currentMoviesInRepoList.size())
		return;

	const Movie& s = this->currentMoviesInRepoList[idx];
	this->ctrl.addWatchController(s);
	this->currentMoviesInWatchList = this->ctrl.getMovieFromWatchlist();
	this->populateWatchlist();
}

void MovieQt::moveAllMovies()
{
	for (auto s : this->currentMoviesInRepoList)
	{
		this->ctrl.addWatchController(s);
	}
	this->currentMoviesInWatchList = this->ctrl.getMovieFromWatchlist();
	this->populateWatchlist();
}