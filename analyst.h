#ifndef ANALYST_H
#define ANALYST_H

#include <QMainWindow>
#include <QTableWidget.h>
#include <QLabel.h>
#include <QPushButton.h>
#include <QSpinBox.h>
#include "minor.h"
#include "qmovie.h"
#include "qlabel.h"

namespace Ui {
    class Analyst;
}

class Analyst : public QMainWindow
{
    Q_OBJECT

    public:
        Analyst(QWidget *parent = 0);
        ~Analyst();

    public slots:
        void callTracker();
        void mine();

    private:
        void draw();
        void bind();
        QSpinBox *sbTemperatureMin;
        QSpinBox *sbTemperatureMax;
        QSpinBox *sbAccelerometerMax;
        QSpinBox *sbAccelerometerMin;
        QSpinBox *sbHumidityMax;
        QSpinBox *sbHumidityMin;
        QSpinBox *sbGyroscopeMax;
        QSpinBox *sbGyroscopeMin;
        QTableWidget *tableWidget;
        QLabel *lToolTip;
        QPushButton *bDataMining;
        Ui::Analyst *ui;

        QMovie *movie;
        QLabel *processLabel;

        Minor *minor;
};

#endif // ANALYST_H
