# 1.
Sestavte program, který
a) převede desítková čísla  na dvojková
b) převede dvojková čísla na  desítková  

```cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_pushButton_clicked() {
  if (ui->lineEdit->text().toUtf8() == "")
    return;
  int deciamlNumber = ui->lineEdit->text().toInt();
  QString output = "";

  while (deciamlNumber != 0) {
    output.prepend(QString::number(deciamlNumber % 2));
    deciamlNumber /= 2;
  }

  ui->lineEdit_2->setText(output);
}

void MainWindow::on_pushButton_2_clicked() {
  if (ui->lineEdit_2->text().toUtf8() == "")
    return;

  QString binaryNumber = ui->lineEdit_2->text();
  int output = 0, exp = 1;

  for (int i = binaryNumber.length() - 1; i >= 0; --i) {
    output += binaryNumber.at(i).digitValue() * exp;
    exp *= 2;
  }

  ui->lineEdit->setText(QString::number(output));
}
```

# 2.
Sestavte program, který načte matici A ze souboru MATA.TXT  matici B ze souboru MATB.TXT pomocí funkce s parametry. V případě, že matice lze násobit, proveďte součin A * B . Matice A, B a jejich součin vypište na obrazovku.

```cpp
#include <iostream>
#include <fstream>

struct matrix {
    int width, height;
    int **data; // free at the end
};

void load_matrix(std::string filename, matrix& newMatrix);
void print_matrix(matrix A);
void multiply(matrix A, matrix B, matrix &C);

int main() {
    matrix A, B, C;
    load_matrix("/home/hlina/Programming/School/maturita/mat_pr/2/MATA.txt", A);
    print_matrix(A);

    load_matrix("/home/hlina/Programming/School/maturita/mat_pr/2/MATB.txt", B);
    print_matrix(B);

    multiply(A, B, C);
    print_matrix(C);

    // Free allocated memory
    delete[] A.data;
    delete[] B.data;
    delete[] C.data;

    return 0;
}


void load_matrix(std::string filename, matrix& newMatrix)
{
    std::fstream file(filename);
    if(!file.is_open()) {
        std::cerr << "Couldn't open file " << filename;
        return;
    }

    file >> newMatrix.height >> newMatrix.width;

    newMatrix.data = new int*[newMatrix.height];
    for (int i = 0; i < newMatrix.height; ++i) {
        newMatrix.data[i] = new int[newMatrix.width];
    }

    for (int i = 0; i <newMatrix.height; ++i) {
        for (int j = 0; j < newMatrix.width; ++j) {
            file >> newMatrix.data[i][j];
        }
    }

    file.close();
}

void print_matrix(matrix A)
{
    for (int i = 0; i < A.height; ++i) {
        for (int j = 0; j < A.width; ++j) {
            std::cout << A.data[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void multiply(matrix A, matrix B, matrix &C)
{
    if(A.width != B.height) {
        std::cerr << "Can't multiply matrices";
        return;
    }

    C.height = A.height;
    C.width = B.width;

    C.data = new int*[C.height];
    for (int i = 0; i < C.height; ++i) {
        C.data[i] = new int[C.width];
        for (int j = 0; j < C.width; ++j) {
            C.data[i][j] = 0;
        }
    }


    for (int i = 0; i < C.height; ++i) {
        for (int j = 0; j < C.width; ++j) {
            for (int k = 0; k < A.width; ++k) {
                C.data[i][j] += A.data[i][k] * B.data[k][j];
            }
        }
    }
}
```

# 3.
Výsledky závodu jsou  uvedeny v textovém souboru  ZAVOD.TXT ve tvaru:                 jméno závodníka a hodnocení (číslo) na každém řádku. Sestavte program, který seřadí závodníky podle dosažených výsledků a vypíše na obrazovku. Použijte pole záznamů (structure)

```cpp
#include <iostream>
#include <fstream>

struct zavodnik{
    std::string jmeno;
    int hodnoceni;
};

int main()
{
    zavodnik zavodnici[100];

    std::ifstream file("/home/hlina/Programming/School/maturita/mat_pr/3/ZAVOD.txt");
    if(!file.is_open()) {
        std::cerr << "Coulnd't open file" << std::endl;
    }

    int pocet = 0;

    while (file >> zavodnici[pocet].jmeno) {
        file >> zavodnici[pocet].hodnoceni;
        pocet++;
    }

    for (int i = 0; i < pocet-1; ++i) {
        for (int j = i; j < pocet-1; ++j) {
            if (zavodnici[j].hodnoceni > zavodnici[j + 1].hodnoceni) {
                zavodnik tmp = zavodnici[j + 1];
                zavodnici[j + 1] = zavodnici[j];
                zavodnici[j] = tmp;
            }
        }
    }

    for (int i = 0; i < pocet; ++i) {
        std::cout << zavodnici[i].jmeno << ' ' << zavodnici[i].hodnoceni << std::endl;
    }

    file.close();

    return 0;
}
```

