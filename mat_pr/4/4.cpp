#include <fstream>
#include <iostream>

const int max = 100;

void quicksort(int arr[], int start, int end);
void print_array(int arr[], int size);
void remove(int arr[], int index, int size);

int main() {
  int A[max];

  std::ifstream file(
      "/home/hlina/Programming/School/maturita/mat_pr/4/DATA.txt");
  if (!file.is_open()) {
    std::cout << "Couldn't find the file" << std::endl;
  }

  int count = 0;
  while (file >> A[count]) {
    count++;
  }

  quicksort(A, 0, count - 1);

  int lastNumber = A[0];
  for (int i = 1; i < count; i++) {
    if (lastNumber == A[i]) {
      remove(A, i, count);
      count--;
    }
    lastNumber = A[i];
  }

  print_array(A, count);

  int C;
  std::cout << "Value to insert: ";
  std::cin >> C;

  if (C > A[count - 1]) {
    A[count] = C;
    count++;
  } else {
    for (int i = 0; i < count; i++) {
      if (C < A[i]) {
        for (int j = count; j > i; j--) {
          A[j] = A[j - 1];
        }
        A[i] = C;
        count++;
        break;
      }
    }
  }

  print_array(A, count);

  file.close();
}

void quicksort(int arr[], int start, int end) {
  int middle = (start + end) / 2, lower = start, higher = end;

  do {
    while (lower <= higher && arr[lower] < arr[middle])
      lower++;
    while (higher >= lower && arr[higher] > arr[middle])
      higher--;
    if (lower <= higher) {
      int tmp = arr[lower];
      arr[lower] = arr[higher];
      arr[higher] = tmp;
      lower++;
      higher--;
    }
  } while (lower <= higher);

  if (lower < end)
    quicksort(arr, lower, end);
  if (higher > start)
    quicksort(arr, start, higher);
}

void print_array(int arr[], int size) {
  for (int i = 0; i < size; ++i) {
    std::cout << arr[i] << ' ';
  }
  std::cout << std::endl;
}

void remove(int arr[], int index, int size) {
  for (int i = index; i < size - 1; i++) {
    arr[i] = arr[i + 1];
  }
}
