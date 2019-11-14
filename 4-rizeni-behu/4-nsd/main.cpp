#include <iostream>

int nsd(int a, int b);

int main()
{
    int amount, last, input;
    std::cout << "How many numbers you want to import: ";
    std::cin >> amount;
    std::cout << std::endl << "Input your natural numbers: " << std::endl;
    std::cin >> last;
    if (last < 1) std::cerr << "Input wasn't in natural numbers";
    for (int i = 0; i < amount-1; i++)
    {
        std::cin >> input;
        if (input < 1) std::cerr << "Input wasn't in natural numbers" << std::endl;
        last = nsd(last, input);
    }
    std::cout << std::endl << "NSD is: " << last;
    return 0;
}

int nsd(int first, int second)
{
    int result;

    while(second != 0)
    {
        result = first % second;
        first = second;
        second = result;
    }
    return first;
}
