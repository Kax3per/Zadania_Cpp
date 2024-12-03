#include <iostream>
#include <string>
using namespace std;

// Klasa bazowa
class Pracownik
{
protected:
    string imie, nazwisko, stanowisko;

public:
    Pracownik(string imie, string nazwisko, string stanowisko)
        : imie(imie), nazwisko(nazwisko), stanowisko(stanowisko) {}

    virtual void wyswietlDane()
    {
        cout << "Stanowisko: " << stanowisko << ", Imie: " << imie << ", Nazwisko: " << nazwisko << endl;
    }
};

// Klasy pochodne
class Dyrektor : public Pracownik
{
public:
    Dyrektor(string imie, string nazwisko)
        : Pracownik(imie, nazwisko, "Dyrektor") {}
};

class Nauczyciel : public Pracownik
{
public:
    Nauczyciel(string imie, string nazwisko)
        : Pracownik(imie, nazwisko, "Nauczyciel") {}
};

class Wychowawca : public Pracownik
{
public:
    Wychowawca(string imie, string nazwisko)
        : Pracownik(imie, nazwisko, "Wychowawca") {}
};

class Sekretarka : public Pracownik
{
public:
    Sekretarka(string imie, string nazwisko)
        : Pracownik(imie, nazwisko, "Sekretarka") {}
};

// Główna funkcja z interfejsem
int main()
{
    Pracownik *pracownicy[10];
    int liczbaPracownikow = 0;
    int wybor;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Dodaj Dyrektora\n";
        cout << "2. Dodaj Nauczyciela\n";
        cout << "3. Dodaj Wychowawcę\n";
        cout << "4. Dodaj Sekretarkę\n";
        cout << "5. Wyświetl wszystkich pracowników\n";
        cout << "6. Wyjście\n";
        cout << "Wybierz opcję: ";
        cin >> wybor;

        if (wybor >= 1 && wybor <= 4)
        {
            string imie, nazwisko;
            cout << "Podaj imię: ";
            cin >> imie;
            cout << "Podaj nazwisko: ";
            cin >> nazwisko;

            switch (wybor)
            {
            case 1:
                pracownicy[liczbaPracownikow++] = new Dyrektor(imie, nazwisko);
                break;
            case 2:
                pracownicy[liczbaPracownikow++] = new Nauczyciel(imie, nazwisko);
                break;
            case 3:
                pracownicy[liczbaPracownikow++] = new Wychowawca(imie, nazwisko);
                break;
            case 4:
                pracownicy[liczbaPracownikow++] = new Sekretarka(imie, nazwisko);
                break;
            }
        }
        else if (wybor == 5)
        {
            cout << "\nLista pracowników:\n";
            for (int i = 0; i < liczbaPracownikow; i++)
            {
                pracownicy[i]->wyswietlDane();
            }
        }
        else if (wybor != 6)
        {
            cout << "Nieprawidłowa opcja! Spróbuj ponownie.\n";
        }
    } while (wybor != 6);

    // Czyszczenie pamięci
    for (int i = 0; i < liczbaPracownikow; i++)
    {
        delete pracownicy[i];
    }

    cout << "Koniec programu.\n";
    return 0;
}
