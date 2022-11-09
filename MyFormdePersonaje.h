#pragma once

namespace EligiendoPersonaje {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

	/// <summary>
	/// Resumen de MyFormdePersonaje
	/// </summary>
	public ref class MyFormdePersonaje : public System::Windows::Forms::Form
	{
	private:
		Bitmap^ fondo = gcnew Bitmap("fondo.png");
		SoundPlayer^ audio = gcnew SoundPlayer("audio-juego.wav");
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button;
	public:
		MyFormdePersonaje(void)
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
		~MyFormdePersonaje()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;

	private: System::Windows::Forms::Label^ label1;



	private: System::Windows::Forms::PictureBox^ pictureBox1;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::Windows::Forms::RadioButton^ radioButton2;





	protected:
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyFormdePersonaje::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyFormdePersonaje::timer1_Tick);
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Cursor = System::Windows::Forms::Cursors::Default;
			this->label1->Font = (gcnew System::Drawing::Font(L"Snap ITC", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Lime;
			this->label1->Location = System::Drawing::Point(217, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(361, 81);
			this->label1->TabIndex = 1;
			this->label1->Text = L"SickCity";
			this->label1->Click += gcnew System::EventHandler(this, &MyFormdePersonaje::label1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(189, 302);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(85, 55);
			this->pictureBox1->TabIndex = 5;
			this->pictureBox1->TabStop = false;
			// 
			// label3
			// 
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Snap ITC", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::Yellow;
			this->label3->Location = System::Drawing::Point(225, 103);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(333, 47);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Seleccione personaje";
			// 
			// radioButton1
			// 
			this->radioButton1->BackColor = System::Drawing::Color::LightGray;
			this->radioButton1->CheckAlign = System::Drawing::ContentAlignment::BottomLeft;
			this->radioButton1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->radioButton1->Font = (gcnew System::Drawing::Font(L"Snap ITC", 12));
			this->radioButton1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"radioButton1.Image")));
			this->radioButton1->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->radioButton1->Location = System::Drawing::Point(135, 177);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(229, 180);
			this->radioButton1->TabIndex = 8;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"ENFERMERA";
			this->radioButton1->TextAlign = System::Drawing::ContentAlignment::BottomLeft;
			this->radioButton1->UseVisualStyleBackColor = false;
			this->radioButton1->CheckedChanged += gcnew System::EventHandler(this, &MyFormdePersonaje::radioButton1_CheckedChanged);
			// 
			// radioButton2
			// 
			this->radioButton2->AutoEllipsis = true;
			this->radioButton2->BackColor = System::Drawing::Color::LightGray;
			this->radioButton2->CheckAlign = System::Drawing::ContentAlignment::BottomLeft;
			this->radioButton2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->radioButton2->Font = (gcnew System::Drawing::Font(L"Snap ITC", 12));
			this->radioButton2->ForeColor = System::Drawing::SystemColors::ControlText;
			this->radioButton2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"radioButton2.Image")));
			this->radioButton2->ImageAlign = System::Drawing::ContentAlignment::TopCenter;
			this->radioButton2->Location = System::Drawing::Point(443, 177);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(233, 180);
			this->radioButton2->TabIndex = 9;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"ENFERMERO";
			this->radioButton2->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->radioButton2->UseVisualStyleBackColor = false;
			// 
			// button3
			// 
			this->button3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button3.Image")));
			this->button3->Location = System::Drawing::Point(23, 12);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(30, 28);
			this->button3->TabIndex = 10;
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyFormdePersonaje::button3_Click);
			// 
			// button4
			// 
			this->button4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button4.Image")));
			this->button4->Location = System::Drawing::Point(59, 12);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(33, 28);
			this->button4->TabIndex = 11;
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyFormdePersonaje::button4_Click);
			// 
			// MyFormdePersonaje
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::DarkViolet;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(816, 477);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->radioButton1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label1);
			this->Name = L"MyFormdePersonaje";
			this->Text = L"SickCity Game";
			this->Load += gcnew System::EventHandler(this, &MyFormdePersonaje::MyFormdePersonaje_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyFormdePersonaje_Load(System::Object^ sender, System::EventArgs^ e) {
		timer1->Enabled = true;
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ f = this->CreateGraphics(); //Crear los gráficos necesarios para el fondo
		BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;//darle el espacio para que se pueda generar el punto
		BufferedGraphics^ Buffer = espacio->Allocate(f, this->ClientRectangle);
		Buffer->Graphics->DrawImage(fondo/*el nombre de variable que contiene la imagen*/, 0, 0, /*donde inicia (0,0)*/ (int)Buffer->Graphics->VisibleClipBounds.Width/*ancho*/, (int)Buffer->Graphics->VisibleClipBounds.Height)/*alto*/;
		Buffer->Render(f);
		delete Buffer;
		delete espacio;
		delete f;

	}
	
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
//private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
//	
//}



private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	/*this->button1->UseVisualStyleBackColor = false;
	this->button2->UseVisualStyleBackColor = true;*/

	
}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
}

private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	/*this->button2->UseVisualStyleBackColor = false;
	this->button1->UseVisualStyleBackColor = true;*/

}
private: System::Void textBox1_TextChanged_1(System::Object^ sender, System::EventArgs^ e) {
}

private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	this->audio->PlayLooping();
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	this->audio->Stop();
}
};
}
