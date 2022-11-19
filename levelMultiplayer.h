#pragma once
#include <conio.h>
#include "Enfermero.h"
#include "ScreenWin.h"
#include "Cronometro.h"
#include "GestorBalas.h"
#include "GestorEnfermo.h"
#include "screenGameOver.h"
#include "funcionesAddicionales.h"

namespace TrabajoFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Media;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de levelMultiplayer
	/// </summary>
	public ref class levelMultiplayer : public System::Windows::Forms::Form
	{
	private:
		Enfermero* player1 = new Enfermero(10, 290, 10, 5, LIMITE_PISO);
		Enfermero* player2 = new Enfermero(10, 320, 10, 5, LIMITE_PISO);
		
		SoundPlayer^ audio;
		Cronometro* cronometro = new Cronometro();
		GesContagiado* g_contagiado = new GesContagiado();
		GestorBalas* lista_balas = new GestorBalas();

		Bitmap^ mapa_player1 = gcnew Bitmap(RUTA_SPRITE_ENF);
		Bitmap^ mapa_player2 = gcnew Bitmap(RUTA_SPRITE_ENFRA);
		Bitmap^ mapa_contagiados = gcnew Bitmap(RUTA_SPRITE_CONT);
		Bitmap^ mapa_bala = gcnew Bitmap(RUTA_SPRITE_BALA);

	public:
		levelMultiplayer(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~levelMultiplayer()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ imgVidasP1;
	protected:
	private: System::Windows::Forms::PictureBox^ imgVidasP2;
	private: System::Windows::Forms::PictureBox^ imgMuerte;
	private: System::Windows::Forms::PictureBox^ pictureBox1;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(levelMultiplayer::typeid));
			this->imgVidasP1 = (gcnew System::Windows::Forms::PictureBox());
			this->imgVidasP2 = (gcnew System::Windows::Forms::PictureBox());
			this->imgMuerte = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imgVidasP1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imgVidasP2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imgMuerte))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// imgVidasP1
			// 
			this->imgVidasP1->BackColor = System::Drawing::Color::Transparent;
			this->imgVidasP1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"imgVidasP1.BackgroundImage")));
			this->imgVidasP1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->imgVidasP1->Location = System::Drawing::Point(49, 26);
			this->imgVidasP1->Name = L"imgVidasP1";
			this->imgVidasP1->Size = System::Drawing::Size(74, 23);
			this->imgVidasP1->TabIndex = 1;
			this->imgVidasP1->TabStop = false;
			// 
			// imgVidasP2
			// 
			this->imgVidasP2->BackColor = System::Drawing::Color::Transparent;
			this->imgVidasP2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"imgVidasP2.BackgroundImage")));
			this->imgVidasP2->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->imgVidasP2->Location = System::Drawing::Point(49, 68);
			this->imgVidasP2->Name = L"imgVidasP2";
			this->imgVidasP2->Size = System::Drawing::Size(74, 23);
			this->imgVidasP2->TabIndex = 2;
			this->imgVidasP2->TabStop = false;
			// 
			// imgMuerte
			// 
			this->imgMuerte->BackColor = System::Drawing::Color::Transparent;
			this->imgMuerte->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->imgMuerte->Location = System::Drawing::Point(379, 152);
			this->imgMuerte->Name = L"imgMuerte";
			this->imgMuerte->Size = System::Drawing::Size(100, 50);
			this->imgMuerte->TabIndex = 3;
			this->imgMuerte->TabStop = false;
			this->imgMuerte->Visible = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->pictureBox1->Location = System::Drawing::Point(396, 161);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(67, 32);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 4;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Visible = false;
			// 
			// levelMultiplayer
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(859, 354);
			this->Controls->Add(this->imgMuerte);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->imgVidasP2);
			this->Controls->Add(this->imgVidasP1);
			this->DoubleBuffered = true;
			this->ForeColor = System::Drawing::Color::White;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"levelMultiplayer";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"levelMultiplayer";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imgVidasP1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imgVidasP2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imgMuerte))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
