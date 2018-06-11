#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLayout>
#include <QBoxLayout>
#include <QGroupBox>
#include <QRadioButton>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QGridLayout>
#include <QMessageBox>
#include <QFontDatabase>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent):QMainWindow(parent){
    setWindowTitle(tr("（GDUT）PL0编译器 —— 高仿Qt重制版 v1.0.0    【GitHub 地址：https://github.com/gdut-yy/PL0_Qt 】"));   //设置标题

    createPL0Page();
    setCentralWidget(pl0Page);
}

MainWindow::~MainWindow(){
}

void MainWindow::createPL0Page(){
    pl0Page = new QWidget;

    // 定义页面字体样式
    QFont qfont;
    qfont.setPointSize(30);
    qfont.setFamily("黑体");
    qfont.setBold(true);

    QFont qfont1;
    qfont1.setPointSize(30);
    qfont1.setFamily("Courier New");
    qfont1.setBold(true);

//    QFontDatabase database;
//    foreach (const QString &family, database.families())
//    {
//         qDebug()<<family;
//    }

    // 左部文本框
    pl0TextEdit = new QTextEdit();
        pl0TextEdit->setText(tr("***** PL/0 Compiler Demo *****"));
        pl0TextEdit->setFont(qfont1);

    // 右部
    sourceLabel = new QLabel(tr("源程序名"));
        sourceLabel->setFont(qfont);

    sourceLineEdit = new QLineEdit(tr("E01"));
        sourceLineEdit->setFont(qfont1);

    isVisibleGroupBox = new QGroupBox(tr("目标代码"));
    visibleRadioButton = new QRadioButton(tr("显示"));
    invisibleRadioButton = new QRadioButton(tr("不显示"));
        visibleRadioButton->setChecked(true);

    QLayout *isVisibleLayout = new QVBoxLayout;
    isVisibleLayout->addWidget(visibleRadioButton);
    isVisibleLayout->addWidget(invisibleRadioButton);
    isVisibleGroupBox->setLayout(isVisibleLayout);
        isVisibleGroupBox->setFont(qfont);

    runButton = new QPushButton(tr("RUN"));
        connect(runButton, SIGNAL(clicked(bool)), this, SLOT(runClicked()));
        runButton->setFont(qfont);

    QGridLayout *pageLayout = new QGridLayout;
    pageLayout->setColumnStretch(0,5);
    pageLayout->setColumnStretch(1,1);
    pageLayout->setRowStretch(0,1);     // label
    pageLayout->setRowStretch(1,1);     // lineedit
    pageLayout->setRowStretch(2,1);
    pageLayout->setRowStretch(3,5);     // groupbox
    pageLayout->setRowStretch(4,1);
    pageLayout->setRowStretch(5,2);     // button
    pageLayout->setRowStretch(6,10);
    pageLayout->addWidget(pl0TextEdit,0,0,7,1);
    pageLayout->addWidget(sourceLabel,0,1,1,1);
    pageLayout->addWidget(sourceLineEdit,1,1,1,1);
    pageLayout->addWidget(isVisibleGroupBox,3,1,1,1);
    pageLayout->addWidget(runButton,5,1,1,1);
    pl0Page->setLayout(pageLayout);
}

void MainWindow::pl0printf(QString s){
    pl0TextEdit->moveCursor(QTextCursor::End);
    pl0TextEdit->insertPlainText("\n"+s);
}

void MainWindow::printfs(const char* s){
    QString qs=QString(s);
    pl0printf(qs);
}
void MainWindow::printcs(const char c){
    QString qs=QString(c);
    pl0printf(qs);
}
void MainWindow::printls(const char *s0, long v){
    QString qs=QString(s0)+QString::number(v);
    pl0printf(qs);
}
void MainWindow::printrs(const char *s0, float v){
    QString qs=QString(s0)+QString("%1").arg(0);
    pl0printf(qs);
}
