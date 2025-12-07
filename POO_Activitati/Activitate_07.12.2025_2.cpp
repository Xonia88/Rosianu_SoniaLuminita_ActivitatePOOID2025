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
//polimorfism supraincarcarea operatorilor si metode virtuale, un operator defineste un comportament diferit; metode virtuale 
// clasa de baza sau clasa parinte Laptop


// abstractiza: generalizarea clasei
//clasa abtractizata: clasa care contine cel putin o metoda virtuala pura
//clasa abtractizata nu poate fi instantiata 
// o interfata este clasa care contine doar metode virtuale pure
// o metoda virtuala pura este o metoda fara implementare, doar definire
//o metoda virtuala contine cuv cheie: virtual, ajuta compilatorul sa stie ce metoda sa apeleze
//clasele derivate care implementeaza/mosteneste o clasa abstracta este"fortata" sa implementeze metoda virtuala pura


//transfomam clasa laptop in clasa abstracta, adaugam metoda virtuala pura
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

	virtual void afisare() {


		cout << endl << "Memorie: " << this->memorie << endl << "Marca: " << this->marca << endl << "Pret: " << this->pret;
		cout << endl;
	}
	//metoda virtuala pura
	// =0 marcheaza ca nu este implementare
	virtual string getPlacaVideo() = 0;
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
	virtual string getPlacaVideo()
	{
		return this->placaVideo;
	};

};


int main() {
	Laptop* vectorLaptopuri[3];//vector de pointer la obiect 
	vectorLaptopuri[0] = new LaptopGaming(500, "Lenovo", 7000, "NVIDIA");
	vectorLaptopuri[1] = new LaptopGaming(250, "Asus", 3500, "INTEL");
	vectorLaptopuri[2] = new LaptopGaming(1000, "Samsung", 6000, "NVIDIA");


	//trebuie modificata metoda de afisare in metoda virtuala pura
	for (int i = 0; i < 3; i++)
	{
		vectorLaptopuri[i]->afisare();
		delete vectorLaptopuri[i];
	}


}
// in clasa parinte metoda de afisare virtuala, in clasa copil nu e virtuala si foloseste metoda din clasa parinte 