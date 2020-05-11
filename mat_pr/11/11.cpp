#include <ctime>
#include <iostream>

const int size = 64;

void sort(int array[size]);

int main() {
  srand(time(nullptr));

  int array[size];

  for (int i = 0; i < size; i++) {
    array[i] = rand();
    std::cout << array[i] << " ";
  }
  std::cout << std::endl;

  sort(array);

  for (int i = 0; i < size; i++) {
    std::cout << array[i] << " ";
  }
  std::cout << std::endl;

  bool isInArray = false;
  int inputNumber;
  std::cout << "Enter number you are looking for: ";
  std::cin >> inputNumber;

  for (int i = 0; i < size; i++) {
    if (inputNumber == array[i]) {
      isInArray = true;
      break;
    }
  }
  std::cout << "Number " << inputNumber << " is " << (isInArray ? "" : "not ")
            << "in array." << std::endl;
}

void sort(int array[size]) {
  for (int i = 0; i < size - 1; i++) {
    int j = i + 1;

    while (j != 0 && array[j] < array[j - 1]) {
      int tmp = array[j];
      array[j] = array[j - 1];
      array[j - 1] = tmp;
      j--;
    }
  }
}
