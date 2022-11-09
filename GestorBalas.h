#pragma once
#include "Bala.h"
#include <vector>

class GestorBalas {
	
public:
	GestorBalas();
	std::vector<Bala*> lista;
	std::vector<Bala*> getLista();
	void animar(System::Drawing::BufferedGraphics^, System::Drawing::Bitmap^);
	void addBala(Bala*);
	void delBala(Bala*);
	void actualizarLista();
	void actualizarSalida(System::Drawing::BufferedGraphics^ buffer);

};