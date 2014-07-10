#pragma once

namespace clrTest {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for CommandInfoForm
	/// </summary>
	public ref class CommandInfoForm : public System::Windows::Forms::Form
	{
	public:
		CommandInfoForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~CommandInfoForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label13;
	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(28, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(77, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Command";
			// 
			// label2
			// 
			this->label2->Location = System::Drawing::Point(31, 43);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(74, 62);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Forward #\r\nTurnLeft\r\nPenUp\r\nPenDown";
			// 
			// label3
			// 
			this->label3->Location = System::Drawing::Point(130, 43);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(74, 62);
			this->label3->TabIndex = 3;
			this->label3->Text = L"FW #\r\nTL\r\nPU\r\nPD";
			this->label3->Click += gcnew System::EventHandler(this, &CommandInfoForm::label3_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(127, 20);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(85, 16);
			this->label4->TabIndex = 2;
			this->label4->Text = L"Short Hand";
			this->label4->Click += gcnew System::EventHandler(this, &CommandInfoForm::label4_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(19, 108);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(164, 13);
			this->label5->TabIndex = 4;
			this->label5->Text = L"# The number of spaces to move";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(222, 132);
			this->groupBox1->TabIndex = 5;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Commands";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->label6);
			this->groupBox2->Controls->Add(this->label7);
			this->groupBox2->Controls->Add(this->label8);
			this->groupBox2->Controls->Add(this->label9);
			this->groupBox2->Location = System::Drawing::Point(13, 151);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(321, 133);
			this->groupBox2->TabIndex = 6;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Control Statements";
			// 
			// label6
			// 
			this->label6->Location = System::Drawing::Point(33, 40);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(113, 62);
			this->label6->TabIndex = 5;
			this->label6->Text = L"IF <condition>\r\n\r\n\r\nWHILE <condition>";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(30, 17);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(77, 16);
			this->label7->TabIndex = 4;
			this->label7->Text = L"Statement";
			// 
			// label8
			// 
			this->label8->Location = System::Drawing::Point(185, 40);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(92, 89);
			this->label8->TabIndex = 7;
			this->label8->Text = L"Run once if the condition is true\r\n\r\nRuns until the condition is no longer true";
			this->label8->Click += gcnew System::EventHandler(this, &CommandInfoForm::label8_Click);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(182, 17);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(33, 16);
			this->label9->TabIndex = 6;
			this->label9->Text = L"Info";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->label10);
			this->groupBox3->Controls->Add(this->label11);
			this->groupBox3->Controls->Add(this->label12);
			this->groupBox3->Controls->Add(this->label13);
			this->groupBox3->Location = System::Drawing::Point(12, 290);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(321, 133);
			this->groupBox3->TabIndex = 7;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Conditions";
			// 
			// label10
			// 
			this->label10->Location = System::Drawing::Point(33, 40);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(86, 62);
			this->label10->TabIndex = 5;
			this->label10->Text = L"FacingUp\r\nFacingLeft\r\nFacingDown\r\nFacingRight";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label11->Location = System::Drawing::Point(30, 17);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(73, 16);
			this->label11->TabIndex = 4;
			this->label11->Text = L"Condition";
			// 
			// label12
			// 
			this->label12->Location = System::Drawing::Point(144, 40);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(92, 62);
			this->label12->TabIndex = 7;
			this->label12->Text = L"The condition will be true if it is the direction is facing.";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label13->Location = System::Drawing::Point(147, 17);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(33, 16);
			this->label13->TabIndex = 6;
			this->label13->Text = L"Info";
			// 
			// CommandInfoForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(368, 441);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Name = L"CommandInfoForm";
			this->Text = L"Command Info Form";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void label4_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void label3_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void label8_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
};
}
