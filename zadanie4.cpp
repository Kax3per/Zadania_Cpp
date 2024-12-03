#include <iostream>
#include <string>
using namespace std;

// Klasa Pracownik z hermetyzacją
class Pracownik {
private:
    string imie, nazwisko, stanowisko;

public:
    Pracownik(string imie, string nazwisko, string stanowisko)
        : imie(imie), nazwisko(nazwisko), stanowisko(stanowisko) {}

    string getImie() const { return imie; }
    string getNazwisko() const { return nazwisko; }
    string getStanowisko() const { return stanowisko; }

    void wyswietlDane() {
        cout << "Stanowisko: " << stanowisko << ", Imie: " << imie << ", Nazwisko: " << nazwisko << endl;
    }
};

// Testowy program
int main() {
    Pracownik pracownik("Jan", "Kowalski", "Dyrektor");

    // Użycie getterów do wyświetlenia danych
    cout << "Imie: " << pracownik.getImie() << endl;
    cout << "Nazwisko: " << pracownik.getNazwisko() << endl;
    cout << "Stanowisko: " << pracownik.getStanowisko() << endl;

    pracownik.wyswietlDane();

    return 0;
}
