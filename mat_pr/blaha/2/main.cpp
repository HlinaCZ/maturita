#include <iostream>

std::string encode(std::string originalMessage, std::string keyword);

int main() {
  std::string originalMessage, keyword;

  std::cout << "Message to encode: ";
  std::cin >> originalMessage;
  std::cout << "Keyword for encoding: ";
  std::cin >> keyword;

  std::string encodedMessage = encode(originalMessage, keyword);
  std::cout << encodedMessage << std::endl;
}

std::string encode(std::string originalMessage, std::string keyword) {
  std::string encodedMessage = "";

  for (int charIndex = 0; charIndex < originalMessage.size(); ++charIndex) {
    int keywordIndex = charIndex % keyword.size();
    int shift = keyword[keywordIndex] - 64;
    char shiftedChar =
        ((originalMessage[charIndex] + shift) > (int)'Z')
            ? originalMessage[charIndex] + shift - ((int)'Z' - (int)'A') - 1
            : originalMessage[charIndex] + shift;
    encodedMessage += shiftedChar;
  }

  return encodedMessage;
}
