#include <cassert>
#include <iostream>

#include <QApplication>
#include <QSystemTrayIcon>
#include <QQmlApplicationEngine>
#include <QQuickWindow>

#include "mainwindow.h"

#define USE_QML 1

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

#if not USE_QML
    MainWindow window;
    window.show();
#else
    QQmlApplicationEngine engine;
    engine.load(QUrl("qrc:/main.qml"));
    assert(engine.rootObjects().size() == 1);
    QQuickWindow *window = qobject_cast<QQuickWindow*>(engine.rootObjects()[0]);
    window->show();
#endif

    // the code works if these two lines are commented out
    QSystemTrayIcon trayIcon;
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
