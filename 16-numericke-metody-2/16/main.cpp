#include <fstream>
#include <iostream>

using namespace std;

void nacti_ze_souboru(const string filename, double **&matrix, ulong &Nsize);
void tiskni_matici(double **matrix, const ulong Nsize);
void eliminacni_metoda(double **matrix, const ulong Nsize, double Xs[]);

int main() {
  double **matrix = nullptr;
  ulong Nsize;

  // cout << "Before: " << matrix << endl;

  nacti_ze_souboru("/home/hlina/Programming/School/maturita/"
                   "16-numericke-metody-2/16/matrix.txt",
                   matrix, Nsize);
  // cout << "After: " << matrix << endl;
  // cout << matrix[0] << endl;

  double Xs[Nsize];

  tiskni_matici(matrix, Nsize);

  eliminacni_metoda(matrix, Nsize, Xs);

  // Cleanup dyn 2d array
  for (ulong i = 0; i < Nsize; ++i) {
    delete[] matrix[i];
  }
  delete[] matrix;

  return 0;
}

void eliminacni_metoda(double **matrix, const ulong Nsize, double Xs[]) {
  // Eliminacni metoda
  for (int k = 0; k < Nsize - 1; k++) {
    for (int i = k + 1; i < Nsize; i++) {
      double multiplier = matrix[i][k] / matrix[k][k];
      for (int j = k + 1; j < Nsize + 1; j++) {
        matrix[i][j] -= multiplier * matrix[k][j];
      }
    }
  }

  tiskni_matici(matrix, Nsize);

  // Diskuze
  if (matrix[Nsize - 1][Nsize - 1] == 0.0) {
    if (matrix[Nsize - 1][Nsize] == 0.0) {
      cout << "Nekonecne mnoho reseni" << endl;
    } else {
      cout << "Zadne reseni" << endl;
    }
  } else {
    // Zpetny chod
    Xs[Nsize - 1] = matrix[Nsize - 1][Nsize] / matrix[Nsize - 1][Nsize - 1];

    for (int k = Nsize - 2; k >= 0; k--) {
      for (int i = Nsize - 1; i >= k + 1; i--) {
        matrix[k][Nsize] -= matrix[k][i] * Xs[i];
      }
      Xs[k] = matrix[k][Nsize] / matrix[k][k];
    }

    cout << "Koreny:" << endl;
    for (int i = 0; i < Nsize; i++) {
      cout << Xs[i] << ' ';
    }
  }
}

void nacti_ze_souboru(string filename, double **&matrix, ulong &Nsize) {
  ifstream file(filename);
  if (!file.is_open()) {
    cout << "File didnt opened" << endl;
    return;
  }

  file >> Nsize;
  // cout << "Nsize: " << Nsize << endl;

  // cout << matrix << endl;
  matrix = new double *[Nsize];
  // cout << matrix << endl;

  for (ulong i = 0; i < Nsize; ++i) {
    matrix[i] = new double[Nsize + 1];
  }
  // cout << matrix << endl;

  for (ulong row = 0; row < Nsize; ++row) {
    for (ulong column = 0; column < Nsize + 1; ++column) {
      file >> matrix[row][column];
    }
  }
  // cout << matrix << endl;

  file.close();
}

void tiskni_matici(double **matrix, const ulong Nsize) {
  for (ulong row = 0; row < Nsize; ++row) {
    for (ulong column = 0; column < Nsize + 1; ++column) {
      cout << matrix[row][column] << ' ';
    }
    cout << endl;
  }
  cout << endl;
}
