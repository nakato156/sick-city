#pragma once
#include <conio.h>
#include "ScreenWin.h"
#include "Cronometro.h"
#include "GestorBalas.h"
#include "GestorEnfermo.h"
#include "screenGameOver.h"
#include "EnfermeroController.h"
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
	public:
		bool GM = false;
		bool showForm = false, mostrarCP = true, CPVisible = false;
		int velCP = 30;
	private:
		int sizeImgVida = 24;

		CtrlEnfermero* player1 = new CtrlEnfermero(10, 255, 10, 5, 'D');
		CtrlEnfermero* player2 = new CtrlEnfermero(10, 300, 10, 5);
		
		SoundPlayer^ audio = gcnew SoundPlayer("audio-juego.wav");;
		Cronometro* cronometro = new Cronometro();
		GesContagiado* g_contagiado = new GesContagiado();
		GestorBalas* balas_player1 = new GestorBalas();
		GestorBalas* balas_player2 = new GestorBalas();

		Bitmap^ mapa_player1 = gcnew Bitmap(RUTA_SPRITE_ENF);
		Bitmap^ mapa_player2 = gcnew Bitmap(RUTA_SPRITE_ENFRA);
		Bitmap^ mapa_contagiados = gcnew Bitmap(RUTA_SPRITE_CONT);
	private: System::Windows::Forms::Panel^ controlPanel;
	private: System::Windows::Forms::Button^ btn_reanudar;
	private: System::Windows::Forms::Button^ btn_mute;
	private: System::Windows::Forms::Button^ btn_unmute;
	private: System::Windows::Forms::Button^ btnBack;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Timer^ animaciones;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
		   Bitmap^ mapa_bala = gcnew Bitmap(RUTA_SPRITE_BALA);

	public:
		levelMultiplayer(void)
		{
			audio->PlayLooping();
			InitializeComponent();
			int cantidad = Random().Next(5, 20);
			g_contagiado->creaContagiados(cantidad, 8);
			dibujaVidas();
			cronometro->init();
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
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(levelMultiplayer::typeid));
			this->imgVidasP1 = (gcnew System::Windows::Forms::PictureBox());
			this->imgVidasP2 = (gcnew System::Windows::Forms::PictureBox());
			this->imgMuerte = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->controlPanel = (gcnew System::Windows::Forms::Panel());
			this->btn_reanudar = (gcnew System::Windows::Forms::Button());
			this->btn_mute = (gcnew System::Windows::Forms::Button());
			this->btn_unmute = (gcnew System::Windows::Forms::Button());
			this->btnBack = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->animaciones = (gcnew System::Windows::Forms::Timer(this->components));
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imgVidasP1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imgVidasP2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imgMuerte))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->controlPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->SuspendLayout();
			// 
			// imgVidasP1
			// 
			this->imgVidasP1->BackColor = System::Drawing::Color::Transparent;
			this->imgVidasP1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"imgVidasP1.BackgroundImage")));
			this->imgVidasP1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->imgVidasP1->Location = System::Drawing::Point(49, 31);
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
			this->imgVidasP2->Location = System::Drawing::Point(49, 74);
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
			this->btn_reanudar->Click += gcnew System::EventHandler(this, &levelMultiplayer::btn_reanudar_Click);
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
			this->btn_mute->Click += gcnew System::EventHandler(this, &levelMultiplayer::btn_mute_Click);
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
			this->btn_unmute->Click += gcnew System::EventHandler(this, &levelMultiplayer::btn_unmute_Click);
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
			this->btnBack->Click += gcnew System::EventHandler(this, &levelMultiplayer::btnBack_Click);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &levelMultiplayer::timer1_Tick);
			// 
			// animaciones
			// 
			this->animaciones->Tick += gcnew System::EventHandler(this, &levelMultiplayer::animaciones_Tick);
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.BackgroundImage")));
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox2->Location = System::Drawing::Point(5, 26);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(38, 32);
			this->pictureBox2->TabIndex = 6;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.BackgroundImage")));
			this->pictureBox3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox3->Location = System::Drawing::Point(5, 68);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(38, 32);
			this->pictureBox3->TabIndex = 7;
			this->pictureBox3->TabStop = false;
			// 
			// levelMultiplayer
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(859, 354);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->imgMuerte);
			this->Controls->Add(this->controlPanel);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->imgVidasP2);
			this->Controls->Add(this->imgVidasP1);
			this->DoubleBuffered = true;
			this->ForeColor = System::Drawing::Color::White;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"levelMultiplayer";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"levelMultiplayer";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &levelMultiplayer::levelMultiplayer_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &levelMultiplayer::levelMultiplayer_KeyUp);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imgVidasP1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imgVidasP2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imgMuerte))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->controlPanel->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	//eventos
	private: System::Void levelMultiplayer_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		auto key = e->KeyCode;
		if (key == Keys::Space) balas_player1->addBala(new Bala(40, 10, player1, 20));
		else if (key == Keys::F) balas_player2->addBala(new Bala(40, 10, player2, 20));
		player1->Accion(e);
		player2->Accion(e);
	}

	private: System::Void levelMultiplayer_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		auto key = e->KeyCode;
		if (key == Keys::LControlKey) player1->resetVelocidad();
		else if (key == Keys::RControlKey) player2->resetVelocidad();
		else if (key == Keys::Escape) animaciones->Enabled = true;
		player1->stop(e);
		player2->stop(e);
	}
	
	//funciones adicionales
	private: 
		void dibujaVidas() {
			this->imgVidasP1->Width = player1->getVidas() * sizeImgVida;
			this->imgVidasP2->Width = player2->getVidas() * sizeImgVida;
		}

		void gameWin() {
			auto curados = g_contagiado->curados;
			cronometro->fin();
			auto tiempo = cronometro->getParseTime();
			showScreenWinGame(this, gcnew ScreenWin(tiempo, curados), timer1);
		}

		void gameOver() {
			if (!this->imgMuerte->Visible) {
				this->imgMuerte->Image = gcnew Bitmap("imgs/imgMuerte.png");
				this->imgMuerte->Visible = true;
			}
			else if (this->imgMuerte->Location.Y > 0) {
				auto punto = this->imgMuerte->Location;
				this->imgMuerte->Location = Point(punto.X - 4, punto.Y - 4);
				this->imgMuerte->Width += 8;
				this->imgMuerte->Height += 8;
			}
			else if (this->imgMuerte->Location.Y <= 0) {
				this->timer1->Enabled = false;
				auto curados = g_contagiado->curados;
				auto screenGO = gcnew screenGameOver(cronometro->getParseTime(), curados);
				
				this->Hide();
				audio->Stop();
				auto result = screenGO->ShowDialog();
				DialogResult = result;
				
				if (result == System::Windows::Forms::DialogResult::OK) {
					delete screenGO;
					this->Close();
				}
				else if (result == System::Windows::Forms::DialogResult::Retry) this->Close();

			}
		}

		void verificarColisionesBalas(GestorBalas* lista_balas, CtrlEnfermero* player, BufferedGraphics^ buffer) {
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
			if (!g_contagiado->getCantidad()) {
				gameWin();
				return;
			}
			lista_balas->actualizarSalida(buffer);
		}
	}

		void verificarColisionContagiados() {
		for (auto contagiados : g_contagiado->lista_contagiados) {
			//chequear la colision del contagiado con el enfermero
			if (contagiados->checkColisionEnfermero(player1)) {
				dibujaVidas();
				player1->reset();
				contagiados->setColisionEnfermero(false);
			}
			if (contagiados->checkColisionEnfermero(player2)) {
				dibujaVidas();
				player2->reset();
				contagiados->setColisionEnfermero(false);
			}

			if (player1->getVidas() <= 0 && player2->getVidas() <= 0) {
				cronometro->fin();
				GM = true;
				dibujaVidas();
				break;
			}
		}
	}

