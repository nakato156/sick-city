#pragma once
#include <string>
#include "Item.h"
#include "Enfermero.h"


class Bala : public Item {
private:
	bool colision = false;
	bool salida = false;
	int velocidad;
	System::Drawing::Rectangle areaUsar;
	System::Drawing::Rectangle aumento;
public:
	Bala();
	Bala(int ancho_, int alto_, Enfermero*, int vel);
	void Mover();
	void Dibujar(System::Drawing::BufferedGraphics^, System::Drawing::Bitmap^);
	void Animar(System::Drawing::BufferedGraphics^, System::Drawing::Bitmap^);
	int getX();
	int getY();
	int getAncho();
	int getAlto();
	bool getColision();
	void setColision(bool _colision);
	bool checkSalida(System::Drawing::BufferedGraphics^ buffer);
	bool getSalida();
};