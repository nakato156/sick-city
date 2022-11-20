#pragma once
#include "selecModoJuego.h"

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
		int activeMove, moveX, moveY;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	public:
		Inicio(void)
		{
			InitializeComponent();
			this->leftMsg = this->label1->Left - 120;
			//
			//TODO: agregar código de constructor aquí
			//
		}
	private: System::Windows::Forms::TextBox^ txtInputName;

	public:

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		int leftMsg;
		~Inicio()
		{
			if (components)
			{
				delete components;
			}
		}
	protected:
	private: System::Windows::Forms::Label^ label1;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Inicio::typeid));
			this->txtInputName = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// txtInputName
			// 
			this->txtInputName->BackColor = System::Drawing::SystemColors::Window;
			this->txtInputName->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtInputName->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtInputName->Location = System::Drawing::Point(357, 223);
			this->txtInputName->Name = L"txtInputName";
			this->txtInputName->Size = System::Drawing::Size(197, 29);
			this->txtInputName->TabIndex = 0;
			this->txtInputName->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Inicio::textInputName_KeyPress);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(357, 255);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(197, 21);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Ingrese su nombre";
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.BackgroundImage")));
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox2->Location = System::Drawing::Point(844, 0);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(36, 30);
			this->pictureBox2->TabIndex = 6;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Click += gcnew System::EventHandler(this, &Inicio::pictureBox2_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->panel1->Controls->Add(this->pictureBox2);
			this->panel1->Location = System::Drawing::Point(-3, -2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(895, 30);
			this->panel1->TabIndex = 7;
			this->panel1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Inicio::panel1_MouseDown);
			this->panel1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Inicio::panel1_MouseMove);
			this->panel1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Inicio::panel1_MouseUp);
			// 
			// Inicio
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Inherit;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(875, 393);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txtInputName);
			this->ForeColor = System::Drawing::Color::White;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Inicio";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Load += gcnew System::EventHandler(this, &Inicio::Inicio_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Inicio::Inicio_Paint_1);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	private: System::Void Inicio_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		checkName(e);
	}

	private: System::Void txtInputName_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		checkName(e);
	}

private: System::Void textInputName_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	checkName(e);
}
	   void dibujarTrazado(PaintEventArgs^ e) {
		   System::Drawing::Drawing2D::GraphicsPath^ trazado = gcnew System::Drawing::Drawing2D::GraphicsPath;
		   int ancho = this->ClientSize.Width;
		   int mitad = ancho / 2;
		   trazado->AddEllipse(mitad - 170, 0, 200, 100);
		   array<Point>^ u = { Point(mitad - 120, 30),	Point(mitad - 120, 70),	Point(mitad - 100,70),	Point(mitad - 100, 30) };
		   array<Point>^ p = { Point(mitad - 80,40),	Point(mitad - 60,40),	Point(mitad - 60,30),	Point(mitad - 80, 30),	Point(mitad - 80,70) };
		   array<Point>^ c = { Point(mitad - 20,30),	Point(mitad - 40,30),	Point(mitad - 40,70),	Point(mitad - 20, 70) };
		   trazado->AddLines(u);
		   trazado->AddLines(p);
		   trazado->AddLines(c);
		   System::Drawing::Drawing2D::Matrix^ matriz = gcnew System::Drawing::Drawing2D::Matrix;
		   //crea un matriz para hacer el movimiento de todos los puntos a una nuevaposicion X,Y
		   matriz->Translate(100, 100);
		   trazado->Transform(matriz);
		   // Crear lapicero
		   // Dibuja el trazado de dibujo en la pantalla.
		   e->Graphics->DrawPath(Pens::White, trazado);
		   //Disfuncionales
		   Graphics^ canva = this->CreateGraphics();
		   Drawing::Font^ tipoLetra = gcnew Drawing::Font("Times New Roman", 42);
		   //canva->Clear(Color::White);						color de fondo
		   canva->DrawString("Los Disfuncionales", tipoLetra, Brushes::Red, (ancho / 3) - 50, 25);

	   }
	   void checkName(System::Windows::Forms::KeyPressEventArgs^ e) {
		   if (e->KeyChar == '\r') {
			   if (this->txtInputName->Text->Trim()->Equals("")) {
				   this->label1->Left = leftMsg;
				   this->label1->Text = "Por favor ingrese su nombre para continuar";
			   }
			   else {
				   System::String^ name = System::Convert::ToString(this->txtInputName->Text->Trim());
				   selecModoJuego^ VModoJuego = gcnew TrabajoFinal::selecModoJuego(name);
				   this->Visible = false;
				   if (VModoJuego->ShowDialog() == System::Windows::Forms::DialogResult::Abort)
					   this->Close();
			   }
		   }
	   }

private: System::Void Inicio_Paint_1(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	dibujarTrazado(e);
}
private: System::Void Inicio_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void pictureBox1_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
}
private: System::Void pictureBox1_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
}
private: System::Void pictureBox1_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
}
private: System::Void pictureBox2_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
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
};
}
