#include<iostream>
using namespace std;

class Osoba {
protected:
    string imie;
    string nazwisko;
public:
    void setImie(string noweImie){
        imie = noweImie;
    }
    string getImie(){
    return imie;
    }
    virtual void Drukuj(){
        cout <<"Osoba: "<< imie << endl;
    }
};

class Student: public Osoba {
    private:
        string nr_indeks;
    public:
        void setImie(string noweImie){
            imie = noweImie;
        }
        string getImie(){
            return imie;
        }
        void Drukuj(){
        cout <<"Student: "<< imie << endl;
        }

};

class Pracownik: public Osoba {
    private:
        string stanowisko;
    public:
        void setImie(string noweImie){
            imie = noweImie;
        }
        string getImie(){
            return imie;
        }
        void Drukuj(){
        cout <<"Pracownik: "<< imie << endl;
        }
};

int main()
{
    Osoba *tab[10];

    Osoba os1;
    Student st1;
    Pracownik pc1;

    tab[0]=&os1;
    tab[1]=&st1;
    tab[2]=&pc1;

    tab[0]->Drukuj();
    tab[1]->Drukuj();
    tab[2]->Drukuj();
}