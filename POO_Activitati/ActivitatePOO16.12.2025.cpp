#include<iostream>
#include<list>
#include<iterator>

using namespace std;

//tema: map, set, vector

class Laptop {
private:
	float pret;
public:
	Laptop() :pret(0) {}
	Laptop(float pret) :pret(pret) {}
	float getPret() { return this->pret; }

	Laptop operator+(const Laptop l) {
		Laptop laptop = *this;
		laptop.pret = this->pret + l.pret;
		return laptop;
	}
};

template<class T>
T suma(T a, T b) {
	return a + b;
}

template<class colectie>
class Telefon {
private:
	int nrComponente;
	colectie* preturiComponente;
public:
	Telefon(int nrComponente, colectie* preturiComponente) {
		this->nrComponente = nrComponente;
		this->preturiComponente = new colectie[this->nrComponente];
		for (int i = 0; i < this->nrComponente; i++) {
			this->preturiComponente[i] = preturiComponente[i];
		}
	}

	Telefon() {
		this->nrComponente = 0;
		this->preturiComponente = nullptr;
	}

	~Telefon() {
		if (this->preturiComponente != nullptr) {
			delete[] this->preturiComponente;
		}
	}

	float pretMediu() {
		float medie = 0;
		for (int i = 0; i < this->nrComponente; i++) {
			medie += this->preturiComponente[i];
		}
		if (this->nrComponente > 0)
			return medie / this->nrComponente;
		else {
			return 0;
		}
	}
};

void afisareLista(list<int> lista) {
	list<int>::iterator it;
	cout << endl << "Parcurgere lista: ";
	for (it = lista.begin(); it != lista.end(); it++) {
		cout << " " << *it;
	}
}

int main() {
	cout << endl << suma(7, 8);
	cout << endl << suma(7.5, 8.4);
	Laptop laptop1(2000);
	Laptop laptop2(4000);
	Laptop laptop3 = suma(laptop1, laptop2);
	cout << endl << laptop3.getPret();

	float* preturi = new float[3] {100, 200, 300};
	Telefon<float> telefon(3, preturi);
	cout << endl << telefon.pretMediu();

	list<int> lista1, lista2;

	for (int i = 0; i < 3; i++) {
		lista1.push_front(i);
		lista2.push_front(i * 2);
	}

	afisareLista(lista1);
	afisareLista(lista2);

	lista1.pop_front();
	afisareLista(lista1);

	lista2.sort();
	afisareLista(lista2);

	lista1.reverse();
	afisareLista(lista1);
}