#include <iostream>
#include <string>

using namespace std;

//exceptie custom

class ExceptieCustom : public exception
{
public:
	ExceptieCustom(const char* mesaj) : exception(mesaj) {}
};


// mostenire 2 clase: clasa de baza(parinte)- avem atribute si metode
// si clasa derivata(copii)- mostenim atribute si metode de la parinte
// clasa mostenita - is a a parintelui 
//protected- mostenire, atributele din public si protected se vad la copii
//polimorfism supraincarcarea operatorilor si metode virtuale
// clasa de baza sau clasa parinte Laptop

class Laptop {
	//incapsulare private prima si public a doua

private:
	int memorie;
	string marca;
	float pret;
	static const float PRET_MINIM;
	// la constante folosim majuscule 

public:
	Laptop() {

		// dam valori default
		this->memorie = 0;
		this->marca = "Nedefinita";
		this->pret = 0;
	}
	Laptop(int memorie, string marca, float pret) {


		this->memorie = memorie;
		this->marca = marca;
		if (pret < PRET_MINIM) {
			throw ExceptieCustom("Pretul este prea mic");
		}
		else {
			this->pret = pret;
		}
	}

	void afisare() {


		cout << endl << "Memorie: " << this->memorie << endl << "Marca: " << this->marca << endl << "Pret: " << this->pret;
		cout << endl;
	}

};


const float Laptop::PRET_MINIM = 1;
// clasa derivata :( ca mosteneste) public clasa pe care o mosteneste
//apelam metodele din clasa parinte si adaugam atribute din clasa copii
class LaptopGaming : public Laptop {
private:
	string placaVideo;

public:
	//constructor default folosim constructorul din clasa de baza
	LaptopGaming() :Laptop() {
		//atribute mostenite



		//atribut nou
		this->placaVideo = "Nedefinit";


	}

	LaptopGaming(int memorie, string marca, float pret, string placaVideo) :Laptop(memorie, marca, pret) {
		//atribute mostenite



		//atribut nou
		this->placaVideo = placaVideo;


	}
	void afisare() {
		//folosim metoda de afisare din clasa de baza si adaugam atributele noi
		this->Laptop::afisare();
		cout << endl << "Placa video: " << this->placaVideo;
	}


};


int main() {
	try {
		Laptop lenovo(500, "Lenovo", 7000);
		lenovo.afisare();
	}
	catch (ExceptieCustom e) {
		cout << endl << e.what();
	};



	LaptopGaming laptopGaming(500, "Asus", 7000, "NVIDIA");
	laptopGaming.afisare();




}