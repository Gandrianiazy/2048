#ifndef DAMIER_H
#define DAMIER_H
#include <QList>
#include <QObject>
#include <cmath>

class damier : public QObject
{
    Q_OBJECT
public:
    explicit damier(QObject *parent = nullptr);
    Q_INVOKABLE void changeScore(int a);
    Q_INVOKABLE int readScore();
    Q_INVOKABLE void changeBestScore(int a);
    Q_INVOKABLE int readBestScore();
    Q_INVOKABLE bool readGameOver();
    Q_INVOKABLE void changeGameOver();
    Q_INVOKABLE QList<int> readCases();
    Q_INVOKABLE void changeCases(int rang, int val);
    Q_INVOKABLE void changeCases2(int rang);
    Q_INVOKABLE void changeCasesUp();
    Q_INVOKABLE QString colorChoice(int a);


    Q_PROPERTY(int scoreQML READ readScore WRITE changeScore NOTIFY scoreChanged);
    Q_PROPERTY(int bestScoreQML READ readBestScore WRITE changeBestScore NOTIFY bestScoreChanged);
    Q_PROPERTY(bool gameOverQML READ readGameOver NOTIFY gameOverChanged);
    Q_PROPERTY(QList<int> casesQML READ readCases NOTIFY casesChanged);

signals:
    void scoreChanged();
    void bestScoreChanged();
    void gameOverChanged();
    void casesChanged();

public slots:

private:
    int score;
    int bestScore;
    bool gameOver;
    QList<int> cases;
};

#endif // DAMIER_H
