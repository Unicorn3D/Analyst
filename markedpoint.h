#ifndef MARKEDPOINT_H
#define MARKEDPOINT_H
#include <QString.h>
#include <point.h>


class markedPoint : public point
{
    public:
        markedPoint();
        markedPoint(float lat, float lng, QString title, QString info);
        QString info;
        QString title;
        void write(QJsonObject &json) const;
};

#endif // MARKEDPOINT_H
