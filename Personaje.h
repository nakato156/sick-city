#pragma once
#include "Mochila.h"

class Personaje {
protected:
	int posX, posY;
	int velocidad;
	int vidas;
	Mochila mochila;
	int indiceX, indiceY;
public:
	Personaje(int, int);
	~Personaje();
};