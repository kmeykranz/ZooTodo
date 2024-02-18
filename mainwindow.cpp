#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(800,600);
    zooWidget=new ZooWidget(ui->Zoo);
    ReadAnimal();
    ReadTask();
    for(;animalNum>=0;animalNum--){
        zooWidget->New(animal[animalNum]);
    }
    connect(ui->lineEdit,SIGNAL(returnPressed()),this,SLOT(on_addButton_clicked()));
}

MainWindow::~MainWindow()
{
    WriteTask();
    delete ui;
    delete zooWidget;
}


void MainWindow::on_clearButton_clicked()
{
    QListWidgetItem* item=ui->listWidget->takeItem(ui->listWidget->currentRow());
    delete item;
    //if all the tasks confirmed are finished
    if(isConfirmed&&ui->listWidget->count()==0&&gained==0){
        AddAnimal();
        //avoid repeatedly providing animals
        gained=1;
    }
}

void MainWindow::on_addButton_clicked()
{
    QListWidgetItem* item=new QListWidgetItem(ui->lineEdit->text(),ui->listWidget);
    ui->listWidget->addItem(item);
    item->setFlags(item->flags()|Qt::ItemIsEditable);
    ui->lineEdit->clear();
    ui->lineEdit->setFocus();
}


void MainWindow::on_confirmButton_clicked()
{
    if(!isConfirmed){
        isConfirmed=1;
        ui->confirmButton->setText("Refresh");
        ui->addButton->hide();
        ui->lineEdit->hide();
        ui->clearButton->setText("Finish");
        //allow providing animal again
        gained=0;
    }else{
        isConfirmed=0;
        ui->confirmButton->setText("Confirm");
        ui->addButton->show();
        ui->lineEdit->show();
        ui->clearButton->setText("Remove");
        ui->listWidget->clear();
    }
}

void MainWindow::ReadTask(){
    QFile file(path);
    if(!file.open(QIODevice::ReadWrite)){
        QMessageBox::information(0,"error",file.errorString());
    }
    QTextStream in(&file);
    isConfirmed=in.readLine().toInt();
    while(!in.atEnd()){
        QListWidgetItem* item=new QListWidgetItem(in.readLine(),ui->listWidget);
        ui->listWidget->addItem(item);
        item->setFlags(item->flags()|Qt::ItemIsEditable);
    }
    file.close();
    if(isConfirmed){
        ui->confirmButton->setText("Refresh");
        ui->addButton->hide();
        ui->lineEdit->hide();
        ui->clearButton->setText("Finish");
    }else{
        ui->confirmButton->setText("Confirm");
        ui->addButton->show();
        ui->lineEdit->show();
        ui->clearButton->setText("Remove");
    }
}

void MainWindow::WriteTask(){
    QFile file(path);
    if(!file.open(QIODevice::ReadWrite|QFile::Truncate)){
        QMessageBox::information(0,"error",file.errorString());
    }
    QTextStream out(&file);
    out<<isConfirmed<<"\n";
    for(int i=0;i<ui->listWidget->count();++i){
        out<<ui->listWidget->item(i)->text()<<"\n";
    }
    file.close();
}

void MainWindow::ReadAnimal(){
    QFile file(path2);
    if(!file.open(QIODevice::ReadWrite)){
        QMessageBox::information(0,"error",file.errorString());
    }
    QTextStream in(&file);
    animalNum=0;
    while(!in.atEnd()){
        animal[animalNum]=in.readLine();
        animalNum++;
    }
    file.close();
}

void MainWindow::AddAnimal(){
    QFile file(path2);
    if(!file.open(QIODevice::Append)){
        QMessageBox::information(0,"error",file.errorString());
    }
    QTextStream out(&file);
    srand(QTime(0,0,0).secsTo(QTime::currentTime()));
    int aNum=rand()%9;
    out<<"\n"<<animalType[aNum];
    file.close();
    zooWidget->New(animalType[aNum]);
}

void MainWindow::keyPressEvent(QKeyEvent *event){
    switch(event->key()){
    case Qt::Key_Up:ui->listWidget->setCurrentRow(ui->listWidget->currentRow()-1);break;
    case Qt::Key_Down:ui->listWidget->setCurrentRow(ui->listWidget->currentRow()+1);break;
    case Qt::Key_Delete:on_clearButton_clicked();break;
    case Qt::Key_Alt:zooWidget->AnimalWalk();break;
    default: break;
    }
}
