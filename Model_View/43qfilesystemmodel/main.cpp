#include "myqfilesystemmodel.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyQFileSystemModel fileSystemModel;
    fileSystemModel.show();
    return a.exec();
}
