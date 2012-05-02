/*
 * ====================================================================
 * Copyright (c) 2012 Alexander Mueller.  All rights reserved.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program (in the file GPL.txt.
 * If not, see <http://www.gnu.org/licenses/>.
 *
 * This software consists of voluntary contributions made by many
 * individuals.  For exact contribution history, see the revision
 * history and logs, available at http://rapidshell.org/.
 * ====================================================================
 */

#include "svnwcmodel.h"

struct SvnWcModel::Data
{
    QString root;
};

SvnWcModel::SvnWcModel(QObject *parent) :
    QAbstractItemModel(parent), m(new Data)
{
}

SvnWcModel::~SvnWcModel()
{
    delete m;
}

void SvnWcModel::setRoot(const QString &location)
{
    m->root = location;
}

const QString &SvnWcModel::root() const
{
    return m->root;
}

QModelIndex SvnWcModel::index(int row, int column, const QModelIndex &parent) const
{
    return createIndex(row, column);
}

QModelIndex SvnWcModel::parent(const QModelIndex &child) const
{
    return QModelIndex();
}

int SvnWcModel::rowCount(const QModelIndex &parent) const
{
    return 0;
}

int SvnWcModel::columnCount(const QModelIndex &parent) const
{
    return 0;
}

QVariant SvnWcModel::data(const QModelIndex &index, int role) const
{
    return QVariant();
}

void SvnWcModel::refresh()
{
}
