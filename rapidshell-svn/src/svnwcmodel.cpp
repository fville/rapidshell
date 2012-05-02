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

#include "svninfoxmlhandler.h"

#include <QProcess>
#include <QProcessEnvironment>
#include <QXmlSimpleReader>
#include <QXmlInputSource>


struct SvnWcModel::Data
{
    QString root;
    QXmlSimpleReader *xmlReader;
    QXmlInputSource *xmlInputSource;
    QProcess *svnProcess;
    SvnInfoXmlHandler *handler;

    Data() :
        xmlReader(0),
        xmlInputSource(0),
        svnProcess(0),
        handler(0)
    {
    }
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
    Q_ASSERT(0 == m->svnProcess);
    Q_ASSERT(0 == m->xmlInputSource);

    m->handler = new SvnInfoXmlHandler();

    m->xmlReader = new QXmlSimpleReader();
    m->xmlReader->setContentHandler(m->handler);

    QStringList args;
    args << "info" << "--recursive" << "--xml" << m->root;

    QProcessEnvironment processEnvironment = QProcessEnvironment::systemEnvironment();
    processEnvironment.insert("LANG", "C");

    m->svnProcess = new QProcess(this);
    m->svnProcess->setProcessEnvironment(processEnvironment);
    m->svnProcess->setReadChannel(QProcess::StandardOutput);

    m->xmlInputSource = new QXmlInputSource(m->svnProcess);
    m->xmlReader->parse(m->xmlInputSource, true);

    m->svnProcess->start("svn", args, QProcess::ReadOnly);
    m->svnProcess->waitForFinished();
}

void SvnWcModel::readyReadStandardOutput()
{
    //m->xmlInputSource.setData(m->svnProcess->readAllStandardOutput());
}
