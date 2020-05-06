#include <iostream>
#include <time.h>

#define SIZE 25

void sort(int *);
void print(int *);
bool binary_search(int *, int);

int main(int argc, char ** agrv) {
	srand(time(nullptr));

	int array[SIZE];
	for(int i = 0; i < SIZE; i++) {
		array[i] = rand()%100;
	}

	sort(array);
	print(array);

	int searchNumber;
	std::cout << "Input number to search in array." << std::endl;
	std::cin >> searchNumber;
	std::cout << std::endl;

	bool isInArray = binary_search(array, searchNumber);
	std::cout << "Is number in array: " << isInArray << std::endl;

	return 0;
}

void sort(int * array) {
	// starts from index = 1
	// search for value lower than previous value
	// switch value with previous values until the value is higher then value on the left
	for(int i = 1; i < SIZE; i++) {
		int j = i;
		while (array[j] < array[j-1] && j > 0) {
			int tmp = array[j];
			array[j] = array[j-1];
			array[j-1] = tmp;
			j--;
		}
	}
}

void print(int * array) {
	for(int i = 0; i < SIZE; i++) {
		std::cout << array[i] << ' ';
	}
	std::cout << std::endl;
}

bool binary_search(int * array, int searchNumber) {
	int min = 0, max = SIZE - 1, mid;

	while(min != max) {
		std::cout << "min: " << min << " max: " << max << std::endl;
		mid = (min+max)/2;
		if(searchNumber == array[mid]) {
			return true;
		} else if(searchNumber > array[mid]) {
			min = mid;
		} else {
			max = mid;
		}
	}
	std::cout << std::endl;

	return false;
}
