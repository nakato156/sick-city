#pragma once
#include <string>
class Item {
protected:
	std::string nombre;
	int durabilidad;
	int ancho, alto;
	int posX, posY;
public:
	Item(){}
	int getDurabilidad();
};