#include <iostream>
#include <stack>
#include <iostream>
#include <string>
#include <queue>
#include <string.h>
#include <sstream>
#pragma once

namespace Project7 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Xml;
	using namespace std;
	using namespace FastColoredTextBoxNS;
	
	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;

	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  newFileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  openFileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  editToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveAsCurrentXMLToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveAsNewXMLToolStripMenuItem;

	private: System::Windows::Forms::TextBox^  LineNumberTextBox;
	private: FastColoredTextBoxNS::FastColoredTextBox^  fastColoredTextBox1;
	private: System::Windows::Forms::MenuStrip^  menuStrip2;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem7;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem8;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem3;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem5;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem6;
	private: FastColoredTextBoxNS::FastColoredTextBox^  fastColoredTextBox2;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::ToolStripMenuItem^  validateToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  formatToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  minifyToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  convertToJSONToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  compressToolStripMenuItem;
	private: System::Windows::Forms::Button^  solve_btn;
	private: FastColoredTextBoxNS::FastColoredTextBox^  After;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->menuStrip2 = (gcnew System::Windows::Forms::MenuStrip());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem7 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem8 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->validateToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->formatToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->minifyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->convertToJSONToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->compressToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem3 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem5 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem6 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->fastColoredTextBox2 = (gcnew FastColoredTextBoxNS::FastColoredTextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->solve_btn = (gcnew System::Windows::Forms::Button());
			this->After = (gcnew FastColoredTextBoxNS::FastColoredTextBox());
			this->menuStrip2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->fastColoredTextBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->After))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip2
			// 
			this->menuStrip2->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->toolStripMenuItem1, 
				this->toolStripMenuItem2, this->toolStripMenuItem3});
			this->menuStrip2->Location = System::Drawing::Point(0, 0);
			this->menuStrip2->Name = L"menuStrip2";
			this->menuStrip2->Size = System::Drawing::Size(887, 24);
			this->menuStrip2->TabIndex = 0;
			this->menuStrip2->Text = L"menuStrip2";
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->toolStripMenuItem7, 
				this->toolStripMenuItem8});
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(37, 20);
			this->toolStripMenuItem1->Text = L"File";
			// 
			// toolStripMenuItem7
			// 
			this->toolStripMenuItem7->Name = L"toolStripMenuItem7";
			this->toolStripMenuItem7->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift) 
				| System::Windows::Forms::Keys::N));
			this->toolStripMenuItem7->Size = System::Drawing::Size(199, 22);
			this->toolStripMenuItem7->Text = L"New File";
			this->toolStripMenuItem7->Click += gcnew System::EventHandler(this, &MyForm::toolStripMenuItem7_Click);
			// 
			// toolStripMenuItem8
			// 
			this->toolStripMenuItem8->Name = L"toolStripMenuItem8";
			this->toolStripMenuItem8->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift) 
				| System::Windows::Forms::Keys::O));
			this->toolStripMenuItem8->Size = System::Drawing::Size(199, 22);
			this->toolStripMenuItem8->Text = L"Open File";
			this->toolStripMenuItem8->Click += gcnew System::EventHandler(this, &MyForm::toolStripMenuItem8_Click);
			// 
			// toolStripMenuItem2
			// 
			this->toolStripMenuItem2->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {this->validateToolStripMenuItem, 
				this->formatToolStripMenuItem, this->minifyToolStripMenuItem, this->convertToJSONToolStripMenuItem, this->compressToolStripMenuItem});
			this->toolStripMenuItem2->Name = L"toolStripMenuItem2";
			this->toolStripMenuItem2->Size = System::Drawing::Size(39, 20);
			this->toolStripMenuItem2->Text = L"Edit";
			// 
			// validateToolStripMenuItem
			// 
			this->validateToolStripMenuItem->Name = L"validateToolStripMenuItem";
			this->validateToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift) 
				| System::Windows::Forms::Keys::V));
			this->validateToolStripMenuItem->Size = System::Drawing::Size(231, 22);
			this->validateToolStripMenuItem->Text = L"Validate";
			// 
			// formatToolStripMenuItem
			// 
			this->formatToolStripMenuItem->Name = L"formatToolStripMenuItem";
			this->formatToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift) 
				| System::Windows::Forms::Keys::F));
			this->formatToolStripMenuItem->Size = System::Drawing::Size(231, 22);
			this->formatToolStripMenuItem->Text = L"Format";
			// 
			// minifyToolStripMenuItem
			// 
			this->minifyToolStripMenuItem->Name = L"minifyToolStripMenuItem";
			this->minifyToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift) 
				| System::Windows::Forms::Keys::M));
			this->minifyToolStripMenuItem->Size = System::Drawing::Size(231, 22);
			this->minifyToolStripMenuItem->Text = L"Minify";
			// 
			// convertToJSONToolStripMenuItem
			// 
			this->convertToJSONToolStripMenuItem->Name = L"convertToJSONToolStripMenuItem";
			this->convertToJSONToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift) 
				| System::Windows::Forms::Keys::J));
			this->convertToJSONToolStripMenuItem->Size = System::Drawing::Size(231, 22);
			this->convertToJSONToolStripMenuItem->Text = L"Convert to JSON";
			// 
			// compressToolStripMenuItem
			// 
			this->compressToolStripMenuItem->Name = L"compressToolStripMenuItem";
			this->compressToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift) 
				| System::Windows::Forms::Keys::C));
			this->compressToolStripMenuItem->Size = System::Drawing::Size(231, 22);
			this->compressToolStripMenuItem->Text = L"Compress";
			// 
			// toolStripMenuItem3
			// 
			this->toolStripMenuItem3->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->toolStripMenuItem5, 
				this->toolStripMenuItem6});
			this->toolStripMenuItem3->Name = L"toolStripMenuItem3";
			this->toolStripMenuItem3->Size = System::Drawing::Size(43, 20);
			this->toolStripMenuItem3->Text = L"Save";
			// 
			// toolStripMenuItem5
			// 
			this->toolStripMenuItem5->Name = L"toolStripMenuItem5";
			this->toolStripMenuItem5->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::S));
			this->toolStripMenuItem5->Size = System::Drawing::Size(240, 22);
			this->toolStripMenuItem5->Text = L"Save as Current XML";
			this->toolStripMenuItem5->Click += gcnew System::EventHandler(this, &MyForm::toolStripMenuItem5_Click);
			// 
			// toolStripMenuItem6
			// 
			this->toolStripMenuItem6->Name = L"toolStripMenuItem6";
			this->toolStripMenuItem6->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift) 
				| System::Windows::Forms::Keys::A));
			this->toolStripMenuItem6->Size = System::Drawing::Size(240, 22);
			this->toolStripMenuItem6->Text = L"Save as New XML";
			this->toolStripMenuItem6->Click += gcnew System::EventHandler(this, &MyForm::toolStripMenuItem6_Click);
			// 
			// fastColoredTextBox2
			// 
			this->fastColoredTextBox2->AutoCompleteBracketsList = gcnew cli::array< System::Char >(10) {'(', ')', '{', '}', '[', ']', '\"', 
				'\"', '\'', '\''};
			this->fastColoredTextBox2->AutoIndentCharsPatterns = L"^\\s*[\\w\\.]+(\\s\\w+)\?\\s*(\?<range>=)\\s*(\?<range>[^;=]+);\r\n^\\s*(case|default)\\s*[^:]*" 
				L"(\?<range>:)\\s*(\?<range>[^;]+);";
			this->fastColoredTextBox2->AutoScrollMinSize = System::Drawing::Size(27, 14);
			this->fastColoredTextBox2->BackBrush = nullptr;
			this->fastColoredTextBox2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->fastColoredTextBox2->CharHeight = 14;
			this->fastColoredTextBox2->CharWidth = 8;
			this->fastColoredTextBox2->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->fastColoredTextBox2->DisabledColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)), 
				static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(180)));
			this->fastColoredTextBox2->IsReplaceMode = false;
			this->fastColoredTextBox2->Location = System::Drawing::Point(21, 41);
			this->fastColoredTextBox2->Name = L"fastColoredTextBox2";
			this->fastColoredTextBox2->Paddings = System::Windows::Forms::Padding(0);
			this->fastColoredTextBox2->SelectionColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->fastColoredTextBox2->ServiceColors = (cli::safe_cast<FastColoredTextBoxNS::ServiceColors^  >(resources->GetObject(L"fastColoredTextBox2.ServiceColors")));
			this->fastColoredTextBox2->ShowFoldingLines = true;
			this->fastColoredTextBox2->Size = System::Drawing::Size(360, 408);
			this->fastColoredTextBox2->TabIndex = 1;
			this->fastColoredTextBox2->Zoom = 100;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(800, 99);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Check";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// solve_btn
			// 
			this->solve_btn->Location = System::Drawing::Point(800, 148);
			this->solve_btn->Name = L"solve_btn";
			this->solve_btn->Size = System::Drawing::Size(75, 23);
			this->solve_btn->TabIndex = 3;
			this->solve_btn->Text = L"Solve";
			this->solve_btn->UseVisualStyleBackColor = true;
			this->solve_btn->Click += gcnew System::EventHandler(this, &MyForm::solve_btn_Click);
			// 
			// After
			// 
			this->After->AutoCompleteBracketsList = gcnew cli::array< System::Char >(10) {'(', ')', '{', '}', '[', ']', '\"', '\"', '\'', 
				'\''};
			this->After->AutoIndentCharsPatterns = L"^\\s*[\\w\\.]+(\\s\\w+)\?\\s*(\?<range>=)\\s*(\?<range>[^;=]+);\r\n^\\s*(case|default)\\s*[^:]*" 
				L"(\?<range>:)\\s*(\?<range>[^;]+);";
			this->After->AutoScrollMinSize = System::Drawing::Size(27, 14);
			this->After->BackBrush = nullptr;
			this->After->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->After->CharHeight = 14;
			this->After->CharWidth = 8;
			this->After->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->After->DisabledColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(180)), 
				static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(180)));
			this->After->IsReplaceMode = false;
			this->After->Location = System::Drawing::Point(396, 41);
			this->After->Name = L"After";
			this->After->Paddings = System::Windows::Forms::Padding(0);
			this->After->SelectionColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->After->ServiceColors = (cli::safe_cast<FastColoredTextBoxNS::ServiceColors^  >(resources->GetObject(L"After.ServiceColors")));
			this->After->Size = System::Drawing::Size(364, 408);
			this->After->TabIndex = 4;
			this->After->Zoom = 100;
			this->After->Load += gcnew System::EventHandler(this, &MyForm::After_Load);
			// 
			// MyForm
			// 
			this->ClientSize = System::Drawing::Size(887, 461);
			this->Controls->Add(this->After);
			this->Controls->Add(this->solve_btn);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->fastColoredTextBox2);
			this->Controls->Add(this->menuStrip2);
			this->MainMenuStrip = this->menuStrip2;
			this->Name = L"MyForm";
			this->Text = L"XML Editor";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->menuStrip2->ResumeLayout(false);
			this->menuStrip2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->fastColoredTextBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->After))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	String^ fileName ;
	String^ readFile;
	int num_of_lines ;


	
