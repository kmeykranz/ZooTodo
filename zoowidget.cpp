#include "zoowidget.h"

ZooWidget::ZooWidget(QWidget *widget)
{
    this->Load();
    thisWidget=widget;
    bg=new QLabel(widget);
    this->Init();
}

ZooWidget::~ZooWidget(){
    delete bg;
}

void ZooWidget::Init(){
    bg->setPixmap(bgImage);
    bg->setFixedSize(500,580);
    bg->setScaledContents(true);
    bg->show();
}

void ZooWidget::New(QString ani){
    animal[n]=new Animal(thisWidget,ani);
    n++;
}

void ZooWidget::Load(){
    bgImage.load("Assets/bg.png");
}

void ZooWidget::AnimalWalk(){
    for(int i=n-1;i>0;i--){
        animal[i]->Touched();
    }
}
