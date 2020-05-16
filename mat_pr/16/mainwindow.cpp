#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_actionAbout_triggered() {
  QMessageBox::about(this, "About", "c++ ide 9.0.1");
}

void MainWindow::on_actionCopy_triggered() { ui->textEdit->copy(); }

void MainWindow::on_actionCut_triggered() { ui->textEdit->cut(); }

void MainWindow::on_actionPaste_triggered() { ui->textEdit->paste(); }

void MainWindow::on_actionExit_triggered() { MainWindow::close(); }

void MainWindow::on_actionNew_triggered() { ui->textEdit->setText(""); }

void MainWindow::on_actionBackground_triggered() {
  ui->textEdit->setTextBackgroundColor(QColorDialog::getColor());
}

void MainWindow::on_actionPen_triggered() {
  ui->textEdit->setTextColor(QColorDialog::getColor());
}

void MainWindow::on_actionSave_triggered() {
  QString filename = QFileDialog::getSaveFileName(this, "Save file");

  QFile file(filename);
  if (!file.open(QFile::WriteOnly))
    return;

  QTextStream out(&file);
  out << ui->textEdit->toPlainText();

  file.close();
}

void MainWindow::on_actionOpen_triggered() {
  QString filename = QFileDialog::getOpenFileName(this, "Open file");

  QFile file(filename);
  if (!file.open(QFile::ReadOnly))
    return;

  QTextStream in(&file);
  ui->textEdit->setText(in.readAll());

  file.close();
}
