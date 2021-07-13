#pragma once
//#include "stdafx.h"
#include <string>

namespace CppCLRWinformsProjekt {
	//using std::string;
	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Xml;

	/// <summary>
	/// Zusammenfassung für Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{

	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ openFileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ Minify;
	private: System::Windows::Forms::ToolStripMenuItem^ detectErrorToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ formatToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ convertToJsonToolStripMenuItem;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::RichTextBox^ Before;
	private: System::Windows::Forms::RichTextBox^ After;
	private: System::Windows::Forms::ToolStripMenuItem^ newFileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ saveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ saveAsCurrentXMLToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ saveAsNewXMLToolStripMenuItem;

		   





	protected:








	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->newFileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Minify = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->detectErrorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->formatToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->convertToJsonToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveAsCurrentXMLToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveAsNewXMLToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Before = (gcnew System::Windows::Forms::RichTextBox());
			this->After = (gcnew System::Windows::Forms::RichTextBox());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->openFileToolStripMenuItem,
					this->newFileToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			this->fileToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::fileToolStripMenuItem_Click);
			// 
			// openFileToolStripMenuItem
			// 
			this->openFileToolStripMenuItem->Name = L"openFileToolStripMenuItem";
			this->openFileToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift)
				| System::Windows::Forms::Keys::O));
			this->openFileToolStripMenuItem->Size = System::Drawing::Size(199, 22);
			this->openFileToolStripMenuItem->Text = L"Open File";
			this->openFileToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::openFileToolStripMenuItem_Click);
			// 
			// newFileToolStripMenuItem
			// 
			this->newFileToolStripMenuItem->Name = L"newFileToolStripMenuItem";
			this->newFileToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift)
				| System::Windows::Forms::Keys::N));
			this->newFileToolStripMenuItem->Size = System::Drawing::Size(199, 22);
			this->newFileToolStripMenuItem->Text = L"New File";
			this->newFileToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::newFileToolStripMenuItem_Click);
			// 
			// Minify
			// 
			this->Minify->Name = L"Minify";
			this->Minify->Size = System::Drawing::Size(53, 20);
			this->Minify->Text = L"Minify";
			this->Minify->Click += gcnew System::EventHandler(this, &Form1::toolStripMenuItem1_Click);
			// 
			// detectErrorToolStripMenuItem
			// 
			this->detectErrorToolStripMenuItem->Name = L"detectErrorToolStripMenuItem";
			this->detectErrorToolStripMenuItem->Size = System::Drawing::Size(81, 20);
			this->detectErrorToolStripMenuItem->Text = L"Detect Error";
			// 
			// formatToolStripMenuItem
			// 
			this->formatToolStripMenuItem->Name = L"formatToolStripMenuItem";
			this->formatToolStripMenuItem->Size = System::Drawing::Size(57, 20);
			this->formatToolStripMenuItem->Text = L"Format";
			// 
			// convertToJsonToolStripMenuItem
			// 
			this->convertToJsonToolStripMenuItem->Name = L"convertToJsonToolStripMenuItem";
			this->convertToJsonToolStripMenuItem->Size = System::Drawing::Size(101, 20);
			this->convertToJsonToolStripMenuItem->Text = L"Convert to Json";
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->fileToolStripMenuItem,
					this->Minify, this->detectErrorToolStripMenuItem, this->formatToolStripMenuItem, this->convertToJsonToolStripMenuItem, this->saveToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(988, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->saveAsCurrentXMLToolStripMenuItem,
					this->saveAsNewXMLToolStripMenuItem
			});
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->Size = System::Drawing::Size(43, 20);
			this->saveToolStripMenuItem->Text = L"Save";
			// 
			// saveAsCurrentXMLToolStripMenuItem
			// 
			this->saveAsCurrentXMLToolStripMenuItem->Name = L"saveAsCurrentXMLToolStripMenuItem";
			this->saveAsCurrentXMLToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::S));
			this->saveAsCurrentXMLToolStripMenuItem->Size = System::Drawing::Size(238, 22);
			this->saveAsCurrentXMLToolStripMenuItem->Text = L"Save as Current XML";
			this->saveAsCurrentXMLToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::saveAsCurrentXMLToolStripMenuItem_Click);
			// 
			// saveAsNewXMLToolStripMenuItem
			// 
			this->saveAsNewXMLToolStripMenuItem->Name = L"saveAsNewXMLToolStripMenuItem";
			this->saveAsNewXMLToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift)
				| System::Windows::Forms::Keys::S));
			this->saveAsNewXMLToolStripMenuItem->Size = System::Drawing::Size(238, 22);
			this->saveAsNewXMLToolStripMenuItem->Text = L"Save as New XML";
			this->saveAsNewXMLToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::saveAsNewXMLToolStripMenuItem_Click);
			// 
			// Before
			// 
			this->Before->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(61)), static_cast<System::Int32>(static_cast<System::Byte>(65)),
				static_cast<System::Int32>(static_cast<System::Byte>(67)));
			this->Before->ForeColor = System::Drawing::SystemColors::Window;
			this->Before->Location = System::Drawing::Point(12, 38);
			this->Before->Name = L"Before";
			this->Before->Size = System::Drawing::Size(463, 413);
			this->Before->TabIndex = 1;
			this->Before->Text = L"";
			this->Before->TextChanged += gcnew System::EventHandler(this, &Form1::Before_TextChanged);
			// 
			// After
			// 
			this->After->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(61)), static_cast<System::Int32>(static_cast<System::Byte>(65)),
				static_cast<System::Int32>(static_cast<System::Byte>(67)));
			this->After->ForeColor = System::Drawing::SystemColors::Menu;
			this->After->Location = System::Drawing::Point(481, 38);
			this->After->Name = L"After";
			this->After->ReadOnly = true;
			this->After->Size = System::Drawing::Size(482, 413);
			this->After->TabIndex = 2;
			this->After->Text = L"";
			this->After->TextChanged += gcnew System::EventHandler(this, &Form1::After_TextChanged);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(32)), static_cast<System::Int32>(static_cast<System::Byte>(34)),
				static_cast<System::Int32>(static_cast<System::Byte>(37)));
			this->ClientSize = System::Drawing::Size(988, 525);
			this->Controls->Add(this->After);
			this->Controls->Add(this->Before);
			this->Controls->Add(this->menuStrip1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		
		
		string Minify_function(string x)
		{
			int y = 0;
			int z = 0;
			for (int i = 0;i < x.length();i++)
			{
				if (x.find("<!--") != -1)
				{
					y = x.find("!") - 1;
					z = y;
					while (x[z] != '>')
					{
						z++;
					}
					x = x.erase(y, (z - y + 1));
				}

			}
			x.erase(std::remove(x.begin(), x.end(), '\n'), x.end());
			bool flag = false;
			int k = 0;
			for (int i = 0; i < x.length(); i++)
			{
				if ((x[i] == '>' && x[i + 1] == ' ') ||(x[i] == '>' && x[i + 1] =='\n'))
				{
					k = i;
					while (x[k] != '<')
					{
				
						k++;
					}
				/*	for (i;i + 1 < k;i++)
					{
						if (x[i] == ' ')
							flag = true;
						else 
						{
							flag = false;
							break;
						}
					}
					
					if(flag)*/
					x = x.erase(i + 1, (k - i - 1));
				}
				
			}

			return x;
		}


		String^ fileName;
		String^ readFile;

		void Convert_system_to_std(String^ s, string& os) {
			using namespace Runtime::InteropServices;
			const char* chars =
				(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
			os = chars;
			Marshal::FreeHGlobal(IntPtr((void*)chars));
		}
		

		


#pragma endregion
	private: System::Void toolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		string zaza;
		Convert_system_to_std(Before->Text, zaza);
		string zezo =Minify_function(zaza);
	    After->Text = gcnew String(zezo.c_str());

	//	After->Text = zaza;
		
	}
	private: System::Void openFileToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
	{

		File^ f;
		OpenFileDialog^ ofd = gcnew OpenFileDialog;
		ofd->InitialDirectory = "c:\\";
		ofd->Filter = "xml files |*.xml";
		ofd->RestoreDirectory = true;
		if (ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			fileName = ofd->FileName;
			readFile = f->ReadAllText(fileName);
			//richTextBox1->Text = readFile;
			Before->Text = readFile;
		}

	}
private: System::Void fileToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
   {
	 

   }
private: System::Void Before_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void After_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	
}
	   
