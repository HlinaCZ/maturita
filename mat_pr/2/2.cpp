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