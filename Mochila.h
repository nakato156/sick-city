#pragma once
#include "Item.h"
#include <vector>

class Mochila {
protected:
	std::vector<Item*> contenedor;

public:
	Mochila();
	int cant_items();
	std::vector<Item*> getItems();
	void addItem(Item*);
	void delItem(Item*);
};