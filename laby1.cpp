#include <iostream>
#include <string>
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
    string getImie(){
        return imie;
    }
    void setIndeks(string n) {
        indeks = n;
    }
    string getIndeks() {
        return indeks;
    }
    void ustawDane(string imie, string nazwisko, string indeks);
};

class listaObecnosci {
private:
    Student tabStudent[10];
    bool tabObecnosc[10];
public:
    void dodajOsobe(Student student);
    void ustawObecnosc(string nazwisko, bool obecnosc);
    void drukujListe();
    void usunOsobe(string nazwisko);
};

void Student::ustawDane(string imie, string nazwisko, string indeks){
    setImie(imie);
    setNazwisko(nazwisko);
    setIndeks(indeks);
}

void listaObecnosci::dodajOsobe(Student student){
    for(int i=0;i<10;i++)
    {
        if(tabStudent[i].getNazwisko()=="")
        {
            tabStudent[i]=student;
            return;
        }
    }
}

void listaObecnosci::usunOsobe(string nazwisko){
    for(int i=0;i<10;i++){
            if(tabStudent[i].getNazwisko()==nazwisko){
                tabStudent[i]=Student();
                tabObecnosc[i]=false;
                break;
            }
        }
}

void listaObecnosci::ustawObecnosc(string nazwisko, bool obecnosc){
	for(int i=0;i<10;i++){
		if(tabStudent[i].getNazwisko()==nazwisko){
			tabObecnosc[i] = obecnosc;
			break;
		}
	}
}

void listaObecnosci::drukujListe(){
	for(int i=0;i<10;i++){
        if(tabStudent[i].getNazwisko() != ""){
            cout<<tabStudent[i].getImie()<<" "<<tabStudent[i].getNazwisko()<<" "<<tabObecnosc[i]<<endl;
        }
	}
}

int main(){
    listaObecnosci ppo1;
    listaObecnosci analiza1;
    Student student;
	string nazwisko;
    string imie;
    string indeks;
	bool Obecnosc;
	int wybor = 0;
    int wyborListy =0;
    listaObecnosci *aktywnaLista;


    cout<<"wybierz czy chcesz operować na liście (1)ppo1 czy (2)analiza1";
    cin>>wyborListy;
    switch(wyborListy){
        case(1):
            aktywnaLista = &ppo1;
            break;
        case(2):
            aktywnaLista = &analiza1;
            break;
    }
    while(wybor !=5){
    
    cout<<"masz do wyboru 1:dodać osobe, 2: ustawić jej obecnosc, 3: wydrukować liste obecnosci, 4:wybór listy, 5: zamknij program"<<endl;
		cin>>wybor;
		switch(wybor){
			case(1):
                cout<<"podaj imie"<<endl;
				cin>>imie;
                cout<<"podaj nazwisko"<<endl;
				cin>>nazwisko;
				cout<<"podaj indeks"<<endl;
				cin>>indeks;
                student.ustawDane(imie,nazwisko,indeks);
				aktywnaLista->dodajOsobe(student);
				break;
			case(2):
				cout<<"podaj nazwisko studenta"<<endl;
				cin>>nazwisko;
				cout<<"podaj czy ma być obecna(1) czy nieobecna(0)"<<endl;
				cin>>Obecnosc;
				aktywnaLista->ustawObecnosc(nazwisko,Obecnosc);
				break;
			case(3):
				aktywnaLista->drukujListe();
				break;
            case(4):
                cout<<"wybierz czy chcesz operować na liście (1)ppo1 czy (2)analiza1";
                cin>>wyborListy;
                switch(wyborListy){
                    case(1):
                        aktywnaLista = &ppo1;
                        break;
                    case(2):
                        aktywnaLista = &analiza1;
                        break;
                }

		};
	};
}
