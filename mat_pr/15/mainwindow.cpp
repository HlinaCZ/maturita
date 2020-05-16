#include "mainwindow.h"
#include "ui_mainwindow.h"

bool setX = true;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 15; j++) {
      QPushButton *btn = new QPushButton;

      connect(btn, SIGNAL(clicked()), this, SLOT(fill()));

      ui->gridLayout->addWidget(btn, i, j);
    }
  }
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::fill() {
  QPushButton *btn = (QPushButton *)QObject::sender();

  if (btn->text() == "") {
    btn->setText(setX ? "x" : "0");
    setX = !setX;
  }
}
