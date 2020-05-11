#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  int numbers[10] = {7, 8, 9, 4, 5, 6, 1, 2, 3, 0};

  for (int i = 0; i < 10; i++) {
    int number = numbers[i], row = i / 3, column = i % 3;

    QPushButton *newButton = new QPushButton;
    newButton->setText(QString::number(number));

    connect(newButton, &QPushButton::clicked, this, &MainWindow::add_number);

    ui->gridLayout_2->addWidget(newButton, row, column);
  }
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_pushButton_clicked() { ui->lineEdit->setText("0"); }

void MainWindow::on_pushButton_2_clicked() { ui->lineEdit_2->setText("0"); }

void MainWindow::add_number() {
  QPushButton *btn = qobject_cast<QPushButton *>(sender());

  if (ui->lineEdit_2->text() == "0") {
    ui->lineEdit_2->setText(btn->text());
  } else {
    ui->lineEdit_2->insert(btn->text());
  }
}

void MainWindow::on_pushButton_3_clicked() {
  int number = ui->lineEdit_2->text().toInt(),
      result = ui->lineEdit->text().toInt() + number;
  ui->lineEdit->setText(QString::number(result));
}

void MainWindow::on_pushButton_4_clicked() {
  int number = ui->lineEdit_2->text().toInt(),
      result = ui->lineEdit->text().toInt() - number;
  ui->lineEdit->setText(QString::number(result));
}
