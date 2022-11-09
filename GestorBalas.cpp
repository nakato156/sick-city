#include "GestorBalas.h"
using namespace std;
using namespace System::Drawing;

GestorBalas::GestorBalas() = default;

void GestorBalas::addBala(Bala * bala) { lista.push_back(bala); }
vector<Bala*> GestorBalas::getLista() { return lista; }
void GestorBalas::animar(BufferedGraphics^ buffer, Bitmap^ bmp) {
	for (auto bala : lista) bala->Animar(buffer, bmp); 
}
void GestorBalas::delBala(Bala* bala) {}

void GestorBalas::actualizarLista() {
	vector <Bala*> lista_nueva;
	for (auto bala : lista) {
		bool valor_colision = bala->getColision();
		if (!valor_colision) {
			lista_nueva.push_back(bala);
		}
	}
	lista = lista_nueva;
}
void GestorBalas::actualizarSalida(System::Drawing::BufferedGraphics^ buffer) {
	vector <Bala*> nueva_lista;
	for (auto bala : lista) {
		if (bala->checkSalida(buffer)) {
			continue;
		}
		nueva_lista.push_back(bala);
	}
	lista = nueva_lista;
}