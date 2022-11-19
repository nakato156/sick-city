#pragma once
#include "selecPersonaje.h"
#include <fstream>
#include <sstream>
#include <string>
namespace TrabajoFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Reglas
	/// </summary>
	public ref class Reglas : public System::Windows::Forms::Form
	{
	private:
		//System::String^ playerName;
	public:
		Reglas()
		{
			InitializeComponent();
			//playerName = name;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Reglas()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->AutoSize = true;
			this->button1->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button1->Location = System::Drawing::Point(1114, 609);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(135, 63);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Continuar";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Reglas::button1_Click);
			// 
			// Reglas
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->ClientSize = System::Drawing::Size(1299, 708);
			this->Controls->Add(this->button1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Reglas";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Reglas";
			this->Load += gcnew System::EventHandler(this, &Reglas::Reglas_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Reglas::PintaRegla);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		auto seleccionarPers= gcnew selecPersonaje();
		auto result = seleccionarPers->ShowDialog();
		if (result == System::Windows::Forms::DialogResult::Abort) {
			DialogResult = result;
			this->Close();
		}
		else this->Close();
	}
	private: System::Void PintaRegla(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		DibujarReglas(e);
	}
		   void DibujarReglas(PaintEventArgs^ e) {
			   std::ifstream archivo;
			   archivo.open("reglas.txt");
			   std::string linea;
			   std::string texto = "\n\n";
			   if (archivo.is_open()) {
				   while (getline(archivo, linea)) texto += linea + '\n';
				   archivo.close();
			   } else exit(EXIT_FAILURE);
			   
			   Graphics^ canva = this->CreateGraphics();
			   int ancho = this->ClientSize.Width;

			   Drawing::Font^ tipoLetra = gcnew Drawing::Font("Times New Roman", 20);
			   canva->DrawString("Reglas del juego: ", tipoLetra, Brushes::Red, (ancho / 3) - 50, 25);
			   
			   Drawing::Font^ tipoLetraReglas = gcnew Drawing::Font("Times New Roman", 10);
			   auto nuevoString = gcnew String(texto.c_str());
			   canva->DrawString(nuevoString, tipoLetraReglas, Brushes::White, (ancho/5), 35);
		   }
	private: System::Void Reglas_Load(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
