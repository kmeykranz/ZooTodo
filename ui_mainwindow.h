/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QWidget *Zoo;
    QWidget *ToDoList;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *confirmButton;
    QPushButton *clearButton;
    QListWidget *listWidget;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineEdit;
    QPushButton *addButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 599);
        MainWindow->setStyleSheet(QString::fromUtf8("#centralwidget{\n"
"background-color: rgb(255,250,240);\n"
"}\n"
"#ToDoList,#Zoo{\n"
"background-color: rgb(253,245,230);\n"
"}\n"
"#ToDoList{\n"
"border: 3px solid rgb(238,220,130);\n"
"}\n"
"QLineEdit {\n"
"      border: 0.5px solid rgb(147, 150, 154);\n"
"      border-radius: 6px;\n"
"      background-color: rgb(255,250,245);\n"
"      min-width: 80px;\n"
"	  font-family: \"Microsoft YaHei\";\n"
"	  font-size:11pt;\n"
"	  font-weight: bold;\n"
"	  color:rgb(100, 100, 100);\n"
"}\n"
"QListWidget{\n"
"      border: 0.5px solid rgb(147, 150, 154);\n"
"      border-radius: 6px;\n"
"      background-color: rgb(255,250,245);\n"
"      min-width: 80px;\n"
"	  font-family: \"Microsoft YaHei\";\n"
"	  font-size:11pt;\n"
"	  font-weight: bold;\n"
"      padding:10px;\n"
"	  color:rgb(100, 100, 100);\n"
"}\n"
"QPushButton {\n"
"      border: 0.5px solid white;\n"
"      border-radius: 6px;\n"
"      background-color: rgb(90,194,198);\n"
"      min-width: 40px;\n"
"	  font-family: \"Microsoft YaHei\";\n"
"	  font-size:"
                        "11pt;\n"
"	  font-weight: bold;\n"
"	  color:white;\n"
"  }\n"
" QPushButton:hover { \n"
"	border: 0.5px solid white;\n"
"      border-radius: 6px;\n"
"      background-color: #1fab89;\n"
"      min-width: 40px;\n"
"	  font-family: \"Microsoft YaHei\";\n"
"	  font-size:10pt;\n"
"	  font-weight: bold;\n"
"	  color:white;\n"
" }"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        Zoo = new QWidget(centralwidget);
        Zoo->setObjectName(QString::fromUtf8("Zoo"));
        Zoo->setMinimumSize(QSize(500, 0));

        horizontalLayout->addWidget(Zoo);

        ToDoList = new QWidget(centralwidget);
        ToDoList->setObjectName(QString::fromUtf8("ToDoList"));
        horizontalLayout_4 = new QHBoxLayout(ToDoList);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        confirmButton = new QPushButton(ToDoList);
        confirmButton->setObjectName(QString::fromUtf8("confirmButton"));

        horizontalLayout_2->addWidget(confirmButton);

        clearButton = new QPushButton(ToDoList);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));

        horizontalLayout_2->addWidget(clearButton);


        verticalLayout->addLayout(horizontalLayout_2);

        listWidget = new QListWidget(ToDoList);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setLineWidth(1);
        listWidget->setSpacing(2);

        verticalLayout->addWidget(listWidget);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        lineEdit = new QLineEdit(ToDoList);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMinimumSize(QSize(82, 30));

        horizontalLayout_3->addWidget(lineEdit);

        addButton = new QPushButton(ToDoList);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        addButton->setMinimumSize(QSize(42, 30));

        horizontalLayout_3->addWidget(addButton);


        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout_4->addLayout(verticalLayout);


        horizontalLayout->addWidget(ToDoList);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "ZooToDo", nullptr));
        confirmButton->setText(QCoreApplication::translate("MainWindow", "Confirm", nullptr));
        clearButton->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
