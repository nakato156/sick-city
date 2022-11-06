#include "GestorBalas.h"

using namespace std;
using namespace System::Drawing;

GestorBalas::GestorBalas() = default;

void GestorBalas::addBala(Bala * bala) { lista.push_back(bala); }
vector<Bala*> GestorBalas::getLista() { return lista; }
void GestorBalas::animar(BufferedGraphics^ buffer, Bitmap^ bmp) {
	for (auto bala : lista) bala->Animar(buffer, bmp); 
}
void GestorBalas::delBala(Bala* bala) {}