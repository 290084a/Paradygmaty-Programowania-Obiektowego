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
};



int main()
{
    Osoba os1;
    Student student1;
    os1.setImie("Aleksander");
    student1.setImie("Michal");
    cout << student1.getImie() << endl;
    cout << os1.getImie() << endl;
}