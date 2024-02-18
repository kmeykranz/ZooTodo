#ifndef ZOOWIDGET_H
#define ZOOWIDGET_H

#include <QObject>
#include <QWidget>
#include <QPixmap>
#include <QLabel>
#include <animal.h>

class ZooWidget
{
public:
    ZooWidget(QWidget *widget);
    ~ZooWidget();
    void Init();
    void Load();
    void New(QString ani);
    void AnimalWalk();
private:
    QLabel* bg;
    QPixmap bgImage;
    Animal *animal[10];
    QWidget *thisWidget;
    int n=0;
};

#endif // ZOOWIDGET_H
