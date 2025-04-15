#include "Form1.h"
#include "Form2.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args) {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	//lab3::Form1 form;
	lab3b::Form1 form;
	Application::Run(% form);
}



//*/