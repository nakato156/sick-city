#include "Inicio.h"
//#include "screenGameOver.h"

using namespace std;
using namespace System;
using namespace TrabajoFinal;

int main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	//Application::Run(gcnew TrabajoFinal::screenGameOver());
	Application::Run(gcnew TrabajoFinal::Inicio());
	return 0;
}
