#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <string>
#include <vector>
#include<fstream>
#include <QFile>
#include <QString>

namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();
  std::vector <QString> date;
  std::string bufer;

private slots:
  void on_button_clicked();

  void on_pushButton_clicked();

private:
  Ui::MainWindow *ui;
  double x_begin, x_end, h, X, A, W, F;
  int n;
  QVector <double> x, y;

};

#endif // MAINWINDOW_H
