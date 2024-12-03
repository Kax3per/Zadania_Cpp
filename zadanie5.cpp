#include <iostream>
#include <string>

using namespace std;

// Klasa bazowa
class Pojazd
{
protected:
    string marka;
    string model;
    int rokProdukcji;

public:
    // Konstruktory
    Pojazd() : marka(""), model(""), rokProdukcji(0) {}
    Pojazd(string marka, string model, int rokProdukcji)
        : marka(marka), model(model), rokProdukcji(rokProdukcji) {}

    // Wyświetlenie informacji
    void wyswietl() const
    {
        cout << "Marka: " << marka << ", Model: " << model << ", Rok produkcji: " << rokProdukcji << endl;
    }
};

// Klasa pochodna dla ciężarówki
class Ciezarowka : public Pojazd
{
protected:
    string przeznaczenie; // Wywrotka, chłodnia, cysterna

public:
    // Konstruktory
    Ciezarowka() : Pojazd(), przeznaczenie("") {}
    Ciezarowka(string marka, string model, int rokProdukcji, string przeznaczenie)
        : Pojazd(marka, model, rokProdukcji), przeznaczenie(przeznaczenie) {}

    // Wyświetlenie informacji
    void wyswietl() const
    {
        Pojazd::wyswietl();
        cout << "Przeznaczenie: " << przeznaczenie << endl;
    }
};

// Klasa pochodna dla autobusu
class Autobus : public Pojazd
{
protected:
    int miejscaSiedzace;
    int miejscaStojace;

public:
    // Konstruktory
    Autobus() : Pojazd(), miejscaSiedzace(0), miejscaStojace(0) {}
    Autobus(string marka, string model, int rokProdukcji, int miejscaSiedzace, int miejscaStojace)
        : Pojazd(marka, model, rokProdukcji), miejscaSiedzace(miejscaSiedzace), miejscaStojace(miejscaStojace) {}

    // Wprowadzenie i wyświetlenie danych
    void wprowadzDane()
    {
        cout << "Podaj marke: ";
        cin >> marka;
        cout << "Podaj model: ";
        cin >> model;
        cout << "Podaj rok produkcji: ";
        cin >> rokProdukcji;
        cout << "Podaj liczbe miejsc siedzących: ";
        cin >> miejscaSiedzace;
        cout << "Podaj liczbe miejsc stojących: ";
        cin >> miejscaStojace;
    }

    void wyswietl() const
    {
        Pojazd::wyswietl();
        cout << "Miejsca siedzące: " << miejscaSiedzace << ", Miejsca stojące: " << miejscaStojace << endl;
    }
};

int main()
{
    int wybor;
    Autobus autobus("MAN", "BUS", 1980, 100, 300);

    do
    {
        cout << "\n=====================" << endl;
        cout << "Menu: " << endl;
        cout << "1. Wyswietl dane autobusu" << endl;
        cout << "2. Wprowadz dane nowego autobusu" << endl;
        cout << "3. Zakoncz" << endl;
        cout << "Wybierz opcje: ";
        cin >> wybor;

        switch (wybor)
        {
        case 1:
            autobus.wyswietl();
            break;
        case 2:
            cout << "\nWprowadź dane nowego autobusu:" << endl;
            Autobus nowyAutobus;
            nowyAutobus.wprowadzDane();
            cout << "\nNowy autobus:" << endl;
            nowyAutobus.wyswietl();
            break;
        }
    } while (wybor != 3);

    return 0;
}
