#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QStandardPaths>
#include <QMessageBox>
#include <zoowidget.h>
#include <QKeyEvent>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void ReadTask();
    void WriteTask();
    void ReadAnimal();
    void AddAnimal();
    void StartWalk();

private slots:
    void on_clearButton_clicked();

    void on_addButton_clicked();

    void on_confirmButton_clicked();
protected:
    void keyPressEvent(QKeyEvent *event);

private:
    Ui::MainWindow *ui;
    QString path=QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)+"\\ToDoFile.txt";
    QString path2=QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation)+"\\AnimalFile.txt";
    QString animal[10];
    QString animalType[10]={"dog","cat","duck","cro","pig","mon","koa","bear","rab"};
    int animalNum=0;
    bool isConfirmed=0;
    int taskNum=0;
    bool gained=0;
    ZooWidget *zooWidget;
};
#endif // MAINWINDOW_H
