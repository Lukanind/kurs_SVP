#include "mainwindow.h"
#include <QApplication>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  MainWindow w;
  w.show();

  ofstream out;
  out.open("date.txt");
  if (out.is_open()){
      qDebug("open");
  }
  else qDebug("no");
  out.close();
  return a.exec();
}
