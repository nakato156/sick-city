#pragma once
//#include "Level1.h"
#include "Reglas.h"
namespace TrabajoFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de selecModoJuego
	/// </summary>
	public ref class selecModoJuego : public System::Windows::Forms::Form
	{
	public:
		System::String^ name;
		selecModoJuego(System::String^ name_)
		{
			name = name_;
			InitializeComponent();
			this->msgBienvenida->Text += name + ", escoja su modo de juego!";
			//
			//TODO: agregar c�digo de constructor aqu�
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se est�n usando.
		/// </summary>
		~selecModoJuego()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ msgBienvenida;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::PictureBox^ imgSingleplayer;
	private: System::Windows::Forms::PictureBox^ imgMultiplayer;

	private:
		/// <summary>
		/// Variable del dise�ador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�todo necesario para admitir el Dise�ador. No se puede modificar
		/// el contenido de este m�todo con el editor de c�digo.
		/// </summary>
		void InitializeComponent(void)
		{
			this->msgBienvenida = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->imgSingleplayer = (gcnew System::Windows::Forms::PictureBox());
			this->imgMultiplayer = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imgSingleplayer))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imgMultiplayer))->BeginInit();
			this->SuspendLayout();
			// 
			// msgBienvenida
			// 
			this->msgBienvenida->AutoSize = true;
			this->msgBienvenida->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->msgBienvenida->Location = System::Drawing::Point(80, 69);
			this->msgBienvenida->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->msgBienvenida->Name = L"msgBienvenida";
			this->msgBienvenida->Size = System::Drawing::Size(202, 32);
			this->msgBienvenida->TabIndex = 0;
			this->msgBienvenida->Text = L"Bienvenido ";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(234, 406);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(152, 27);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Un jugador";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(765, 406);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(180, 27);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Multijugador";
			// 
			// imgSingleplayer
			// 
			this->imgSingleplayer->Cursor = System::Windows::Forms::Cursors::Hand;
			this->imgSingleplayer->Location = System::Drawing::Point(201, 222);
			this->imgSingleplayer->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->imgSingleplayer->Name = L"imgSingleplayer";
			this->imgSingleplayer->Size = System::Drawing::Size(228, 158);
			this->imgSingleplayer->TabIndex = 3;
			this->imgSingleplayer->TabStop = false;
			this->imgSingleplayer->Click += gcnew System::EventHandler(this, &selecModoJuego::imgSingleplayer_Click);
			// 
			// imgMultiplayer
			// 
			this->imgMultiplayer->Cursor = System::Windows::Forms::Cursors::Hand;
			this->imgMultiplayer->Location = System::Drawing::Point(746, 222);
			this->imgMultiplayer->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->imgMultiplayer->Name = L"imgMultiplayer";
			this->imgMultiplayer->Size = System::Drawing::Size(228, 158);
			this->imgMultiplayer->TabIndex = 4;
			this->imgMultiplayer->TabStop = false;
			// 
			// selecModoJuego
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(1312, 605);
			this->ControlBox = false;
			this->Controls->Add(this->imgMultiplayer);
			this->Controls->Add(this->imgSingleplayer);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->msgBienvenida);
			this->ForeColor = System::Drawing::Color::White;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"selecModoJuego";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->TopMost = true;
			this->Load += gcnew System::EventHandler(this, &selecModoJuego::selecModoJuego_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imgSingleplayer))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imgMultiplayer))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void imgSingleplayer_Click(System::Object^ sender, System::EventArgs^ e) {
		Reglas^ reglas = gcnew Reglas();
		this->Visible = false;
		reglas->Show();
		//Level1^ lvl1 = gcnew Level1();
		//lvl1->Show();
	}
private: System::Void selecModoJuego_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}
