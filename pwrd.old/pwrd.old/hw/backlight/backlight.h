#ifndef BACKLIGHT_H
#define BACKLIGHT_H

#include <QObject>

class Backlight : public QObject
{
    Q_OBJECT
public:
    explicit Backlight(QObject *parent = nullptr);

signals:

public slots:
};

#endif // BACKLIGHT_H
