#include "mainwindow.h"
#include "ui_mainwindow.h"

constexpr double function(double x) {
  return x * x * x + 3 * x * x - 19 * x - 22;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_pushButton_clicked() {
  double x1, x2, x0, precision = 0.0001;
  x1 = ui->lineEdit->text().toDouble();
  x2 = ui->lineEdit_2->text().toDouble();

  if (function(x1) * function(x2) < 0) {
    do {
      x0 = x1 - function(x1) * (x2 - x1) / (function(x2) - function(x1));

      if (function(x1) * function(x0) < 0) {
        x2 = x0;
      } else {
        x1 = x0;
      }

    } while (fabs(function(x0)) > precision);

    ui->lineEdit_3->setText(QString::number(x0));
  } else {
    QMessageBox messageBox;
    messageBox.critical(0, "Error", "An error has occured !");
    messageBox.setFixedSize(500, 200);
  }
}

void MainWindow::on_pushButton_2_clicked() {
  const double h = 0.001, precision = 0.0001;
  double x0, x1 = ui->lineEdit->text().toDouble();

  do {
    x0 = x1 - (h * function(x1)) / (function(x1 + h) - function(x1));
    x1 = x0;
  } while (fabs(function(x0)) > precision);

  ui->lineEdit_4->setText(QString::number(x0));
}
