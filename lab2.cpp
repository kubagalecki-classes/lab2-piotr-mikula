#include <iostream>

class Wektor
{
public:
    Wektor(int n_wek)
    {
        dlugosc   = n_wek;
        pojemnosc = n_wek;
        vector    = new double[dlugosc];
        for (int i = 0; i < dlugosc; i++)
            vector[i] = 0;
    }

    ~Wektor() { delete[] vector; }

    double* vector;

    void dlugosc_wek() { std::cout << "Dlugosc wektora wynosi " << dlugosc << std::endl; }

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

    void ZmienDlugosc(int nowe_n)
    {
        if (nowe_n <= pojemnosc) {
            for (int i = nowe_n; i < pojemnosc; i++)
                vector[i] = 0;
            dlugosc = nowe_n;
        }
        else if (nowe_n > pojemnosc) {
            double* temp = new double[nowe_n];
            for (int i = 0; i < dlugosc; i++)
                temp[i] = vector[i];
            for (int i = dlugosc; i < nowe_n; i++)
                temp[i] = 0.0;

            vector = temp;
            delete[] temp;

            dlugosc   = nowe_n;
            pojemnosc = dlugosc;
        }
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
    std::cout << "Zmiana dlugosci wektora na mniejszy\n";
    wek.ZmienDlugosc(3);
    wek.dlugosc_wek();
    wek.print();
    std::cout << "Zmiana dlugosci wektora na wiekszy\n";
    wek.ZmienDlugosc(5);
    wek.dlugosc_wek();
    wek.print();

    std::cout << "Ostatnia linijka kodu." << std::endl;
}