# 4.
Sestavte program, který načte data z text. souboru  DATA.TXT do pole A(N), seřadí je vzestupně a vytiskne. Pak
 a) vyloučí vícekrát se opakující prvky a vytiskne
 b) do pole vloží na správné místo hodnotu C načtenou z klávesnice a vytiskne

```cpp
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
```

# 5.
Vytvořte program, který simuluje život ve společenství  mikroorganismů. Životní prostředí tvoří teoreticky nekonečně  čtverečkované pole. Každý mikroorganismus zaujímá plochu  jednoho čtverečku. První generaci vygenerujte náhodně. Další generace jsou vytvářeny následujícím algoritmem:
 - v políčku, které má právě tři sousedy vzniká nová buňka
 - mikroorganismy, které mají dva nebo tři sousedy, přežívají  - mikroorganismy, které mají jednoho nebo žádného  souseda, umírají na samotu
 - mikroorganismy, které mají čtyři a více sousedů,  umírají na nedostatek potravy
Délka života každého jedince je
 a) neomezená
 b) maximálně K generací pro zadané přirozené číslo K

```cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  srand(static_cast<unsigned char>(time(nullptr)));
  for (auto &row : new_generation) {
    for (auto &cell : row) {
      cell = rand() % 2;
    }
  }
  printArray();
  timer = new QTimer(this);
  connect(timer, SIGNAL(timeout()), this, SLOT(rerender()));
}

void MainWindow::printArray() {
  ui->textEdit->clear();
  for (const auto &row : new_generation) {
    QString ret = "";
    for (const auto &cell : row) {
      if (cell)
        ret += '*';
      else
        ret += ' ';
    }
    ui->textEdit->append(ret);
  }
}

void MainWindow::rerender() {
  std::copy(new_generation.begin(), new_generation.end(),
            old_generation.begin());

  for (unsigned long row = 1; row < new_generation.size(); row++) {
    for (unsigned long column = 1; column < new_generation.size(); column++) {
      unsigned long neighbours = countNeighbours(row, column);
      if ((neighbours == 2 && old_generation[row][column]) || neighbours == 3) {
        new_generation[row][column] = true;
      } else {
        new_generation[row][column] = false;
      }
    }
  }
  printArray();
}

unsigned long MainWindow::countNeighbours(unsigned long row,
                                          unsigned long column) {
  unsigned long neighbours = 0;
  for (auto i = row - 1; i <= row + 1; i++) {
    for (auto j = column - 1; j <= column + 1; j++) {
      if (!((i == row) && (j == column))) {
        if (old_generation[i][j])
          neighbours++;
      }
    }
  }
  return neighbours;
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_pushButton_clicked() {
  timer->setInterval(100);
  timer->start();
}
```

# 6.
Naprogramujte řazení čísel metodou  quicksort.

```cpp
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
```


# 7.
Napište program, který vygeneruje náhodná kladná čísla a vytvoří z nich dva seznamy. V prvním budou lichá čísla ve stejném pořadí jak byla generována (fronta), ve druhém budou sudá čísla v opačném pořadí než v jakém byla generována (zásobník). Oba seznamy vypište na obrazovku

```cpp
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
```

# 8.
Objekty – bankovní účet

