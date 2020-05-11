#include <ctime>
#include <iostream>

struct Node {
  Node *next = nullptr;
  int value;
};

int main() {
  srand(time(nullptr));

  Node *queue = nullptr, *stack = nullptr;

  for (int i = 0; i < 1000; i++) {
    int random = rand() % 100;
    if (random % 2 == 0) {
      // Stack
      Node *newNode = new Node;
      newNode->value = random;
      newNode->next = stack;
      stack = newNode;
    } else {
      // Queue
      Node *newNode = new Node;
      newNode->value = random;
      if (queue == nullptr) {
        queue = newNode;
      } else {
        Node *crawler = queue;
        while (crawler != nullptr && crawler->next != nullptr) {
          crawler = crawler->next;
        }

        crawler->next = newNode;
      }
    }
  }

  Node *crawler = queue;
  while (crawler != nullptr && crawler->next != nullptr) {
    std::cout << crawler->value << ' ';
    crawler = crawler->next;
  }
  std::cout << crawler->value << ' ';
  std::cout << std::endl;

  crawler = stack;
  while (crawler != nullptr && crawler->next != nullptr) {
    std::cout << crawler->value << ' ';
    crawler = crawler->next;
  }
  std::cout << crawler->value << ' ';
  std::cout << std::endl;
}
