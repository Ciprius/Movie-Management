#include "moviewidget.h"

MovieWidget::MovieWidget(Repository &r, QAbstractItemModel* model, QWidget * parent) : repo{ r }, tableModel{ model },QWidget(parent) {
	ui.setupUi(this);
	this->ui.movietableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	this->ui.movietableView->setModel(this->tableModel);
	this->ui.movietableView->setSortingEnabled(true);
}

MovieWidget::~MovieWidget() {
	
}
