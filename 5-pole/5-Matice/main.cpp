#include <iostream>
#include <fstream>

void load_matrix(char file_name[], int matrix[5][5]);
void add_matrix(int mata[5][5], int matb[5][5], int matc[5][5]);
void save_matrix(char file_name[], int matrix[5][5]);
void print_matrix(int matrix[5][5]);

int main()
{
    int mata[5][5], matb[5][5], matc[5][5];

    load_matrix("mata.dat", mata);
    print_matrix(mata);

    load_matrix("matb.dat", matb);
    print_matrix(matb);

    add_matrix(mata, matb, matc);
    print_matrix(matc);

    save_matrix("matc.dat", matc);

    return 0;
}

void load_matrix(char file_name[], int matrix[5][5])
{
    std::ifstream file;
    file.open(file_name);

    for (int row = 0; row < 5; row++)
    {
        for (int column = 0; column < 5; column++)
        {
            file >> matrix[row][column];
        }
    }

    file.close();
}

void add_matrix(int mata[5][5], int matb[5][5], int matc[5][5])
{
    for (int row = 0; row < 5; row++)
    {
        for (int column = 0; column < 5; column++)
        {
            matc[row][column] = mata[row][column] + matb[row][column];
        }
    }
}

void save_matrix(char file_name[], int matrix[5][5])
{
    std::ofstream file;
    file.open(file_name);

    for (int row = 0; row < 5; row++)
    {
        for (int column = 0; column < 5; column++)
        {
            file << matrix[row][column] << '\t';
        }
        file << '\n';
    }

    file.close();
}

void print_matrix(int matrix[5][5])
{
for (int row = 0; row < 5; row++)
    {
        for (int column = 0; column < 5; column++)
        {
            std::cout << matrix[row][column] << '\t';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}
