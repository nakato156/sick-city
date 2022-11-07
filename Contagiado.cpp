#include "Enfermo.h"
#include "constantes.h"

using namespace std;
using namespace System::Drawing;

Contagiado::Contagiado(int anchoV, int vel) {
	velocidad = vel;
	vidas = 1;
	indiceX = 0; indiceY = 0;
	//DEFINIR CON SPRITE
	alto = 64; ancho = 64;

	posX = anchoV;
	posY = LIMITE_PISO  + rand() % (HEIGHT_VENTANA - LIMITE_PISO );
}
Contagiado::~Contagiado(){}

void Contagiado::dibujaContagiado(BufferedGraphics^ buffer, Bitmap^ bmp) {
	Rectangle areaUsar = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
	//aumentar el tamanio del personaje
	Rectangle aumentoDeContagiado = Rectangle(posX, posY, ancho * 1.2, alto * 1.2);
	buffer->Graphics->DrawImage(bmp, aumentoDeContagiado, areaUsar, GraphicsUnit::Pixel);
}

void Contagiado::mueveContagiado(BufferedGraphics^ buffer, Bitmap^ bmp, Enfermero* enfermero) {
	dibujaContagiado(buffer, bmp);
	
	int enfX = enfermero->getX();
	int enfY = enfermero->getY();
	
	posX += posX > enfX ? -velocidad : velocidad;
	if(abs(posX - enfX) < 155) posY += posY > enfY ? -velocidad : velocidad;

	indiceX < 3 ? indiceX++ : indiceX = 0;
}
bool Contagiado::checkColision(Bala* bala) {
	int xBala = bala->getX(); int yBala = bala->getY();
	int anchoBala = bala->getAncho(); int altoBala = bala->getAlto();
	if (posX + ancho > xBala && posX < xBala + anchoBala &&
		posY + alto > yBala && posY < yBala + altoBala) {
		colision = true;
	}
	return colision;
}
bool Contagiado::getColision() {
	return colision;
}