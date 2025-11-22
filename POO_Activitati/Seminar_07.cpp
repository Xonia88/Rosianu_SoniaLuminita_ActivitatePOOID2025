#include<iostream>
#include<string>

using namespace std;
enum Tip { BIO = 7, DE_BAZA = 3, NORMAL = 5 };

class ProdusAlimentar {
private:
	const int id;
	float pret;
	string denumire;
	Tip tip;
	int nrIngrediente;
	float* cantitati;
	static int nrProduseAlimentare;
public:
	//constructor default//fara parametri
	ProdusAlimentar() :id(++nrProduseAlimentare) {
		this->denumire = "Produs default";
		this->pret = 0;
		this->nrIngrediente = 0;
		this->cantitati = nullptr;
		this->tip = NORMAL;
	}

	ProdusAlimentar(string denumire, float pret, int nrIngrediente, float* cantitatiIngrediente, Tip tip) :id(++nrProduseAlimentare) {
		this->denumire = denumire;
		this->pret = pret;
		this->nrIngrediente = nrIngrediente;
		this->cantitati = new float[this->nrIngrediente];
		for (int i = 0; i < this->nrIngrediente; i++) {
			this->cantitati[i] = cantitatiIngrediente[i];
		}
		this->tip = tip;

		delete[] cantitatiIngrediente;
	}

	ProdusAlimentar(const ProdusAlimentar& copie) :id(++nrProduseAlimentare) {
		this->pret = copie.pret;
		this->denumire = copie.denumire;
		this->tip = copie.tip;
		this->nrIngrediente = copie.nrIngrediente;

		if (copie.cantitati != nullptr) {
			this->cantitati = new float[copie.nrIngrediente];
			for (int i = 0; i < copie.nrIngrediente; i++) {
				this->cantitati[i] = copie.cantitati[i];
			}
		}
		else {
			this->cantitati = nullptr;
		}
	}

	void operator=(const ProdusAlimentar& copie) {
		this->denumire = copie.denumire;
		this->pret = copie.pret;
		this->tip = copie.tip;
		this->nrIngrediente = copie.nrIngrediente;

		if (this->cantitati != nullptr) {
			delete[] this->cantitati;
			this->cantitati = nullptr;
		}

		if (copie.cantitati != nullptr) {
			this->cantitati = new float[copie.nrIngrediente];
			for (int i = 0; i < copie.nrIngrediente; i++) {
				this->cantitati[i] = copie.cantitati[i];
			}
		}
		else {
			this->cantitati = nullptr;
		}
		//return *this;
	}

	void afisareProdusAlimentar() {
		cout << endl << this->id << ". Produsul alimentar " << this->denumire << " costa " << this->pret << " lei, este de tipul ";
		if (this->tip == NORMAL) cout << "NORMAL";
		if (this->tip == BIO) cout << "BIO";
		if (this->tip == DE_BAZA) cout << "DE_BAZA";
		cout << " si contine " << this->nrIngrediente << " ingrediente: ";
		if (this->cantitati != nullptr) {
			for (int i = 0; i < this->nrIngrediente - 1; i++) {
				cout << this->cantitati[i] << " grame, ";
			}
			cout << this->cantitati[this->nrIngrediente - 1] << " grame.";
		}
	}

	//get si set pentru nrIngrediente
	int getNrIngrediente() {
		return this->nrIngrediente;
	}

	void setNrIngrediente(int nrIngredienteNou) {
		if (nrIngredienteNou > 0)
		{
			this->nrIngrediente = nrIngredienteNou;
		}
		else {
			//throw exception();
			//throw 404;
			throw "Valoare negativa";
		}
	}

	//get si set pentru pointeri
	float* getCantitati() {
		//return this->cantitati; - asa nu
		float* copieCantitati = new float[this->nrIngrediente];
		for (int i = 0; i < this->nrIngrediente; i++) {
			copieCantitati[i] = this->cantitati[i];
		}

		return copieCantitati;
	}

	void setCantitati(float* cantitatiNoi, int nrIngredienteNou) {
		setNrIngrediente(nrIngredienteNou);

		if (this->cantitati != nullptr) {
			delete[] this->cantitati;
		}
		this->cantitati = new float[this->nrIngrediente];
		for (int i = 0; i < this->nrIngrediente; i++) {
			this->cantitati[i] = cantitatiNoi[i];
		}

		delete[] cantitatiNoi;
	}

