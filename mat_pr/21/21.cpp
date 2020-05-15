#include <iostream>
#include <fstream>
#include <algorithm>

int main() {
	std::ifstream file( "vypoved.txt" );
	if ( !file.is_open() ) std::cerr << "Couldnt open file" << std::endl;

	std::string word, line;

	while ( getline(file, line) ) {
		int pos = 0;
		if ( line.find("ne", 0) == 0 ) {
			line.erase(0, 2);
		}
		while ( ( pos = line.find(" ne", pos) ) != std::string::npos ) {
			line.erase(pos+1, 2);
		}
		std::cout << line << std::endl;
	}

	file.close();
}
