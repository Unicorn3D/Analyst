#ifndef COUCHDB_H
#define COUCHDB_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QMap>
#include <QJsonDocument>
#include <QJsonValue>
#include <QVariantList>
#include <QJsonArray>


class Couchdb : public QObject
{
    Q_OBJECT

public:
    explicit Couchdb(QObject *parent = 0);
    void getAllDocuments(const QString &url, const QString &db);
    static QJsonArray documents;
private:
    QString baseUrl;
    QNetworkAccessManager *manager;

private slots:
    void replyFinished(QNetworkReply *reply);
};

#endif // COUCHDB_H