	~ProdusAlimentar() {
		if (this->cantitati != nullptr) {
			delete[] this->cantitati;
		}
	}

	void operator+=(float pretDeAdunat) {
		this->pret += pretDeAdunat;
	}

	bool operator>(const ProdusAlimentar& pa) {
		return this->pret > pa.pret;
	}

	//operatorul negatie
	bool operator!() {
		return this->pret > 0;
	}

	//operatorul functie
	float operator()(float valoareDeAdaugat)
	{
		return this->pret + valoareDeAdaugat;
	}

	//operatorul index
	float& operator[](int index) {
		if (index >= 0 && index < this->nrIngrediente) {
			return this->cantitati[index];
		}
		else {
			throw exception();
		}
	}

	//operator << / operator de afisare
	friend void operator<<(ostream& out, ProdusAlimentar prod) {
		out << endl << "Operator de afisare: ";
		out << endl << "Id: " << prod.id;
		out << endl << "Denumire: " << prod.denumire;
		out << endl << "Pret: " << prod.pret;
		out << endl << "Tip: ";
		if (prod.tip == NORMAL) out << "NORMAL";
		if (prod.tip == BIO) out << "BIO";
		if (prod.tip == DE_BAZA) out << "DE_BAZA";
		out << endl << "Nr ingrediente: " << prod.nrIngrediente;
		if (prod.cantitati != nullptr) {
			out << endl << "Cantitati: ";
			for (int i = 0; i < prod.nrIngrediente - 1; i++) {
				out << prod.cantitati[i] << " grame, ";
			}
			out << prod.cantitati[prod.nrIngrediente - 1] << " grame.";
		}
	}

	friend void operator>>(istream& in, ProdusAlimentar& prod);

	//postincrementare
	ProdusAlimentar operator++(int) {
		ProdusAlimentar copie = *this;
		this->pret++;

		return copie;
	}

	//preincrementare
	ProdusAlimentar operator++() {
		this->pret++;
		return *this;
	}

	//cast explicit
	explicit operator int() {
		return this->nrIngrediente;
	}
};

int ProdusAlimentar::nrProduseAlimentare = 0;

void operator>>(istream& in, ProdusAlimentar& prod) {
	cout << endl << "Pret: ";
	in >> prod.pret;

	cout << endl << "Denumire: ";
	in >> prod.denumire;

	cout << endl << "Tip: ";
	int tip;
	in >> tip;

	if (tip == 5) prod.tip = NORMAL;
	if (tip == 7) prod.tip = BIO;
	if (tip == 3) prod.tip = DE_BAZA;

	cout << endl << "Nr ingrediente: ";
	in >> prod.nrIngrediente;

	cout << endl << "Cantitati: ";

	if (prod.cantitati != nullptr) {
		delete[] prod.cantitati;
		prod.cantitati = nullptr;
	}

	prod.cantitati = new float[prod.nrIngrediente];
	for (int i = 0; i < prod.nrIngrediente; i++) {
		cout << endl << "cantitati[" << i << "]: ";
		in >> prod.cantitati[i];
	}
}

void main() {
	ProdusAlimentar pizza;
	pizza.afisareProdusAlimentar();

	float* cantitati = new float[3] {100, 200, 300};
	ProdusAlimentar* sushi = new ProdusAlimentar("sushi", 100, 3, cantitati, BIO);
	sushi->afisareProdusAlimentar();

	if (!pizza) {
		cout << endl << "Pretul este mai mare decat 0!";
	}
	else {
		cout << endl << "Pretul este mai mic sau egal cu 0!";
	}

	cout << endl << pizza(2.5);

	(*sushi)[0] = 101;

	cout << endl << (*sushi)[0];

	cout << *sushi;

	//cin >> pizza;
	//cout << pizza;
	//pizza are pretul 0;
	ProdusAlimentar pa = pizza++;
	//pizza are pretul 1;
	ProdusAlimentar pa2 = ++pizza;
	//pizza are pretul 2;
	//pa are pretul 0;
	//pa2 are pretul 2;

	cout << pa;
	cout << pa2;

	cout << (int)(*sushi);

	delete sushi;
}