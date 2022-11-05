#pragma once
#include <iostream>
#include "Personaje.h"
#include "Enfermero.h"
#include "Enfermo.h"
#include "GestorEnfermo.h"
namespace TrabajoFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Inicio
	/// </summary>
	public ref class Inicio : public System::Windows::Forms::Form
	{
	private:
		Enfermero* enfermero = new Enfermero(10, 300, 2);
		GesContagiado* g_contagiado = new GesContagiado();
		Bitmap^ mapa_contagiados = gcnew Bitmap("abeja.png");
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
		   //DEFINIR RUTA DEL SPRITE
		Bitmap^ mapa_enfermero = gcnew Bitmap("hulk.png");
	public:
		Inicio(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			int cantidad = 7 + rand() % 20 - 7;
			g_contagiado->agregaContagiados(cantidad);
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Inicio()
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Inicio::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &Inicio::timer1_Tick);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(599, 247);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(100, 50);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Visible = false;
			// 
			// Inicio
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1313, 605);
			this->Controls->Add(this->pictureBox1);
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"Inicio";
			this->Text = L"Inicio";
			this->Load += gcnew System::EventHandler(this, &Inicio::Inicio_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Inicio::Inicio_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Inicio::Inicio_KeyUp);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
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
		enfermero->mueveEnfermero(buffer, mapa_enfermero);
		g_contagiado->moverContagiados(buffer, mapa_contagiados);
		buffer->Render(canvaFormulario);
		delete buffer;
		delete canvaFormulario;
		delete espacio;
	}
	private: System::Void Inicio_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode) {
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
		enfermero->setDireccion(Ninguna);
	}
	};
}
