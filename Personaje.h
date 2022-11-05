#pragma once
#include "Mochila.h"

class Personaje {
protected:
	int posX, posY;
	int velocidad;
	int vidas;
	int ancho;
	int alto;
	Mochila mochila;
	int indiceX, indiceY;
public:
	Personaje(){}
	Personaje(int posX, int posY, int velocidad){
		this->posX = posX;
		this->posY = posY;
		this->velocidad = velocidad;
	}
	~Personaje(){}
};