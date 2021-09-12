#include <iostream>

int main()
{
    int x,y;
    std::cin >> x >> y;

    for(int i = 0; i < x; i++, std::cout << "Hello World!\n");
    for(int i = 0; i < y; i++, std::cout << "Olá Mundo!\n");

    return 0;
}