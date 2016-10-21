#include "routinemapfile.h"
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

RoutineMapFile::RoutineMapFile(QString file, QString name)
{
    m_file = file;
    m_name = name;
}

bool RoutineMapFile::open(QString file)
{
    m_file = file;
    QFile qfile(m_file);
    if (qfile.open(QIODevice::ReadOnly)) {
        if (m_routines != NULL) {
            m_routines->clear();
            delete m_routines;
        }
        m_routines = new QList<RoutineEntry>();
        QByteArray data = qfile.readAll();
        QJsonDocument jsdoc = QJsonDocument::fromJson(data);
        QJsonObject jsobj = jsdoc.object();
        m_name = jsobj["name"].toString();
        QJsonArray jsRoutines = jsobj["routines"].toArray();
        for (int i = 0; i < jsRoutines.size(); i++) {
            QJsonObject jsR = jsRoutines[i].toObject();
            RoutineEntry r;
            r.address = jsR["address"].toInt();
            r.name = jsR["name"].toString();
            r.description = jsR["description"].toString();
            m_routines->append(r);
        }
        return true;
    }
    return false;
}

bool RoutineMapFile::save(QString file)
{
    if (!file.isNull())
        m_file = file;
    QJsonObject json;
    json["name"] = m_name;
    QJsonArray  jsRoutines;
    foreach(RoutineEntry r, *m_routines) {
        QJsonObject jsR;
        jsR["address"] = (int) r.address;
        jsR["name"] = r.name;
        jsR["description"] = r.description;
        jsRoutines.append(jsR);
    }
    json["routines"] = jsRoutines;
    QFile qfile(m_file);
    if (qfile.open(QIODevice::WriteOnly)) {
        QJsonDocument jsdoc(json);
        QByteArray data = jsdoc.toJson();
        qfile.write(data);
        return true;
    }
    return false;
}

QString RoutineMapFile::name() const
{
    return m_name;
}

void RoutineMapFile::setName(const QString &name)
{
    m_name = name;
}

QList<RoutineEntry> *RoutineMapFile::routines()
{
    return m_routines;
}
