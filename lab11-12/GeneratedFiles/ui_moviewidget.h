/********************************************************************************
** Form generated from reading UI file 'moviewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOVIEWIDGET_H
#define UI_MOVIEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MovieWidget
{
public:
    QGridLayout *gridLayout;
    QTableView *movietableView;

    void setupUi(QWidget *MovieWidget)
    {
        if (MovieWidget->objectName().isEmpty())
            MovieWidget->setObjectName(QStringLiteral("MovieWidget"));
        MovieWidget->resize(527, 465);
        gridLayout = new QGridLayout(MovieWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        movietableView = new QTableView(MovieWidget);
        movietableView->setObjectName(QStringLiteral("movietableView"));

        gridLayout->addWidget(movietableView, 0, 0, 1, 1);


        retranslateUi(MovieWidget);

        QMetaObject::connectSlotsByName(MovieWidget);
    } // setupUi

    void retranslateUi(QWidget *MovieWidget)
    {
        MovieWidget->setWindowTitle(QApplication::translate("MovieWidget", "MovieWidget", 0));
    } // retranslateUi

};

namespace Ui {
    class MovieWidget: public Ui_MovieWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOVIEWIDGET_H
