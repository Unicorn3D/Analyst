#include "couchdb.h"
#include "QJsonObject"
#include "QJsonArray"
#include "QJsonDocument"
#include "QJsonValue"
#include "QVariant"
#include "QVariantList"

Couchdb::Couchdb(QObject* parent) : QObject(parent)
{

}

void Couchdb::getAllDocuments(const QString &url, const QString &db)
{
    manager = new QNetworkAccessManager(this);

    connect(manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(replyFinished(QNetworkReply*)));

    QString finalUrl(QString("%1/%2/_all_docs").arg(url).arg(db));
    QNetworkRequest request = QNetworkRequest(QUrl(finalUrl));
    request.setRawHeader("User-Agent", "Mozilla Firefox");

    qDebug() << "Making a GET http request to " << finalUrl;


    manager->get(request);
}

void Couchdb::replyFinished(QNetworkReply *reply)
{
    if(reply->error())
    {
        qDebug() << "ERROR!";
        qDebug() << reply->errorString();
    }
    else
    {
        qDebug() << reply->attribute(QNetworkRequest::HttpReasonPhraseAttribute).toString();
        qDebug() << "Documents listing finished";
        const QByteArray response = reply->readAll();
        QJsonDocument document = QJsonDocument::fromJson(response);
        QJsonObject object = document.object();
        QJsonArray array = object["rows"].toArray();
        QVariantList list = array.toVariantList();
        this->documents = list;
        qDebug() << "There is " << list.size() << " documents in database.";
    }

    reply->deleteLater();
}