bool check(String^ t)
{
	int closing = 0 , opening = 0 , flag = 0;
	String^ tag ;
	Stack^  s = gcnew Stack;
		for (int i = 0; i < t->Length; i++)
		{
			if (t[i]=='<' && t[i+1]=='/')  //closing tag
			{
				closing = 1 ;
				opening = 0 ;
				continue;
			}
			else if (t[i]=='<' && t[i+1]!='/')  //opening tag
			{
				opening = 1 ;
				closing = 0 ;
				continue;
			}
			else if (t[i] == '/' && opening)  //self closing tag
			{
				flag = 0 ;
				tag = "" ;
				opening = 0 ;
				closing = 0 ;
				continue;
			}
			else if (t[i] == '>')  //end of tag
			{
				flag = 0 ; 
				if (opening)
				{
					s->Push(tag);
					opening = 0 ;
					tag = "" ;
					continue;
				}

				else if (closing && (s->Count > 0) && ((String^)s->Peek()==tag))
				{
					s->Pop();
					closing = 0 ;
					tag = "" ;
					continue;
				}
				else if (closing && ((String^)s->Peek()!=tag))
				{
					fastColoredTextBox2->SelectionStart = i - tag->Length - 2 ;
					fastColoredTextBox2->SelectionLength = tag->Length + 3 ;
					fastColoredTextBox2->SelectionColor = Color::DarkGreen ;
					return false;
				}
				else if (closing && s->Count == 0)
					return false;
			}
		
			if (opening && t[i] == ' ')  //stop before the attributes of opening tag
				flag = 1 ;
			if (opening && flag == 0) 
			{
				tag += t[i] ;
			}
			else if (closing)
			{
				if (t[i] == '/')
					continue;
				tag += t[i] ;
			}
	}
	if (s->Count==0)
		return true;
	else
		return false;
}

