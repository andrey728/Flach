#pragma once
#include <chrono>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <cmath>

namespace Flach {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Text::RegularExpressions;

	double Gl;
	double REEEEE;
	double Sentences;
	double Words;
	double Glases;
	double ASW = Glases / Words;
	double ASL = Words / Sentences;
	double Big_Word;
	double Fog_Index;

	std::vector <std::string> word;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(60, 52);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(118, 40);
			this->button1->TabIndex = 0;
			this->button1->Text = L"ѕодсчет данных";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(249, 52);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(272, 74);
			this->textBox1->TabIndex = 1;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(249, 144);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(272, 89);
			this->textBox2->TabIndex = 2;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(60, 144);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(118, 40);
			this->button2->TabIndex = 3;
			this->button2->Text = L"–асчет дл€ јнглийского текста";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(60, 98);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(118, 40);
			this->button3->TabIndex = 4;
			this->button3->Text = L"–асчет дл€ –усского текста";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(383, 239);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(138, 20);
			this->textBox3->TabIndex = 5;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(383, 265);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(138, 20);
			this->textBox4->TabIndex = 6;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(235, 242);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(142, 13);
			this->label1->TabIndex = 7;
			this->label1->Text = L"”ровень удобочитаемости";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(221, 268);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(156, 13);
			this->label2->TabIndex = 8;
			this->label2->Text = L"”ровень по ‘лешу- инсайду";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(570, 352);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:void MarshalString(String^ s, std::string& os) {
		using namespace Runtime::InteropServices;
		const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
		os = chars;
		Marshal::FreeHGlobal(IntPtr((void*)chars));
	}


	//private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	//	Stream^ s;
	//	//
	//	// Ќастройка открыти€ файла
	//	//
	//	openFileDialog1->Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
	//	openFileDialog1->FilterIndex = 2;
	//	openFileDialog1->RestoreDirectory = true;
	//	//
	//	textBox1->Text = "";
	//	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	//	{
	//		if ((s = openFileDialog1->OpenFile()) != nullptr)
	//		{
	//			Regex^ Noprob = gcnew Regex("\\S+");
	//			String^ path = openFileDialog1->FileName;
	//			StreamReader^ sr = gcnew StreamReader(path);
	//			String^ line;
	//			word.clear();
	//			while ((line = sr->ReadLine()) != nullptr)
	//			{
	//				textBox1->AppendText(line + " ");
	//				std::string std = "";
	//				MarshalString(line, std);
	//				//std::istringstream strvec(std);

	//				try {
	//					for (Match^ piece = Noprob->Match(std); piece->Success; piece = piece->NextMatch())
	//					{
	//						if (piece->Value->Length > 0) { word.push_back(piece->Value); }
	//					}
	//				}
	//				catch (Exception ^ e) { MessageBox::Show("F"); }

	//				//double vec;
	//				//while (strvec >> vec) {
	//					//mass.push_back(vec);
	//				//}
	//			}
	//			sr->Close();
	//			if (textBox1->Text == " ") textBox1->Text = "‘айл пуст";
	//		}
	//		else MessageBox::Show("ќшибка открыти€ файла");
	//	}
	//	s->Close();

	////	for (int i = 0; i < word.size(); i++) {
	//	//	textBox2 = textBox2 + Convert::ToString(word[i]) + " ";
	//	//}




