#ifndef PWRDOBJECT_H
#define PWRDOBJECT_H

#include <QObject>

class PWRDObject : public QObject
{
    Q_OBJECT
public:
    explicit PWRDObject(QObject *parent = nullptr);

public:
    virtual QString JSONName()=0;
    virtual QString Name()=0;

signals:

public slots:
};

#endif // PWRDOBJECT_H
