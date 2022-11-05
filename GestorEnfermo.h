#pragma once
#include <iostream>
#include "Enfermo.h"
#include <vector>
using namespace std;

class GesContagiado {
public:
	vector <Contagiado*> lista_contagiados;
	GesContagiado(){}
	~GesContagiado() {}
	void agregaContagiado(Contagiado* oc) {
		lista_contagiados.push_back(oc);
	}
	void agregaContagiados(int cantidad) {
		Contagiado* oc;
		for (int i = 0; i < cantidad; i++) {
			oc = new Contagiado(10 + rand() % (200 - 10), 10 + rand() % (200 - 10), 1 + rand() % 3 - 1);
			lista_contagiados.push_back(oc);
		}
	}
	void moverContagiados(BufferedGraphics^ buffer, Bitmap^ bmp) {
		for (int i = 0; i < lista_contagiados.size(); i++) {
			lista_contagiados[i]->mueveContagiado(buffer, bmp);
		}
	}
};