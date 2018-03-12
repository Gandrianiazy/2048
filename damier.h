#ifndef DAMIER_H
#define DAMIER_H

#include <QObject>

class Damier : public QObject
{
    Q_OBJECT
public:
    explicit Damier(QObject *parent = nullptr);

signals:

public slots:
};

#endif // DAMIER_H