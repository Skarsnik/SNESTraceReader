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
