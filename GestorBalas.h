#pragma once
#include "Bala.h"
#include <vector>

class GestorBalas {
private:
	std::vector<Bala*> lista;
public:
	GestorBalas();

	std::vector<Bala*> getLista();
	void animar(System::Drawing::BufferedGraphics^, System::Drawing::Bitmap^);
	void addBala(Bala*);
	void delBala(Bala*);
};