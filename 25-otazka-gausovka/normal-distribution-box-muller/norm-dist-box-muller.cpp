#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>
#include <limits>

const double mean = 1.34, standardDeviation = 0.023;
const int nrolls = 100000;

double normal_distribution(const double mean, const double standardDeviation);

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

double normal_distribution(const double mean, const double standardDeviation) {
  // double random1 = rand()/(double)RAND_MAX;
  // double random2 = rand()/(double)RAND_MAX;
  // double z0 = std::sqrt(-2.0*std::log(random1)*std::cos(2*pi*random2));
  // double z1 = std::sqrt(-2.0*std::log(random1)*std::sin(2*pi*random2));
  // double number = z0*standardDeviation + mean;

  static const double epsilon = std::numeric_limits<double>::min();
  static const double two_pi = 2.0 * 3.14159265358979323846;

  thread_local double z1;
  thread_local bool generate;
  generate = !generate;

  if (!generate)
    return z1 * standardDeviation + mean;

  double u1, u2;
  do {
    u1 = rand() * (1.0 / RAND_MAX);
    u2 = rand() * (1.0 / RAND_MAX);
  } while (u1 <= epsilon);

  double z0;
  z0 = sqrt(-2.0 * log(u1)) * cos(two_pi * u2);
  z1 = sqrt(-2.0 * log(u1)) * sin(two_pi * u2);
  return z0 * standardDeviation + mean;
}
