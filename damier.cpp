#include "damier.h"

damier::damier(QObject *parent) : QObject(parent)
{
    score = 0;
    bestScore = 0;
    gameOver = false;
    for (int i=0; i<16; i++)
    {
        cases.append(0);
    }
}

void damier::changeScore(int a)
{
    score = a;
    scoreChanged();
}

int damier::readScore()
{
    return score;
}

void damier::changeBestScore()
{
    if (bestScore<score){
        bestScore=score;
    }
    bestScoreChanged();
}

int damier::readBestScore()
{
    return bestScore;
}

bool damier::readGameOver()
{
    return gameOver;
}

void damier::changeGameOver()
{
    gameOver = ! gameOver;
    gameOverChanged();

}

QList<int> damier::readCases()
{
    return cases;
}

void damier::changeCases(int rang, int val)
{
    cases[rang]=val;
    casesChanged();
}

void damier::changeCases2(int rang)
{
    changeCases(rang, cases[rang]+cases[rang-1]);
}

void damier::changeCasesUp()
{

}

QString damier::colorChoice(int a)
{
    if(a==2){
        return("#e6d8d3");
    }
    else if(a==4){
        return("#f0deca");
    }
    else if(a==8){
        return("#f2b179");
    }
    else if(a==16){
        return("#f79266");
    }
    else if(a==32){
        return("#f97a62");
    }
    else if(a==64){
        return("#fa5c3f");
    }
    else if(a==128){
        return("#f55c3f");
    }
    else if(a==256){
        return("#efca64");
    }
    else if(a==512){
        return("#e3bb51");
    }
    else if(a==1024){
        return("#e4b93f");
    }
    else if(a==2048){
        return("#eec032");
    }
    else if(a==4096){
        return("#f1646e");
    }
    else if(a==8192){
        return("#ef4c5c");
    }
    else if(a==16384){
        return("#e34239");
    }
    else if(a==32768){
        return("#72b2d6");
    }
    else if(a==65536){
        return("#5f9ee2");
    }
    else if(a==131072){
        return("#0374b4");
    }
    else{
        return("#cdc1b4");
    }
}

void damier::generator()
{
    int compteurVide = 0;
    for (int i=0; i<16; i++)
    {
        if(cases[i]==0)
        {
            compteurVide++;        }
    }
    if(compteurVide>0){
        int numero = randomInt(0,compteurVide);

        compteurVide = 0;

        for (int i=0; i<16; i++)
        {
            if(cases[i]==0)
            {
                if(compteurVide==numero)
                {
                    int test = randomInt(0,10);
                    if(test==0)
                    {
                        cases[i]=4;
                    }
                    else
                    {
                        cases[i]=2;
                    }
                }
                compteurVide++;
            }
        }
    }
    casesChanged();
}

int damier::randomInt(int a, int b)
{
    srand(time(NULL));
    return (rand()%(b-a)+a);
}
