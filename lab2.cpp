#include <iostream>

class Wektor
{
public:
    Wektor(int n_wek)
    {
        dlugosc   = n_wek;
        pojemnosc = dlugosc;
        vector    = new double[dlugosc];
        for (int i = 0; i < dlugosc; i++)
            vector[i] = 0;
    }

    ~Wektor() { delete[] vector; }

    double* vector;

    void dlugosc_wek() { std::cout << "Dlugosc wektora wynosi " << dlugosc << "\n" << std::endl; }

    int getDlugosc() { return dlugosc; }
    int getPojemnosc() { return pojemnosc; }

    void print()
    {
        std::cout << "Obecna zawartosc wektora [";
        for (int i = 0; i < dlugosc; ++i) {
            std::cout << vector[i];
            if (i < (dlugosc - 1))
                std::cout << ", ";
        }
        std::cout << "]\n" << std::endl;
    }

private:
    int dlugosc;
    int pojemnosc;
};

int main()
{
    Wektor wek{4};
    wek.dlugosc_wek();
    wek.print();

    std::cout << "Ostatnia linijka kodu." << std::endl;
}