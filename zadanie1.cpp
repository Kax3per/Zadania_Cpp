#include <iostream>
#include <string>

using namespace std;

// Klasa podstawowa Komputer
class Komputer
{
public:
    string marka;
    string model;

    Komputer(string marka = "", string model = "")
    {
        this->marka = marka;
        this->model = model;
    }

    virtual void wyswietlInformacje()
    {
        cout << "Marka: " << marka << ", Model: " << model;
    }
};

// Klasa PC dziedzicząca Komputer
class KomputerStacjonarny : public Komputer
{
public:
    string typObudowy;

    KomputerStacjonarny(string marka = "", string model = "", string typObudowy = "")
    {
        this->marka = marka;
        this->model = model;
        this->typObudowy = typObudowy;
    }

    void wyswietlInformacje() override
    {
        Komputer::wyswietlInformacje();
        cout << ", Typ obudowy: " << typObudowy << endl;
    }
};

// Klasa Laptop dziedzicząca Komputer
class Laptop : public Komputer
{
public:
    double przekatnaEkranu;
    string kolorObudowy;

    Laptop(string marka = "", string model = "", double przekatnaEkranu = 0.0, string kolorObudowy = "")
    {
        this->marka = marka;
        this->model = model;
        this->przekatnaEkranu = przekatnaEkranu;
        this->kolorObudowy = kolorObudowy;
    }

    void wyswietlInformacje() override
    {
        Komputer::wyswietlInformacje();
        cout << ", Przekątna ekranu: " << przekatnaEkranu << " cali, Kolor obudowy: " << kolorObudowy << endl;
    }
};

void wprowadzDaneLaptopa(Laptop &laptop)
{
    cout << "Podaj dane laptopa:" << endl;
    cout << "Marka: ";
    cin >> laptop.marka;
    cout << "Model: ";
    cin >> laptop.model;
    cout << "Przekątna ekranu (cale): ";
    cin >> laptop.przekatnaEkranu;
    cout << "Kolor obudowy: ";
    cin >> laptop.kolorObudowy;
}

void wprowadzDaneKomputeraStacjonarnego(KomputerStacjonarny &komputerStacjonarny)
{
    cout << "Podaj dane komputera stacjonarnego:" << endl;
    cout << "Marka: ";
    cin >> komputerStacjonarny.marka;
    cout << "Model: ";
    cin >> komputerStacjonarny.model;
    cout << "Typ obudowy: ";
    cin >> komputerStacjonarny.typObudowy;
}

int main()
{
    Laptop laptop;
    KomputerStacjonarny komputerStacjonarny;

    // Interfejs wprowadzania danych
    wprowadzDaneLaptopa(laptop);
    wprowadzDaneKomputeraStacjonarnego(komputerStacjonarny);

    // Wyświetlanie danych
    cout << "\nDane wprowadzone dla laptopa:" << endl;
    laptop.wyswietlInformacje();

    cout << "\nDane wprowadzone dla komputera stacjonarnego:" << endl;
    komputerStacjonarny.wyswietlInformacje();

    return 0;
}
