#include "Mochila.h"
#include <vector>

using namespace std;

Mochila::Mochila() = default;
int Mochila::cant_items() { return contenedor.size(); }
vector<Item*> Mochila::getItems() { return contenedor; }
void Mochila::addItem(Item* item) { contenedor.push_back(item); }
void Mochila::delItem(Item* item) {
	for (int i = 0; i < contenedor.size(); i++) {
		if (contenedor.at(i) == item) {
			contenedor.erase(contenedor.begin() + i);
			break;
		}
	}
}