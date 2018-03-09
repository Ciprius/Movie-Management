#ifndef MYCLASS_H
#define MYCLASS_H

#include <QtWidgets/QMainWindow>
#include "Controller.h"
#include <QListWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QRadioButton>
#include <QLabel>

class MovieQt : public QWidget
{
	Q_OBJECT

public:
	MovieQt(Controller& c, QWidget *parent = 0);
	~MovieQt();

private:
	Controller& ctrl;
	std::vector<Movie> currentMoviesInRepoList;
	std::vector<Movie> backup;
	std::vector<Movie> currentMoviesInWatchList;
	std::vector<Movie> backup2;

	QListWidget* repoList;
	QLineEdit* nameEdit;
	QLineEdit* genderEdit;
	QLineEdit* yearEdit;
	QLineEdit* likesEdit;
	QLineEdit* trailerEdit;
	QLineEdit* nameWatch;
	QLineEdit* genderWatch;
	QLineEdit* LikesWatch;
	QLineEdit* HtmlWatch;
	QPushButton* addButton;
	QPushButton* deleteButton;
	QPushButton* updateButton;
	QPushButton* filterButton;
	QPushButton* clearButton;
	QPushButton* moveOneMovieButton;
	QPushButton* moveAllMoviesButton;
	QPushButton* deleteBut;
	QPushButton* play;
	QPushButton* next;
	QPushButton* html;
	QPushButton* save;
	QPushButton* undo;
	QRadioButton* sort;
	QRadioButton* normal;
	

	QListWidget* watchList;

	void initGUI();
	void populateRepoList();
	void populateWatchlist();
	int getRepoListSelectedIndex();
	int getRepoListSelectedIndex2();

	void connectSignalsAndSlots();

private slots:
	// When an item in the list is clicked, the text boxes get filled with the item's information
	void listItemChanged();
	void listItemChanged2();

	void addNewMovie();
	void deleteMovie();
	void updateMovie();
	void clearMovie();
	void deleteMovieFromWatchlist();
	void SortVector();
	void Normal();
	void Undo();

	// filters the elements in the list, by the artist written in the artist edit box
	void filterRepoMovie();


	void Play();
	void Next();
	void htmlfile();
	void openFile();
	void moveMoviesToWatchlist();
	void moveAllMovies();
};

#endif // MYCLASS_H
