/*
Copyright (C) 2006 - 2019 Evan Teran
						  evan.teran@gmail.com

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef ResultsModel_20070419_H_
#define ResultsModel_20070419_H_

#include <QAbstractItemModel>
#include <QVector>
#include "Types.h"
#include "Function.h"

namespace FunctionFinderPlugin {

struct Result {
	edb::address_t        start_address = 0;
	edb::address_t        end_address   = 0;
	size_t                size          = 0;
	int                   score         = 0;
	Function::Type        type          = Function::Type::FUNCTION_STANDARD;
	QString               symbol;
};

class ResultsModel : public QAbstractItemModel {
	Q_OBJECT
public:
	explicit ResultsModel(QObject *parent = nullptr);

public:
	QVariant data(const QModelIndex &index, int role) const override;
	QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
	QModelIndex parent(const QModelIndex &index) const override;
	int rowCount(const QModelIndex &parent = QModelIndex()) const override;
	int columnCount(const QModelIndex &parent = QModelIndex()) const override;
	QVariant headerData ( int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
	void sort (int column, Qt::SortOrder order = Qt::AscendingOrder) override;

public:
	void addResult(const Result &r);

public:
	QVector<Result> &results() { return results_; }

private:
	QVector<Result> results_;
};

}

#endif
