#pragma once
#include "Personaje.h"
using namespace std;
using namespace System::Drawing;

class Contagiado : public Personaje {
public:
	Contagiado(int posX, int posY, int velocidad) : Personaje(posX, posY, velocidad) {
		indiceX = 0; //DEFINIR CON SPRITE
		indiceY = 0; //DEFINIR CON SPRITE
		vidas = 1;
		alto = 64; //DEFINIR CON SPRITE
		ancho = 64; //DEFINIR CON SPRITE
	}
	~Contagiado(){}
	void dibujaContagiado(BufferedGraphics^ buffer, Bitmap^ bmp) {
		Rectangle areaUsar = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
		//aumentar el tamanio del personaje
		Rectangle aumentoDeContagiado = Rectangle(posX, posY, ancho * 1.2, alto * 1.2);
		buffer->Graphics->DrawImage(bmp, aumentoDeContagiado, areaUsar, GraphicsUnit::Pixel);
		posX += velocidad;
		posY += velocidad;
	}
	void mueveContagiado(BufferedGraphics^ buffer, Bitmap^ bmp) {
		dibujaContagiado(buffer, bmp);
		if (indiceX < 3) indiceX++;
		else indiceX = 0;
		if (posX <= 1 || posY + ancho >= buffer->Graphics->VisibleClipBounds.Width) velocidad *= -1;
		if (posY <= 1 || posY + alto >= buffer->Graphics->VisibleClipBounds.Height) velocidad *= -1;
	}
};