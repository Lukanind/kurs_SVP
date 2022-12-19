#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtMath>
#include <fstream>
#include <QFile>
#include <QTextStream>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  x_begin = -10;
  x_end = 10;
  h = 0.1;

  ui->widget->xAxis->setRange(-10, 10);
  ui->widget->yAxis->setRange(-10, 10);

  ui->widget->xAxis->setLabel("x");
  ui->widget->yAxis->setLabel("y");

}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::on_button_clicked()
{
  ui->widget->clearGraphs();
  A = ui->A_Edit->value();
  W = ui->W_Edit->value();
  F = ui->F_Edit->value();
  if (A > 10) ui->widget->yAxis->setRange(-1.5*A, 1.5*A);
  if (A <= 10) ui->widget->yAxis->setRange(-10, 10);
  for (X = x_begin; X <= x_end; X += h){
      x.push_back(X);
      y.push_back(A*sin(W*X+F));
    }
  ui->widget->addGraph();
  ui->widget->graph(0)->addData(x,y);
  ui->widget->replot();

  bufer = to_string(A) + " " + to_string(W) + " " + to_string(F);
  date.push_back(QString::fromStdString(bufer));


  x.clear();
  y.clear();
}

void MainWindow::on_pushButton_clicked()
{
  QFile file("test.txt");
  if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
    qDebug("open");
    QTextStream writeStream(&file);
    for (int i = 0; i < date.size(); i++){
      writeStream << date[i] << endl;
    }
    file.close();
  }
  QWidget::close();
}
