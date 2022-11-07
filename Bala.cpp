#include "Bala.h"

using namespace std;
using namespace System::Drawing;

Bala::Bala() {
}
Bala::Bala(int ancho_, int alto_, int enfX, int enfY, int vel) {
	nombre = "vacuna";
	
	velocidad = vel;
	ancho = ancho_; alto = alto_;
	posX = enfX;
	posY = enfY + 15;
}

void Bala::Mover() { posX += velocidad; }
void Bala::Dibujar(BufferedGraphics^ buffer, Bitmap^ bmp) {
	areaUsar = Rectangle(0, 0, ancho, alto);
	aumento = Rectangle(posX, posY, ancho * 1.2, alto * 1.2);

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