//timers
private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
	if (GM) return gameOver();
	else if (CPVisible) return;

	Graphics^ canvaFormulario = this->CreateGraphics();
	BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
	BufferedGraphics^ buffer = espacio->Allocate(canvaFormulario, this->ClientRectangle);
	buffer->Graphics->Clear(Color::White);

	int ancho = buffer->Graphics->VisibleClipBounds.Width;
	int alto = buffer->Graphics->VisibleClipBounds.Height;
	buffer->Graphics->DrawImage(pictureBox1->Image, 0, 0, ancho, alto);


	//movimientos
	if (player1->getVidas() > 0) {
		player1->mueveEnfermero(buffer, mapa_player1);
		balas_player1->animar(buffer, mapa_bala);
	}
	
	if (player2->getVidas() > 0) {
		player2->mueveEnfermero(buffer, mapa_player2);
		balas_player2->animar(buffer, mapa_bala);
	}

	auto player = player1->getX() > player2->getX() ? player1 : player2;
	g_contagiado->moverContagiados(buffer, mapa_contagiados, player);

	verificarColisionesBalas(balas_player1, player1, buffer);
	verificarColisionesBalas(balas_player2, player2, buffer);
	verificarColisionContagiados();

	buffer->Render(canvaFormulario);
	delete buffer;
	delete canvaFormulario;
	delete espacio;
}
private: System::Void animaciones_Tick(System::Object^ sender, System::EventArgs^ e) {
	if (mostrarCP && !CPVisible) showControlPanel(this, this->controlPanel, this->animaciones);
	else if (!mostrarCP && CPVisible) hideControlPanel(this, this->controlPanel, this->animaciones);
}

//Panel de control
private: System::Void btn_reanudar_Click(System::Object^ sender, System::EventArgs^ e) {
	animaciones->Enabled = true;
}
private: System::Void btnBack_Click(System::Object^ sender, System::EventArgs^ e) {
	DialogResult = System::Windows::Forms::DialogResult::Ignore;
	audio->Stop();
	this->Close();
}
private: System::Void btn_mute_Click(System::Object^ sender, System::EventArgs^ e) {
	audio->Stop();
}
private: System::Void btn_unmute_Click(System::Object^ sender, System::EventArgs^ e) {
	audio->PlayLooping();
}

};
}
