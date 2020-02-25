#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QMainWindow>
#include <QPushButton>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

  QPushButton *field[4][4];
  int numberMatrix[4][4];

private slots:
  void getpos(int number, int &x, int &y);
  void doStuff();
  void moveUp(int x, int y);
  void moveRight(int x, int y);
  void moveDown(int x, int y);
  void moveLeft(int x, int y);
  void redraw();
  bool isSolved();

  void on_pushButton_clicked();

  void on_pushButton_2_clicked();

private:
  Ui::MainWindow *ui;

  void initGameField();
};
#endif // MAINWINDOW_H
