/*
 * Copyright (C) 2014  Andrew Gunnerson <andrewgunnerson@gmail.com>
 *
 * This file is part of MultiBootPatcher
 *
 * MultiBootPatcher is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * MultiBootPatcher is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with MultiBootPatcher.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "mainwindow.h"

#include <QtCore/QStringBuilder>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMessageBox>

#include <iostream>

#include <libmbp/logging.h>

#ifdef PORTABLE
#  if defined(DATA_DIR)
#    error DATA_DIR should not be defined for portable builds
#  endif
#else
#  if !defined(DATA_DIR)
#    error DATA_DIR must be defined for non-portable builds
#  endif
#endif

static const QChar Sep = QLatin1Char('/');


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setApplicationName(QObject::tr("Dual Boot Patcher"));

    mbp::PatcherConfig pc;

#ifdef PORTABLE
    pc.setDataDirectory(a.applicationDirPath().toStdString() + "/" + LOCAL_DATA_DIR);
#else
    pc.setDataDirectory(DATA_DIR);
#endif

    MainWindow w(&pc);
    w.show();

    return a.exec();
}
