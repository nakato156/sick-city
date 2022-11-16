#pragma once
#include<conio.h>
#include <iostream>
#include "Enfermero.h"
#include "GestorEnfermo.h"
#include "GestorBalas.h"
#include "Cronometro.h"
#include "screenGameOver.h"
namespace TrabajoFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

	/// <summary>
	/// Summary for Level2
	/// </summary>
	public ref class Level2 : public System::Windows::Forms::Form
	{
	private:
		bool GM = false;
		SoundPlayer^ audio;
		Cronometro* cronometro = new Cronometro();
		Enfermero* enfermero = new Enfermero(10, 300, 10, 3);
		GesContagiado* g_contagiado = new GesContagiado();
		GestorBalas* lista_balas = new GestorBalas();

		Bitmap^ mapa_contagiados = gcnew Bitmap("enfermo.png");
		Bitmap^ mapa_enfermero;
		Bitmap^ mapa_bala = gcnew Bitmap("bala.png");


	private: System::Windows::Forms::PictureBox^ imgMuerte;

		   int sizeImgVida = 24;
		   int widthPantalla = this->ClientSize.Width;

	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::PictureBox^ imgVidas;
	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::PictureBox^ pictureBox1;
	public:
		Level2(System::String^ personaje, SoundPlayer^ musica)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			audio = musica;
			Random r;
			int cantidad = r.Next(10, 25);
			g_contagiado->creaContagiados(cantidad, 12);

			cronometro->init();

			mapa_enfermero = gcnew Bitmap(personaje + ".png");
			dibujaVidas();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Level2()
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
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Level2::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->imgVidas = (gcnew System::Windows::Forms::PictureBox());
			this->imgMuerte = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imgVidas))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imgMuerte))->BeginInit();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &Level2::timer1_Tick);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(549, 236);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(121, 48);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Visible = false;
			// 
			// imgVidas
			// 
			this->imgVidas->BackColor = System::Drawing::Color::Transparent;
			this->imgVidas->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"imgVidas.BackgroundImage")));
			this->imgVidas->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->imgVidas->Location = System::Drawing::Point(13, 14);
			this->imgVidas->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->imgVidas->Name = L"imgVidas";
			this->imgVidas->Size = System::Drawing::Size(111, 35);
			this->imgVidas->TabIndex = 1;
			this->imgVidas->TabStop = false;
			// 
			// imgMuerte
			// 
			this->imgMuerte->BackColor = System::Drawing::Color::Transparent;
			this->imgMuerte->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->imgMuerte->Location = System::Drawing::Point(378, 218);
			this->imgMuerte->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->imgMuerte->Name = L"imgMuerte";
			this->imgMuerte->Size = System::Drawing::Size(150, 77);
			this->imgMuerte->TabIndex = 2;
			this->imgMuerte->TabStop = false;
			this->imgMuerte->Visible = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(490, 30);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(51, 20);
			this->label1->TabIndex = 3;
			this->label1->Text = L"label1";
			// 
			// Level2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1312, 605);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->imgMuerte);
			this->Controls->Add(this->imgVidas);
			this->Controls->Add(this->pictureBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Level2";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Level2";
			this->Load += gcnew System::EventHandler(this, &Level2::Level2_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Level2::Level2_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Level2::Level2_KeyUp);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imgVidas))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imgMuerte))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void Level2_Load(System::Object^ sender, System::EventArgs^ e) {
		}
		private: void dibujaVidas() {
			this->imgVidas->Width = enfermero->getVidas() * sizeImgVida;
		}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (GM) {
			gameOver();
			return;
		}
		label1->BackColor = Color::Red;
		label1->Text = "NIVEL 2";
		Graphics^ canvaFormulario = this->CreateGraphics();
		BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacio->Allocate(canvaFormulario, this->ClientRectangle);
		buffer->Graphics->Clear(Color::White);

		int ancho = buffer->Graphics->VisibleClipBounds.Width;
		int alto = buffer->Graphics->VisibleClipBounds.Height;
		buffer->Graphics->DrawImage(pictureBox1->Image, 0, 0, ancho, alto);
		//movimientos
		enfermero->mueveEnfermero(buffer, mapa_enfermero);
		lista_balas->animar(buffer, mapa_bala);
		g_contagiado->moverContagiados(buffer, mapa_contagiados, enfermero);

		//chequear colisiones
		for (auto bala : lista_balas->lista) {
			for (auto contagiado : g_contagiado->lista_contagiados)
			{
				//chequear colision de la bala con los enfermos
				if (contagiado->checkColision(bala)) {
					bala->setColision(true);			//si hay colision, cambiar el estado de la bala
					g_contagiado->actualizarLista();	//eliminar el contagiado colisionado
					lista_balas->actualizarLista();		//eliminar la bala que colisiono
				}
			}
			lista_balas->actualizarSalida(buffer);
		}

		for (auto contagiados : g_contagiado->lista_contagiados) {
			//chequear la colision del contagiado con el enfermero
			if (contagiados->checkColisionEnfermero(enfermero)) {
				enfermero->reset();
				if (enfermero->getVidas() == 0) {
					cronometro->fin();
					GM = true;
					audio->Stop();
				}
				dibujaVidas();
				contagiados->setColisionEnfermero(false);
				if (GM) break;
			}
		}
		buffer->Render(canvaFormulario);
		delete buffer;
		delete canvaFormulario;
		delete espacio;
	}
	private: System::Void Level2_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::ControlKey) enfermero->addVelocidad(8);
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
private: System::Void Level2_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	auto key = e->KeyCode;
	if (key == Keys::ControlKey) enfermero->resetVelocidad();
	else if (key == Keys::Right || key == Keys::Left || key == Keys::Up || key == Keys::Down) {
		enfermero->setDireccion(Ninguna);
	}
}
	   private:
		   void gameOver() {
			   if (!this->imgMuerte->Visible) {
				   this->imgMuerte->Image = gcnew Bitmap("imgs/imgMuerte.png");
				   this->imgMuerte->Visible = true;
			   }
			   auto punto = this->imgMuerte->Location;
			   this->imgMuerte->Location = Point(punto.X - 4, punto.Y - 4);
			   this->imgMuerte->Width += 8;
			   this->imgMuerte->Height += 8;
			   if (this->imgMuerte->Location.Y <= 0) {
				   auto curados = g_contagiado->curados;
				   auto screenGO = gcnew screenGameOver(cronometro->getParseTime(), curados);
				   screenGO->Show();
				   this->Close();
			   }
		   }
};
}
