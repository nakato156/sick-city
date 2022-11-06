#include "Inicio.h"

using namespace std;
using namespace System;
using namespace TrabajoFinal;

int main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew TrabajoFinal::Inicio());
	return 0;
}
