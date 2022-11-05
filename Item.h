#pragma once
#include <string>
class Item {
protected:
	std::string nombre;
	int durabilidad;
public:
	Item(){}
	int getDurabilidad();
};