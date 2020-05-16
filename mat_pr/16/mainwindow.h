#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QColorDialog>
#include <QFile>
#include <QFileDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QTextStream>

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

private slots:
  void on_actionAbout_triggered();

  void on_actionCopy_triggered();

  void on_actionCut_triggered();

  void on_actionPaste_triggered();

  void on_actionExit_triggered();

  void on_actionNew_triggered();

  void on_actionBackground_triggered();

  void on_actionPen_triggered();

  void on_actionSave_triggered();

  void on_actionOpen_triggered();

private:
  Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