```cpp
#include <iostream>
#include <string>

class BankovniUcet {
protected:
    std::string cisloUctu;
    int hotovost;

public:
    BankovniUcet(std::string ucet, int pocatecniCastka);

    void vypisUdaje();

    void vklad(int castkaVkladu);

    virtual int vyber(int castkaVyberu);

    virtual void prevod(int suma, BankovniUcet *ucet2);
};

class UcetsPoplatkem : public BankovniUcet {
    int Poplatek;

public:
    UcetsPoplatkem(std::string ucet, int pocatecniCastka, int poplatek);

    virtual int vyber(int castkaVyberu);

    virtual void prevod(int suma, BankovniUcet *ucet2);
};

int main() {
    BankovniUcet *ucet1, *ucet2;
    ucet1 = new UcetsPoplatkem("123456789", 10000, 3);
    ucet2 = new BankovniUcet("55555555", 10000);

    ucet1->vypisUdaje();
    ucet2->vypisUdaje();

    ucet1->vyber(100);
    ucet2->vyber(5000);

    ucet1->vypisUdaje();
    ucet2->vypisUdaje();

    ucet1->prevod(9000, ucet2);

    ucet1->vypisUdaje();
    ucet2->vypisUdaje();

    delete ucet1;
    delete ucet2;

    return 0;
}

UcetsPoplatkem::UcetsPoplatkem(std::string ucet, int pocatecniCastka, int poplatek) : BankovniUcet(ucet, pocatecniCastka), Poplatek(poplatek) {
}

int UcetsPoplatkem::vyber(int castkaVyberu) {
    if (hotovost > castkaVyberu + Poplatek) {
        hotovost -= castkaVyberu + Poplatek;
    } else {
        std::cout << "Neni dostatek penez" << std::endl;
    }
}

void UcetsPoplatkem::prevod(int suma, BankovniUcet *ucet2) {

    if (suma + Poplatek > hotovost) {
        std::cout << "Neni dostatek penez" << std::endl;
        return;
    }
    hotovost -= suma + Poplatek;
    ucet2->vklad(suma);
}

BankovniUcet::BankovniUcet(std::string ucet, int pocatecniCastka) : cisloUctu(ucet), hotovost(pocatecniCastka) {
}

void BankovniUcet::vypisUdaje() {
    std::cout << "Ucet: " << cisloUctu << "\nHotovost: " << hotovost << std::endl;
}

void BankovniUcet::vklad(int castkaVkladu) {
    if (castkaVkladu > 0) {
        hotovost += castkaVkladu;
    } else {
        std::cout << "Neni dostatek penez" << std::endl;
    }
}

int BankovniUcet::vyber(int castkaVyberu) {
    if (castkaVyberu > 0 && hotovost > castkaVyberu) {
        hotovost -= castkaVyberu;
        return castkaVyberu;
    }
    return -1;
}

void BankovniUcet::prevod(int suma, BankovniUcet *ucet2) {
    if (suma > hotovost) {
        return;
    }
    hotovost -= suma;
    ucet2->vklad(suma);
}
```

# 9.
Napište program, který vygeneruje náhodná celá čísla, vypíše je na obrazovku a uloží do pole. Pole seřadí a opět vypíše. Použijte některý  z uvedených řadících algoritmů – selectsort, insertsort, bubblesort. Pak načte hodnotu z klávesnice a vyhledá ji v uspořádaném poli. Vypíše zprávu na obrazovku.

```cpp
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
```

# 10.
V textovém souboru jsou slova různé délky oddělena od sebe mezerou.  Napište program, který zjistí kolikrát se každé slovo vyskytuje v daném textovém souboru ( lze použít pole structur nebo dynamický seznam ). Rozdíly mezi malými a velkými písmeny se ignorují.

```cpp
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
```

# 11.
Vytvořte binární soubor struktur pro evidenci výrobků ve skladu načtením dat z textového souboru. Textového soubor obsahuje alespoň 5 řádků. V každém řádku uvedeno: 
  název, cena/ks, min. množství, skut. množství 
Binární soubor zobrazte.
Vyhledejte v binárním souboru ty struktury, u kterých skutečné množství je menší než minimální množství a zobrazte je. Dále na obrazovku vypište sumu potřebnou k doplnění skladu na minimální množství. 

```cpp
#include <iostream>
#include <fstream>

// nazev, cena/ks, min. mnozstvi, skutecne mnozstvi
// txt --> bin (5 lines)
// print bin
// find product where real amount < min amount
// sum of amount need to fill minimum

struct Product {
	std::string name;
	unsigned int pricePerPiece, minimumQuantity, realQuantity;
};

int main(int argc, char ** argv) {
	Product product;
	std::ifstream textFile("text.txt");
	std::fstream binaryFile("binary.bin", std::ios::binary | std::ios::out | std::ios::trunc);
	std::string line;

	while(textFile >> product.name) {
		textFile >> product.pricePerPiece
			>> product.minimumQuantity
			>> product.realQuantity;
		binaryFile.write((char *)&product, sizeof(product));
	}

	binaryFile.close();
	binaryFile.open("binary.bin", std::ios::binary | std::ios::in);

	unsigned int sum = 0;

	while(binaryFile.read((char *)&product, sizeof(Product))) {
		std::cout << product.name << ' '
			<< product.pricePerPiece << ' '
			<< product.minimumQuantity << ' '
			<< product.realQuantity << ' '
			<< std::endl;
		if(product.realQuantity < product.minimumQuantity) {
			sum += product.minimumQuantity - product.realQuantity;
		}
	}

	std::cout << "Potrebujeme doplnit: " << sum << " kusu." << std::endl;

	textFile.close();
	binaryFile.close();
}
```

# 12.
Vytvořte aplikaci se dvěma formuláři podle následujícího obrázku:
1. Formulář MainWindow obsahuje 2 objekty timeEdit  a 2 tlačítka (viz. obrázek). 
2. Po zmáčknutí tlačítka Hodiny se v timeEdit zobrazuje aktuální čas. 
3. Do timeEdit _2 vepíšeme čas pro budík. Po zmáčknutí tlačítka Budík se kontroluje 
shoda obou objektů  timeEdit. V případě shody obou časů se zobrazí MessageBox vstavej a spusti se zvuk ( window.h) 

```cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timerClock = new QTimer(this);
    timerAlarm = new QTimer(this);
    connect(timerClock, SIGNAL(timeout()), this, SLOT(updateClock()));
    connect(timerAlarm, SIGNAL(timeout()), this, SLOT(checkAlarm()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateClock() {
    QTime time = QTime::currentTime();
    ui->timeEdit->setTime(time);
}

void MainWindow::checkAlarm() {
    if (ui->timeEdit->time() >= ui->timeEdit_2->time()) {
        player = new QMediaPlayer;
        player->setMedia(QUrl::fromLocalFile("/home/hlina/Programming/Škola/QT/Clock/oof.mp3"));
        player->setVolume(50);
        player->play();
        QMessageBox::about(this, "as", "ds");
        timerAlarm->stop();
    }
}

void MainWindow::on_pushButton_clicked()
{
    timerClock->start();
}

void MainWindow::on_pushButton_2_clicked()
{
    timerAlarm->start(1);
}
```

# 13.
1. Sestavte program, který metodou sečen vyřeší rovnici
 x3 + 3x2 - 5x - 2 = 0    s přesností 0,001
Řešení leží v intervalech <-1,0>, <1,2>, <-4,-5>

2. Sestavte program, který metodou tečen vyřeší rovnici 
 x3 - 3x - 1 = 0     s přesností 0,001

```cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"

constexpr double function(double x) {
  return x * x * x + 3 * x * x - 19 * x - 22;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_pushButton_clicked() {
  double x1, x2, x0, precision = 0.0001;
  x1 = ui->lineEdit->text().toDouble();
  x2 = ui->lineEdit_2->text().toDouble();

  if (function(x1) * function(x2) < 0) {
    do {
      x0 = x1 - function(x1) * (x2 - x1) / (function(x2) - function(x1));

      if (function(x1) * function(x0) < 0) {
        x2 = x0;
      } else {
        x1 = x0;
      }

    } while (fabs(function(x0)) > precision);

    ui->lineEdit_3->setText(QString::number(x0));
  } else {
    QMessageBox messageBox;
    messageBox.critical(0, "Error", "An error has occured !");
    messageBox.setFixedSize(500, 200);
  }
}

void MainWindow::on_pushButton_2_clicked() {
  const double h = 0.001, precision = 0.0001;
  double x0, x1 = ui->lineEdit->text().toDouble();

  do {
    x0 = x1 - (h * function(x1)) / (function(x1 + h) - function(x1));
    x1 = x0;
  } while (fabs(function(x0)) > precision);

  ui->lineEdit_4->setText(QString::number(x0));
}
```

# 14.
1. Sestavte program pro řešení soustavy lineárních rovnic iterační  metodou a vyřešte soustavu rovnic:
 4x1 + 2x2 + x3 = 11
 -x1 + 2x2 = 3
 2x1 + x2 + 4x3 = 16

```cpp
#include <cmath>
#include <fstream>
#include <iostream>

struct SoustavaRovnic {
  int pocetRovnic;
  double nezname[10];
  double Matice[10][10];
};

SoustavaRovnic *nacti_matici(std::string filename);
void tiskni_matici(SoustavaRovnic s);
void iteracni_metoda(SoustavaRovnic s);

int main() {
  SoustavaRovnic *s = nacti_matici("../16-iter/Matice.txt");
  tiskni_matici(*s);
  iteracni_metoda(*s);

  return 0;
}

void iteracni_metoda(SoustavaRovnic s) {
  // osamostatnit si Xs
  for (int i = 0; i < s.pocetRovnic; ++i) {
    for (int j = 0; j < s.pocetRovnic + 1; ++j) {
      if (j != i)
        s.Matice[i][j] /= s.Matice[i][i];
    }
    s.Matice[i][i] = 0;
  }

  // Xs = 1
  for (int i = 0; i < s.pocetRovnic; ++i) {
    s.nezname[i] = 1;
  }

  // zpetny chod
  double x;
  do {
    x = s.nezname[0];
    for (int i = 0; i < s.pocetRovnic; ++i) {
      double vysledek = s.Matice[i][s.pocetRovnic];
      for (int j = 0; j < s.pocetRovnic + 1; ++j) {
        vysledek -= s.Matice[i][j] * s.nezname[j];
      }
      s.nezname[i] = vysledek;
    }
  } while (fabs(x - s.nezname[0]) > 0.0001);

  for (int i = 0; i < s.pocetRovnic; ++i) {
    std::cout << "x" << i << ": " << s.nezname[i] << ", ";
  }
  std::cout << std::endl;
}

SoustavaRovnic *nacti_matici(std::string filename) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    std::cout << "Failed to open file: " << filename << std::endl;
    return nullptr;
  }

  SoustavaRovnic *s = new SoustavaRovnic;

  file >> s->pocetRovnic;

  for (int rovnice = 0; rovnice < s->pocetRovnic; ++rovnice) {
    for (int prvek = 0; prvek < s->pocetRovnic + 1; ++prvek) {
      file >> s->Matice[rovnice][prvek];
    }
  }

  return s;
}

void tiskni_matici(SoustavaRovnic s) {
  for (int radek = 0; radek < s.pocetRovnic; ++radek) {
    for (int prvek = 0; prvek < s.pocetRovnic + 1; ++prvek) {
      std::cout << s.Matice[radek][prvek] << ' ';
    }
    std::cout << std::endl;
  }
}
```

