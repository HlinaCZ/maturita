#include <iostream>

// zadani
void decimal_to_binary(unsigned char input, char *output);
void binary_to_decimal(char *input, unsigned char &output);

int main() {
  char number_in_binary[9];
  decimal_to_binary(0xF1, number_in_binary);
  std::cout << number_in_binary << std::endl;

  unsigned char number;
  binary_to_decimal(number_in_binary, number);
  std::cout << static_cast<int>(number) << std::endl;

  return 0;
}

void decimal_to_binary(unsigned char input, char *output) {
  for (int i = 7; i >= 0; i--) {
    output[i] = input % 2 + 48;
    input = input / 2;
  }
  output[8] = 0;
}

void binary_to_decimal(char *input, unsigned char &output) {}
