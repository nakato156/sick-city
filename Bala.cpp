#include "Bala.h"

using namespace std;
using namespace System::Drawing;

Bala::Bala() = default;
Bala::Bala(int ancho_, int alto_, int enfX, int enfY, int vel) {
	nombre = "vacuna";

	areaUsar = Rectangle(0, 0, ancho, alto);
	aumento = Rectangle(posX, posY, ancho * 1.2, alto * 1.2);
	
	velocidad = vel;
	ancho = ancho_; alto = alto_;
	posX = enfX;
	posY = enfY + 3;
}

void Bala::Mover() { posX += velocidad; }
void Bala::Dibujar(BufferedGraphics^ buffer, Bitmap^ bmp) {
	buffer->Graphics->DrawImage(bmp, aumento, areaUsar, GraphicsUnit::Pixel);
}

void Bala::Animar(BufferedGraphics^ buffer, Bitmap^ bmp){
	Mover();
	Dibujar(buffer, bmp);
}