2. Sestavte program pro řešení soustavy lineárních rovnic Gaussovou  eliminační metodou a vyřešte soustavu rovnic:
3x1 + 4x2 - x3 = 9  
15x1 + 24x2 + 7x3 = -7
21x1 - x2 = 64

```cpp
#include <fstream>
#include <iostream>

struct SoustavaRovnic {
  double Matice[10][10];
  int pocetRovnic;
  double nezname[10];
};

SoustavaRovnic *nactiMatici(std::string filename);
void tiskni_matici(SoustavaRovnic s);
void eliminacni_metoda(SoustavaRovnic s);

int main() {
  SoustavaRovnic *soustava =
      nactiMatici("/home/hlina/Programming/School/maturita/"
                  "16-numericke-metody-2/16/matrix.txt");
  tiskni_matici(*soustava);
  eliminacni_metoda(*soustava);

  return 0;
}

SoustavaRovnic *nactiMatici(std::string filename) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    std::cout << "Failed to open file: " << filename << std::endl;
    return nullptr;
  }

  SoustavaRovnic *s = new SoustavaRovnic;
  file >> s->pocetRovnic;

  for (int rovnice = 0; rovnice < s->pocetRovnic; ++rovnice) {
    for (int prvek = 0; prvek < s->pocetRovnic + 1; ++prvek) {
      file >> s->Matice[rovnice][prvek];
    }
  }

  return s;
}

void tiskni_matici(SoustavaRovnic s) {
  for (int rovnice = 0; rovnice < s.pocetRovnic; ++rovnice) {
    for (int prvek = 0; prvek < s.pocetRovnic + 1; ++prvek) {
      std::cout << s.Matice[rovnice][prvek] << ' ';
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

void eliminacni_metoda(SoustavaRovnic s) {
  // Stupnovity tvar

  // Pro vsechny rovnice krome posledni
  for (int i = 0; i < s.pocetRovnic - 1; ++i) {
    // Upravime nasledujici rovnici
    for (int j = i + 1; j < s.pocetRovnic; ++j) {
      double nasobek = s.Matice[j][i] / s.Matice[i][i];

      // pro vsechny prvky od indexu [j][i]
      for (int k = i + 1; k < s.pocetRovnic + 1; ++k) {
        s.Matice[j][k] -= nasobek * s.Matice[i][k];
      }
    }
  }

  tiskni_matici(s);

  // Diskuze
  // 0*x = ?
  if (s.Matice[s.pocetRovnic - 1][s.pocetRovnic - 1] == 0.0) {
    // 0*x = 0
    if (s.Matice[s.pocetRovnic - 1][s.pocetRovnic] == 0.0) {
      std::cout << "Nekonecne mnoho reseni" << std::endl;
      return;
    } else {
      std::cout << "Nema reseni" << std::endl;
      return;
    }
  } else {
    // Zpetny chod
    s.nezname[s.pocetRovnic - 1] =
        s.Matice[s.pocetRovnic - 1][s.pocetRovnic] /
        s.Matice[s.pocetRovnic - 1][s.pocetRovnic - 1];

    for (int neznama = s.pocetRovnic - 2; neznama >= 0; --neznama) {
      double vysledek = s.Matice[neznama][s.pocetRovnic];
      for (int i = s.pocetRovnic - 1; i >= neznama + 1; --i) {
        vysledek -= s.Matice[neznama][i] * s.nezname[i];
      }

      s.nezname[neznama] = vysledek / s.Matice[neznama][neznama];
    }
  }

  for (int i = 0; i < s.pocetRovnic; ++i)
    std::cout << 'x' << i << ": " << s.nezname[i] << ", ";
  std::cout << std::endl;
}
```

