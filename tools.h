#ifndef TOOLS_H
#define TOOLS_H
#include <QProcess.h>
#include <QJsonObject.h>
#include <QFile.h>
#include <QJsonDocument.h>
#include <point.h>
#include <markedpoint.h>
#include <QJsonArray.h>

class tools
{
public:
    static void execCommandLine(QString path, QString parameter);
    static void execCommandLineDetached(QString path, QString parameter);
    static bool writeJsonFile(QString name, QJsonObject object);
    static QJsonObject createJsonObject(QList<point> path, QList<markedPoint> markedPoints);
};

#endif // TOOLS_H