bool detect(String^ t)
{
	int closing = 0 , opening = 0 , flag = 0 ;
	String^ tag ;
	Stack^  s = gcnew Stack;
		for (int i = 0; i < t->Length; i++)
		{
			if (t[i]=='<' && t[i+1]=='/')  //closing tag
			{
				closing = 1 ;
				opening = 0 ;
				continue;
			}
			else if (t[i]=='<' && t[i+1]!='/')  //opening tag
			{
				opening = 1 ;
				closing = 0 ;
				continue;
			}
			else if (t[i] == '/' && opening)  //self closing tag
			{
				flag = 0 ;
				tag = "" ;
				opening = 0 ;
				closing = 0 ;
				continue;
			}
			else if (t[i] == '>')  //end of tag
			{
				flag = 0 ; 
				if (opening)
				{
					s->Push(tag);
					opening = 0 ;
					tag = "" ;
					continue;
				}

				else if (closing && (s->Count > 0) && ((String^)s->Peek()==tag))
				{
					s->Pop();
					closing = 0 ;
					tag = "" ;
					continue;
				}
				else if (closing && ((String^)s->Peek()!=tag))  //error
				{
					MessageBox::Show("Missing closing tag for "+"<"+(String^)s->Peek()+">");
					fastColoredTextBox2->SelectionStart = i - tag->Length - 2 ;
					fastColoredTextBox2->SelectionLength = tag->Length + 3 ;
					fastColoredTextBox2->SelectionColor = Color::Red ;
					s->Pop();
					closing = 0 ;
					tag = "" ;
					continue;
				}
				else if (closing && s->Count == 0)
					return false;
			}
		
			if (opening && t[i] == ' ')  //stop before the attributes of opening tag
				flag = 1 ;
			if (opening && flag == 0) 
			{
				tag += t[i] ;
			}
			else if (closing)
			{
				if (t[i] == '/')
					continue;
				tag += t[i] ;
			}
	}
	if (s->Count==0)
		return true;
	else
		return false;
}

