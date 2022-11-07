#pragma once
#include "Personaje.h"
#include "Enfermero.h"
#include "Bala.h"

class Contagiado : public Personaje {
private:
	bool colision = false;
public:
	Contagiado(int anchoV, int velocidad);
	~Contagiado();
	void dibujaContagiado(System::Drawing::BufferedGraphics^ buffer, System::Drawing::Bitmap^ bmp);
	void mueveContagiado(System::Drawing::BufferedGraphics^ buffer, System::Drawing::Bitmap^ bmp, Enfermero*);
	bool getColision();
	bool checkColision(Bala* bala);
};