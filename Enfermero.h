#pragma once
#include "Personaje.h"
#include "constantes.h"

class Enfermero : public Personaje{
private:
	int velocidadNormal;
	Direcciones ultimatecla;
	Direcciones direccion;
public:
	Enfermero(int posX, int posY, int velocidad, int vidas, int limite);
	~Enfermero() = default;
	void setDireccion(Direcciones _direccion);
	int getX();	
	int getY();	
	int getAncho();
	int getAlto();
	int getVidas();
	void addVelocidad(int);
	void resetVelocidad();

	void dibujaEnfermero(System::Drawing::BufferedGraphics^ buffer, System::Drawing::Bitmap^ bmp);
	void mueveEnfermero(System::Drawing::BufferedGraphics^ buffer, System::Drawing::Bitmap^ bmp);
	void reset();
};