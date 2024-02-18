#ifndef ANIMAL_H
#define ANIMAL_H

#include <QObject>
#include <QLabel>
#include <QMovie>
#include <QPropertyAnimation>

class Animal
{
public:
    Animal(QWidget *widget,QString type);
    ~Animal();
    void Move(int x,int y);
    int PosX(QString t);
    int PosY(QString t);
    void Touched();

private:
    QLabel* animal;
    QMovie* move;
    QMovie* stand;
    QMovie* walk;
    int xp;
    int yp;
    bool isWalk=0;
    bool left=1;
};

#endif // ANIMAL_H
