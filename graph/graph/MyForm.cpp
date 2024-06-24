#include "MyForm.h"
#include "formula.cpp" // ������ �� ����������� �������� � �������

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]

int main(array<String^>^ args) { // ^ - ����������� �������� ���'��

	Application::SetCompatibleTextRenderingDefault(false); // �������� ������� ������
	Application::EnableVisualStyles();// ��������� ��� ������� ����
	graph::MyForm form; // ���������� �� �������� ���� (graph) � ���� �� ����� (MyForm) �� ��������� �
						//�� ��������� ��'��� (form) 
	Application::Run(% form); // ��'��� (form) �������� �� ������� (%)
}

System::Void graph::MyForm::builtToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) // ������ ���������� ������
{
	if (textBox_h->Text == "" || textBox_A->Text == "" || textBox_B->Text == "") {// ����������, �� ����� ��� ���� � ���������
		MessageBox::Show("Parameters set by default!", "Warning!");// ���� �, ��� ����������� ��� �� �����������
		DefaultParams();//����������� ��������� �� �����������
	}
	else {
		h = Convert::ToDouble(textBox_h->Text);
		a = Convert::ToDouble(textBox_A->Text);
		b = Convert::ToDouble(textBox_B->Text);
	}

	this->chart->Series[0]->Points->Clear();
	x = a;
	while (x <= b) {
		// ������� �� ������� �� ����� formula.cpp
		//y = Math::Sin(x);
		 y = fx(x);
		// 
		this->chart->Series[0]->Points->AddXY(x,y);
		x += h;
	}

}

System::Void graph::MyForm::clearToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)//������� ��������� ������
{
	this->chart->Series[0]->Points->Clear();// ������� ������
}

System::Void graph::MyForm::exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)//������� �����
{
	if (MessageBox::Show("Exit program?", "Warning!", MessageBoxButtons::YesNo) == Windows::Forms::DialogResult::Yes) {
		Application::Exit();
	}
}

void graph::MyForm::DefaultParams() //��������� �� �������������
{
	a = 1;
	b = 2;
	h = 0.1;
}
