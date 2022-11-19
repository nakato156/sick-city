#pragma once
#include "Enfermero.h"

using namespace System::Windows::Forms;

class CtrlEnfermero : public Enfermero {
private:
	int tipo = 1;
	Direcciones normalizar(System::Windows::Forms::KeyEventArgs^ key) {
		auto tecla = key->KeyCode;
		if (tipo && tecla == Keys::Right	|| !tipo && tecla == Keys::D) return Derecha;
		else if (tipo && tecla == Keys::Up	|| !tipo && tecla == Keys::W) return Arriba;
		else if (tipo && tecla == Keys::Left	|| !tipo && tecla == Keys::A) return Izquierda;
		else if (tipo && tecla == Keys::Down	|| !tipo && tecla == Keys::S) return Abajo;
		else if (tipo && tecla == Keys::Space	|| !tipo && tecla == Keys::F) return Disparar;
		return Ninguna;
	}

public:
	CtrlEnfermero(int posX, int posY, int vel, int vidas, char tipo = 'w') : Enfermero(posX, posY, vel, vidas, LIMITE_PISO) {
		this->tipo = tipo == 'D';
	}

	void Accion(System::Windows::Forms::KeyEventArgs^ e){
		auto key = e->KeyCode;
		if (key == Keys::Control) {
			addVelocidad(8);
			return;
		}
		Direcciones direccion = normalizar(e);
		if(direccion != Ninguna) setDireccion(direccion);
	}

	void stop(System::Windows::Forms::KeyEventArgs^ e) {
		auto key = e->KeyCode;
		if (tipo && (key == Keys::Right || key == Keys::Left || key == Keys::Up || key == Keys::Down))
			setDireccion(Ninguna);
		else if (!tipo && (key == Keys::D || key == Keys::A || key == Keys::W || key == Keys::S))
			setDireccion(Ninguna);
	}
};