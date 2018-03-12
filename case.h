#ifndef CASE_H
#define CASE_H

#include <QObject>

class Case : public QObject
{
    Q_OBJECT
public:
    explicit Case(QObject *parent = nullptr);

signals:

public slots:
};

#endif // CASE_H