#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

using namespace std;

class Banca {
private:
    string denumire = "Necunoscut";
    char* locatie = nullptr;
    int nrAngajati = 0;
    bool areProfit = true;

public:

    // Constructor default
    Banca() {}

    // Constructor cu parametri 
    Banca(string denumire,
        const char* locatie,
        int nrAngajati,
        bool areProfit)
    {
        this->denumire = denumire;
        this->nrAngajati = nrAngajati;
        this->areProfit = areProfit;

        this->locatie = new char[strlen(locatie) + 1];
        strcpy_s(this->locatie, strlen(locatie) + 1, locatie);
    }

    // Destructor
    ~Banca() {
        if (this->locatie != nullptr) {
            delete[] this->locatie;
            locatie = nullptr;
        }
    }

    // Operator << pentru cout
    friend ostream& operator<<(ostream& out, const Banca& b) {
        out << "\nNumar angajati: " << b.nrAngajati;
        out << "\nDenumire: " << b.denumire;
        out << "\n" << (b.areProfit ? "Are profit" : "Nu are profit");
        out << "\nLocatie: " << (b.locatie != nullptr ? b.locatie : "Locatie default");
        out << "\n";
        return out;
    }

    // Operator << pentru fstream (scriere in fisier)
    friend fstream& operator<<(fstream& outFile, const Banca& b) {
        outFile << b.nrAngajati << endl;
        outFile << b.denumire << endl;
        outFile << b.areProfit << endl;
        outFile << (b.locatie != nullptr ? b.locatie : "Locatie default") << endl;
        return outFile;
    }

    // Operator >> pentru ifstream (citire din fisier)
    friend ifstream& operator>>(ifstream& inFile, Banca& b) {

        inFile >> b.nrAngajati;
        inFile >> b.denumire;
        inFile >> b.areProfit;

        // Eliberare memorie veche
        if (b.locatie != nullptr) {
            delete[] b.locatie;
            b.locatie = nullptr;
        }

        char buffer[256];
        inFile >> buffer;

        b.locatie = new char[strlen(buffer) + 1];
        strcpy_s(b.locatie, strlen(buffer) + 1, buffer);

        return inFile;
    }
};


int main() {

    Banca bcr("BCR", "PiataRomana", 15, true);

    // Scriere in fisier
    fstream fileStream("Banca.txt", ios::out);
    fileStream << bcr;
    fileStream.close();

    // Citire din fisier
    Banca bcrCopie;
    ifstream inputFileStream("Banca.txt");
    inputFileStream >> bcrCopie;
    inputFileStream.close();

    cout << "\n--- Obiectul original ---";
    cout << bcr;

    cout << "\n--- Obiectul citit din fisier ---";
    cout << bcrCopie;

    return 0;
}
