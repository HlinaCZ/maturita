#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <string>

struct Node {
  Node *next;
  std::string word;
  int count;
};

int main() {
  std::ifstream file(
      "/home/hlina/Programming/School/maturita/mat_pr/10/soubor.txt");
  if (!file.is_open()) {
    std::cerr << "Couldn't open file with words" << std::endl;
  }

  Node *root = nullptr;
  std::string word;

  while (file >> word) {
    // converting to lowercase - need <algorithm> and <cctype>
    std::transform(word.begin(), word.end(), word.begin(), ::tolower);

    Node *crawler = root;
    while (crawler != nullptr && crawler->next != nullptr &&
           crawler->word != word) {
      crawler = crawler->next;
    }

    if (crawler != nullptr) {
      // found some node
      if (crawler->word == word) {
        crawler->count++;
      } else if (crawler->next == nullptr) {
        Node *newNode = new Node;
        newNode->word = word;
        newNode->count = 1;
        newNode->next = nullptr;
        crawler->next = newNode;
      } else {
        std::cerr << "Shouldn't happened" << std::endl;
      }
    } else {
      Node *newNode = new Node;
      newNode->word = word;
      newNode->count = 1;
      newNode->next = nullptr;
      root = newNode;
    }
  }

  Node *crawler = root;
  while (crawler != nullptr) {
    std::cout << crawler->word << ": " << crawler->count << std::endl;
    crawler = crawler->next;
  }

  file.close();
}
