#include <iostream>
#include <string>
using namespace std;

class Komputer
{
private:
    string marka;
    string model;

public:
    Komputer(string marka = "", string model = "") : marka(marka), model(model) {}

    string pobierzMarke() const
    {
        return marka;
    }
    string pobierzModel() const
    {
        return model;
    }

    void ustawMarke(string nowaMarka)
    {
        marka = nowaMarka;
    }
    void ustawModel(string nowyModel)
    {
        model = nowyModel;
    }

    virtual void wyswietlDane()
    {
        cout << "Marka: " << marka << ", Model: " << model << endl;
    }
};

class KomputerStacjonarny : public Komputer
{
private:
    string rodzajObudowy;

public:
    KomputerStacjonarny(string marka = "", string model = "", string rodzajObudowy = "")
        : Komputer(marka, model), rodzajObudowy(rodzajObudowy) {}

    string pobierzRodzajObudowy() const { return rodzajObudowy; }
    void ustawRodzajObudowy(string nowaObudowa) { rodzajObudowy = nowaObudowa; }

    void wyswietlDane() override
    {
        Komputer::wyswietlDane();
        cout << "Rodzaj obudowy: " << rodzajObudowy << endl;
    }
};

class Laptop : public Komputer
{
private:
    float przekatnaEkranu;
    string kolorObudowy;

public:
    Laptop(string marka = "", string model = "", float przekatnaEkranu = 0.0, string kolorObudowy = "")
        : Komputer(marka, model), przekatnaEkranu(przekatnaEkranu), kolorObudowy(kolorObudowy) {}

    float pobierzPrzekatnaEkranu() const { return przekatnaEkranu; }
    string pobierzKolorObudowy() const { return kolorObudowy; }

    void ustawPrzekatnaEkranu(float nowaPrzekatna) { przekatnaEkranu = nowaPrzekatna; }
    void ustawKolorObudowy(string nowyKolor) { kolorObudowy = nowyKolor; }

    void wyswietlDane() override
    {
        Komputer::wyswietlDane();
        cout << "Przekątna ekranu: " << przekatnaEkranu << " cali, Kolor obudowy: " << kolorObudowy << endl;
    }
};

void wprowadzDaneKomputeraStacjonarnego(KomputerStacjonarny &komputer)
{
    string marka, model, rodzajObudowy;
    cout << "Wprowadź dane komputera stacjonarnego:" << endl;
    cout << "Marka: ";
    cin >> marka;
    cout << "Model: ";
    cin >> model;
    cout << "Rodzaj obudowy: ";
    cin >> rodzajObudowy;

    komputer.ustawMarke(marka);
    komputer.ustawModel(model);
    komputer.ustawRodzajObudowy(rodzajObudowy);
}

void wprowadzDaneLaptopa(Laptop &laptop)
{
    string marka, model, kolorObudowy;
    float przekatnaEkranu;
    cout << "Wprowadź dane laptopa:" << endl;
    cout << "Marka: ";
    cin >> marka;
    cout << "Model: ";
    cin >> model;
    cout << "Przekątna ekranu (cale): ";
    cin >> przekatnaEkranu;
    cout << "Kolor obudowy: ";
    cin >> kolorObudowy;

    laptop.ustawMarke(marka);
    laptop.ustawModel(model);
    laptop.ustawPrzekatnaEkranu(przekatnaEkranu);
    laptop.ustawKolorObudowy(kolorObudowy);
}

int main()
{
    KomputerStacjonarny komputerStacjonarny;
    Laptop laptop;

    // Interfejs do wprowadzania danych
    wprowadzDaneKomputeraStacjonarnego(komputerStacjonarny);
    wprowadzDaneLaptopa(laptop);

    // Wyświetlanie danych
    cout << "\nDane komputera stacjonarnego:" << endl;
    komputerStacjonarny.wyswietlDane();

    cout << "\nDane laptopa:" << endl;
    laptop.wyswietlDane();

    return 0;
}
