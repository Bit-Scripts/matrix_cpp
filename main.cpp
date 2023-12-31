#include <QApplication>
#include <QCoreApplication>
#include <QTranslator>
#include <QLibraryInfo>
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QTranslator translator;
    translator.load("qt_fr", QLibraryInfo::path(QLibraryInfo::TranslationsPath));
    QApplication::installTranslator(&translator);

    QIcon icon("/usr/bin/matrixresources/icons/Matrix.png");

    MainWindow mainWindow;
    mainWindow.resize(1280,720);
    mainWindow.setWindowTitle("Matrix");
    mainWindow.setWindowIcon(icon);
    mainWindow.show();

    return app.exec();
}