void solve(String^ t)
{
	After->Text = fastColoredTextBox2->Text;
	int closing = 0 , opening = 0 , flag = 0 , opening_start_pos = 0 , opening_end_pos = 0 , closing_start_pos = 0 , closing_end_pos = 0 , errors = 0;
	String^ tag ;
	Stack^  s = gcnew Stack;
		for (int i = 0; i < t->Length; i++)
		{
			if (t[i]=='<' && t[i+1]=='/')  //closing tag
			{
				closing = 1 ;
				opening = 0 ;
				closing_start_pos = i ;
				continue;
			}
			else if (t[i]=='<' && t[i+1]!='/')  //opening tag
			{
				opening = 1 ;
				closing = 0 ;
				opening_start_pos = i ;
				continue;
			}
			else if (t[i] == '/' && opening)  //self closing tag
			{
				flag = 0 ;
				tag = "" ;
				opening = 0 ;
				closing = 0 ;
				continue;
			}
			else if (t[i] == '>')  //end of tag
			{
				flag = 0 ; 
				if (opening)
				{
					opening_end_pos = i ;
					s->Push(tag);
					opening = 0 ;
					tag = "" ;
					continue;
				}

				else if (closing && (s->Count > 0) && ((String^)s->Peek()==tag))
				{
					closing_end_pos = i ;
					s->Pop();
					closing = 0 ;
					tag = "" ;
					continue;
				}
				else if (closing && ((String^)s->Peek()!=tag))
				{
					errors++;
					closing_end_pos = i ;
					//fastColoredTextBox2->SelectionStart = closing_start_pos ;
					//fastColoredTextBox2->SelectionLength = closing_end_pos - closing_start_pos + 1 ;
					//fastColoredTextBox2->InsertText("</"+(String^)s->Peek()+">");
					After->SelectionStart = closing_start_pos ;
					After->SelectionLength = closing_end_pos - closing_start_pos + 1 ;
					After->InsertText("</"+(String^)s->Peek()+">");
					//t = fastColoredTextBox2->Text ;  //update text of textbox
					t = After->Text ;
					i = closing_start_pos + 2 + ((String^)s->Peek())->Length ;
					s->Pop();
					closing = 0 ;
					tag = "" ;
					continue;
				}
				else if (closing && s->Count == 0)
				{

				}
			}
		
			if (opening && t[i] == ' ')  //stop before the attributes of opening tag
				flag = 1 ;
			if (opening && flag == 0) 
			{
				tag += t[i] ;
			}
			else if (closing)
			{
				if (t[i] == '/')
					continue;
				tag += t[i] ;
			}
	}
	while (s->Count)
	{
		//fastColoredTextBox2->AppendText("</"+(String^)s->Peek()+">");
		//fastColoredTextBox2->AppendText("\n");
		After->AppendText("</"+(String^)s->Peek()+">");
		After->AppendText("\n");
		s->Pop();
	}
	MessageBox::Show("Solved "+errors.ToString()+" Errors");

}

	
private: System::Void openFileToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 File^ f ;
				 OpenFileDialog^ ofd = gcnew OpenFileDialog;
				 ofd->InitialDirectory = "c:\\"; 
				 ofd->Filter = "xml files |*.xml";
				 ofd->RestoreDirectory = true;
				  if ( ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK )
				  {
					  fileName = ofd->FileName;
					  readFile = f->ReadAllText(fileName);
					  //richTextBox1->Text = readFile;
					  fastColoredTextBox1->Text = readFile;
				  }

			 }
