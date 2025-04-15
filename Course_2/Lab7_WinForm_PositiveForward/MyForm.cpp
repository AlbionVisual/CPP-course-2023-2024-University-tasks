/* При выполнении заданий необходимо использовать как  главную
форму, так и новую форму, которая может быть создана самостоятельно.
Для вывода сообщений использовать диалоговые окна (функция
MessageBox::Show (…)). Для ввода информации использовать компоненты
TextBoxt, NumericUpDown (ввод числовых данных) и другие. Для
указания на окончание ввода исходных данных использовать как
кнопки, так и нажатие на клавишу Enter. При вводе числовых данных в
текстовые компоненты предусмотреть контроль вводимых данных.

8. Преобразовать одномерный массив таким образом, чтобы сначала
располагались все положительные элементы, а потом – все
отрицательные.*/

#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args) {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	Lab7WinFormPositiveForward::MyForm form;
	Application::Run(% form);
}