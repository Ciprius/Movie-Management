#include "myclass.h"
#include <QtWidgets/QApplication>
#include <QSortFilterProxyModel>
#include "CSVFile.h"
#include "HTMLFile.h"
#include "Movievalidator.h"
#include "MovieModel.h"
#include "moviewidget.h"
#include <QMessageBox>
#include <QPushButton>
#include <QListWidget>
#include <QFormLayout>
#include <QLabel>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Repository repo{ "Movie.txt" };
	MovieTableModel* tableModel = new MovieTableModel{ repo };
	QSortFilterProxyModel* sortModel = new QSortFilterProxyModel{};
	sortModel->setSourceModel(tableModel);
	MovieWidget movieTable{repo,sortModel};
	movieTable.setWindowTitle("Movie list");
	movieTable.show();

	HTMLFile watchlist;
	Controller cont{ repo,watchlist, MovieValidator{} };
	MovieQt w{ cont };
	w.show();
	
	return a.exec();
}
