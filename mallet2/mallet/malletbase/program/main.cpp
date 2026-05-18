#include "malletbase.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    mallet window;
    window.show();
    return app.exec();
}
