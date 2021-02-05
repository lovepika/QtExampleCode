#include "server.h"
#include "client.h"
#include <string.h>
#include "my_qevent.h"
#include <QCoreApplication>

class Server;
class Client;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    //
    Server server;
    Client client;
    client.callFunc(&server);

    return a.exec();
}
