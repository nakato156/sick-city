#pragma once
#include<conio.h>
#include <iostream>
#include "Personaje.h"
#include "Enfermero.h"
#include "GestorEnfermo.h"
#include "GestorBalas.h"

namespace TrabajoFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

	/// <summary>
	/// Resumen de Level1
	/// </summary>
	public ref class Level1 : public System::Windows::Forms::Form
	{
	private:
		Enfermero* enfermero = new Enfermero(10, 300, 10);
		GesContagiado* g_contagiado = new GesContagiado();
		GestorBalas* lista_balas = new GestorBalas();
		

		Bitmap^ mapa_contagiados = gcnew Bitmap("enfermo.png");
		Bitmap^ mapa_enfermero;
		Bitmap^ mapa_bala= gcnew Bitmap("bala.png");

		int sizeImgVida = 24;
		int widthPantalla = this->ClientSize.Width;

	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::PictureBox^ imgVidas;

	private: System::Windows::Forms::PictureBox^ pictureBox1;
	public:
		Level1(System::String^ personaje)
		{
			InitializeComponent();
			//
			//TODO: agregar c�digo de constructor aqu�
			//
			Random r;
			int cantidad = r.Next(5, 20);
			g_contagiado->creaContagiados(cantidad);

			mapa_enfermero = gcnew Bitmap(personaje +  ".png");
			dibujaVidas();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se est�n usando.
		/// </summary>
		~Level1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Variable del dise�ador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�todo necesario para admitir el Dise�ador. No se puede modificar
		/// el contenido de este m�todo con el editor de c�digo.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Level1::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->imgVidas = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imgVidas))->BeginInit();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &Level1::timer1_Tick);
			// 
			// pictureBox1
			// 
			resources->ApplyResources(this->pictureBox1, L"pictureBox1");
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->TabStop = false;
			// 
			// imgVidas
			// 
			this->imgVidas->BackColor = System::Drawing::Color::Transparent;
			resources->ApplyResources(this->imgVidas, L"imgVidas");
			this->imgVidas->Name = L"imgVidas";
			//this->imgVidas->TabStop = false;
			// 
			// Level1
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->imgVidas);
			this->Controls->Add(this->pictureBox1);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Level1";
			this->Load += gcnew System::EventHandler(this, &Level1::Inicio_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Level1::Inicio_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Level1::Inicio_KeyUp);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imgVidas))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: void dibujaVidas() {
		this->imgVidas->Width = enfermero->getVidas() * sizeImgVida;
		this->imgVidas->Left = widthPantalla - this->imgVidas->Width - sizeImgVida;
	}
	private: System::Void Inicio_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ canvaFormulario = this->CreateGraphics();
		BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacio->Allocate(canvaFormulario, this->ClientRectangle);
		buffer->Graphics->Clear(Color::White);
		
		int ancho = buffer->Graphics->VisibleClipBounds.Width;
		int alto = buffer->Graphics->VisibleClipBounds.Height;
		buffer->Graphics->DrawImage(pictureBox1->Image, 0, 0,ancho, alto);

		//movimientos
		enfermero->mueveEnfermero(buffer, mapa_enfermero);
		lista_balas->animar(buffer, mapa_bala);
		g_contagiado->moverContagiados(buffer, mapa_contagiados, enfermero);
		//chequear colisiones
		for (auto bala : lista_balas->lista) { //recorrer la lista de balas
			for (auto contagiado : g_contagiado->lista_contagiados)  //recorrer lista de contagiados
			{
				contagiado->checkColision(bala); //chequear colision de la bala con los enfermos
				if (contagiado->getColision()) {
					bala->setColision(true);                      //si hay colision, cambiar el estaod de la bala
					g_contagiado->actualizarLista();		//eliminar el contagiado colisionado
					lista_balas->actualizarLista();				//eliminar la bala que colisiono
				}
			}
			lista_balas->actualizarSalida(buffer);
		}
		for (auto contagiados : g_contagiado->lista_contagiados) { //recorrer la lista de contagiados
			contagiados->checkColisionEnfermero(enfermero);			//chequear la colision del contagiado con el enfermero
			if (contagiados->getColisionEnfermero()) {
				enfermero->reset();
				dibujaVidas();
				contagiados->setColisionEnfermero(false);
			}
		}

		buffer->Render(canvaFormulario);
		delete buffer;
		delete canvaFormulario;
		delete espacio;
	}
	private: System::Void Inicio_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::ControlKey) enfermero->addVelocidad(5);
		switch (e->KeyCode) {
		case Keys::Space:
			enfermero->setDireccion(Disparar);
			lista_balas->addBala(new Bala(40, 10, enfermero, 30));
			break;
		case Keys::Left:
			enfermero->setDireccion(Izquierda);
			break;
		case Keys::Right:
			enfermero->setDireccion(Derecha);
			break;
		case Keys::Up:
			enfermero->setDireccion(Arriba);
			break;
		case Keys::Down:
			enfermero->setDireccion(Abajo);
			break;
		}

	}
	private: System::Void Inicio_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		auto key = e->KeyCode;
		if(key == Keys::ControlKey) enfermero->resetVelocidad();
		else if (key == Keys::Right || key == Keys::Left || key == Keys::Up || key == Keys::Down) {
			enfermero->setDireccion(Ninguna);
		}
	}
	};
}
