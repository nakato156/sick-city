#pragma once
#include <string>
#include <iostream>
namespace TrabajoFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ScreenWin
	/// </summary>
	public ref class ScreenWin : public System::Windows::Forms::Form
	{
	public:
		ScreenWin(std::string tiempoTranscurrido, int curados)
		{
			InitializeComponent();
			this->lblTimetotal->Text = gcnew System::String(tiempoTranscurrido.c_str());
			this->lblInfcCurados->Text = gcnew System::String(std::to_string(curados).c_str());
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ScreenWin()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ lblTimetotal;
	private: System::Windows::Forms::Label^ lblInfcCurados;

	private: System::Windows::Forms::Button^ btnBackMenu;
	private: System::Windows::Forms::PictureBox^ pictureBox1;



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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ScreenWin::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->lblTimetotal = (gcnew System::Windows::Forms::Label());
			this->lblInfcCurados = (gcnew System::Windows::Forms::Label());
			this->btnBackMenu = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Courier New", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label1->Location = System::Drawing::Point(103, 479);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(354, 31);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Tiempo Transcurrido:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Courier New", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label2->Location = System::Drawing::Point(109, 518);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(354, 31);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Infectados Curados: ";
			// 
			// lblTimetotal
			// 
			this->lblTimetotal->AutoSize = true;
			this->lblTimetotal->Font = (gcnew System::Drawing::Font(L"Courier New", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTimetotal->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->lblTimetotal->Location = System::Drawing::Point(481, 479);
			this->lblTimetotal->Name = L"lblTimetotal";
			this->lblTimetotal->Size = System::Drawing::Size(31, 31);
			this->lblTimetotal->TabIndex = 2;
			this->lblTimetotal->Text = L"0";
			// 
			// lblInfcCurados
			// 
			this->lblInfcCurados->AutoSize = true;
			this->lblInfcCurados->Font = (gcnew System::Drawing::Font(L"Courier New", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblInfcCurados->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->lblInfcCurados->Location = System::Drawing::Point(481, 518);
			this->lblInfcCurados->Name = L"lblInfcCurados";
			this->lblInfcCurados->Size = System::Drawing::Size(31, 31);
			this->lblInfcCurados->TabIndex = 3;
			this->lblInfcCurados->Text = L"0";
			// 
			// btnBackMenu
			// 
			this->btnBackMenu->BackColor = System::Drawing::Color::DarkRed;
			this->btnBackMenu->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnBackMenu->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnBackMenu->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->btnBackMenu->Location = System::Drawing::Point(851, 562);
			this->btnBackMenu->Name = L"btnBackMenu";
			this->btnBackMenu->Size = System::Drawing::Size(186, 64);
			this->btnBackMenu->TabIndex = 4;
			this->btnBackMenu->Text = L"Ir al menu";
			this->btnBackMenu->UseVisualStyleBackColor = false;
			this->btnBackMenu->Click += gcnew System::EventHandler(this, &ScreenWin::btnBackMenu_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(311, 56);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(336, 276);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 5;
			this->pictureBox1->TabStop = false;
			// 
			// ScreenWin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->ClientSize = System::Drawing::Size(1091, 638);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->btnBackMenu);
			this->Controls->Add(this->lblInfcCurados);
			this->Controls->Add(this->lblTimetotal);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"ScreenWin";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"ScreenWin";
			this->Load += gcnew System::EventHandler(this, &ScreenWin::ScreenWin_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void ScreenWin_Load(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void btnBackMenu_Click(System::Object^ sender, System::EventArgs^ e) {
	this->DialogResult = System::Windows::Forms::DialogResult::OK;
	this->Close();
}
};
}
