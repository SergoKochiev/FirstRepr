#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCharts>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    QValueAxis* axisX =  new QValueAxis ();
    QValueAxis* axisY =  new QValueAxis ();


    QChart* NewChar= 0 ;
    QChartView* ChartView =0 ;

private:
    Ui::MainWindow *ui;

public slots:
   void NewCharF();
   void Delete();
};

#endif // MAINWINDOW_H
