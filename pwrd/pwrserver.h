#ifndef PWRSERVER_H
#define PWRSERVER_H

#include <QObject>

class PWRServer : public QObject
{
    Q_OBJECT
public:
    explicit PWRServer(QObject *parent = nullptr);

signals:

public slots:
};

#endif // PWRSERVER_H
