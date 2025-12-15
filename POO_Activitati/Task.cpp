#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

/*
  Proiect POO - Faza 1
  Student: Sonia Rosianu
  Initiale: SR
  Domeniu: Restaurant
*/

// =======================
// Clasa Restaurant
// =======================
class Restaurant {
public:
    const int idRestaurant;
    static int nrRestaurante;

    char* nume;
    int capacitate;
    float rating;

    // Constructor implicit
    Restaurant() : idRestaurant(++nrRestaurante) {
        nume = new char[strlen("Necunoscut") + 1];
        strcpy(nume, "Necunoscut");
        capacitate = 0;
        rating = 0;
    }

    // Constructor cu 1 parametru
    Restaurant(const char* nume) : idRestaurant(++nrRestaurante) {
        this->nume = new char[strlen(nume) + 1];
        strcpy(this->nume, nume);
        capacitate = 50;
        rating = 3;
    }

    // Constructor cu 3 parametri
    Restaurant(const char* nume, int capacitate, float rating) : idRestaurant(++nrRestaurante) {
        this->nume = new char[strlen(nume) + 1];
        strcpy(this->nume, nume);
        this->capacitate = capacitate;
        this->rating = rating;
    }

    // Functie statica
    static int getNrRestaurante() {
        return nrRestaurante;
    }

    void afisare() {
        cout << endl << "Restaurant " << idRestaurant
            << ": " << nume
            << ", capacitate " << capacitate
            << ", rating " << rating;
    }

    ~Restaurant() {
        delete[] nume;
    }
};

int Restaurant::nrRestaurante = 0;

// =======================
// Clasa Rezervare
// =======================
class Rezervare {
public:
    const int idRezervare;
    static int nrRezervari;

    char* numeClient;
    int nrPersoane;

    // Constructor implicit
    Rezervare() : idRezervare(++nrRezervari) {
        numeClient = new char[strlen("Anonim") + 1];
        strcpy(numeClient, "Anonim");
        nrPersoane = 0;
    }

    // Constructor cu 1 parametru
    Rezervare(const char* client) : idRezervare(++nrRezervari) {
        numeClient = new char[strlen(client) + 1];
        strcpy(numeClient, client);
        nrPersoane = 2;
    }

    // Constructor cu 2 parametri
    Rezervare(const char* client, int nrPersoane) : idRezervare(++nrRezervari) {
        numeClient = new char[strlen(client) + 1];
        strcpy(numeClient, client);
        this->nrPersoane = nrPersoane;
    }

    // Functie statica
    static int getNrRezervari() {
        return nrRezervari;
    }

    void afisare() {
        cout << endl << "Rezervare " << idRezervare
            << ": client " << numeClient
            << ", persoane " << nrPersoane;
    }

    ~Rezervare() {
        delete[] numeClient;
    }
};

int Rezervare::nrRezervari = 0;

// =======================
// Clasa Reteta
// =======================
class Reteta {
public:
    const int idReteta;
    static int nrRetete;

    char* denumire;
    int calorii;

    // Constructor implicit
    Reteta() : idReteta(++nrRetete) {
        denumire = new char[strlen("Fara nume") + 1];
        strcpy(denumire, "Fara nume");
        calorii = 0;
    }

    // Constructor cu 1 parametru
    Reteta(const char* denumire) : idReteta(++nrRetete) {
        this->denumire = new char[strlen(denumire) + 1];
        strcpy(this->denumire, denumire);
        calorii = 200;
    }

    // Constructor cu 2 parametri
    Reteta(const char* denumire, int calorii) : idReteta(++nrRetete) {
        this->denumire = new char[strlen(denumire) + 1];
        strcpy(this->denumire, denumire);
        this->calorii = calorii;
    }

    // Functie statica
    static int getNrRetete() {
        return nrRetete;
    }

    void afisare() {
        cout << endl << "Reteta " << idReteta
            << ": " << denumire
            << ", calorii " << calorii;
    }

    ~Reteta() {
        delete[] denumire;
    }
};

int Reteta::nrRetete = 0;

// =======================
// Functia main
// =======================
int main() {

    cout << "Proiect POO - Faza 1 - Sonia Rosianu (SR)" << endl;

    // Restaurante
    Restaurant r1;
    Restaurant r2("La Mama");
    Restaurant r3("Bistro SR", 120, 4.5f);

    r1.afisare();
    r2.afisare();
    r3.afisare();

    // Rezervari
    Rezervare z1;
    Rezervare z2("Ion Popescu");
    Rezervare z3("Ana Ionescu", 4);

    z1.afisare();
    z2.afisare();
    z3.afisare();

    // Retete
    Reteta t1;
    Reteta t2("Ciorba");
    Reteta t3("Sarmale", 650);

    t1.afisare();
    t2.afisare();
    t3.afisare();

    cout << endl << endl << "Total restaurante: " << Restaurant::getNrRestaurante();
    cout << endl << "Total rezervari: " << Rezervare::getNrRezervari();
    cout << endl << "Total retete: " << Reteta::getNrRetete();

    return 0;
}
