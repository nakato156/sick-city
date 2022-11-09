#include "MyFormdePersonaje.h"

using namespace EligiendoPersonaje;
void main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew  EligiendoPersonaje::MyFormdePersonaje()); // S91Formularios 1 es el nombre del proyecto
}