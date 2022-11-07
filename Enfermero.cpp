#include "Enfermero.h"
#include "constantes.h"

using namespace std;
using namespace System::Drawing;

Enfermero::Enfermero(int posX, int posY, int velocidad){
	this->posX = posX;
	this->posY = posY;

	this->velocidad = velocidad;
	velocidadNormal = velocidad;
	
	indiceX = 0;	//falta definir tras sprite
	indiceY = 0;	//falta definir tras sprite
	
	alto = 161;		//falta definir tras sprite
	ancho = 132;		//falta definir tras sprite
	
	vidas = 5;
	
	ultimatecla = Derecha;
	direccion = Ninguna;
}
void Enfermero::setDireccion(Direcciones _direccion) {
	direccion = _direccion;
}
int Enfermero::getX() { return posX; }
int Enfermero::getY() { return posY; }

void Enfermero::addVelocidad(int vel) { velocidad += vel; }
void Enfermero::resetVelocidad() { velocidad = velocidadNormal; }

void Enfermero::dibujaEnfermero(BufferedGraphics^ buffer, Bitmap^ bmp) {
	Rectangle areaUsar = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
	
	//aumentar el tamanio del personaje
	Rectangle aumentoDeEnfermero = Rectangle(posX, posY, ancho / 2, alto / 2);
	buffer->Graphics->DrawImage(bmp, aumentoDeEnfermero, areaUsar, GraphicsUnit::Pixel);
}
void Enfermero::mueveEnfermero(BufferedGraphics^ buffer, Bitmap^ bmp) {
	dibujaEnfermero(buffer, bmp);

	switch (direccion)
	{
	//ARREGLAR INDICES CON EL SPRITE
	case Abajo:
		indiceY = 0;
		if (indiceX >= 0 && indiceX < 3) indiceX++;
		else indiceX = 0;

		if (posY < HEIGHT_VENTANA) posY += velocidad;
		ultimatecla = Abajo;
		break;
	case Arriba:
		indiceY = 0;
		if (indiceX >= 0 && indiceX < 3) indiceX++;
		else indiceX = 0;
		
		if (posY > LIMITE_PISO) posY -= velocidad;
		ultimatecla = Arriba;
		break;
	case Izquierda:
		indiceY = 0;
		if (indiceX >= 0 && indiceX < 3) indiceX++;
		else indiceX = 0;

		if (posX > 0) posX -= velocidad;
		ultimatecla = Izquierda;
		break;
	case Derecha:
		indiceY = 0;
		if (indiceX >= 0 && indiceX < 3) indiceX++;
		else indiceX = 0;
		
		if (posX < WIDTH_VENTANA) posX += velocidad;
		ultimatecla = Derecha;
		break;
	case Ninguna:
		switch (ultimatecla) {
		case Abajo:
			indiceX = 1;
			indiceY = 0;
			break;
		case Arriba:
			indiceX = 3;
			indiceY = 0;
			break;
		case Izquierda:
			indiceX = 0;
			indiceY = 0;
			break;
		case Derecha:
			indiceX = 0;
			indiceY = 1;
			break;
		}
		break;
	}
}