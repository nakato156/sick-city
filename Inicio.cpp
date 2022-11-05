#include "Inicio.h"
using namespace std;
using namespace System;
using namespace TrabajoFinal;
int main()
{
	srand(time(NULL));
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew TrabajoFinal::Inicio());
	return 0;
}
