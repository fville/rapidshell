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

#include "svnview.h"
#include "ui_svnview.h"

#include "svnwcmodel.h"


struct SvnView::Data
{
    SvnWcModel model;
};

SvnView::SvnView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SvnView),
    m(new Data)
{
    ui->setupUi(this);
}

SvnView::~SvnView()
{
    delete m;
    delete ui;
}

void SvnView::setRoot(const QString &location)
{
    m->model.setRoot(location);
    m->model.refresh();
}

const QString &SvnView::root() const
{
    return m->model.root();
}
