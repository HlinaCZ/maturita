#include <fstream>
#include <iostream>

const int copySize = sizeof(char);

int main() {
  std::cout << "Directory to install the program" << std::endl;

  std::string outputDirectory;
  std::cin >> outputDirectory;

  std::ifstream installFilesList("SOUBORY.txt");
  if (!installFilesList.is_open()) {
    std::cerr << "Couldn't open install file" << std::endl;
  }

  std::string installFile;
  while (installFilesList >> installFile) {
    std::ifstream inputFile(installFile, std::ios::binary | std::ios::in);
    if (!inputFile.is_open()) {
      std::cerr << "Couldn't open " << installFile << " file" << std::endl;
    }

    std::ofstream outputFile(outputDirectory + installFile,
                             std::ios::binary | std::ios::out | std::ios::app);
    if (!outputFile.is_open()) {
      std::cerr << "Couldn't open " << outputDirectory + installFile << " file"
                << std::endl;
    }

    std::cout << "Installing file " << installFile << " to "
              << outputDirectory + installFile << std::endl;

    char copyContent;
    /* char copyContent[copySize];
     for (int i = 0; i < copySize; i++) {
       copyContent[i] = 0;
     }*/
    inputFile.read(&copyContent, copySize);
    do {
      std::cout << copyContent << std::endl;
      outputFile.write(&copyContent, copySize);
    } while (inputFile.read(&copyContent, copySize));

    inputFile.close();
    outputFile.close();
  }

  installFilesList.close();
}
