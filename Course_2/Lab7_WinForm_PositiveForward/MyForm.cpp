/* ��� ���������� ������� ���������� ������������ ���  �������
�����, ��� � ����� �����, ������� ����� ���� ������� ��������������.
��� ������ ��������� ������������ ���������� ���� (�������
MessageBox::Show (�)). ��� ����� ���������� ������������ ����������
TextBoxt, NumericUpDown (���� �������� ������) � ������. ���
�������� �� ��������� ����� �������� ������ ������������ ���
������, ��� � ������� �� ������� Enter. ��� ����� �������� ������ �
��������� ���������� ������������� �������� �������� ������.

8. ������������� ���������� ������ ����� �������, ����� �������
������������� ��� ������������� ��������, � ����� � ���
�������������.*/

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