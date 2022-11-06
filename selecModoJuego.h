#pragma once

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
	private:
		System::String^ name;
	public:
		selecModoJuego(System::String^ name_)
		{
			name = name_;
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
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
			this->msgBienvenida = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// msgBienvenida
			// 
			this->msgBienvenida->AutoSize = true;
			this->msgBienvenida->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->msgBienvenida->Location = System::Drawing::Point(53, 45);
			this->msgBienvenida->Name = L"msgBienvenida";
			this->msgBienvenida->Size = System::Drawing::Size(131, 21);
			this->msgBienvenida->TabIndex = 0;
			this->msgBienvenida->Text = L"Bienvenido " + name + ", escoja el modo de juego!";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(160, 264);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(108, 18);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Un jugador";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(510, 264);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(128, 18);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Multijugador";
			// 
			// selecModoJuego
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(875, 393);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->msgBienvenida);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"selecModoJuego";
			this->Text = L"selecModoJuego";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
