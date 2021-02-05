#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include "server.h"

class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = nullptr);

public:
    void callFunc(Server *server);

};

#endif // CLIENT_H
