#pragma once
//#include "Inicio.h"
#include <string>
namespace TrabajoFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de screenGameOver
	/// </summary>
	public ref class screenGameOver : public System::Windows::Forms::Form
	{
	public:
		screenGameOver(std::string tiempoTranscurrido, int curados)
		{
			InitializeComponent();
			this->lblTimetotal->Text = gcnew System::String(tiempoTranscurrido.c_str());
			this->lblInfcCurados->Text = gcnew System::String(std::to_string(curados).c_str());
			//
			//TODO: agregar c�digo de constructor aqu�
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se est�n usando.
		/// </summary>
		~screenGameOver()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2_Click;
	private: System::Windows::Forms::Button^ btnBackMenu;
	private: System::Windows::Forms::Button^ btnAgain;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ lblTimetotal;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ lblInfcCurados;

	protected:

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
			this->btnBackMenu = (gcnew System::Windows::Forms::Button());
			this->btnAgain = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lblTimetotal = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->lblInfcCurados = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btnBackMenu
			// 
			this->btnBackMenu->BackColor = System::Drawing::Color::DarkRed;
			this->btnBackMenu->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnBackMenu->Location = System::Drawing::Point(740, 351);
			this->btnBackMenu->Name = L"btnBackMenu";
			this->btnBackMenu->Size = System::Drawing::Size(123, 30);
			this->btnBackMenu->TabIndex = 0;
			this->btnBackMenu->Text = L"Ir al menu";
			this->btnBackMenu->UseVisualStyleBackColor = false;
			this->btnBackMenu->Click += gcnew System::EventHandler(this, &screenGameOver::btnBackMenu_Click);
			// 
			// btnAgain
			// 
			this->btnAgain->BackColor = System::Drawing::Color::DarkRed;
			this->btnAgain->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnAgain->Location = System::Drawing::Point(594, 351);
			this->btnAgain->Name = L"btnAgain";
			this->btnAgain->Size = System::Drawing::Size(123, 30);
			this->btnAgain->TabIndex = 1;
			this->btnAgain->Text = L"Reintentar";
			this->btnAgain->UseVisualStyleBackColor = false;
			this->btnAgain->Click += gcnew System::EventHandler(this, &screenGameOver::btnAgain_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(30, 79);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(230, 22);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Tiempo Transcurrido:";
			// 
			// lblTimetotal
			// 
			this->lblTimetotal->AutoSize = true;
			this->lblTimetotal->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTimetotal->Location = System::Drawing::Point(266, 79);
			this->lblTimetotal->Name = L"lblTimetotal";
			this->lblTimetotal->Size = System::Drawing::Size(21, 22);
			this->lblTimetotal->TabIndex = 3;
			this->lblTimetotal->Text = L"0";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(30, 127);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(219, 22);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Infectados curados:";
			// 
			// lblInfcCurados
			// 
			this->lblInfcCurados->AutoSize = true;
			this->lblInfcCurados->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblInfcCurados->Location = System::Drawing::Point(266, 127);
			this->lblInfcCurados->Name = L"lblInfcCurados";
			this->lblInfcCurados->Size = System::Drawing::Size(21, 22);
			this->lblInfcCurados->TabIndex = 5;
			this->lblInfcCurados->Text = L"0";
			// 
			// screenGameOver
			// 
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(875, 393);
			this->Controls->Add(this->lblInfcCurados);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->lblTimetotal);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btnAgain);
			this->Controls->Add(this->btnBackMenu);
			this->Font = (gcnew System::Drawing::Font(L"Courier New", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ForeColor = System::Drawing::Color::White;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"screenGameOver";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Load += gcnew System::EventHandler(this, &screenGameOver::screenGameOver_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void pantallaFinal_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btnBackMenu_Click(System::Object^ sender, System::EventArgs^ e) { 
		//cuando se aprete el boton de menu, este formulario se cierra y el formulario inicial vuelve a ejecutarse
		this->DialogResult = System::Windows::Forms::DialogResult::OK;
		this->Close();
	}
	private: System::Void btnAgain_Click(System::Object^ sender, System::EventArgs^ e) {
		//cuando se aprete el boton de volver a iniciar, este formulario se cierrra y el formulario de level1 vuelve a ejecutarse
		this->DialogResult = System::Windows::Forms::DialogResult::Retry;
		this->Close();
	}
private: System::Void screenGameOver_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}
