#include "damier.h"

damier::damier(QObject *parent) : QObject(parent)
{
    score = 0;
    bestScore = 0;
    gameOver = false;
    ifCasesChanged=false;
    for (int i=0; i<16; i++)
    {
        cases.append(0);
    }
    srand(time(NULL));
    resetDamier();
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
                    if(randomInt(0,10)==0)
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
    return (rand()%(b-a)+a);
}

void damier::resetDamier()
{
    for(int i = 0; i<16; i++)
    {
        cases[i]=0;
    }
    casesChanged();
    generator();
    generator();
    casesChanged();
    score=0;
    bestScore=0;
    scoreChanged();
    bestScoreChanged();
}

void damier::changeCasesUp()
{
    decalerUp();
    fusionUp();
    decalerUp();
    if(ifCasesChanged)
    {
        generator();
        scoreChanged();
        bestScoreChanged();
    }
    ifCasesChanged=false;
}

void damier::decalerUp()
{
    for(int col=0; col<4; col++){
            int row=0;
            int compteurVide=0;
            while(row<4)
            {
                if(cases[4*row+col]==0)
                {
                    row++;
                }
                else{
                    cases[4*compteurVide+col]=cases[4*row+col];
                    if(compteurVide<row){
                        cases[4*row+col]=0;
                        casesChanged();
                        ifCasesChanged=true;

                    }
                    compteurVide++;
                    row++;
                }
            }
    }
}

void damier::fusionUp()
{
    for(int col=0; col<4; col++)
    {
        int row=0;
        while(row<3)
        {
            if (cases[4*row+col]==cases[4*(row+1)+col])
            {
                changeCases(4*row+col, 2*cases[4*row+col]);
                changeScore(score+cases[4*row+col]);
                scoreChanged();
                changeBestScore();
                bestScoreChanged();
                changeCases(4*(row+1)+col, 0);
                row++;
                row++;
                casesChanged();
                ifCasesChanged=true;
            }
            else
            {
                row++;
            }
        }
    }
}

void damier::changeCasesDown()
{
    decalerDown();
    fusionDown();
    decalerDown();
    if(ifCasesChanged)
    {
        generator();
        scoreChanged();
        bestScoreChanged();
    }
}

void damier::decalerDown()
{
    for(int col=0; col<4; col++){
            int row=3;
            int compteurVide=3;
            while(row>-1)
            {
                if(cases[4*row+col]==0)
                {
                    row--;
                }
                else{
                    cases[4*compteurVide+col]=cases[4*row+col];
                    if(compteurVide>row){
                        cases[4*row+col]=0;
                        casesChanged();
                        ifCasesChanged=true;

                    }
                    compteurVide--;
                    row--;
                }
            }
    }
}

void damier::fusionDown()
{
    for(int col=0; col<4; col++)
    {
        int row=3;
        while(row>0)
        {
            if (cases[4*row+col]==cases[4*(row-1)+col])
            {
                changeCases(4*row+col, 2*cases[4*row+col]);
                changeScore(score+cases[4*row+col]);
                scoreChanged();
                changeBestScore();
                bestScoreChanged();
                changeCases(4*(row-1)+col, 0);
                row--;
                row--;
                casesChanged();
                ifCasesChanged=true;
            }
            else
            {
                row--;
            }
        }
    }
}

void damier::changeCasesRight()
{
    decalerRight();
    fusionRight();
    decalerRight();
    if(ifCasesChanged)
    {
        generator();
        scoreChanged();
        bestScoreChanged();
    }
}

void damier::decalerRight()
{
    for(int row=0; row<4; row++){
            int col=3;
            int compteurVide=3;
            while(col>-1)
            {
                if(cases[4*row+col]==0)
                {
                    col--;
                }
                else{
                    cases[4*row+compteurVide]=cases[4*row+col];
                    if(compteurVide>col){
                        cases[4*row+col]=0;
                        casesChanged();
                        ifCasesChanged=true;

                    }
                    compteurVide--;
                    col--;
                }
            }
    }
}

void damier::fusionRight()
{
    for(int row=0; row<4; row++)
    {
        int col=3;
        while(col>0)
        {
            if (cases[4*row+col]==cases[4*row+col-1])
            {
                changeCases(4*row+col, 2*cases[4*row+col]);
                changeScore(score+cases[4*row+col]);
                scoreChanged();
                changeBestScore();
                bestScoreChanged();
                changeCases(4*row+col-1, 0);
                col--;
                col--;
                casesChanged();
                ifCasesChanged=true;
            }
            else
            {
                col--;
            }
        }
    }
}

void damier::changeCasesLeft()
{
    decalerLeft();
    fusionLeft();
    decalerLeft();
    if(ifCasesChanged)
    {
        generator();
        scoreChanged();
        bestScoreChanged();
    }
    ifCasesChanged=false;
}

void damier::decalerLeft()
{
    for(int row=0; row<4; row++){
            int col=0;
            int compteurVide=0;
            while(col<4)
            {
                if(cases[4*row+col]==0)
                {
                    col++;
                }
                else{
                    cases[4*row+compteurVide]=cases[4*row+col];
                    if(compteurVide<col){
                        cases[4*row+col]=0;
                        casesChanged();
                        ifCasesChanged=true;

                    }
                    compteurVide++;
                    col++;
                }
            }
    }
}

void damier::fusionLeft()
{
    for(int row=0; row<4; row++)
    {
        int col=0;
        while(col<3)
        {
            if (cases[4*row+col]==cases[4*row+col+1])
            {
                changeCases(4*row+col, 2*cases[4*row+col]);
                changeScore(score+cases[4*row+col]);
                scoreChanged();
                changeBestScore();
                bestScoreChanged();
                changeCases(4*row+col+1, 0);
                col++;
                col++;
                casesChanged();
                ifCasesChanged=true;
            }
            else
            {
                col++;
            }
        }
    }
}

void damier::testGameOver()
{

}
