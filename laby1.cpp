#include <iostream>
#include <string>
using namespace std;

void dodajOsobe(string *tabNazwiska,string Nazwisko){
	for(int i=0; i<10;i++){
		if (tabNazwiska[i] == ""){
			tabNazwiska[i] = Nazwisko;
			break;
		};
	};
};

void ustawObecnosc(string *tabNazwiska, bool *tabObecnosc, string Nazwisko, bool obecnosc){
	for(int i=0;i<10;i++){
		if(tabNazwiska[i]==Nazwisko){
			tabObecnosc[i] = true;
			break;
		};
	};
};

void DrukujListe(string *tabNazwiska,bool *tabObecnosc){
	for(int i=0;i<10;i++){
		cout<<tabNazwiska[i]<<" "<<tabObecnosc[i]<<endl;
	};
};

int main(){
	string tabNazwiska[10];
	bool tabObecnosc[10]={};
	string Nazwisko;
	bool Obecnosc;
	int wybor;
	cout<<"masz do wyboru 1:dodać osobe, 2: ustawić jej obecnosc, 3: wydrukować liste obecnosci, 4:zamknąć program"<<endl;

    while(wybor !=4){
		cin>>wybor;
		switch(wybor){
			case(1):
				cout<<"podaj nazwisko"<<endl;
				cin>>Nazwisko;
				dodajOsobe(tabNazwiska,Nazwisko);
				break;
			case(2):
				cout<<"podaj nazwisko"<<endl;
				cin>>Nazwisko;
				cout<<"podaj czy ma być obecna(1) czy nieobecna(0)"<<endl;
				cin>>Obecnosc;
				ustawObecnosc(tabNazwiska,tabObecnosc,Nazwisko,Obecnosc);
				break;
			case(3):
				DrukujListe(tabNazwiska,tabObecnosc);
				break;
		};
	};
	};
