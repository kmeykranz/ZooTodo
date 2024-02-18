#include "animal.h"

Animal::Animal(QWidget *widget,QString type)
{
    stand=new QMovie("Assets/"+type+".gif");
    walk=new QMovie("Assets/"+type+"2.gif");
    animal=new QLabel(widget);
    QSize size(80,100);
    stand->setScaledSize(size);
    walk->setScaledSize(size);
    animal->setMovie(stand);
    xp=PosX(type),yp=PosY(type);
    animal->move(xp,yp);
    stand->start();
    animal->show();
}
Animal::~Animal(){

}

void Animal::Touched(){
    if(isWalk==0){
        isWalk=1;
        animal->setMovie(walk);
        walk->start();

        QPropertyAnimation *animation = new QPropertyAnimation(animal);
        animation->setDuration(1000);
        animation->setTargetObject(animal);
        animation->setPropertyName("geometry");
        animation->setStartValue(QRect(xp, yp, 80, 100));
        if(left==1)xp-=50;
        else xp+=50;

        if(xp<50)left=0;
        else if(xp>400)left=1;
        animation->setEndValue(QRect(xp, yp, 80, 100));
        animation->setLoopCount(1);
        animation->start();
    }
    else{
        isWalk=0;
        animal->setMovie(stand);
    }
}

void Animal::Move(int x,int y){
    animal->move(x,y);
}

//returns fixed positions of certain animals
int Animal::PosX(QString t){
    if(t=="dog")return 300;
    else if(t=="cat")return 150;
    else if(t=="duck")return 50;
    else if(t=="cro")return 178;
    else if(t=="pig")return 10;
    else if(t=="mon")return 320;
    else if(t=="koa")return 231;
    else if(t=="bear")return 89;
    else if(t=="rab")return 290;
    else return 0;
}
int Animal::PosY(QString t){
    if(t=="dog")return 230;
    else if(t=="cat")return 430;
    else if(t=="duck")return 200;
    else if(t=="cro")return 230;
    else if(t=="pig")return 345;
    else if(t=="mon")return 500;
    else if(t=="koa")return 245;
    else if(t=="bear")return 475;
    else if(t=="rab")return 180;
    else return 0;
}
