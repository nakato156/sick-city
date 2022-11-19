#pragma once

template <class F, class NF>
void showScreenWinGame(F^ form, NF^ nuevoForm, System::Windows::Forms::Timer^ timer) {
	timer->Enabled = false;
	form->Hide();
	auto resultado = nuevoForm->ShowDialog(form);
	if (resultado == System::Windows::Forms::DialogResult::OK)
		form->DialogResult = System::Windows::Forms::DialogResult::OK;
		form->Close();
}

template <class F>
void showControlPanel(F^ form, System::Windows::Forms::Panel^ controlPanel, System::Windows::Forms::Timer^ timer) {
	controlPanel->Visible = true;
	auto punto = controlPanel->Location;
	if (punto.Y + form->velCP >= 0) {
		form->CPVisible = true;
		form->mostrarCP = false;
		timer->Enabled = false;
	}
	else controlPanel->Location = System::Drawing::Point(punto.X, punto.Y + form->velCP);
}

template <class F>
void hideControlPanel(F^ form, System::Windows::Forms::Panel^ controlPanel, System::Windows::Forms::Timer^ timer) {
	auto punto = controlPanel->Location;

	if (punto.Y + form->velCP <= (-190 - form->velCP)) {
		form->CPVisible = false;
		form->mostrarCP = true;
		timer->Enabled = false;
		controlPanel->Hide();
		form->Focus();
	}
	else controlPanel->Location = System::Drawing::Point(punto.X, punto.Y - form->velCP);
}