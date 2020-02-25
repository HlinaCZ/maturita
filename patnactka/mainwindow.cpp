#include "mainwindow.h"
#include "ui_mainwindow.h"

const uint8_t SIZE = 4;
const uint8_t BTNSIZE = 100;
const int EMPTYNUM = 16;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  initGameField();
  // qDebug() << "Should be true:" << isSolved();
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::initGameField() {
  int btnNumber = 0;
  for (int i = 0; i < SIZE; ++i) {
    for (int j = 0; j < SIZE; ++j) {
      btnNumber++;
      numberMatrix[i][j] = btnNumber;

      field[i][j] = new QPushButton(this);
      field[i][j]->setMaximumSize(BTNSIZE, BTNSIZE);
      field[i][j]->setText(QString::number(btnNumber));
      field[i][j]->connect(field[i][j], SIGNAL(clicked()), this,
                           SLOT(doStuff()));
      ui->gridLayout->addWidget(field[i][j], i, j);
    }
  }
}

// x and y are return parameters
void MainWindow::getpos(int number, int &x, int &y) {
  for (int i = 0; i < SIZE; ++i) {
    for (int j = 0; j < SIZE; ++j) {
      if (numberMatrix[i][j] == number) {
        x = j;
        y = i;
        return;
      }
    }
  }
}

bool MainWindow::isSolved() {
  int number = 0;

  for (int row = 0; row < SIZE; ++row) {
    for (int column = 0; column < SIZE; ++column) {
      number++;
      if (number == 16)
        break;
      if (numberMatrix[row][column] != number)
        return false;
    }
  }
  return true;
}

void MainWindow::doStuff() {
  int x, y;

  QPushButton *btn = (QPushButton *)QObject::sender();

  if (btn->text() == "")
    return;

  getpos(btn->text().toInt(), x, y);

  moveUp(x, y);
  moveDown(x, y);
  moveLeft(x, y);
  moveRight(x, y);

  redraw();
}

void MainWindow::on_pushButton_clicked() {
  int x = 3, y = 3;
  for (int mixCount = 0; mixCount < 50; ++mixCount) {
    getpos(16, x, y);
    redraw();
    int dir = rand() % 4;
    switch (dir) {
    case 0:
      // move 16 down = move lower btn up
      moveUp(x, y + 1);
      break;
    case 1:
      // move 16 left = move left btn right
      moveRight(x - 1, y);
      break;
    case 2:
      // move 16 up = move upper btn down
      moveDown(x, y - 1);
      break;
    case 3:
      // move 16 right = move right btn left
      moveLeft(x + 1, y);
      break;
    }
  }
  // qDebug() << "Should be false: " << isSolved();
}

void MainWindow::redraw() {
  for (int i = 0; i < SIZE; ++i) {
    for (int j = 0; j < SIZE; ++j) {
      if (numberMatrix[i][j] == EMPTYNUM)
        field[i][j]->setText("");
      else
        field[i][j]->setText(QString::number(numberMatrix[i][j]));
    }
  }
}

void MainWindow::moveUp(int x, int y) {
  if ((y >= 0 && y <= 3) && (numberMatrix[y - 1][x] == EMPTYNUM)) {
    numberMatrix[y - 1][x] = numberMatrix[y][x];
    numberMatrix[y][x] = EMPTYNUM;
  }
}
void MainWindow::moveRight(int x, int y) {
  if ((x <= 3 && x >= 0) && (numberMatrix[y][x + 1] == EMPTYNUM)) {
    numberMatrix[y][x + 1] = numberMatrix[y][x];
    numberMatrix[y][x] = EMPTYNUM;
  }
}

void MainWindow::moveDown(int x, int y) {
  if ((y <= 3 && y >= 0) && (numberMatrix[y + 1][x] == EMPTYNUM)) {
    numberMatrix[y + 1][x] = numberMatrix[y][x];
    numberMatrix[y][x] = EMPTYNUM;
  }
}

void MainWindow::moveLeft(int x, int y) {
  if ((x >= 0 && x <= 3) && (numberMatrix[y][x - 1] == EMPTYNUM)) {
    numberMatrix[y][x - 1] = numberMatrix[y][x];
    numberMatrix[y][x] = EMPTYNUM;
  }
}

// Tried to make it solve itself -- this isn't
// solution at all
void MainWindow::on_pushButton_2_clicked() {
  int x, y;
  do {
    getpos(16, x, y);
    redraw();
    // std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    int dir = rand() % 4;
    switch (dir) {
    case 0:
      // move 0 down = move lower btn up
      moveUp(x, y + 1);
      break;
    case 1:
      // move 0 left = move left btn right
      moveRight(x - 1, y);
      break;
    case 2:
      // move 0 up = move upper btn down
      moveDown(x, y - 1);
      break;
    case 3:
      // move 0 right = move right btn left
      moveLeft(x + 1, y);
      break;
    }
  } while (!isSolved());
}
