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
	using namespace System::Drawing;
	using namespace System::Media;

	/// <summary>
	/// Summary for Level2
	/// </summary>
	public ref class Level2 : public System::Windows::Forms::Form
	{
	public:
		bool mostrarCP = true, CPVisible = false;
		int velCP = 30;

	private:
		bool GO = false, GW = false;

		SoundPlayer^ audio;
		Cronometro* cronometro = new Cronometro();
		Enfermero* enfermero = new Enfermero(10, 300, 10, 3, 270);
		GesContagiado* g_contagiado = new GesContagiado();
		GestorBalas* lista_balas = new GestorBalas();

		Bitmap^ mapa_contagiados = gcnew Bitmap(RUTA_SPRITE_CONT);
		Bitmap^ mapa_enfermero;
		Bitmap^ mapa_bala = gcnew Bitmap(RUTA_SPRITE_BALA);


	private: System::Windows::Forms::PictureBox^ imgMuerte;

		   int sizeImgVida = 24;
		   int widthPantalla = this->ClientSize.Width;

	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::PictureBox^ imgVidas;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::PictureBox^ imgWin;
	private: System::Windows::Forms::Panel^ controlPanel;
	private: System::Windows::Forms::Button^ btn_reanudar;
	private: System::Windows::Forms::Button^ btn_mute;
	private: System::Windows::Forms::Button^ btn_unmute;
	private: System::Windows::Forms::Button^ btnBack;
	private: System::Windows::Forms::Timer^ animaciones;

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

			mapa_enfermero = gcnew Bitmap( FOLDER_SPRITES + personaje + ".png");
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
			this->imgWin = (gcnew System::Windows::Forms::PictureBox());
			this->controlPanel = (gcnew System::Windows::Forms::Panel());
			this->btn_reanudar = (gcnew System::Windows::Forms::Button());
			this->btn_mute = (gcnew System::Windows::Forms::Button());
			this->btn_unmute = (gcnew System::Windows::Forms::Button());
			this->btnBack = (gcnew System::Windows::Forms::Button());
			this->animaciones = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imgVidas))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imgMuerte))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imgWin))->BeginInit();
			this->controlPanel->SuspendLayout();
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
			this->pictureBox1->Location = System::Drawing::Point(366, 153);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(81, 31);
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
			this->imgVidas->Location = System::Drawing::Point(9, 9);
			this->imgVidas->Name = L"imgVidas";
			this->imgVidas->Size = System::Drawing::Size(74, 23);
			this->imgVidas->TabIndex = 1;
			this->imgVidas->TabStop = false;
			// 
			// imgMuerte
			// 
			this->imgMuerte->BackColor = System::Drawing::Color::Transparent;
			this->imgMuerte->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->imgMuerte->Location = System::Drawing::Point(252, 142);
			this->imgMuerte->Name = L"imgMuerte";
			this->imgMuerte->Size = System::Drawing::Size(100, 50);
			this->imgMuerte->TabIndex = 2;
			this->imgMuerte->TabStop = false;
			this->imgMuerte->Visible = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(327, 19);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"label1";
			// 
			// imgWin
			// 
			this->imgWin->BackColor = System::Drawing::Color::Transparent;
			this->imgWin->Location = System::Drawing::Point(252, 197);
			this->imgWin->Name = L"imgWin";
			this->imgWin->Size = System::Drawing::Size(100, 50);
			this->imgWin->TabIndex = 4;
			this->imgWin->TabStop = false;
			this->imgWin->Visible = false;
			// 
			// controlPanel
			// 
			this->controlPanel->BackColor = System::Drawing::Color::Black;
			this->controlPanel->Controls->Add(this->btn_reanudar);
			this->controlPanel->Controls->Add(this->btn_mute);
			this->controlPanel->Controls->Add(this->btn_unmute);
			this->controlPanel->Controls->Add(this->btnBack);
			this->controlPanel->ForeColor = System::Drawing::Color::White;
			this->controlPanel->Location = System::Drawing::Point(317, -190);
			this->controlPanel->Name = L"controlPanel";
			this->controlPanel->Size = System::Drawing::Size(200, 190);
			this->controlPanel->TabIndex = 5;
			this->controlPanel->Visible = false;
			// 
			// btn_reanudar
			// 
			this->btn_reanudar->BackColor = System::Drawing::Color::DarkRed;
			this->btn_reanudar->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_reanudar->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_reanudar->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->btn_reanudar->Location = System::Drawing::Point(59, 92);
			this->btn_reanudar->Name = L"btn_reanudar";
			this->btn_reanudar->Size = System::Drawing::Size(90, 32);
			this->btn_reanudar->TabIndex = 14;
			this->btn_reanudar->Text = L"Reanudar";
			this->btn_reanudar->UseVisualStyleBackColor = false;
			this->btn_reanudar->Click += gcnew System::EventHandler(this, &Level2::btn_reanudar_Click);
			// 
			// btn_mute
			// 
			this->btn_mute->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_mute->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_mute->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_mute.Image")));
			this->btn_mute->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->btn_mute->Location = System::Drawing::Point(107, 35);
			this->btn_mute->Name = L"btn_mute";
			this->btn_mute->Size = System::Drawing::Size(33, 28);
			this->btn_mute->TabIndex = 13;
			this->btn_mute->UseVisualStyleBackColor = true;
			// 
			// btn_unmute
			// 
			this->btn_unmute->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_unmute->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_unmute->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_unmute.Image")));
			this->btn_unmute->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->btn_unmute->Location = System::Drawing::Point(59, 35);
			this->btn_unmute->Name = L"btn_unmute";
			this->btn_unmute->Size = System::Drawing::Size(30, 28);
			this->btn_unmute->TabIndex = 12;
			this->btn_unmute->UseVisualStyleBackColor = true;
			// 
			// btnBack
			// 
			this->btnBack->BackColor = System::Drawing::Color::DarkRed;
			this->btnBack->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnBack->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnBack->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->btnBack->Location = System::Drawing::Point(59, 134);
			this->btnBack->Name = L"btnBack";
			this->btnBack->Size = System::Drawing::Size(90, 32);
			this->btnBack->TabIndex = 0;
			this->btnBack->Text = L"Ir al menu";
			this->btnBack->UseVisualStyleBackColor = false;
			this->btnBack->Click += gcnew System::EventHandler(this, &Level2::btnBack_Click);
			// 
			// animaciones
			// 
			this->animaciones->Tick += gcnew System::EventHandler(this, &Level2::animaciones_Tick);
			// 
			// Level2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(875, 393);
			this->Controls->Add(this->controlPanel);
			this->Controls->Add(this->imgWin);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->imgMuerte);
			this->Controls->Add(this->imgVidas);
			this->Controls->Add(this->pictureBox1);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"Level2";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Level2";
			this->Load += gcnew System::EventHandler(this, &Level2::Level2_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Level2::Level2_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Level2::Level2_KeyUp);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imgVidas))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imgMuerte))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imgWin))->EndInit();
			this->controlPanel->ResumeLayout(false);
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
		if (GO) {
			gameOver();
			return;
		}
		else if (GW) {
			gameWin();
			return;
		}
		else if (CPVisible) return;
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
				if (g_contagiado->getCantidad() == 0) {
					cronometro->fin();
					GW = true;
					audio->Stop();
					break;
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
					GO = true;
					audio->Stop();
				}
				
				dibujaVidas();
				contagiados->setColisionEnfermero(false);
				if (GO) break;
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
	else if (key == Keys::Escape) animaciones->Enabled = true;
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
			this->timer1->Enabled = false;
			auto curados = g_contagiado->curados;
			auto screenGO = gcnew screenGameOver(cronometro->getParseTime(), curados);
			auto result = screenGO->ShowDialog();
			DialogResult = result;
			this->Close();
		}
	}