private: System::Void newFileToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 File^ f ;
			 Path^ p ;
			 SaveFileDialog^ sfd = gcnew SaveFileDialog;
            sfd->InitialDirectory =  "c:\\"; 
            sfd->FileName = "untitled.xml";
            if (sfd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
            {
                if (p->GetExtension(sfd->FileName) != ".xml")
                {
                    sfd->FileName += ".xml";
                }
                StreamWriter^ sw = gcnew StreamWriter(sfd->FileName);
				sw->WriteLine(fastColoredTextBox1->Text);
                sw->Close();
            }
		 }
private: System::Void saveAsCurrentXMLToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
				StreamWriter^ sw = gcnew StreamWriter(fileName);
				sw->WriteLine(fastColoredTextBox1->Text);
                sw->Close();
		 }
private: System::Void saveAsNewXMLToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			File^ f ;
			Path^ p ;
			SaveFileDialog^ sfd = gcnew SaveFileDialog;
            sfd->InitialDirectory =  "c:\\"; 
            sfd->FileName = "untitled.xml";
            if (sfd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
            {
                if (p->GetExtension(sfd->FileName) != ".xml")
                {
                    sfd->FileName += ".xml";
                }
                StreamWriter^ sw = gcnew StreamWriter(sfd->FileName);
				sw->WriteLine(fastColoredTextBox1->Text);
                sw->Close();
            }
		 }

