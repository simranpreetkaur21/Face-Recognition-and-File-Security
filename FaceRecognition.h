#include "stdafx.h"
#include "FaceReg.h"
#include "ShowFile.h"
#include <msclr\marshal_cppstd.h>
#pragma once


namespace FaceDetection {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Microsoft::Win32;
	using namespace System::Diagnostics;

	/// <summary>
	/// Summary for FaceRecognition
	/// </summary>
	public ref class FaceRecognition : public System::Windows::Forms::Form
	{
	public: static int	numFiles;
	public:
		FaceRecognition(void)
		{
			InitializeComponent();
			numFiles = 4;
			void OnApplicationExit(Object^ /*sender*/, EventArgs^ /*e*/);
			Application::ApplicationExit += gcnew EventHandler(this, &FaceRecognition::OnApplicationExit);
			//
			//TODO: Add the constructor code here
			//
		}
		void OnApplicationExit(Object^ /*sender*/, EventArgs^ /*e*/)
		{
			try
			{
				this->Close();
			}
			catch (Exception^)
			{
				MessageBox::Show("Exception error\n");
			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FaceRecognition()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::PictureBox^  pictureBox1;

	private: System::Windows::Forms::Button^  button2;

	private: System::Windows::Forms::Button^  button3;

	private: System::Windows::Forms::Button^  button5;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(FaceRecognition::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::HighlightText;
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 14.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(329, 18);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(136, 60);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Start Recognition";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &FaceRecognition::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(198, 100);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(98, 28);
			this->textBox1->TabIndex = 3;
			this->textBox1->Text = L"\?\?\?";
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &FaceRecognition::textBox1_TextChanged);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.InitialImage")));
			this->pictureBox1->Location = System::Drawing::Point(198, 158);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(98, 76);
			this->pictureBox1->TabIndex = 4;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &FaceRecognition::pictureBox1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::HighlightText;
			this->button2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button2->Enabled = false;
			this->button2->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 14.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(17, 252);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(125, 48);
			this->button2->TabIndex = 11;
			this->button2->Text = L"Show Apps";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &FaceRecognition::button2_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::SystemColors::HighlightText;
			this->button3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button3->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 14.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(17, 18);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(125, 60);
			this->button3->TabIndex = 13;
			this->button3->Text = L"Start Training";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &FaceRecognition::button3_Click);
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::SystemColors::HighlightText;
			this->button5->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button5->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 14.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button5->Location = System::Drawing::Point(341, 252);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(124, 48);
			this->button5->TabIndex = 17;
			this->button5->Text = L"Exit";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &FaceRecognition::button5_Click);
			// 
			// FaceRecognition
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->ClientSize = System::Drawing::Size(492, 337);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Name = L"FaceRecognition";
			this->Text = L"Face Recognition";
			this->Load += gcnew System::EventHandler(this, &FaceRecognition::FaceRecognition_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	
				 std::string name;
				 int valid = -1;
				 name = LBPHFaceRecog();
				 msclr::interop::marshal_context context;

				 textBox1->Text = context.marshal_as<String^>(name);
				 if (name == "simran")
				 {
					 pictureBox1->Image = Image::FromFile("E:\simran.jpg");
					 valid = 1;
				 }
				 else
				 if (name == "jasmine")
				 {
					 pictureBox1->Image = Image::FromFile("E:\jasmine_kaur.jpg");
					 valid = 1;
				 }  
				 else
				 if (name == "ruby")
				 {
					 MessageBox::Show("ruby");
					 pictureBox1->Image = Image::FromFile("E:\ruchi.jpg");
					// pictureBox1->Image = Image::FromFile("‪E:\ruby.jpg");
					 valid = 1;
				 }

				 if (valid == 1)
				 {
					 button2->Enabled = true;
				 }
				
	}

	private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {

				 ShowFile ^sf = gcnew ShowFile();
				 String^ keyName = "HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer\\DisallowRun";
				 for (int i = 1; i <= numFiles; i++)
				 {
					 String^ num = Convert::ToString(i);
					 String^ file = (String^)Registry::GetValue(keyName, num, "SuchName does not exist.");
					 if (String::Compare(file, "0") != 0)
					 {
						 sf->listBox1->Items->Add(file);
					 }

				 }

				 sf->ShowDialog();
				 button2->Enabled = false;	//Show App button
	}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
				 LBPHFaceTrainer();
	}
	private: System::Void label5_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->Close();
	}
	private: System::Void FaceRecognition_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void label4_Click(System::Object^  sender, System::EventArgs^  e) {
	}
};
}
