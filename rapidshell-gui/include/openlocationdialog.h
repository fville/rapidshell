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

#ifndef OPENLOCATIONDIALOG_H
#define OPENLOCATIONDIALOG_H

#include <QDialog>

namespace Ui {
class OpenLocationDialog;
}

class OpenLocationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit OpenLocationDialog(QWidget *parent = 0);
    ~OpenLocationDialog();

    QString location() const;

private slots:
    void browse();

private:
    Ui::OpenLocationDialog *ui;
};

#endif // OPENLOCATIONDIALOG_H
