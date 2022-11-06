#include "GestorEnfermo.h"
#include "constantes.h"

using namespace std;
using namespace System::Drawing;

GesContagiado::GesContagiado() = default;
GesContagiado::~GesContagiado() = default;

void GesContagiado::agregaContagiado(Contagiado* oc) {
	lista_contagiados.push_back(oc);
}
void GesContagiado::creaContagiados(int cantidad) {
	Contagiado* oc;
	for (int i = 0; i < cantidad; i++) {
		oc = new Contagiado(WIDTH_VENTANA + rand() % (WIDTH_VENTANA / 2), 4);
		lista_contagiados.push_back(oc);
	}
}

void GesContagiado::moverContagiados(BufferedGraphics^ buffer, Bitmap^ bmp, Enfermero* enf) {
	for (int i = 0; i < lista_contagiados.size(); i++) {
		lista_contagiados[i]->mueveContagiado(buffer, bmp, enf);
	}
}