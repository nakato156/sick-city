#pragma once
#include "Personaje.h"
#include "Enfermero.h"

class Contagiado : public Personaje {
public:
	Contagiado(int anchoV, int velocidad);
	~Contagiado();
	void dibujaContagiado(System::Drawing::BufferedGraphics^ buffer, System::Drawing::Bitmap^ bmp);
	void mueveContagiado(System::Drawing::BufferedGraphics^ buffer, System::Drawing::Bitmap^ bmp, Enfermero*);
};