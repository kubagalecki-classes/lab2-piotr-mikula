#include <iostream>

class Wektor
{
public:
    Wektor(int n_wek) { n = n_wek; }

    ~Wektor() { delete[] vector; }

    int     n;
    double* vector = new double[n];

    void dlugosc() { std::cout << "Dlugosc wektora wynosi " << n << std::endl; }
};

int main()
{
    Wektor wek{4};
    wek.dlugosc();

    std::cout << "Ostatnia linijka kodu." << std::endl;
}
