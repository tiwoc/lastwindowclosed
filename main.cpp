#include <iostream>

#include <QApplication>
#include <QSystemTrayIcon>
#include <QQmlApplicationEngine>

#include "mainwindow.h"

#define USE_WIDGETS 0
#define USE_QML 1

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

#if USE_WIDGETS
    MainWindow widget;
    widget.show();
#endif
#if USE_QML
    QQmlApplicationEngine engine;
    engine.load(QUrl("qrc:/main.qml"));
#endif

    QSystemTrayIcon trayIcon;
    // the code works if the following line is commented out
    trayIcon.show();

    QObject::connect(&app, &QApplication::lastWindowClosed, []()
    {
        std::cerr << "last window closed" << std::endl;
    });

    std::cerr << "quitOnLastWindowClosed = "
              << app.quitOnLastWindowClosed()
              << std::endl;

    return app.exec();
}