# 15.
Naprogramujte v QT4 hru piškvorky. Program vytvoří hrací pole tlačítek (pushButton) 15 sloupců a 10 řádků.Po kliknutí na tlačítko se do něho vepíše 0 nebo x pouze v případě, že v tlačítku není žádný znak. Zapisování znaků  x a 0 se střídá (po vložení x se na další tlačítko vloží 0 a po vložení 0 se na další tlačítko vloží x)

```cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"

bool setX = true;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 15; j++) {
      QPushButton *btn = new QPushButton;

      connect(btn, SIGNAL(clicked()), this, SLOT(fill()));

      ui->gridLayout->addWidget(btn, i, j);
    }
  }
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::fill() {
  QPushButton *btn = (QPushButton *)QObject::sender();

  if (btn->text() == "") {
    btn->setText(setX ? "x" : "0");
    setX = !setX;
  }
}
```

# 16.
Textový editor – QT

```cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_actionAbout_triggered() {
  QMessageBox::about(this, "About", "c++ ide 9.0.1");
}

void MainWindow::on_actionCopy_triggered() { ui->textEdit->copy(); }

void MainWindow::on_actionCut_triggered() { ui->textEdit->cut(); }

void MainWindow::on_actionPaste_triggered() { ui->textEdit->paste(); }

void MainWindow::on_actionExit_triggered() { MainWindow::close(); }

void MainWindow::on_actionNew_triggered() { ui->textEdit->setText(""); }

void MainWindow::on_actionBackground_triggered() {
  ui->textEdit->setTextBackgroundColor(QColorDialog::getColor());
}

void MainWindow::on_actionPen_triggered() {
  ui->textEdit->setTextColor(QColorDialog::getColor());
}

void MainWindow::on_actionSave_triggered() {
  QString filename = QFileDialog::getSaveFileName(this, "Save file");

  QFile file(filename);
  if (!file.open(QFile::WriteOnly))
    return;

  QTextStream out(&file);
  out << ui->textEdit->toPlainText();

  file.close();
}

void MainWindow::on_actionOpen_triggered() {
  QString filename = QFileDialog::getOpenFileName(this, "Open file");

  QFile file(filename);
  if (!file.open(QFile::ReadOnly))
    return;

  QTextStream in(&file);
  ui->textEdit->setText(in.readAll());

  file.close();
}
```

# 17.
Excel – přiklad Nakladatelská rozvaha na www.jaroska.cz/informatika

# 18.
HTML - Vytvořte 2 stránky v HTML pro cestovní kancelář podle vzoru. Po zavolání odkazu autobusem nebo letadlem se zobrazí v pravé části odpovídající obrázek.
Obrázky letadla a autobusu najděte na internetu. Použijte kaskádové styly. www.jaroska.cz/informatika

prvni.html
```html
<html>
	<head>
<style>
.menu {
	grid-area: menu;
	overflow: scroll;
	border: 2px solid grey;
}
.frame {
	grid-area: frame;
}
.grid-container {
	display: grid;
	grid-template-areas:
		'menu frame';
}
</style>
	</head>
	<body class="grid-container">
		<div class="menu">
			<h1>Nase nabidka</h1>
			<ul>
				<li> Pobytove zajezdy </li>
				<ul>
					<li><a href="prvni.html">letadlem</a></li>
					<li><a href="druhy.html">autobusem</a></li>
				</ul>
				<li>Poznavaci zajezdy</li>
		</div>
		<div class="frame">
			<h1>Nase letadlo</h1>
			<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/5/5e/ANA_777-300_Taking_off_from_JFK.jpg/300px-ANA_777-300_Taking_off_from_JFK.jpg">
	</body>
</html>
```

druhy.html
```html
<html>
	<head>
<style>
.menu {
	grid-area: menu;
	overflow: scroll;
	border: 2px solid grey;
	margin: 10%;
}
.frame {
	grid-area: frame;
}
.grid-container {
	display: grid;
	grid-template-areas:
		'menu frame';
}
</style>
	</head>
	<body class="grid-container">
		<div class="menu">
			<h1>Nase nabidka</h1>
			<ul>
				<li> Pobytove zajezdy </li>
				<ul>
					<li><a href="prvni.html">letadlem</a></li>
					<li><a href="druhy.html">autobusem</a></li>
				</ul>
				<li>Poznavaci zajezdy</li>
		</div>
		<div class="frame">
			<h1>Nas autobus</h1>
			<img height="450" width="450" src="https://upload.wikimedia.org/wikipedia/commons/thumb/8/89/MB_O_405_N_MVV274.jpeg/1200px-MB_O_405_N_MVV274.jpeg">
	</body>
</html>
```

# 19.
Příklad
Napište skript v php, který vytvoří formulář pro výpočet alkoholu v krvi podle vzoru.

