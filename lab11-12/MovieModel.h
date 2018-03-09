#pragma once
#include <QAbstractItemModel>
#include "Repository.h"
#include <qbrush.h>
#include <qcolor.h>



class MovieTableModel : public QAbstractTableModel
{
private:
	Repository& repo;

public:
	MovieTableModel(Repository& r) : repo{ r } {}
	~MovieTableModel()
	{

	}

	// we must implement the following three methods (which are abstract in the class QAbstractTableModel)
	int rowCount(const QModelIndex& parent = QModelIndex{}) const override // provides the number of rows for the table
	{
		return this->repo.getMovies().size();
	}	
	int columnCount(const QModelIndex& parent = QModelIndex{}) const override// provides the number of columns for the table
	{
		return 4;
	}
		
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override				// provides the text content for a cell
	{
		Movie currentStudent = this->repo.getMovies()[index.row()];

		if (role == Qt::DisplayRole || role == Qt::EditRole)
		{
			switch (index.column())
			{
			case 0:		// first column - name
				return QString::fromStdString(currentStudent.getName());
			case 1:		// second column - group
				return QString::fromStdString(currentStudent.getGender());
			case 2:		// third column - lab grade
				return QString::number(currentStudent.getYear());
			case 3:		// fourth column - seminar grade
				return QString::number(currentStudent.getLikes());
			default:
				break;
			}
		}

		return QVariant();
	}
																									// add header data
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override
	{
		if (role == Qt::DisplayRole)
		{
			if (orientation == Qt::Horizontal)
			{
				switch (section)
				{
				case 0:
					return QString{ "Name" };
				case 1:
					return QString{ "Gender" };
				case 2:
					return QString{ "Year" };
				case 3:
					return QString{ "Likes" };
				default:
					break;
				}
			}
		}

		return QVariant();
	}


	bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole) override	// will be called when a cell is edited
	{
		if (!index.isValid() || role != Qt::EditRole)
			return false;

		int row = index.row();
		int col = index.column();

		Movie& currMovie = this->repo.getMovies()[index.row()];

		if (role == Qt::EditRole)
		{
			switch (col)
			{
			case 0:
				break;
			case 1:
				break;
			case 2:
			{
				std::string year{ value.toString().toStdString() };
				currMovie.setYear(std::stoi(year));
				break;
			}
			case 3:
			{
				std::string likes{ value.toString().toStdString() };
				currMovie.setLikes(std::stoi(likes));
			}
			}
		}

		emit dataChanged(index, index);
		return true;
	}
	
	Qt::ItemFlags flags(const QModelIndex & index) const override										// used to set certain properties of a cell
	{
		int col = index.column();
		if (col == 0 || col == 1)
			return Qt::ItemFlags{};
		return Qt::ItemIsEnabled | Qt::ItemIsEditable | Qt::ItemIsSelectable;
	}
};