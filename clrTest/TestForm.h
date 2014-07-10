#pragma once
#include "SplitCommand.h"
#include "CommandIterator.h"
#include "IfCommand.h"
#include "CommandInfoForm.h"
#include "CommandProcesser.h"
using namespace std;
#include <iostream>
#include <conio.h>

namespace clrTest {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Summary for TestForm
	/// </summary>
	public ref class TestForm : public System::Windows::Forms::Form
	{
	public:
		TestForm(void)
		{
			InitializeComponent();
			cProcesser = gcnew CommandProcesser(background, pieceControl);
			pi = new Piece;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~TestForm()
		{
			delete pi;
			delete cProcesser;

			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  background;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::TextBox^  commandTxt;
	private: System::Windows::Forms::Button^  runButton;
		
	private: System::Windows::Forms::Label^  pieceControl;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Button^  startButton;

	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  openToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  commandInfoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;
	private: System::Windows::Forms::OpenFileDialog^  openCommandsFileDia;
	private: System::Windows::Forms::SaveFileDialog^  saveCommandsFileDia;
	private: System::Windows::Forms::Button^  pauseButton;
	private: System::Windows::Forms::ToolStripMenuItem^  closeToolStripMenuItem;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	private: System::Windows::Forms::ToolStripStatusLabel^  commandStatus;
	private: System::Windows::Forms::SplitContainer^  splitContainer1;

		
		
	private: System::ComponentModel::IContainer^  components;
	protected: 
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->background = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->commandTxt = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->startButton = (gcnew System::Windows::Forms::Button());
			this->runButton = (gcnew System::Windows::Forms::Button());
			this->pauseButton = (gcnew System::Windows::Forms::Button());
			this->pieceControl = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->closeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->commandInfoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openCommandsFileDia = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveCommandsFileDia = (gcnew System::Windows::Forms::SaveFileDialog());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->commandStatus = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->statusStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// background
			// 
			this->background->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->background->Dock = System::Windows::Forms::DockStyle::Fill;
			this->background->Location = System::Drawing::Point(0, 24);
			this->background->Name = L"background";
			this->background->Size = System::Drawing::Size(665, 276);
			this->background->TabIndex = 1;
			this->background->Click += gcnew System::EventHandler(this, &TestForm::background_Click);
			this->background->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &TestForm::background_Paint);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->splitContainer1);
			this->groupBox1->Dock = System::Windows::Forms::DockStyle::Right;
			this->groupBox1->Location = System::Drawing::Point(465, 24);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(200, 276);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Commands";
			// 
			// splitContainer1
			// 
			this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer1->FixedPanel = System::Windows::Forms::FixedPanel::Panel2;
			this->splitContainer1->Location = System::Drawing::Point(3, 16);
			this->splitContainer1->Name = L"splitContainer1";
			this->splitContainer1->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->Controls->Add(this->commandTxt);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->groupBox2);
			this->splitContainer1->Panel2->ForeColor = System::Drawing::SystemColors::ControlText;
			this->splitContainer1->Size = System::Drawing::Size(194, 257);
			this->splitContainer1->SplitterDistance = 133;
			this->splitContainer1->TabIndex = 0;
			// 
			// commandTxt
			// 
			this->commandTxt->AcceptsTab = true;
			this->commandTxt->AutoCompleteCustomSource->AddRange(gcnew cli::array< System::String^  >(4) {L"FW", L"LT", L"PU", L"PD"});
			this->commandTxt->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::Suggest;
			this->commandTxt->Dock = System::Windows::Forms::DockStyle::Fill;
			this->commandTxt->Location = System::Drawing::Point(0, 0);
			this->commandTxt->Margin = System::Windows::Forms::Padding(3, 3, 3, 115);
			this->commandTxt->Multiline = true;
			this->commandTxt->Name = L"commandTxt";
			this->commandTxt->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->commandTxt->Size = System::Drawing::Size(194, 133);
			this->commandTxt->TabIndex = 1;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->startButton);
			this->groupBox2->Controls->Add(this->runButton);
			this->groupBox2->Controls->Add(this->pauseButton);
			this->groupBox2->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->groupBox2->Location = System::Drawing::Point(0, 5);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(194, 115);
			this->groupBox2->TabIndex = 5;
			this->groupBox2->TabStop = false;
			// 
			// startButton
			// 
			this->startButton->Location = System::Drawing::Point(6, 49);
			this->startButton->Name = L"startButton";
			this->startButton->Size = System::Drawing::Size(170, 23);
			this->startButton->TabIndex = 2;
			this->startButton->Text = L"Start";
			this->startButton->UseVisualStyleBackColor = true;
			this->startButton->Click += gcnew System::EventHandler(this, &TestForm::startButton_Click);
			// 
			// runButton
			// 
			this->runButton->Location = System::Drawing::Point(6, 19);
			this->runButton->Name = L"runButton";
			this->runButton->Size = System::Drawing::Size(170, 23);
			this->runButton->TabIndex = 0;
			this->runButton->Text = L"Run";
			this->runButton->UseVisualStyleBackColor = true;
			this->runButton->Click += gcnew System::EventHandler(this, &TestForm::runButton_Click);
			// 
			// pauseButton
			// 
			this->pauseButton->Enabled = false;
			this->pauseButton->Location = System::Drawing::Point(6, 78);
			this->pauseButton->Name = L"pauseButton";
			this->pauseButton->Size = System::Drawing::Size(170, 23);
			this->pauseButton->TabIndex = 4;
			this->pauseButton->Text = L"Pause";
			this->pauseButton->UseVisualStyleBackColor = true;
			this->pauseButton->Click += gcnew System::EventHandler(this, &TestForm::pauseButton_Click);
			// 
			// pieceControl
			// 
			this->pieceControl->AutoSize = true;
			this->pieceControl->Location = System::Drawing::Point(22, 29);
			this->pieceControl->Name = L"pieceControl";
			this->pieceControl->Size = System::Drawing::Size(13, 13);
			this->pieceControl->TabIndex = 3;
			this->pieceControl->Text = L"\?";
			// 
			// timer1
			// 
			this->timer1->Interval = 500;
			this->timer1->Tick += gcnew System::EventHandler(this, &TestForm::timer1_Tick);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->fileToolStripMenuItem, 
				this->helpToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(665, 24);
			this->menuStrip1->TabIndex = 4;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->openToolStripMenuItem, 
				this->saveToolStripMenuItem, this->closeToolStripMenuItem});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(112, 22);
			this->openToolStripMenuItem->Text = L"Open";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &TestForm::openToolStripMenuItem_Click);
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->Size = System::Drawing::Size(112, 22);
			this->saveToolStripMenuItem->Text = L"Save as";
			this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &TestForm::saveToolStripMenuItem_Click);
			// 
			// closeToolStripMenuItem
			// 
			this->closeToolStripMenuItem->Name = L"closeToolStripMenuItem";
			this->closeToolStripMenuItem->Size = System::Drawing::Size(112, 22);
			this->closeToolStripMenuItem->Text = L"Close";
			this->closeToolStripMenuItem->Click += gcnew System::EventHandler(this, &TestForm::closeToolStripMenuItem_Click);
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->commandInfoToolStripMenuItem, 
				this->aboutToolStripMenuItem});
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->helpToolStripMenuItem->Text = L"Help";
			// 
			// commandInfoToolStripMenuItem
			// 
			this->commandInfoToolStripMenuItem->Name = L"commandInfoToolStripMenuItem";
			this->commandInfoToolStripMenuItem->Size = System::Drawing::Size(155, 22);
			this->commandInfoToolStripMenuItem->Text = L"Command Info";
			this->commandInfoToolStripMenuItem->Click += gcnew System::EventHandler(this, &TestForm::commandInfoToolStripMenuItem_Click);
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(155, 22);
			this->aboutToolStripMenuItem->Text = L"About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &TestForm::aboutToolStripMenuItem_Click);
			// 
			// openCommandsFileDia
			// 
			this->openCommandsFileDia->Filter = L"Logo files|*.logo|test files|*.txt";
			// 
			// saveCommandsFileDia
			// 
			this->saveCommandsFileDia->Filter = L"Logo files|*.logo|test files|*.txt";
			// 
			// statusStrip1
			// 
			this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->commandStatus});
			this->statusStrip1->Location = System::Drawing::Point(0, 278);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(465, 22);
			this->statusStrip1->TabIndex = 5;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// commandStatus
			// 
			this->commandStatus->Name = L"commandStatus";
			this->commandStatus->Size = System::Drawing::Size(36, 17);
			this->commandStatus->Text = L"ready";
			// 
			// TestForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(665, 300);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->pieceControl);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->background);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->MinimumSize = System::Drawing::Size(400, 240);
			this->Name = L"TestForm";
			this->Text = L"Scott\'s Logo programming envirement";
			this->ResizeEnd += gcnew System::EventHandler(this, &TestForm::background_Click);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &TestForm::background_Paint);
			this->groupBox1->ResumeLayout(false);
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel1->PerformLayout();
			this->splitContainer1->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->statusStrip1->ResumeLayout(false);
			this->statusStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: 
		//_______________________________________________
		System::Void runButton_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			cProcesser->buildCommands(commandTxt);
			string errorString = "";
			while ( cProcesser->runCommand(errorString) );
			commandStatus->Text = gcnew String(errorString.c_str());
		}
		//_______________________________________________
		System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) 
		{
			string errorString = "";
			if (! cProcesser->runCommand(errorString))
			{
				timer1->Stop(); 
				commandStatus->Text += " | Done ";
				pauseButton->Text = "Pause";
				pauseButton->Enabled = false;
				startButton->Text = "Start";
			}
			if (errorString != "")
			{
				commandStatus->Text += gcnew String(errorString.c_str());
			}
		}
		//_______________________________________________
		System::Void startButton_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			if(commandTxt->Lines->Length == 0) return;

			startButton->Text = "Restart";
			pauseButton->Text = "Pause";
			commandStatus->Text = "Starting: ";

			cProcesser->buildCommands(commandTxt);
			timer1->Start();
			pauseButton->Enabled = true;
		}
		//_______________________________________________
		System::Void background_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			cProcesser->reprintLines();
		}
		//_______________________________________________
		System::Void background_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) 
		{
			cProcesser->reprintLines();
		}
		//_______________________________________________
		System::Void aboutToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			MessageBox::Show("Logo Programming Environment\nBy Scott Henwood\n2013", "About");
		}
		//_______________________________________________
			 CommandInfoForm^ cForm;
		System::Void commandInfoToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			if (!cForm)
			{
				cForm = gcnew CommandInfoForm();
			}
			cForm->Activate();
			cForm->Show();
		}
		//_______________________________________________
		System::Void saveToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			if (saveCommandsFileDia->ShowDialog() == ::DialogResult::OK )
			{
				Stream^ s = saveCommandsFileDia->OpenFile();
				StreamWriter sw(s);
				sw.Write(commandTxt->Text);
				sw.Close();
				s->Close();
			}
		}
		//_______________________________________________
		System::Void openToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			if (openCommandsFileDia->ShowDialog() == ::DialogResult::OK )
			{
				Stream^ s = openCommandsFileDia->OpenFile();
				StreamReader sr(s);
				commandTxt->Text = sr.ReadToEnd();
				sr.Close();
				s->Close();
			}
		}
		//_______________________________________________
		System::Void pauseButton_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			if (timer1->Enabled)
			{
				timer1->Stop();
				pauseButton->Text = "Resume";
			}
			else
			{
				timer1->Start();
				pauseButton->Text = "Pause";
			}
		}
		//_______________________________________________
		System::Void closeToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			this->Close();
		}
		//_______________________________________________
		System::Void resetToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			cProcesser->reset();
		}

	private:
		Piece *pi;
		CommandProcesser ^cProcesser;
};
}