Vzorec na výpočet množství alkoholu v krvi
Vzorec na výpočet množstva alkoholu v krvi
c = ( d * e * 0.8 ) / ( p * r )
c - poměrné zastoupenií alkoholu v krvi [‰]
d - objem nápoje v decilitrech
e - procentuální zastoupení alkoholu v nápoji
p - hmotnost konzumenta alkoholu
r - koeficient určující podíl vody v organizme. Pro muže je roven 0.68, pre ženy 0.55.
0.8 - zaokrouhlená hmotnost ethylalkoholu
Víno má 12% alkoholu, pivo 12 má 5% alkoholu, pivo 10 má 3,5% alkoholu, whisky 40%

```php
<html>
  <head>
    <title>PHP Test</title>
  </head>
  <body>
    <form>
    Mnozstvi alkoholu v dl
    <input name="d" type="text"> <br />
    Typ napoje: 
    <select name="e">
      <option value="12">vino</option>
      <option value="5">pivo 12</option>
      <option value="3.5">pivo 10</option>
      <option value="40">whisky</option>
    </select> <br />
    Hmotnost v kg 
    <input name="p" type="text"> <br />
    <input name="r" type="radio" value="0.68"> muz
    <input name="r" type="radio" value="0.55"> zena
    <br />

    <input type="submit" value="Submit">
    </form>
<?php 
if(isSet($_GET["d"]) && isSet($_GET["e"]) && isSet($_GET["p"]) && isSet($_GET["r"])) {
  echo ($_GET["d"] * $_GET["e"] * 0.8) / ($_GET["r"] * $_GET["p"]);
}
?>
  </body>
</html>
```

# 20.
Řešte v MySQL
1. Vytvořte databázi VINOTEKA
                2. V databázi vytvořte tabulky s následující strukturou:
                    VINO – ID, BARVA, ODRUDA, CENA, MNOZSTVI
    DODAVKA – ID, ODRUDA, MNOZSTVI
Každá tabulka obsahuje alespoň 3 věty tak, aby následující aktualizace změnila             minimálně 2 věty
3. Aktualizace přičte MNOZSTVI z tabulky DODAVKA k MNOZSTVI v tabulce VINO u těch vín, které mají stejné pole ODRUDA.

```SQL
CREATE DATABASE vinoteka;
use vinoteka;

CREATE TABLE vino (
	id INT,
	barva VARCHAR(30),
	odruda VARCHAR(30),
	mnozstvi INT
);

INSERT INTO vino VALUES ( 0, "cervena", "nevim", 2 ), ( 1, "zelena", "neznam", 4 ), ( 2, "bila", "zadna", 8 );

CREATE TABLE dodavka (
	id INT,
	odruda VARCHAR(30),
	mnozstvi INT
);

INSERT INTO dodavka VALUES ( 3, "idk", 5 ), ( 2, "zadna", 9999 ), ( 1, "nevim", 8 );

SELECT * FROM vino;

UPDATE dodavka, vino SET vino.mnozstvi = vino.mnozstvi + dodavka.mnozstvi WHERE vino.odruda = dodavka.odruda;

SELECT * FROM vino;

DROP DATABASE vinoteka;
```

# 21.
Vytvořte program, který zločincovu výpověď napsanou v textovém souboru 'vypoved.txt' změní tak, že ze všech slov, která začínají písmeny 'ne' tato dvě písmena vypustí. Výsledný upravený text ukládejte do textového souboru 'skutecne.txt'.

```cpp
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int main()
{
    string puvodni, upraveny, test= " ne";
    int pozice = 0;
    ifstream vstup("vypoved.txt");
    ofstream vystup("prava_vypoved.txt");

    while(getline(vstup, puvodni))
    {
        for(int i = 0; i < puvodni.size(); i++)
        {
            /*if(puvodni[i] == "n" and puvodni[i+1] == "e" and puvodni[i-1] == " ")
            {
                puvodni[i].erase (i, 2);
            }*/
            //if(puvodni[i] == "n")

        }
         while(puvodni.find(" ne") != string::npos)
         {
             pozice = puvodni.find(" ne");
             puvodni.erase(pozice+1, 2);
             upraveny=puvodni.substr(0, pozice);
             puvodni.erase(0, pozice);
             cout << upraveny;
         }
         pozice = 0;
        cout << puvodni;
        cout << endl;
        vystup << upraveny << " " << endl;
    }

    return 0;
}
```

# 22.
Vytvořte www stránku, která umožní uživateli zadat do formuláře uživatelské jméno a heslo. Pokud je po odeslání obsahu formuláře uživatelské jméno 'Hugo' a heslo 'Kokoska', zobrazí se stránka s nápisem 'Úspěšné přihlášení'. V opačném případě se zobrazí opět původní stránka s formulářem.

