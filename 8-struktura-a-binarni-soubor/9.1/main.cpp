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

