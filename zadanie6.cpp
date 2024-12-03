#include <iostream>
#include <string>

using namespace std;

// Klasa bazowa
class Pojazd
{
private:
    string nazwaMarki;
    string nazwaModelu;
    int rokProdukcji;

public:
    // Konstruktory
    Pojazd() : nazwaMarki(""), nazwaModelu(""), rokProdukcji(0) {}
    Pojazd(string marka, string model, int rokProdukcji)
        : nazwaMarki(marka), nazwaModelu(model), rokProdukcji(rokProdukcji) {}

    // Settery i gettery
    void setMarka(const string &m) { nazwaMarki = m; }
    string getMarka() const { return nazwaMarki; }

    void setModel(const string &m) { nazwaModelu = m; }
    string getModel() const { return nazwaModelu; }

    void setRokProdukcji(int rok) { rokProdukcji = rok; }
    int getRokProdukcji() const { return rokProdukcji; }

    // Wyświetlenie informacji
    void wyswietl() const
    {
        cout << "Marka: " << nazwaMarki << ", Model: " << nazwaModelu << ", Rok produkcji: " << rokProdukcji << endl;
    }
};

// Klasa pochodna dla ciężarówki
class Ciezarowka : public Pojazd
{
private:
    string typPojazdu; // Wywrotka, chłodnia, cysterna

public:
    // Konstruktory
    Ciezarowka() : Pojazd(), typPojazdu("") {}
    Ciezarowka(string marka, string model, int rokProdukcji, string typ)
        : Pojazd(marka, model, rokProdukcji), typPojazdu(typ) {}

    // Settery i gettery
    void setTypPojazdu(const string &t) { typPojazdu = t; }
    string getTypPojazdu() const { return typPojazdu; }

    // Wyświetlenie informacji
    void wyswietl() const
    {
        Pojazd::wyswietl();
        cout << "Typ pojazdu: " << typPojazdu << endl;
    }
};

// Klasa pochodna dla autobusu
class Autobus : public Pojazd
{
private:
    int liczbaMiejscSiedzacych;
    int liczbaMiejscStojacych;

public:
    // Konstruktory
    Autobus() : Pojazd(), liczbaMiejscSiedzacych(0), liczbaMiejscStojacych(0) {}
    Autobus(string marka, string model, int rokProdukcji, int miejscaSiedzace, int miejscaStojace)
        : Pojazd(marka, model, rokProdukcji), liczbaMiejscSiedzacych(miejscaSiedzace), liczbaMiejscStojacych(miejscaStojace) {}

    // Settery i gettery
    void setLiczbaMiejscSiedzacych(int miejsca) { liczbaMiejscSiedzacych = miejsca; }
    int getLiczbaMiejscSiedzacych() const { return liczbaMiejscSiedzacych; }

    void setLiczbaMiejscStojacych(int miejsca) { liczbaMiejscStojacych = miejsca; }
    int getLiczbaMiejscStojacych() const { return liczbaMiejscStojacych; }

    // Wprowadzenie i wyświetlenie danych
    void wprowadzDane()
    {
        string marka, model;
        int rok, siedzenia, stojace;
        cout << "Podaj marke: ";
        cin.ignore(); // Zignorowanie poprzednich nowych linii
        getline(cin, marka);
        setMarka(marka);
        cout << "Podaj model: ";
        getline(cin, model);
        setModel(model);
        cout << "Podaj rok produkcji: ";
        cin >> rok;
        setRokProdukcji(rok);
        cout << "Podaj liczbe miejsc siedzących: ";
        cin >> siedzenia;
        setLiczbaMiejscSiedzacych(siedzenia);
        cout << "Podaj liczbe miejsc stojących: ";
        cin >> stojace;
        setLiczbaMiejscStojacych(stojace);
    }

    void wyswietl() const
    {
        Pojazd::wyswietl();
        cout << "Miejsca siedzące: " << getLiczbaMiejscSiedzacych() << ", Miejsca stojące: " << getLiczbaMiejscStojacych() << endl;
    }
};

int main()
{
    int wybor;
    Autobus autobus("Solaris", "Ubino", 2000, 20, 30);

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
