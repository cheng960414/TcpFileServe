#include "tcpfileserve.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TcpFileServe w;
    w.show();
    return QApplication::exec();
}
