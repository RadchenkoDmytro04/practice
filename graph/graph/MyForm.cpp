#include "MyForm.h"
#include "formula.cpp" // модуль ≥з розробленою функц≥Їю з вар≥анту

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]

int main(array<String^>^ args) { // ^ - автоматичне очищенн€ пам'€т≥

	Application::SetCompatibleTextRenderingDefault(false); // коректна обробка тексту
	Application::EnableVisualStyles();// п≥дклю€аЇмо р≥зн≥ в≥зуальн≥ стил≥
	graph::MyForm form; // звертаЇмось до простору ≥мен (graph) а пот≥м до класу (MyForm) та створюЇмо о
						//та створюЇмо об'Їкт (form) 
	Application::Run(% form); // об'Їкт (form) передаЇмо за ссилкою (%)
}

System::Void graph::MyForm::builtToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) // кнопка побудувати граф≥к
{
	if (textBox_h->Text == "" || textBox_A->Text == "" || textBox_B->Text == "") {// перев≥р€Їмо, чи задан хоч один з переметр≥в
		MessageBox::Show("Parameters set by default!", "Warning!");// €кщо н≥, тод≥ попереджаЇмо про це користувача
		DefaultParams();//виставл€Їмо параметри за замовченн€м
	}
	else {
		h = Convert::ToDouble(textBox_h->Text);
		a = Convert::ToDouble(textBox_A->Text);
		b = Convert::ToDouble(textBox_B->Text);
	}

	this->chart->Series[0]->Points->Clear();
	x = a;
	while (x <= b) {
		// зам≥нити на функц≥ю ≥з файлу formula.cpp
		//y = Math::Sin(x);
		 y = fx(x);
		// 
		this->chart->Series[0]->Points->AddXY(x,y);
		x += h;
	}

}

System::Void graph::MyForm::clearToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)//конопка очичстити граф≥к
{
	this->chart->Series[0]->Points->Clear();// очищаЇмо граф≥к
}

System::Void graph::MyForm::exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)//конопка вих≥д
{
	if (MessageBox::Show("Exit program?", "Warning!", MessageBoxButtons::YesNo) == Windows::Forms::DialogResult::Yes) {
		Application::Exit();
	}
}

void graph::MyForm::DefaultParams() //параметри за замовчуванн€м
{
	a = 1;
	b = 2;
	h = 0.1;
}