private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
		 }	 
private: System::Void richTextBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 /*if (richTextBox1->Text == "")
			 {    
				AddLineNumbers();    
			 }*/
		 }
private: System::Void richTextBox1_SelectionChanged(Object^ sender, EventArgs^ e)    
        {     
        }
private: System::Void richTextBox1_VScroll(Object^ sender, EventArgs^ e)    
		{        
		}
private: System::Void LineNumberTextBox_MouseDown(Object^ sender, MouseEventArgs^ e)    
		{    
		}   
private: System::Void LineNumberTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
		 }
private: System::Void fastColoredTextBox1_Load(System::Object^  sender, System::EventArgs^  e) 
		 {
		 }
private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) 
		 {
			 fastColoredTextBox2->Language = FastColoredTextBoxNS::Language::XML;
		 }

private: System::Void toolStripMenuItem7_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 File^ f ;
			 Path^ p ;
			 SaveFileDialog^ sfd = gcnew SaveFileDialog;
            sfd->InitialDirectory =  "c:\\"; 
            sfd->FileName = "untitled.xml";
            if (sfd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
            {
                if (p->GetExtension(sfd->FileName) != ".xml")
                {
                    sfd->FileName += ".xml";
                }
                StreamWriter^ sw = gcnew StreamWriter(sfd->FileName);
				sw->WriteLine(fastColoredTextBox2->Text);
                sw->Close();
            }
		 } 
private: System::Void toolStripMenuItem8_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 File^ f ;
				 OpenFileDialog^ ofd = gcnew OpenFileDialog;
				 ofd->InitialDirectory = "c:\\"; 
				 ofd->Filter = "xml files |*.xml";
				 ofd->RestoreDirectory = true;
				  if ( ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK )
				  {
					  fileName = ofd->FileName;
					  readFile = f->ReadAllText(fileName);
					  //richTextBox1->Text = readFile;
					  fastColoredTextBox2->Text = readFile;
				  }
		 }
private: System::Void toolStripMenuItem5_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
				StreamWriter^ sw = gcnew StreamWriter(fileName);
				sw->WriteLine(fastColoredTextBox2->Text);
                sw->Close();
		 }
private: System::Void toolStripMenuItem6_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			File^ f ;
			Path^ p ;
			SaveFileDialog^ sfd = gcnew SaveFileDialog;
            sfd->InitialDirectory =  "c:\\"; 
            sfd->FileName = "untitled.xml";
            if (sfd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
            {
                if (p->GetExtension(sfd->FileName) != ".xml")
                {
                    sfd->FileName += ".xml";
                }
                StreamWriter^ sw = gcnew StreamWriter(sfd->FileName);
				sw->WriteLine(fastColoredTextBox2->Text);
                sw->Close();
            }
		 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
{
	//MessageBox::Show(fastColoredTextBox2->GetLineLength(2).ToString());
	if (check(fastColoredTextBox2->Text))
	{
		MessageBox::Show("No Error");
	}
	else
	{
		MessageBox::Show("Error");
		detect(fastColoredTextBox2->Text);
	}
}
private: System::Void solve_btn_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 solve(fastColoredTextBox2->Text);
			 
		 }
private: System::Void After_Load(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}