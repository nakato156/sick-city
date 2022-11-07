#pragma once
#include <string>
#include "Item.h"


class Bala : public Item {
private:
	int velocidad;
	System::Drawing::Rectangle areaUsar;
	System::Drawing::Rectangle aumento;
public:
	Bala();
	Bala(int ancho_, int alto_, int enfX, int enfY, int vel);
	void Mover();
	void Dibujar(System::Drawing::BufferedGraphics^, System::Drawing::Bitmap^);
	void Animar(System::Drawing::BufferedGraphics^, System::Drawing::Bitmap^);
	int getX();
	int getY();
	int getAncho();
	int getAlto();
};