#include <iostream>
int zmienna_extern = 10;
extern int global;
void wypiszZmiennaGlobalZInnegoPliku()
{
    std::cout << global << std::endl;
}
