#include <cmath>
#include <ctime>
#include <iostream>

const double mean = 1.34, standardDeviation = 0.023;
const int nrolls = 100000;

double normal_distribution(const double mean,
                           const double standardDeviation);

int main() {
  srand(std::time(NULL));

  int result = 0;

  for (int i = 0; i < nrolls; ++i) {
    double number = normal_distribution(mean, standardDeviation);
    if ((number >= 1.37) || (number <= 1.31))
      ++result;
  }

  std::cout << (double)result / nrolls;

  return 0;
}

double normal_distribution(const double mean,
                           const double standardDeviation) {
  double u, v, s;
  do {
  u = rand() / (double)RAND_MAX;
  v = rand() / (double)RAND_MAX;
  s = u*u+v*v;
  } while (s >= 1.0 || s == 0.0);
  s = sqrt(-2.0 * log(s) / s);
  return mean + u * s * standardDeviation;
}
