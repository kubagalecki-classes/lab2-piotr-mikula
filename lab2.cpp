#include <iostream>

class Wektor
{
public:
    Wektor(int n_wek)
    {
        n = n_wek;
        for (int i = 0; i < n; i++)
            vector[i] = 0;
    }

    ~Wektor() { delete[] vector; }

    int     n;
    double* vector = new double[n];

    void dlugosc() { std::cout << "Dlugosc wektora wynosi " << n << std::endl; }
    void wartosci()
    {
        std::cout << "[ ";
        for (int i = 0; i < n; i++)
            std::cout << vector[i] << " ";
        std::cout << "]" << std::endl;
    }
};

int main()
{
    Wektor wek{4};
    wek.dlugosc();
    wek.wartosci();

    std::cout << "Ostatnia linijka kodu." << std::endl;
}
