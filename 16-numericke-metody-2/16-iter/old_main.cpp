#include <cmath>
#include <fstream>
#include <iostream>

using namespace std;

struct Matrix {
  double field[10][10];
  int rows, columns;
  double Xs[100];
};

void loadMatrix(char fileName[200], Matrix &matrix) {
  ifstream file(fileName);
  if (!file.is_open()) {
    cout << "MISSION FAILED WE WILL GET THEM NEXT TIME!!!" << endl;
    return;
  }

  file >> matrix.rows;
  matrix.columns = matrix.rows + 1;

  for (int row = 0; row < matrix.rows; ++row) {
    for (int column = 0; column < matrix.columns; ++column) {
      file >> matrix.field[row][column];
    }
  }
  file.close();
}

void printMatrix(Matrix matrix) {
  for (int row = 0; row < matrix.rows; ++row) {
    for (int column = 0; column < matrix.columns; ++column) {
      cout << matrix.field[row][column] << "  ";
    }
    cout << endl;
  }
  cout << endl;
}

void interateMatrix(Matrix matrix) {
  printMatrix(matrix);
  double x;
  for (int row = 0; row < matrix.rows; row++) {
    for (int column = 0; column < matrix.columns; column++) {

      if (row != column) {
        matrix.field[row][column] /= matrix.field[row][row];
      }
    }
    matrix.field[row][row] = 0;
  }
  printMatrix(matrix);

  for (int i = 0; i < matrix.rows; i++)
    matrix.Xs[i] = 1;

  double sum;

  do {
    x = matrix.Xs[0];
    for (int row = 0; row < matrix.rows; row++) {
      sum = matrix.field[row][matrix.columns - 1];
      cout << sum << endl;
      for (int column = 0; column < matrix.rows; column++) {
        sum = sum - matrix.field[row][column] * matrix.Xs[column];
      }
      matrix.Xs[row] = sum;
    }
    for (int i = 0; i < matrix.rows; i++)
      cout << "X" << i << " = " << matrix.Xs[i] << endl;
    cout << endl;
  } while (fabs(x - matrix.Xs[0]) > 0.000001);
  for (int i = 0; i < matrix.rows; i++)
    cout << "X" << i << " = " << matrix.Xs[i] << endl;
}

int main() {
  Matrix matrixA;
  loadMatrix("../16-iter/Matice.txt", matrixA);
  printMatrix(matrixA);
  interateMatrix(matrixA);
  return 0;
}
