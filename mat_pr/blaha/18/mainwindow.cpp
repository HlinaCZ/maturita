#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_actionNovy_triggered() { ui->textEdit->setText(""); }

void MainWindow::on_actionO_programu_triggered() {
  QMessageBox msgBox;
  msgBox.setText("Jednoduchy textovy editor");
  msgBox.exec();
}

void MainWindow::on_actionVyjmout_triggered() { ui->textEdit->cut(); }

void MainWindow::on_actionKopirovat_triggered() { ui->textEdit->copy(); }

void MainWindow::on_actionVlozit_triggered() { ui->textEdit->paste(); }

void MainWindow::on_actionUlozit_jako_triggered() {
  QString filename = QFileDialog::getSaveFileName(this, "Ulozit jako ...");

  QFile file(filename);
  if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    return;

  QTextStream out(&file);
  QString programText = ui->textEdit->toPlainText();
  out << programText;

  file.close();
}

void MainWindow::on_actionOtevrit_triggered() {
  QString filename = QFileDialog::getOpenFileName(this, "Otevrit ...");

  QFile file(filename);
  if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    return;

  QTextStream in(&file);
  QString fileText = in.readAll();
  ui->textEdit->setText(fileText);

  file.close();
}
