#ifndef DAMIER_H
#define DAMIER_H
#include <QList>
#include <QObject>
#include <cmath>
#include <cstdlib>
#include <ctime>

class damier : public QObject
{
    Q_OBJECT
public:
    explicit damier(QObject *parent = nullptr);
    Q_INVOKABLE void changeScore(int a);
    Q_INVOKABLE int readScore();
    Q_INVOKABLE void changeBestScore();
    Q_INVOKABLE int readBestScore();
    Q_INVOKABLE bool readGameOver();
    Q_INVOKABLE void changeGameOver();
    Q_INVOKABLE QList<int> readCases();
    Q_INVOKABLE void changeCases(int rang, int val);
    Q_INVOKABLE void changeCasesUp();
    Q_INVOKABLE void changeCasesDown();
    Q_INVOKABLE void changeCasesRight();
    Q_INVOKABLE void changeCasesLeft();
    Q_INVOKABLE QString colorChoice(int a);
    Q_INVOKABLE void generator();
    Q_INVOKABLE void menuprincipal();
    Q_INVOKABLE bool readEtatMenuPrincipal();
    Q_INVOKABLE void fermermenu();
    int randomInt(int a, int b);
    Q_INVOKABLE void resetDamier();
    void decalerUp();
    void fusionUp();
    void decalerDown();
    void fusionDown();
    void decalerLeft();
    void fusionLeft();
    void decalerRight();
    void fusionRight();
    void testGameOver();


    Q_PROPERTY(int scoreQML READ readScore WRITE changeScore NOTIFY scoreChanged);
    Q_PROPERTY(int bestScoreQML READ readBestScore NOTIFY bestScoreChanged);
    Q_PROPERTY(bool gameOverQML READ readGameOver NOTIFY gameOverChanged);
    Q_PROPERTY(QList<int> casesQML READ readCases NOTIFY casesChanged);
    Q_PROPERTY(bool etatmenuprincipalQML READ readEtatMenuPrincipal NOTIFY etatmenuprincipalChanged);

signals:
    void scoreChanged();
    void bestScoreChanged();
    void gameOverChanged();
    void casesChanged();
    void etatmenuprincipalChanged();

public slots:

private:
    int score;
    int bestScore;
    bool gameOver;
    QList<int> cases;
    bool ifCasesChanged;
    bool menuprincipalOn;
};

#endif // DAMIER_H
