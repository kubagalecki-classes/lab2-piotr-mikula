#include <iostream>

struct Liczba
{
    Liczba(int w) : wartosc{w} {}
    /*Liczba(const Liczba& l) : wartosc{l.wartosc}
    {
        std::cout << "Utworzono konstruktor kopiujacy\n";
    }*/

    int wartosc;
};

int main()
{
    std::cout << "Krok 1" << std::endl;
    Liczba a{1};
    std::cout << "Krok 2" << std::endl;
    Liczba b{a};
    std::cout << "Krok 3" << std::endl;
    Liczba c = a;
}
//kod się kompiluje