```php
<html>
  <head>
    <title>PHP Test</title>
  </head>
  <body>
<?php
if($_GET["username"] == "Hugo" && $_GET["password"] == "Kokoshka") {
	echo "uspesne prihlaseni";
} else {
	echo "
    <form>
    Uzivatelske jmeno:
    <input name=\"username\" type=\"text\"> <br />

    Heslo:
    <input name=\"password\" type=\"password\"> <br />

    <input type=\"submit\" value=\"Submit\">
    </form>";
}
?>
  </body>
</html>
```

# 23.
Naprogramujte v QT4 zobrazení grafu funkce sinus a cosinus

```cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    /**/
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionRand_triggered()
{
    scene->clear();
    int halfWidth = ui->graphicsView->geometry().width() / 2;
    int halfHeight = ui->graphicsView->geometry().height() / 2;
    scene->addLine(-halfWidth, 0, halfWidth, 0, QPen("black"));
    scene->addLine(0, -halfHeight, 0, halfHeight, QPen("black"));

    int y, xp = -halfWidth, yp = -static_cast<int>(sin(xp / 100.0) * 100);
    for (int x = -halfWidth; x < halfWidth; ++x) {
        y = -static_cast<int>(sin(x / 100.0 * 3.14) * 100);
        scene->addLine(xp, yp, x, y, QPen("red"));

        xp = x;
        yp = y;
    }
}

void MainWindow::on_actionCos_triggered()
{
    scene->clear();
    int halfWidth = ui->graphicsView->geometry().width() / 2;
    int halfHeight = ui->graphicsView->geometry().height() / 2;
    scene->addLine(-halfWidth, 0, halfWidth, 0, QPen("black"));
    scene->addLine(0, -halfHeight, 0, halfHeight, QPen("black"));

    int y, xp = -halfWidth, yp = -static_cast<int>(cos(xp / 100.0) * 100);
    for (int x = -halfWidth; x < halfWidth; ++x) {
        y = -static_cast<int>(cos(x / 100.0) * 100);
        scene->addLine(xp, yp, x, y, QPen("red"));

        xp = x;
        yp = y;
    }
}
```

# 24.
Vytvořte koláž podle vzoru.
Vytvořte obrázek podle vzoru

# 25.
Automatická linka vyrábí šrouby s průměrnou hmotností 1.34 g a  směrodatnou odchylkou 0.023 g. Kolik šroubů se ve vzorku 100000 ks  pravděpodobně odchýlí od normy 1.34 g o více než 0.03 g? Úlohu řešte simulací výroby s předpokladem, že rozměry vyrobených  součástek jsou rozloženy podle normálního rozložení  pravděpodobnosti.
 Pozn. Program vypracujte obecně, vstupní data zadejte z  klávesnice. Pro modelování použijte vzorce
 b = 6s.a + m - 3s
 b - náhodná hodnota podle normálního rozdělení pravděpodobnosti
 a - průměr skupiny generovaných čísel
 m - střední hodnota náhodné veličiny
 s - standardní odchylka náhodné veličiny

```cpp
#include <iostream>
#include <random> // This is c++11 feature

const double mean = 1.34, standardDeviation = 0.023;
const int nrolls = 100000;

int main() {
  std::default_random_engine generator;
  std::normal_distribution<double> distribution(mean, standardDeviation);

  int result = 0;

  for (int i = 0; i < nrolls; ++i) {
    double number = distribution(generator);
    if ((number >= 1.37) || (number <= 1.31))
      ++result;
  }

  std::cout << (double)result / nrolls;

  return 0;
}
```

Poissovo rozdělení
```cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"

constexpr double function(double x) {
  return x * x * x + 3 * x * x - 19 * x - 22;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_pushButton_clicked() {
  double x1, x2, x0, precision = 0.0001;
  x1 = ui->lineEdit->text().toDouble();
  x2 = ui->lineEdit_2->text().toDouble();

  if (function(x1) * function(x2) < 0) {
    do {
      x0 = x1 - function(x1) * (x2 - x1) / (function(x2) - function(x1));

      if (function(x1) * function(x0) < 0) {
        x2 = x0;
      } else {
        x1 = x0;
      }

    } while (fabs(function(x0)) > precision);

    ui->lineEdit_3->setText(QString::number(x0));
  } else {
    QMessageBox messageBox;
    messageBox.critical(0, "Error", "An error has occured !");
    messageBox.setFixedSize(500, 200);
  }
}

void MainWindow::on_pushButton_2_clicked() {
  const double h = 0.001, precision = 0.0001;
  double x0, x1 = ui->lineEdit->text().toDouble();

  do {
    x0 = x1 - (h * function(x1)) / (function(x1 + h) - function(x1));
    x1 = x0;
  } while (fabs(function(x0)) > precision);

  ui->lineEdit_4->setText(QString::number(x0));
}
```
