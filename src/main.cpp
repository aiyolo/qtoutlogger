#include "mainwindow.h"
#include <qDebug>
#include <QtWidgets/QApplication>
#include "qmutex.h"
#include "qfile.h"
#include "qdir.h"
#include <qthread.h>
#include <QDateTime>
#include <QTextStream>
#include <QFileInfo>
#include <QSettings>

#include "qylogger.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Set up logger with log file path, max file size (10MB), and max log files (3)
    setup_logger("C:/ProgramData/qiaoyi/log/Mes", 10 * 1024 * 1024, 3);

    MainWindow w;
    w.test_logger();
    w.show();
    while(1){
        qDebug() << "debug";
        qInfo() << "info";
        qWarning() << "waring";
        qCritical() << "error";
    }
    return a.exec();
}
