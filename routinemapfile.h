/*
 * Copyright (C) 2016 Sylvain "Skarsnik" Colinet

This software is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This software is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef ROUTINEMAPFILE_H
#define ROUTINEMAPFILE_H

#include <QString>
#include <QList>

struct RoutineEntry {
    uint32_t    address;
    QString     name;
    QString     description;
    QList<uint32_t> involvedAddress;
};

class RoutineMapFile
{
public:
    RoutineMapFile(QString file = QString(), QString name = QString());
    bool    open(QString file);
    bool    save(QString file = QString());


    QString name() const;

    void setName(const QString &name);

    QList<RoutineEntry> *routines();

private:
    QString m_file;
    QString m_name;

    QList<RoutineEntry> *m_routines;
};

#endif // ROUTINEMAPFILE_H
