#include "damier.h"

damier::damier(QObject *parent) : QObject(parent)
{
    score = 0;
    bestScore = 0;
    gameOver = false;
    for (int i=0; i<16; i++)
    {
        cases.append(2);
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

void damier::changeBestScore(int a)
{
    bestScore = a;
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
    for(int col = 0; col<4; col++)
    {
        for(int ligne = 0; ligne<3; ligne++)
        {
            if(cases[4*ligne+col]==cases[4*(ligne+1)+col])
            {
                changeCases(4*ligne+col, 2*cases[4*ligne+col]);
                for(int i = ligne+1; i<3; i++)
                {
                    changeCases(4*i+col, cases[4*(i+1)+col]);
                }
            break;
            }
        }
    }
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
