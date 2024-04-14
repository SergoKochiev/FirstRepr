#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QChartView>
#include <QLineSeries>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);




//    NewChar->addSeries(NewLine);
//    NewChar->addSeries(NewLine2);



    connect(ui->ButtonAdd, SIGNAL(clicked(bool)), this, SLOT( NewCharF() ));
    connect(ui->ButtonDelete, SIGNAL(clicked(bool)), this, SLOT( Delete() ));
}


void MainWindow::NewCharF()
{

  NewChar = new QChart ();
  ChartView =  new QChartView ();

  qDebug()<< (NewChar) ;
  qDebug()<< (ChartView) ;

    ChartView->setChart(NewChar);

    ui->LayoutChar->addWidget(ChartView);

    QLineSeries* NewLine = new QLineSeries();
   // QLineSeries* NewLine2 = new QLineSeries();
    int X1, X2, X3, Y1, Y2, Y3;


    X1 = ui->LineX1->text().toInt();
    Y1 = ui->LineY1->text().toInt();

    X2 = ui->LineX2->text().toInt();
    Y2 = ui->LineY2->text().toInt();

    X3 = ui->LineX3->text().toInt();
    Y3 = ui->LineY3->text().toInt();

    NewLine->append(X1, Y1);
    NewLine->append(X2, Y2);
    NewLine->append(X3, Y3);

    NewChar->addSeries(NewLine);


    axisX->setTickCount(1);
    axisY->setTickCount(1);




    NewChar->createDefaultAxes();

    qDebug()<<X2<<Y2;
}

void MainWindow::Delete()
{
    delete NewChar; // удаление плоскости графика
    delete ChartView; // удаление представления
    NewChar =0;
    ChartView = 0;
    qDebug()<< (NewChar) ;
    qDebug()<< (ChartView) ;

}

MainWindow::~MainWindow()
{
    delete ui;
}
