#pragma once
#include <iostream>
#include "Enfermo.h"
#include "Enfermero.h"
#include <vector>

class GesContagiado {
public:
	std::vector <Contagiado*> lista_contagiados;
	GesContagiado();
	~GesContagiado();
	void agregaContagiado(Contagiado* oc);
	void creaContagiados(int cantidad);
	void moverContagiados(System::Drawing::BufferedGraphics^ buffer, System::Drawing::Bitmap^ bmp, Enfermero*);
};