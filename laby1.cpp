#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Student {
private:
    string nazwisko;
    string imie;
    string indeks;

public:
    void setNazwisko(string n) {
        nazwisko = n;
    }
    string getNazwisko() {
        return nazwisko;
    }
    
    void setImie(string n) {
        imie = n;
    }
    string getImie() {
        return imie;
    }
    
    void setIndeks(string n) {
        indeks = n;
    }
    string getIndeks() {
        return indeks;
    }
    
    void ustawDane(string noweImie, string noweNazwisko, string nowyIndeks) {
        setImie(noweImie);
        setNazwisko(noweNazwisko);
        setIndeks(nowyIndeks);
    }
};

class listaObecnosci {
private:
    Student tabStudent[10];
    bool tabObecnosc[10] = {};

public:
    void dodajOsobe(Student student);
    void ustawObecnosc(string nazwisko, bool obecnosc);
    void drukujListe();
    void usunOsobe(string nazwisko);
    
    Student* getTabStudent() {
        return tabStudent;
    }
};

void listaObecnosci::dodajOsobe(Student student) {
    for(int i = 0; i < 10; i++) {
        if(tabStudent[i].getNazwisko() == "") {
            tabStudent[i] = student;
            return;
        }
    }
    cout << "Lista jest pelna!" << endl;
}

void listaObecnosci::usunOsobe(string nazwisko) {
    for(int i = 0; i < 10; i++) {
        if(tabStudent[i].getNazwisko() == nazwisko) {
            tabStudent[i] = Student();
            tabObecnosc[i] = false;
            cout << "Usunieto studenta: " << nazwisko << endl;
            return;
        }
    }
    cout << "Nie znaleziono studenta o takim nazwisku." << endl;
}

void listaObecnosci::ustawObecnosc(string nazwisko, bool obecnosc) {
    for(int i = 0; i < 10; i++) {
        if(tabStudent[i].getNazwisko() == nazwisko) {
            tabObecnosc[i] = obecnosc;
            cout << "Zaktualizowano obecnosc." << endl;
            return;
        }
    }
    cout << "Nie znaleziono studenta o takim nazwisku." << endl;
}

void listaObecnosci::drukujListe() {
    cout << "\n--- LISTA OBECNOSCI ---" << endl;
    for(int i = 0; i < 10; i++) {
        if(tabStudent[i].getNazwisko() != "") {
            cout << tabStudent[i].getImie() << " " 
                 << tabStudent[i].getNazwisko() << " (Indeks: " 
                 << tabStudent[i].getIndeks() << ") - Obecnosc: " 
                 << tabObecnosc[i] << endl;
        }
    }
    cout << "-----------------------" << endl;
}

class interfejsUzytkownika {
private:
    listaObecnosci *wskaznikNaListe;
    Student *wskaznikNaTablice;
    
    listaObecnosci *listaPpo;
    listaObecnosci *listaAnaliza;

public:
    interfejsUzytkownika(listaObecnosci *ppo, listaObecnosci *analiza) {
        listaPpo = ppo;
        listaAnaliza = analiza;
        
        wskaznikNaListe = listaPpo;
        wskaznikNaTablice = wskaznikNaListe->getTabStudent();
    }

    void uruchomPetle();
};

void interfejsUzytkownika::uruchomPetle() {
    Student student;
    string nazwisko, imie, indeks;
    bool Obecnosc;
    int wybor = 0;
    int wyborListy = 0;

    cout << "Wybierz na jakiej liscie chcesz operowac (1 - PPO, 2 - Analiza): ";
    cin >> wyborListy;
    if (wyborListy == 1) {
        wskaznikNaListe = listaPpo;
    } else {
        wskaznikNaListe = listaAnaliza;
    }
    wskaznikNaTablice = wskaznikNaListe->getTabStudent();

    while(wybor != 6) {
        cout << "\n=== MENU GLOWNE ===" << endl;
        cout << "1. Dodaj osobe" << endl;
        cout << "2. Ustaw obecnosc" << endl;
        cout << "3. Wydrukuj liste" << endl;
        cout << "4. Zmien liste (PPO/Analiza)" << endl;
        cout << "5. Usun osobe" << endl;
        cout << "6. Zamknij program" << endl;
        cout << "Twoj wybor: ";
        cin >> wybor;
        
        switch(wybor) {
            case 1:
                cout << "Podaj imie: ";
                cin >> imie;
                cout << "Podaj nazwisko: ";
                cin >> nazwisko;
                cout << "Podaj indeks: ";
                cin >> indeks;
                
                student.ustawDane(imie, nazwisko, indeks);
                wskaznikNaListe->dodajOsobe(student);
                break;
                
            case 2:
                cout << "Podaj nazwisko studenta: ";
                cin >> nazwisko;
                cout << "Podaj czy ma byc obecna(1) czy nieobecna(0): ";
                cin >> Obecnosc;
                
                wskaznikNaListe->ustawObecnosc(nazwisko, Obecnosc);
                break;
                
            case 3:
                wskaznikNaListe->drukujListe();
                break;
                
            case 4:
                cout << "Wybierz na jakiej liscie chcesz operowac (1 - PPO, 2 - Analiza): ";
                cin >> wyborListy;
                if (wyborListy == 1) {
                    wskaznikNaListe = listaPpo;
                } else {
                    wskaznikNaListe = listaAnaliza;
                }
                wskaznikNaTablice = wskaznikNaListe->getTabStudent();
                cout << "Zmieniono aktywna liste!" << endl;
                break;
                
            case 5:
                cout << "Podaj nazwisko studenta do usuniecia: ";
                cin >> nazwisko;
                wskaznikNaListe->usunOsobe(nazwisko);
                break;
                
            case 6:
                cout << "Zamykanie programu..." << endl;
                break;
                
            default:
                cout << "Nieprawidlowy wybor. Sprobuj ponownie." << endl;
                break;
        }
    }
}

int main() {
    system("chcp 65001 > nul");
    listaObecnosci ppo1;
    listaObecnosci analiza1;
    interfejsUzytkownika menu(&ppo1, &analiza1);
    menu.uruchomPetle();
    return 0;
}