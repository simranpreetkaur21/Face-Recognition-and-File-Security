#include<string.h>
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
	/// Summary for ShowFile
	/// </summary>
#pragma once

	public ref class ShowFile : public System::Windows::Forms::Form
	{

	private: static String^ openApp;
	public:
		ShowFile(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &ShowFile::Form1_FormClosing);
			openApp = "";

		}

		System::Void Form1_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e)
		{
			closeAllApp();
		}
	private:
		/*To close all open applications*/
		void closeAllApp()
		{
			String^ keyName = "HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer\\DisallowRun";
			array<Char>^sep1 = gcnew array<Char>{';'};							//first separator
			array<String^>^file;

			file = openApp->Split(sep1, StringSplitOptions::RemoveEmptyEntries);

			for (int i = 0; i < (file->Length) ; i++)
			{
				array<Char>^sep2 = gcnew array<Char>{','};						//second separator
				array<String^>^fileSep;

				fileSep = file[i]->Split(sep2, StringSplitOptions::None);
				array<Char>^ extension = { '.exe' };
				String^ onlyFileName = fileSep[0]->Replace(".exe", "");
				array<Process^>^processName = Process::GetProcessesByName(onlyFileName);

				for (int j = 0; j < processName->Length; j++)
				{
					processName[j]->CloseMainWindow();
					
				}
				Registry::SetValue(keyName, fileSep[1], fileSep[0]);

			}

		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ShowFile()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	public: System::Windows::Forms::ListBox^  listBox1;
	private: System::Windows::Forms::Label^  label1;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(ShowFile::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::Info;
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 15.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(100, 258);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(109, 67);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Open App";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &ShowFile::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::Info;
			this->button2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button2->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 15.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(313, 258);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(100, 67);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Exit";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &ShowFile::button2_Click);
			// 
			// listBox1
			// 
			this->listBox1->BackColor = System::Drawing::SystemColors::HighlightText;
			this->listBox1->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 17;
			this->listBox1->Location = System::Drawing::Point(168, 107);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(154, 106);
			this->listBox1->TabIndex = 2;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &ShowFile::listBox1_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::White;
			this->label1->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 24, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(134, 37);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(251, 39);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Applications Name";
			this->label1->Click += gcnew System::EventHandler(this, &ShowFile::label1_Click);
			// 
			// ShowFile
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(492, 337);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"ShowFile";
			this->Text = L"Applications ";
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion


	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				
				 String^ keyName = "HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Explorer\\DisallowRun";
				 if (listBox1->SelectedIndex == -1)
				 {
					 MessageBox::Show("Select the file name");
				 }
				 else
				 {
					 String^ curItem = Convert::ToString((listBox1->SelectedIndex) + 1);//value name
					 String^ curItemValue = listBox1->SelectedItem->ToString();			//name of the application to be opened

					 /*To keep the track of opened applications*/
					 if (String::Compare((String^)(Registry::GetValue(keyName, curItem, "File doesnot exist")), "0") != 0) 
					 {
						 openApp += curItemValue + "," + curItem + ";";
						 Registry::SetValue(keyName, curItem, "0");
					 }
					 Process::Start(curItemValue);

				 }

	}
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void listBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->Close();

	}
	};
}
