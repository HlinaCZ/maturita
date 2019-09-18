#include <iostream>
#include <fstream>

int const N = 50;

void init_bool_array(bool *beach);
void sieve(bool *beach, std::ofstream& file);

int main() {
  bool beach[N];
  std::ofstream file;

  file.open("file.txt");

  init_bool_array(beach);
  sieve(beach, file);

  file.close();

  return 0;
}

// Predpokladejme ze vsechna cisla jsou prvocisla
void init_bool_array(bool *beach) {
  for (int i = 0; i < N; ++i) {
      beach[i] = true;
    }
}

void sieve(bool *beach, std::ofstream& file)
{
  for (int i = 2; i < N; ++i)
    {
      if (beach[i])
        {
          // Nasli jsme prvocislo i
          std::cout << i << " ";
          file << i << " ";
          // Smazat vsechny nasobky i
          for (int j = i*2; j < N; j += i)
            {
              beach[j] = false;
            }
        }
      else
        {
          // Neni prvocislo
        }
    }
}


/* Original program with vectors
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

std::vector<int> make_primelist(int max);
void fill_vector(std::vector<int> *prime_list, int max);
void sito(std::vector<int> *prime_list, int max);
void print_vector(std::vector<int> &prime_list);

int main()
{
  int max;
  std::cout << "Please, input max number" << std::endl;
  std::cin >> max;
  std::vector<int> prime_list = make_primelist(max);
  print_vector(prime_list);
  std::ofstream f("file.txt");
  if (!f.is_open()){
      std::cout << "Failed to open file" << std::endl;
  } else {
      for (int prime : prime_list) {
          f << prime << ' ';
      }
  }
  f.close();
  return 0;
}

std::vector<int> make_primelist(int max)
{
  std::vector<int> *prime_list = new std::vector<int>;

  fill_vector(prime_list, max);
  sito(prime_list, max);

  return *prime_list;
}

void fill_vector(std::vector<int> *prime_list, int max)
{
  for (int i = 2; i < max; ++i) {
      prime_list->push_back(i);
    }
}

void sito(std::vector<int> *prime_list, int max)
{
  for (int prime : *prime_list)
    {
      for (int i = prime*2; i <= max; i += prime)
        {
          prime_list->erase(std::remove(prime_list->begin(),prime_list->end(), i), prime_list->end());
        }
    }
}

void print_vector(std::vector<int> &prime_list)
{
  std::cout << "Prime numbers: " << std::endl;
  for (int prime : prime_list) {
      std::cout << prime << ' ';
    }
  std::cout << std::endl;
}

*/
