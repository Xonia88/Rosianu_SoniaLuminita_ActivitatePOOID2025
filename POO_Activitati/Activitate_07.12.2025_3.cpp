#include <iostream>

using namespace std;
//compunere sintagma has-a, o clasa contine obiect sau obiecte de tipul altei clase
// clasa a 2-a are obiect din prima clasa


class Autocar {
private:
	float nrKm = 0;//daca dam valori default aici, in contr default nu mai dam valori

public:
	Autocar() {}

	Autocar(float nrKM) :nrKm(nrKM) {}

	float getNrKm() {
		return this->nrKm;

	}
};

class Autobaza
{
private:
	//compunere 1:1 , 1 autobaza are 1 autocare
	Autocar  autocar;// ca tema

	//1:m
	Autocar* vector;
	int nrAutocare;
	string denumire;

public:
	Autobaza(string denumire, int nrAutocare, float* vectorNrKm) {
		this->denumire = denumire;
		this->nrAutocare = nrAutocare;
		this->vector = new Autocar[nrAutocare];
		for (int i = 0; i < nrAutocare; i++) {

			this->vector[i] = Autocar(vectorNrKm[i]);
		}
	}
	Autocar& operator [](int index) {
		if (index >= 0 && index < this->nrAutocare)
		{
			return this->vector[index];
		}
		else {
			throw "Index-ul este in afara intervalului";
		}
	}


	Autobaza(const Autobaza& a) {
		this->denumire = a.denumire;
		this->nrAutocare = a.nrAutocare;
		if (a.vector != nullptr) {
			this->vector = new Autocar[a.nrAutocare];
			for (int i = 0; i < a.nrAutocare; i++) {

				//this->vector[i] = Autocar(a.vector[i].getNrKm());
				this->vector[i] = a.vector[i];
			}
		}
		else
		{

			this->vector = nullptr;

		}
	}

};

int main() {

	float* vectorNrKm = new float[2] {1500000, 756000};
	Autobaza a1("Giulesti", 2, vectorNrKm);
	cout << endl << "Nr km pt al doilea autocar: " << a1[1].getNrKm();
	Autobaza a2 = a1;
	cout << endl << "Nr km pt al doilea autocar: " << a2[1].getNrKm();

};