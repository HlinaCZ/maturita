#include "retezce.h"
#include <cstring>
#include <iostream>

using namespace std;

int main() {
  char a[20], *b;
  for (long i = 0; i < 7700; ++i) {
    strcpy(b + i, "A");
  }
  strcpy(a, b);
  cout << a << endl;

  strdel(a, 1, 2);
  cout << a << endl;

  strins(a, "hooo", 1);
  cout << a << endl;

  return 0;
}