		String^ End = ".!?";
		String^ rus = "Єйцукенгшщзхъфывапролджэ€чсмитьбю";
		String^ RUS = "®…÷” ≈Ќ√Ўў«’Џ‘џ¬јѕ–ќЋƒ∆Ёя„—ћ»“№Ѕё";
		String^ Rus_Glases = "®Є”у≈еџыјаќоЁэя€»иёю";
		String^ eu = "qwertyuiopasdfghjklzxcvbnm";
		String^ EU = "QWERTYUIOPASDFGHJKLZXCVBNM";
		String^ EU_Glases = "AaEeIiOoUuYy";

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		Stream^ s;
		openFileDialog1->Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
		openFileDialog1->FilterIndex = 2;
		openFileDialog1->RestoreDirectory = true;
		bool Start_of_Sent = false;
		bool Start_of_Word = false;
		bool in_Word = false;
		REEEEE = 0;
		Sentences = 0;
		Words = 0;
		Glases = 0;
		double Glases_in_Word = 0;
		Big_Word = 0;

		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			if ((s = openFileDialog1->OpenFile()) != nullptr) {

				String^ path = openFileDialog1->FileName;
				StreamReader^ sr = gcnew StreamReader(path);
				String^ line;
				textBox1->Clear();

				while ((line = sr->ReadLine()) != nullptr)
				{

					// ѕодсчет предложений
					for (int i = 0; i < line->Length; i++) {
						if (Start_of_Sent) {
							for (int k = 0; k < End->Length; k++) {
								if (line[i] == End[k]) {
									Start_of_Sent = false;
									Sentences++;

								}
							}
						}

						// –усский алфавит - подсчет слов
						in_Word = true;
						for (int k = 0; k < rus->Length; k++) {
							if (line[i] == rus[k]) {
								if (!Start_of_Word) {
									Start_of_Word = true;
									Words++;
									for (int l = 0; l < Rus_Glases->Length; l++) { 
										if (line[i] == Rus_Glases[l]) {
											Glases++;
										}
									}
								}
								in_Word = false;
							}
							if (line[i] == RUS[k] && Start_of_Sent == false) {
								Start_of_Sent = true;
							}
						}

						// јнглийский алфавит - подсчет слов
						for (int k = 0; k < eu->Length; k++) {
							if (line[i] == eu[k]) {
								if (!Start_of_Word) {
									Start_of_Word = true;
									Words++;

								}
								in_Word = false;
							}
							if (line[i] == EU[k] && Start_of_Sent == false) {
								Start_of_Sent = true;
							}
						}
						
						// –усский алфавит - подсчет глассных (слогов)
						for (int l = 0; l < Rus_Glases->Length; l++) {
							if (line[i] == Rus_Glases[l]) {
								Glases++;
								if (in_Word) Glases_in_Word++;
							}
						}

						// јнглийский алфавит - подсчет слов
						for (int l = 0; l < EU_Glases->Length; l++) {
							if (line[i] == EU_Glases[l]) {
								Glases++;
								if (in_Word) Glases_in_Word++;
							}
						}

						if (in_Word && Start_of_Word) {
							if (Glases_in_Word > 4) {
								Big_Word++;
								Glases_in_Word = 0;
							}
							Start_of_Word = false;
						}
					}
				}		
				sr->Close();
			}
		}
		s->Close();

		ASW = Glases / Words;
		ASL = Words / Sentences;
		textBox1->Text = Convert::ToString(Sentences) + "  предложений\r\n";
		textBox1->Text += Convert::ToString(Words) + "  слов\r\n";
		textBox1->Text += Convert::ToString(Glases) + "  слогов\r\n";
		textBox1->Text += Convert::ToString(Big_Word) + "  сложных слов\r\n";
	}

	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		REEEEE = 206.835 - 60.1 * ASW - 1.3 * ASL;
		Gl = 8.38 * ASW + 0.45 * ASL - 15.59;
		Fog_Index = 0.4*(0.78*ASL+100*(Big_Word/Words));
		textBox2->Text = Convert::ToString(ASW) + " - среднее число слогов в слове\r\n";
		textBox2->Text += Convert::ToString(ASL) + " - средн€€ длина предложени€\r\n";
		textBox2->Text += Convert::ToString(REEEEE) + " - показатель удобочитаемости\r\n";
		if (REEEEE <= 100) textBox3->Text = "очень высокий";
		if (REEEEE < 90) textBox3->Text = "высокий";
		if (REEEEE < 80) textBox3->Text = "выше среднего";
		if (REEEEE < 70) textBox3->Text = "средний";
		if (REEEEE < 60) textBox3->Text = "ниже среднего";
		if (REEEEE < 50) textBox3->Text = "низкий";
		if (REEEEE < 30) textBox3->Text = "очень низкий";
		textBox2->Text += Convert::ToString(Gl) + " - по ‘лешу- инсайду\r\n";
		int gl = round(Gl);
		textBox4->Text = Convert::ToString(gl);
		textBox2->Text += Convert::ToString(Fog_Index) + " - Fog Index\r\n";

	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		REEEEE = 206.835 - 84.6 * ASW - 1.015 * ASL;
		Gl = 11.8 * ASW + 0.39 * ASL - 15.59;
		Fog_Index = 0.4 * (ASL + 100 * (Big_Word / Words));
		if (REEEEE <= 100) textBox3->Text = "очень высокий";
		if (REEEEE < 90) textBox3->Text = "высокий";
		if (REEEEE < 80) textBox3->Text = "выше среднего";
		if (REEEEE < 70) textBox3->Text = "средний";
		if (REEEEE < 60) textBox3->Text = "ниже среднего";
		if (REEEEE < 50) textBox3->Text = "низкий";
		if (REEEEE < 30) textBox3->Text = "очень низкий";
		textBox2->Text = Convert::ToString(ASW) + " - среднее число слогов в слове\r\n";
		textBox2->Text += Convert::ToString(ASL) + " - средн€€ длина предложени€\r\n";
		textBox2->Text += Convert::ToString(REEEEE) + " - показатель удобочитаемости\r\n";
		textBox2->Text += Convert::ToString(Gl) + " - по ‘лешу- инсайду\r\n";
		int gl = round(Gl);
		textBox4->Text = Convert::ToString(gl);
		textBox2->Text += Convert::ToString(Fog_Index) + " - Fog Index\r\n";
	}

};
}
