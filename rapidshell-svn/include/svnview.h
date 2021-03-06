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

#ifndef SVNVIEW_H
#define SVNVIEW_H

#include <QWidget>

namespace Ui {
class SvnView;
}

class SvnView : public QWidget
{
    Q_OBJECT

public:
    explicit SvnView(QWidget *parent = 0);
    ~SvnView();

    void setRoot(const QString &location);
    const QString& root() const;

private:
    Ui::SvnView *ui;
    struct Data;
    Data *m;
};

#endif // SVNVIEW_H
