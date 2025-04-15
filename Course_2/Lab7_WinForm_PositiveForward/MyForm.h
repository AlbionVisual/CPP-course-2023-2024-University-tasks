#pragma once
#include<string>

namespace Lab7WinFormPositiveForward {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		int* arr;
	private: System::Windows::Forms::Button^ btn_rem;

		   int arr_size = 0;
	public:
		MyForm(void)
		{
			InitializeComponent();

			arr = new int[100];

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
	private: System::Windows::Forms::Button^ btn_calc;

	private: System::Windows::Forms::Button^ btn_add;
	private: System::Windows::Forms::NumericUpDown^ input_field;
	private: System::Windows::Forms::Label^ label_preview;
	protected:




	protected:

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
			this->btn_calc = (gcnew System::Windows::Forms::Button());
			this->btn_add = (gcnew System::Windows::Forms::Button());
			this->input_field = (gcnew System::Windows::Forms::NumericUpDown());
			this->label_preview = (gcnew System::Windows::Forms::Label());
			this->btn_rem = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_field))->BeginInit();
			this->SuspendLayout();
			// 
			// btn_calc
			// 
			this->btn_calc->Location = System::Drawing::Point(108, 276);
			this->btn_calc->Name = L"btn_calc";
			this->btn_calc->Size = System::Drawing::Size(149, 68);
			this->btn_calc->TabIndex = 0;
			this->btn_calc->Text = L"Calculate";
			this->btn_calc->UseVisualStyleBackColor = true;
			this->btn_calc->Click += gcnew System::EventHandler(this, &MyForm::btn_calc_Click);
			// 
			// btn_add
			// 
			this->btn_add->Location = System::Drawing::Point(259, 72);
			this->btn_add->Name = L"btn_add";
			this->btn_add->Size = System::Drawing::Size(131, 46);
			this->btn_add->TabIndex = 2;
			this->btn_add->Text = L"Add";
			this->btn_add->UseVisualStyleBackColor = true;
			this->btn_add->Click += gcnew System::EventHandler(this, &MyForm::btn_add_Click);
			// 
			// input_field
			// 
			this->input_field->Location = System::Drawing::Point(108, 81);
			this->input_field->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 675645, 0, 0, 0 });
			this->input_field->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 675645, 0, 0, System::Int32::MinValue });
			this->input_field->Name = L"input_field";
			this->input_field->Size = System::Drawing::Size(120, 31);
			this->input_field->TabIndex = 3;
			// 
			// label_preview
			// 
			this->label_preview->AutoSize = true;
			this->label_preview->Location = System::Drawing::Point(46, 157);
			this->label_preview->Name = L"label_preview";
			this->label_preview->Size = System::Drawing::Size(76, 25);
			this->label_preview->TabIndex = 4;
			this->label_preview->Text = L"Arr = []";
			// 
			// btn_rem
			// 
			this->btn_rem->Location = System::Drawing::Point(411, 74);
			this->btn_rem->Name = L"btn_rem";
			this->btn_rem->Size = System::Drawing::Size(146, 42);
			this->btn_rem->TabIndex = 5;
			this->btn_rem->Text = L"Remove last";
			this->btn_rem->UseVisualStyleBackColor = true;
			this->btn_rem->Click += gcnew System::EventHandler(this, &MyForm::btn_rem_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(792, 384);
			this->Controls->Add(this->btn_rem);
			this->Controls->Add(this->label_preview);
			this->Controls->Add(this->input_field);
			this->Controls->Add(this->btn_add);
			this->Controls->Add(this->btn_calc);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->KeyPreview = true;
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"Positive forward";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->input_field))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		
	private: System::Void btn_add_Click(System::Object^ sender, System::EventArgs^ e) {
		if (arr_size > 100) {
			MessageBox::Show(this, "You run out of free space", "Error", MessageBoxButtons::OK);
		}
		else {
			arr[arr_size++] = int(this->input_field->Value);
			this->label_preview->Text = "Arr = " + arr_to_string(arr, arr_size);
		}
	}
	private: System::Void btn_calc_Click(System::Object^ sender, System::EventArgs^ e) {
		int* negative = new int[100]; int n_size = 0;
		int* positive = new int[100]; int p_size = 0;
		for (int i = 0; i < arr_size; i++) {
			if (arr[i] < 0) {
				positive[p_size++] = arr[i];
			}
			else {
				negative[n_size++] = arr[i];
			}
		}
		int* res = new int[n_size + p_size];
		for (int i = 0; i < n_size; i++) res[i] = negative[i];
		for (int i = n_size; i < n_size + p_size; i++) res[i] = positive[i - n_size];
		MessageBox::Show(this, "Result arr is: " + arr_to_string(res, n_size + p_size), "Answer", MessageBoxButtons::OK);
	}
	private: String^ arr_to_string(int* arr, int n) {
		String^ result("[");
		for (int i = 0; i < n - 1; i++) {
			result += arr[i].ToString() + ", ";
		}
		if (n != 0)result += arr[n - 1].ToString();
		result += "]";
		return result;
	}

	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyValue == 13) {
			btn_calc->PerformClick();
		}
		// MessageBox::Show(e->KeyValue.ToString());
	}
	private: System::Void btn_rem_Click(System::Object^ sender, System::EventArgs^ e) {
		if (arr_size >= 1) {
			arr_size -= 1;
			this->label_preview->Text = "Arr = " + arr_to_string(arr, arr_size);
		}
		else {
			MessageBox::Show(this, "Your arr is already empty!", "Error", MessageBoxButtons::OK);
		}
	}
};
}
