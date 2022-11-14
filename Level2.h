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

	/// <summary>
	/// Summary for Level2
	/// </summary>
	public ref class Level2 : public System::Windows::Forms::Form
	{
	private:
		bool GM = false;
		SoundPlayer^ audio;
		Cronometro* cronometro = new Cronometro();
		Enfermero* enfermero = new Enfermero(10, 300, 10);
		GesContagiado* g_contagiado = new GesContagiado();
		GestorBalas* lista_balas = new GestorBalas();
		Bitmap^ mapa_contagiados = gcnew Bitmap("enfermo.png");
		Bitmap^ mapa_enfermero;
		Bitmap^ mapa_bala = gcnew Bitmap("bala.png");

	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::PictureBox^ imgVidas;
	private: System::Windows::Forms::PictureBox^ imgMuerte;
		   int sizeImgVida = 24;
		   int widthPantalla = this->ClientSize.Width;
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
			int cantidad = r.Next(5, 20);
			g_contagiado->creaContagiados(cantidad);

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
			// Level2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1292, 525);
			this->Controls->Add(this->imgMuerte);
			this->Controls->Add(this->imgVidas);
			this->Controls->Add(this->pictureBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Level2";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Level2";
			this->Load += gcnew System::EventHandler(this, &Level2::Level2_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imgVidas))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imgMuerte))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		private: void dibujaVidas() {
			this->imgVidas->Width = enfermero->getVidas() * sizeImgVida;
		}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ canvaFormulario = this->CreateGraphics();
		BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacio->Allocate(canvaFormulario, this->ClientRectangle);
		buffer->Graphics->Clear(Color::White);

		int ancho = buffer->Graphics->VisibleClipBounds.Width;
		int alto = buffer->Graphics->VisibleClipBounds.Height;
		buffer->Graphics->DrawImage(pictureBox1->Image, 0, 0, ancho, alto);
		buffer->Render(canvaFormulario);
		delete buffer;
		delete canvaFormulario;
		delete espacio;
	}
	private: System::Void Level2_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
