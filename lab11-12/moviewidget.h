#pragma once
#include <QWidget>
#include "ui_moviewidget.h"
#include "Repository.h"

class MovieWidget : public QWidget {
	Q_OBJECT

public:
	MovieWidget(Repository &r, QAbstractItemModel* model, QWidget * parent = 0);
	~MovieWidget();

private:
	Ui::MovieWidget ui;
	Repository& repo;
	QAbstractItemModel* tableModel;
};
