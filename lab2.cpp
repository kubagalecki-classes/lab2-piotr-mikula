#include <iostream>

class Wektor
{
public:
    Wektor(int n_wek)
    {
        dlugosc = n_wek;
        vector  = new double[dlugosc];
        for (int i = 0; i < dlugosc; i++)
            vector[i] = 0;
    }

    ~Wektor() { delete[] vector; }

    double* vector;

    void dlugosc_wek() { std::cout << "Dlugosc wektora wynosi " << dlugosc << std::endl; }

    int getDlugosc() { return dlugosc; }

private:
    int dlugosc;
};

int main()
{
    Wektor wek{4};
    wek.dlugosc_wek();

    std::cout << "Ostatnia linijka kodu." << std::endl;
}