private: System::Void newFileToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
{
	File^ f;
	Path^ p;
	SaveFileDialog^ sfd = gcnew SaveFileDialog;
	sfd->InitialDirectory = "c:\\";
	sfd->FileName = "untitled.xml";
	if (sfd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		if (p->GetExtension(sfd->FileName) != ".xml")
		{
			sfd->FileName += ".xml";
		}
		StreamWriter^ sw = gcnew StreamWriter(sfd->FileName);
		sw->WriteLine(Before->Text);
		sw->Close();
	}
}
private: System::Void saveAsCurrentXMLToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
{
	StreamWriter^ sw = gcnew StreamWriter(fileName);
	sw->WriteLine(After->Text);
	sw->Close();
}
private: System::Void saveAsNewXMLToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
{
	File^ f;
	Path^ p;
	SaveFileDialog^ sfd = gcnew SaveFileDialog;
	sfd->InitialDirectory = "c:\\";
	sfd->FileName = "untitled.xml";
	if (sfd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		if (p->GetExtension(sfd->FileName) != ".xml")
		{
			sfd->FileName += ".xml";
		}
		StreamWriter^ sw = gcnew StreamWriter(sfd->FileName);
		sw->WriteLine(After->Text);
		sw->Close();
	}
}
};
}


