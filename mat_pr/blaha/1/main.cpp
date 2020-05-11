#include <ctime>
#include <iostream>

const unsigned int max = 101;

void random_fill(char number[max]);
void print_number(char number[max]);

int main() {
  srand(time(nullptr));

  char first_number[max];
  char second_number[max];
  char result_number[max];

  random_fill(first_number);
  random_fill(second_number);

  // first_number[0] = 9;
  // second_number[0] = 9;

  for (int i = 0; i < max; i++) {
    first_number[i] -= 48;
    second_number[i] -= 48;
  }

  int add_one = 0;
  for (int digit = 0; digit < max; digit++) {
    if (first_number[digit] == -48 || second_number[digit] == -48) {
      add_one += 48;
    }
    if (first_number[digit] + second_number[digit] + add_one > 9) {
      result_number[digit] =
          first_number[digit] + second_number[digit] + add_one - 10;
      add_one = 1;
    } else {
      result_number[digit] =
          first_number[digit] + second_number[digit] + add_one;
      add_one = 0;
    }
  }

  print_number(first_number);
  print_number(second_number);
  std::cout << std::endl;
  print_number(result_number);
}

void random_fill(char number[max]) {
  int count = rand() % 50 + 51;
  for (int i = 0; i < count; i++) {
    number[i] = rand() % 10 + 48;
  }
  for (int i = max; i > count; i--) {
    number[i] = 0;
  }
}

void print_number(char number[max]) {
  for (int i = max - 1; i >= 0; i--) {
    if (number[i] == -48)
      std::cout << ' ';
    else
      std::cout << (char)(number[i] + 48);
  }
  std::cout << std::endl;
}
