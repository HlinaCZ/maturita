#include <iostream>
#include <random> // This is c++11 feature

const double mean = 1.34, standardDeviation = 0.023;
const int nrolls = 100000;

int main() {
  std::default_random_engine generator;
  std::normal_distribution<double> distribution(mean, standardDeviation);

  int result = 0;

  for (int i = 0; i < nrolls; ++i) {
    double number = distribution(generator);
    if ((number >= 1.37) || (number <= 1.31))
      ++result;
  }

  std::cout << (double)result / nrolls;

  return 0;
}
