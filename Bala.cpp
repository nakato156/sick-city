#include "Bala.h"
using namespace std;
using namespace System::Drawing;

Bala::Bala() {
}
Bala::Bala(int ancho_, int alto_, Enfermero* enfermero, int vel) {
	nombre = "vacuna";
	
	velocidad = vel;
	ancho = ancho_; alto = alto_;
	posX = enfermero->getX() + enfermero->getAncho() / 2;
	posY = enfermero->getY() + 30;
}

void Bala::Mover() { posX += velocidad; }
void Bala::Dibujar(BufferedGraphics^ buffer, Bitmap^ bmp) {
	areaUsar = Rectangle(0, 0, ancho, alto);
	aumento = Rectangle(posX, posY, ancho / 1.2, alto * 1.2);

	buffer->Graphics->DrawImage(bmp, aumento, areaUsar, GraphicsUnit::Pixel);
}

void Bala::Animar(BufferedGraphics^ buffer, Bitmap^ bmp){
	Mover();
	Dibujar(buffer, bmp);
}
int Bala::getX() { 
	return posX;
}
int Bala::getY() {
	return posY;
}
int Bala::getAncho() {
	return ancho;
}
int Bala::getAlto() {
	return alto;
}
bool Bala::getColision() { return colision; }
void Bala::setColision(bool _colision) { colision = _colision; }

bool Bala::checkSalida(System::Drawing::BufferedGraphics^ buffer) {
	if (posX + ancho >= buffer->Graphics->VisibleClipBounds.Width) {
		salida = true;
	}
	return salida;
}
bool Bala::getSalida() { return salida; }