private:
	void gameWin() {
		if (!this->imgWin->Visible) {
			this->imgWin->Image = gcnew Bitmap("imgs/youWin.png");
			this->imgWin->Visible = true;
		}
		
		auto punto = this->imgWin->Location;
		this->imgWin->Location = Point(punto.X - 4, punto.Y - 4);
		this->imgWin->Width += 10;
		this->imgWin->Height += 10;

		if (this->imgWin->Location.Y <= -10) {
			this->timer1->Enabled = false;

			auto curados = g_contagiado->curados;
			auto screenYW = gcnew ScreenWin(cronometro->getParseTime(), curados);
			this->Hide();
			auto resultado = screenYW->ShowDialog();

			if (resultado == System::Windows::Forms::DialogResult::OK)
			{
				DialogResult = System::Windows::Forms::DialogResult::OK;
			}
			else DialogResult = System::Windows::Forms::DialogResult::Retry;
			this->Close();
		}
	}

private: System::Void animaciones_Tick(System::Object^ sender, System::EventArgs^ e) {
	if (mostrarCP && !CPVisible) showControlPanel(this, this->controlPanel, this->animaciones);
	else if (!mostrarCP && CPVisible) hideControlPanel(this, this->controlPanel, this->animaciones);
}
private: System::Void btn_reanudar_Click(System::Object^ sender, System::EventArgs^ e) {
	animaciones->Enabled = true;
}
private: System::Void btnBack_Click(System::Object^ sender, System::EventArgs^ e) {
	DialogResult = System::Windows::Forms::DialogResult::OK;
	this->Close();
}
};
}
