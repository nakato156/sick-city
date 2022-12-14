#pragma once
#include "Level1.h"
#include "Level2.h"

namespace TrabajoFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

	/// <summary>
	/// Resumen de selecPersonaje
	/// </summary>
	public ref class selecPersonaje : public System::Windows::Forms::Form
	{
	private:
		int activeMove = 0, moveX, moveY; 
		bool playing = true;
		SoundPlayer^ audio = gcnew SoundPlayer("audio-juego.wav");
		System::String^ tipoPersonaje;

		Bitmap^ modelEnfra = gcnew Bitmap("imgs/modelEnfra.png");
		Bitmap^ modelEnfraAtc = gcnew Bitmap("imgs/modelEnfraAct.png");
		Bitmap^ modelEnf = gcnew Bitmap("imgs/modelEnf.png");
		Bitmap^ modelEnfAct = gcnew Bitmap("imgs/modelEnfAct.png");

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;

	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::Windows::Forms::RadioButton^ radioButton2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ btnPlay;
	private: System::Windows::Forms::Button^ button3;

	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;



	private: System::Windows::Forms::Timer^ timer1;
	public:
		selecPersonaje()
		{
			InitializeComponent();
			this->audio->PlayLooping();
			//
			//TODO: agregar c?digo de constructor aqu?
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se est?n usando.
		/// </summary>
		~selecPersonaje()
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
		/// Variable del dise?ador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// M?todo necesario para admitir el Dise?ador. No se puede modificar
		/// el contenido de este m?todo con el editor de c?digo.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(selecPersonaje::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->btnPlay = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &selecPersonaje::timer1_Tick);
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Cursor = System::Windows::Forms::Cursors::Default;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Lime;
			this->label1->Location = System::Drawing::Point(231, 36);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(348, 81);
			this->label1->TabIndex = 1;
			this->label1->Text = L"SickCity";
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label2
			// 
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::Gold;
			this->label2->Location = System::Drawing::Point(225, 103);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(333, 47);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Seleccione su personaje";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// radioButton1
			// 
			this->radioButton1->BackColor = System::Drawing::Color::Transparent;
			this->radioButton1->CheckAlign = System::Drawing::ContentAlignment::BottomLeft;
			this->radioButton1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->radioButton1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->radioButton1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->radioButton1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"radioButton1.Image")));
			this->radioButton1->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->radioButton1->Location = System::Drawing::Point(132, 178);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(215, 184);
			this->radioButton1->TabIndex = 8;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"ENFERMERA";
			this->radioButton1->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->radioButton1->UseVisualStyleBackColor = false;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &selecPersonaje::radioButton1_CheckedChanged);
			this->radioButton1->MouseLeave += gcnew System::EventHandler(this, &selecPersonaje::radioButton1_MouseLeave);
			this->radioButton1->MouseHover += gcnew System::EventHandler(this, &selecPersonaje::radioButton1_MouseHover);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoEllipsis = true;
			this->radioButton2->BackColor = System::Drawing::Color::Transparent;
			this->radioButton2->CheckAlign = System::Drawing::ContentAlignment::BottomLeft;
			this->radioButton2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->radioButton2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->radioButton2->ForeColor = System::Drawing::Color::Black;
			this->radioButton2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"radioButton2.Image")));
			this->radioButton2->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->radioButton2->Location = System::Drawing::Point(443, 177);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(238, 185);
			this->radioButton2->TabIndex = 9;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"ENFERMERO";
			this->radioButton2->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->radioButton2->UseVisualStyleBackColor = false;
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &selecPersonaje::radioButton2_CheckedChanged);
			this->radioButton2->MouseLeave += gcnew System::EventHandler(this, &selecPersonaje::radioButton2_MouseLeave);
			this->radioButton2->MouseHover += gcnew System::EventHandler(this, &selecPersonaje::radioButton2_MouseHover);
			// 
			// button1
			// 
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.Image")));
			this->button1->Location = System::Drawing::Point(14, 36);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(30, 28);
			this->button1->TabIndex = 10;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &selecPersonaje::button1_Click);
			// 
			// button2
			// 
			this->button2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.Image")));
			this->button2->Location = System::Drawing::Point(62, 36);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(33, 28);
			this->button2->TabIndex = 11;
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &selecPersonaje::button2_Click);
			// 
			// btnPlay
			// 
			this->btnPlay->BackColor = System::Drawing::Color::Black;
			this->btnPlay->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnPlay->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnPlay->ForeColor = System::Drawing::Color::White;
			this->btnPlay->Location = System::Drawing::Point(69, 413);
			this->btnPlay->Name = L"btnPlay";
			this->btnPlay->Size = System::Drawing::Size(111, 43);
			this->btnPlay->TabIndex = 12;
			this->btnPlay->Text = L"Jugar Nivel 1\r\n";
			this->btnPlay->UseVisualStyleBackColor = false;
			this->btnPlay->Click += gcnew System::EventHandler(this, &selecPersonaje::btnPlay_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::Black;
			this->button3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button3->ForeColor = System::Drawing::Color::White;
			this->button3->Location = System::Drawing::Point(639, 413);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(111, 43);
			this->button3->TabIndex = 13;
			this->button3->Text = L"Jugar Nivel 2";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &selecPersonaje::button3_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->panel1->Controls->Add(this->pictureBox2);
			this->panel1->Location = System::Drawing::Point(0, -1);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(840, 30);
			this->panel1->TabIndex = 15;
			this->panel1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &selecPersonaje::panel1_MouseDown);
			this->panel1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &selecPersonaje::panel1_MouseMove);
			this->panel1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &selecPersonaje::panel1_MouseUp);
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.BackgroundImage")));
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox2->Location = System::Drawing::Point(785, 0);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(36, 30);
			this->pictureBox2->TabIndex = 7;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Click += gcnew System::EventHandler(this, &selecPersonaje::pictureBox2_Click);
			// 
			// selecPersonaje
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(816, 477);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->btnPlay);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->radioButton1);
			this->ForeColor = System::Drawing::Color::Black;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"selecPersonaje";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"selecPersonaje";
			this->Load += gcnew System::EventHandler(this, &selecPersonaje::selecPersonaje_Load);
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		//Graphics^ f = this->CreateGraphics(); //Crear los gr?ficos necesarios para el fondo
		//BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;//darle el espacio para que se pueda generar el punto
		//BufferedGraphics^ Buffer = espacio->Allocate(f, this->ClientRectangle);
		//Buffer->Graphics->DrawImage(fondo, 0, 0, (int)Buffer->Graphics->VisibleClipBounds.Width, (int)Buffer->Graphics->VisibleClipBounds.Height);
		//Buffer->Render(f);
		//delete Buffer;
		//delete espacio;
		//delete f;
	}
	private: System::Void selecPersonaje_Load(System::Object^ sender, System::EventArgs^ e) {
		timer1->Enabled = true;
	}
	private: System::Void radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		tipoPersonaje = "enfermera";
	}
	private: System::Void radioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		tipoPersonaje = "enfermero";
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		this->audio->Stop();
		playing = false;
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (!playing) {
			playing = true;
			this->audio->PlayLooping();
		}
	}

	private: System::Void radioButton1_MouseHover(System::Object^ sender, System::EventArgs^ e) {
		this->radioButton1->Image = modelEnfraAtc;
	}
	private: System::Void radioButton1_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
		this->radioButton1->Image = modelEnfra;
	}

	private: System::Void radioButton2_MouseHover(System::Object^ sender, System::EventArgs^ e) {
		this->radioButton2->Image = modelEnfAct;
	}

	private: System::Void radioButton2_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
		this->radioButton2->Image = modelEnf;
	}
	
	private: System::Void btnPlay_Click(System::Object^ sender, System::EventArgs^ e) {
		auto lvl1 = gcnew Level1(tipoPersonaje, audio);
		this->Hide();
		lvl1->ShowDialog();
		this->Visible = true;
	}

	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		while (true) {
			auto lvl2 = gcnew Level2(tipoPersonaje, audio);
			auto result = lvl2->ShowDialog();
			if (result != System::Windows::Forms::DialogResult::Retry) break;
		}
		this->Visible = true;
	}
private: System::Void panel1_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	activeMove = 1;
	moveX = e->X; moveY = e->Y;
}
private: System::Void panel1_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (activeMove) this->SetDesktopLocation(MousePosition.X - moveX, MousePosition.Y - moveY);
}
private: System::Void panel1_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	activeMove = 0;
}
private: System::Void pictureBox2_Click(System::Object^ sender, System::EventArgs^ e) {
	DialogResult = System::Windows::Forms::DialogResult::Abort;
	this->Close();
}
};
}
