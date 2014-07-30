#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //initiate splash
    QPixmap pixmap(":/graphics/data/images/splash.png");
    QSplashScreen splash(pixmap);
    a.processEvents();

    MainWindow w;

    //center main window
    QDesktopWidget *qdw = a.desktop();
    QRect sg = qdw->screenGeometry();
    int x = (sg.width()-w.width())/2;
    int y = (sg.height()-w.height())/2;
    w.move(x,y);
    w.show();

    //activate splash
    splash.show();
    splash.raise();
    QString msg = "<p style='color:white; margin:10'><br><br><br><br><br><br><br><br><br><br>Warning: This application is still under heavy development and may contain bugs. Always have a backup copy of your grades.</p>";
    splash.showMessage(msg,Qt::AlignAbsolute);

    return a.exec();
}
