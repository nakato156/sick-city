#pragma once
#include "Personaje.h"
enum Direcciones { Ninguna, Abajo, Arriba, Izquierda, Derecha };
class Enfermero : public Personaje{
private:
	int velocidadNormal;
	Direcciones ultimatecla;
	Direcciones direccion;
public:
	Enfermero(int posX, int posY, int velocidad);
	~Enfermero();
	void setDireccion(Direcciones _direccion);
	int getX();	
	int getY();	
	
	void addVelocidad(int);
	void resetVelocidad();

	void dibujaEnfermero(System::Drawing::BufferedGraphics^ buffer, System::Drawing::Bitmap^ bmp);
	void mueveEnfermero(System::Drawing::BufferedGraphics^ buffer, System::Drawing::Bitmap^ bmp);
};