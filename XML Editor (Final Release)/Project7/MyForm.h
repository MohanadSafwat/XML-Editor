#include <iostream>
#include <stack>
#include <iostream>
#include <string>
#include <queue>
#include <string.h>
#include <sstream>
#include <map>
#include <iterator>
#include <vector>
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
	
	int iBeautify = 0 ;
	int counter = 0;
	int counter2 = 0;
	bool checker=false;
	stringstream json;
	string prevTag = "";
	vector<string> tmpTag;
	vector<string> v;
	
static inline void ltrim(string &s) {
    s.erase(s.begin(), find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !isspace(ch);
    }));
}

// trim from end (in place)
static inline void rtrim(string &s) {
    s.erase(find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !isspace(ch);
    }).base(), s.end());
}

// trim from both ends (in place)
static inline void trim(string &s) {
    ltrim(s);
    rtrim(s);
}

int getDuplicate(vector<string> v ,string key){

    map<string,int> dup;

    for_each( v.begin(), v.end(), [&dup]( string val ){ dup[val]++; } );
    return dup[key];
    }

struct Node
	{
		 string key;
    string value;
    string attr;
    vector<Node*> child;
    Node* parent;

	};
string return_string;

class GeneralTree{
    Node* root;

public:
    vector<string> start;
    Node* nodePointer ;


    GeneralTree();
    void newNode(Node* &node, bool rootCheck);

    string beautify(){
        iBeautify = 0 ;
        return_string="";
        string returnString2;
        vector<string>::iterator it = start.begin();
        int size = start.size();
        for (it; it != start.end() ; it++) {
            returnString2+=*it;
            size--;
            if(size != 0)
                returnString2+='\n';

        }

        returnString2+=beautifyPriv(this->root);
        return  returnString2;

    }
    string beautifyPriv(Node* node)
    {
         Node* tmp = node;
        Node* nodePointerBeautify =tmp;
        if (tmp==NULL)
        {
            return "";
        }
        string att;

//        ve<string,string>::iterator itAttr = tmp->attr.begin();
//        while(itAttr != tmp->attr.end())
//        {
//            att+=" ";
//            att += itAttr->first;
//            att+="=";
//            att += itAttr->second;
//            itAttr++;
//        }


        return_string+='\n'+string(iBeautify,'\t')+"<"+tmp->key+tmp->attr+">"+tmp->value;
        att="";
        iBeautify++;
        vector<Node *>::iterator it = (tmp->child).begin();
        int size = tmp->child.size();

        if(size != 0)
        {
            while(size != 0)
            {
            beautifyPriv(*it);
                it++;
                size--;
                iBeautify--;


            }
            return_string+='\n'+string(iBeautify-1,'\t')+"</"+nodePointerBeautify->key+">";

        }
        else
        {
            return_string+="</"+tmp->key+">";
            nodePointerBeautify = nodePointerBeautify->parent;


        }
        return return_string;

    }


    string minify(){
        iBeautify = 0 ;
        return_string="";
        string returnString2;
        vector<string>::iterator it = start.begin();
        int size = start.size();
        for (it; it != start.end() ; it++) {
            returnString2+=*it;
            size--;
            if(size != 0)
                returnString2+='\n';

        }

        returnString2+=minifyPriv(this->root);
        return  returnString2;

    }
    string minifyPriv(Node* node)
    {
        Node* tmp = node;
        Node* nodePointerBeautify =tmp;
        if (tmp==NULL)
        {
            return "";
        }
        string att;

//        ve<string,string>::iterator itAttr = tmp->attr.begin();
//        while(itAttr != tmp->attr.end())
//        {
//            att+=" ";
//            att += itAttr->first;
//            att+="=";
//            att += itAttr->second;
//            itAttr++;
//        }


        return_string+="<"+tmp->key+tmp->attr+">"+tmp->value;
        att="";
        iBeautify++;
        vector<Node *>::iterator it = (tmp->child).begin();
        int size = tmp->child.size();

        if(size != 0)
        {
            while(size != 0)
            {
            minifyPriv(*it);
                it++;
                size--;
                iBeautify--;


            }
            return_string+="</"+nodePointerBeautify->key+">";

        }
        else
        {
            return_string+="</"+tmp->key+">";
            nodePointerBeautify = nodePointerBeautify->parent;


        }
        return return_string;

    }

    /*JSON Convert*/

	
    string convertJson(){
        json.str("");
        iBeautify = 0 ;
        json<<"{";
        convertJsonPriv(this->root);
        json<<endl<<"}"<<endl;
        return json.str();
    }
    string convertJsonPriv(Node* node)
    {

        Node* tmp = node;
        Node* nodePointerBeautify =tmp;
        int tmpCounter;
        if (tmp==NULL)
            return 0;

        //json<<"---"<<prevTag;
        if(tmp->key != prevTag){
            json<<endl<<string(iBeautify+1,'\t')<<"\""<<tmp->key<<"\":";
        }
        if( tmp!=root && counter < tmp->parent->child.size()-1 &&tmp->key == tmp->parent->child[counter+1]->key && tmp->key != prevTag){
            json<<"[";


            counter = 0;
            prevTag = tmp->key;
            checker = true;


        }
        else{
            checker = false;
        }

        if((tmp->child).size() != 0){


            string str = tmp->attr;
            rtrim(str);
            ltrim(str);
            str.insert(0,"\"_");
            int len = str.length()-1;
            for(int i = 0;i<len;i++){
                if(str[i] == ' ' && str[i+1] == ' '){
                    str.erase(i,1);
                    i--;
                    len--;
                }
            }
            //cout<<str<<endl;
            for(int i = 0;i<str.length();i++){
                if(str[i] == '='){

                    str[i] = ':';
                    str.insert(i,"\"");
                    if(str[i-1]==' '){
                        str.erase(i-1,1);
                    }
                }
                if(str[i] == ' '&& str[i-1] == '\"' ){
                    str[i] = ',';
                    str.insert(i+1,"\"_");
                    str.insert(i+1,string(iBeautify+2,'\t'));
                    str.insert(i+1,"\n");
                }
            }
            str.insert(str.end(),',');

            json<<"{"<<tmp->value;

            for(int i =0;tmp->child.size() != 0 &&i<tmp->child.size();i++){
                v.push_back(tmp->child[i]->key);
            }

            if(tmp->attr.length() > 1){
                json<<endl<<string(iBeautify+2,'\t')<<str;
            }
            tmpCounter = counter;
            counter = 0;
            //json<<"####################"<<prevTag;
            tmpTag.push_back(prevTag);
            prevTag = "";

        }else{

            json<<"\""<<tmp->value<<"\"";
            //json<<counter<<"     "<<getDuplicate(v,tmp->key)-1 ;
            if(counter != (tmp->parent->child).size()-1 ){

                if(tmp->key ==prevTag && counter == getDuplicate(v,tmp->key)-1)  {

                    json<<"]";
                }

                json<<",";

                counter++;
            }
        }

        iBeautify++;

        vector<Node *>::iterator it = (tmp->child).begin();
        int size = tmp->child.size();

        if(size != 0)
        {
            while(size != 0)
            {
            convertJsonPriv(*it);
                it++;
                size--;
                iBeautify--;
            }
            json<<endl<<string(iBeautify,'\t')<<"}";

            counter = tmpCounter+1;

            prevTag = tmpTag[tmpTag.size()-1];
            tmpTag.pop_back();
            if(tmp->key ==prevTag && counter == (tmp->parent->child).size()) json<<"]";
            if(nodePointerBeautify != root )
                if(counter2 != (nodePointerBeautify->parent->child).size()-1 && nodePointerBeautify->parent == root){
                    json<<",";
                    v.clear();
                    counter2++;
                }else if(counter < (tmp->parent->child).size()){
                    json<<",";

                }
        }
        else
        {

            nodePointerBeautify = nodePointerBeautify->parent;
        }
        //cout<<ss.str();
        return json.str();
    }

};


GeneralTree::GeneralTree(){
    root = NULL;
    nodePointer = root;
    }

void GeneralTree::newNode(Node* &node,bool rootCheck)
{
    Node* tmp = node;
    tmp->parent = nodePointer;
    if(nodePointer !=NULL)
    nodePointer->child.push_back(tmp);
    nodePointer = tmp;


    if(rootCheck)
        this->root = tmp;


}

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
	private: System::Windows::Forms::Label^  status;
	private: System::Windows::Forms::ToolStripMenuItem^  decodeToolStripMenuItem;





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
			this->decodeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem3 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem5 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem6 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->fastColoredTextBox2 = (gcnew FastColoredTextBoxNS::FastColoredTextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->solve_btn = (gcnew System::Windows::Forms::Button());
			this->After = (gcnew FastColoredTextBoxNS::FastColoredTextBox());
			this->status = (gcnew System::Windows::Forms::Label());
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
			this->toolStripMenuItem2->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {this->validateToolStripMenuItem, 
				this->formatToolStripMenuItem, this->minifyToolStripMenuItem, this->convertToJSONToolStripMenuItem, this->compressToolStripMenuItem, 
				this->decodeToolStripMenuItem});
			this->toolStripMenuItem2->Name = L"toolStripMenuItem2";
			this->toolStripMenuItem2->Size = System::Drawing::Size(39, 20);
			this->toolStripMenuItem2->Text = L"Edit";
			// 
			// validateToolStripMenuItem
			// 
			this->validateToolStripMenuItem->Name = L"validateToolStripMenuItem";
			this->validateToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift) 
				| System::Windows::Forms::Keys::V));
			this->validateToolStripMenuItem->Size = System::Drawing::Size(245, 22);
			this->validateToolStripMenuItem->Text = L"Validate";
			this->validateToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::validateToolStripMenuItem_Click);
			// 
			// formatToolStripMenuItem
			// 
			this->formatToolStripMenuItem->Name = L"formatToolStripMenuItem";
			this->formatToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift) 
				| System::Windows::Forms::Keys::F));
			this->formatToolStripMenuItem->Size = System::Drawing::Size(245, 22);
			this->formatToolStripMenuItem->Text = L"Format";
			this->formatToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::formatToolStripMenuItem_Click);
			// 
			// minifyToolStripMenuItem
			// 
			this->minifyToolStripMenuItem->Name = L"minifyToolStripMenuItem";
			this->minifyToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift) 
				| System::Windows::Forms::Keys::M));
			this->minifyToolStripMenuItem->Size = System::Drawing::Size(245, 22);
			this->minifyToolStripMenuItem->Text = L"Minify";
			this->minifyToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::minifyToolStripMenuItem_Click);
			// 
			// convertToJSONToolStripMenuItem
			// 
			this->convertToJSONToolStripMenuItem->Name = L"convertToJSONToolStripMenuItem";
			this->convertToJSONToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift) 
				| System::Windows::Forms::Keys::J));
			this->convertToJSONToolStripMenuItem->Size = System::Drawing::Size(245, 22);
			this->convertToJSONToolStripMenuItem->Text = L"Convert to JSON";
			this->convertToJSONToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::convertToJSONToolStripMenuItem_Click);
			// 
			// compressToolStripMenuItem
			// 
			this->compressToolStripMenuItem->Name = L"compressToolStripMenuItem";
			this->compressToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift) 
				| System::Windows::Forms::Keys::C));
			this->compressToolStripMenuItem->Size = System::Drawing::Size(245, 22);
			this->compressToolStripMenuItem->Text = L"Compress/Encode";
			this->compressToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::compressToolStripMenuItem_Click);
			// 
			// decodeToolStripMenuItem
			// 
			this->decodeToolStripMenuItem->Name = L"decodeToolStripMenuItem";
			this->decodeToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift) 
				| System::Windows::Forms::Keys::D));
			this->decodeToolStripMenuItem->Size = System::Drawing::Size(245, 22);
			this->decodeToolStripMenuItem->Text = L"Decode";
			this->decodeToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::decodeToolStripMenuItem_Click);
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
			this->toolStripMenuItem5->Size = System::Drawing::Size(213, 22);
			this->toolStripMenuItem5->Text = L"Save Input";
			this->toolStripMenuItem5->Click += gcnew System::EventHandler(this, &MyForm::toolStripMenuItem5_Click);
			// 
			// toolStripMenuItem6
			// 
			this->toolStripMenuItem6->Name = L"toolStripMenuItem6";
			this->toolStripMenuItem6->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift) 
				| System::Windows::Forms::Keys::A));
			this->toolStripMenuItem6->Size = System::Drawing::Size(213, 22);
			this->toolStripMenuItem6->Text = L"Save Output";
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
			this->fastColoredTextBox2->BackColor = System::Drawing::Color::Gainsboro;
			this->fastColoredTextBox2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->fastColoredTextBox2->CharHeight = 14;
			this->fastColoredTextBox2->CharWidth = 8;
			this->fastColoredTextBox2->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->fastColoredTextBox2->DisabledColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)), 
				static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(180)));
			this->fastColoredTextBox2->IsReplaceMode = false;
			this->fastColoredTextBox2->Location = System::Drawing::Point(12, 41);
			this->fastColoredTextBox2->Name = L"fastColoredTextBox2";
			this->fastColoredTextBox2->Paddings = System::Windows::Forms::Padding(0);
			this->fastColoredTextBox2->SelectionColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->fastColoredTextBox2->ServiceColors = (cli::safe_cast<FastColoredTextBoxNS::ServiceColors^  >(resources->GetObject(L"fastColoredTextBox2.ServiceColors")));
			this->fastColoredTextBox2->ShowFoldingLines = true;
			this->fastColoredTextBox2->Size = System::Drawing::Size(337, 408);
			this->fastColoredTextBox2->TabIndex = 1;
			this->fastColoredTextBox2->Zoom = 100;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(402, 353);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Check";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Visible = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// solve_btn
			// 
			this->solve_btn->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->solve_btn->Location = System::Drawing::Point(407, 115);
			this->solve_btn->Name = L"solve_btn";
			this->solve_btn->Size = System::Drawing::Size(75, 41);
			this->solve_btn->TabIndex = 3;
			this->solve_btn->Text = L"Solve Errors";
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
			this->After->BackColor = System::Drawing::Color::Gainsboro;
			this->After->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->After->CharHeight = 14;
			this->After->CharWidth = 8;
			this->After->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->After->DisabledColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(180)), 
				static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(180)));
			this->After->IsReplaceMode = false;
			this->After->Location = System::Drawing::Point(535, 41);
			this->After->Name = L"After";
			this->After->Paddings = System::Windows::Forms::Padding(0);
			this->After->SelectionColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->After->ServiceColors = (cli::safe_cast<FastColoredTextBoxNS::ServiceColors^  >(resources->GetObject(L"After.ServiceColors")));
			this->After->Size = System::Drawing::Size(340, 408);
			this->After->TabIndex = 4;
			this->After->Zoom = 100;
			this->After->Load += gcnew System::EventHandler(this, &MyForm::After_Load);
			// 
			// status
			// 
			this->status->BackColor = System::Drawing::Color::White;
			this->status->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->status->Font = (gcnew System::Drawing::Font(L"Times New Roman", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->status->Location = System::Drawing::Point(381, 55);
			this->status->Name = L"status";
			this->status->Size = System::Drawing::Size(128, 35);
			this->status->TabIndex = 6;
			this->status->Text = L"Welcome to our Project :)";
			this->status->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->status->Click += gcnew System::EventHandler(this, &MyForm::status_Click);
			// 
			// MyForm
			// 
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(32)), static_cast<System::Int32>(static_cast<System::Byte>(34)), 
				static_cast<System::Int32>(static_cast<System::Byte>(37)));
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(887, 461);
			this->Controls->Add(this->status);
			this->Controls->Add(this->After);
			this->Controls->Add(this->solve_btn);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->fastColoredTextBox2);
			this->Controls->Add(this->menuStrip2);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip2;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
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





GeneralTree createTree(string xmlCode){
    
     GeneralTree tree;
    vector<string> seglist1;
    vector<string> seglist2;

    string segment;
    stringstream ss;
    vector<string> att;
    string attr;

    xmlCode.erase(std::remove(xmlCode.begin(), xmlCode.end(), '\n'), xmlCode.end());
    xmlCode.erase(std::remove(xmlCode.begin(), xmlCode.end(), '\n'), xmlCode.end());

    bool rootTag = true;
    for(int i = 0 ; i< xmlCode.length(); i++)
    {
        if(xmlCode[i] == '<' && xmlCode[i+1] == '?')
        {
            int endTag;
            string startValue;
            endTag = xmlCode.find('>',i);
            startValue = xmlCode.substr(i, endTag +1);
            i = endTag;
            tree.start.push_back(startValue);
        }
        if (xmlCode[i] == '<' && xmlCode[i+1] != '/')
        {
            int endTag;
//            int equalCheck;
            string tagNameAttr;
            string tagName;
            endTag = xmlCode.find('>',i);
            tagNameAttr = xmlCode.substr(i+1, endTag - i-1);
            stringstream ss(tagNameAttr);
            string segment;
            vector<string> seglist;



            while(getline(ss, segment, ' '))
            {
               seglist.push_back(segment);
            }
            vector<string>::iterator it = seglist.begin();
            tagName = *it;
            it++;

            while(it != seglist.end())
            {
                att.push_back(*it);
                it++;

            }
            vector<string>::iterator it2 = att.begin();

            while(it2 != att.end())
            {
                attr+=" ";
                attr += *it2;

                it2++;
            }



            Node* node = new Node;

            node->key = tagName;
            node->attr = attr;
            i = endTag;
            if (rootTag)
            {
                tree.newNode(node, true);
                rootTag = false;
                seglist.clear();
//                seglist2.clear();
                att.clear();
                attr = "";
            }
            else
            {
                tree.newNode(node, false);
                seglist.clear();
//                seglist2.clear();
                attr = "";

                att.clear();
            }
        }
        else if (xmlCode[i] == '<' && xmlCode[i+1] == '/')
        {
            int endTag;
            endTag = xmlCode.find('>',i);
            i = endTag;
            tree.nodePointer = tree.nodePointer->parent;

        }
        else if (xmlCode[i] != '<' && xmlCode[i-1] == '>')
        {
            int endTag;
            string tagValue;
            endTag = xmlCode.find('<',i);
            tagValue = xmlCode.substr(i, endTag - i);
            ltrim(tagValue);
            rtrim(tagValue);
            tree.nodePointer->value = tagValue;
            i = endTag -1 ;
        }



    }

    return tree;
}


void Convert_system_to_std(String^ s, string& os) 
{
			using namespace Runtime::InteropServices;
			const char* chars =
				(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
			os = chars;
			Marshal::FreeHGlobal(IntPtr((void*)chars));
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
					x = x.erase(i + 1, (k - i - 1));
				}
				
			}

			return x;
}

bool check(String^ t)
{
	int closing = 0 , opening = 0 , flag = 0 , comment = 0;
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
				if (tag->Length>=5)
				{
					if (tag[0]=='!'&&tag[1]=='-'&&tag[2]=='-'&&tag[tag->Length-2]=='-'&&tag[tag->Length-1]=='-')  //comment
					{
						opening = 0 ;
						tag = "";
						continue;
					}
				}
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
	After->Text = "";
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
					After->Text += "\nMissing closing tag for "+"<"+(String^)s->Peek()+">";
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
	int closing = 0 , opening = 0 , flag = 0 , opening_start_pos = 0 ,
	opening_end_pos = 0 , closing_start_pos = 0 , closing_end_pos = 0 , errors = 0;
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
					After->SelectionStart = closing_start_pos ;
					After->SelectionLength = closing_end_pos - closing_start_pos + 1 ;
					After->InsertText("</"+(String^)s->Peek()+">");
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
		After->AppendText("</"+(String^)s->Peek()+">");
		After->AppendText("\n");
		s->Pop();
	}

	 string st ;
	 GeneralTree gt ;
	 Convert_system_to_std(After->Text,st);
	 ltrim(st);
	 rtrim(st);
	 gt = createTree(st);
	 st = gt.beautify();
	 After->Text = gcnew String(st.c_str());
     status->Text = "Solved "+errors.ToString()+" errors" ;
	//MessageBox::Show("Solved "+errors.ToString()+" Errors");

}

vector<int> encoding(string inputStr)
{

	map<string, int> codeTable;
	for (int i = 0; i <= 255; i++) {
		string ch = "";
		ch += char(i);
		codeTable[ch] = i;
	}
	string p = "", c = "";
	p += inputStr[0];
	int code = 256;
	vector<int> output_code;
	for (int i = 0; i < inputStr.length(); i++) {
		if (i != inputStr.length() - 1)
			c += inputStr[i + 1];
		if (codeTable.find(p + c) != codeTable.end()) {
			p = p + c;
		}
		else {
			output_code.push_back(codeTable[p]);
			codeTable[p + c] = code;
			code++;
			p = c;
		}
		c = "";
	}
	output_code.push_back(codeTable[p]);
	return output_code;
}

void decoding(vector<int> encodeStr,string &str)
{
	map<int, string> codeTable;
	for (int i = 0; i <= 255; i++) {
		string ch = "";
		ch += char(i);
		codeTable[i] = ch;
	}
	int tmp = encodeStr[0], n;
	string s = codeTable[tmp];
	string c = "";
	c += s[0];
	str += s ;
	int count = 256;
	for (int i = 0; i < encodeStr.size() - 1; i++) {
		n = encodeStr[i + 1];
		if (codeTable.find(n) == codeTable.end()) {
			s = codeTable[tmp];
			s = s + c;
		}
		else {
			s = codeTable[n];
		}
		str += s ;
		c = "";
		c += s[0];
		codeTable[count] = codeTable[tmp] + c;
		count++;
		tmp = n;
	}
	
}


private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) 
		 {
			 fastColoredTextBox2->Language = FastColoredTextBoxNS::Language::XML;
			 After->Language = FastColoredTextBoxNS::Language::XML;
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
					  fastColoredTextBox2->Text = readFile;
				  }
		 }
private: System::Void toolStripMenuItem5_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
				StreamWriter^ sw = gcnew StreamWriter(fileName);
				sw->WriteLine(After->Text);
                sw->Close();
				fastColoredTextBox2->Text = After->Text;
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
				sw->WriteLine(After->Text);
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
			 if (check(fastColoredTextBox2->Text))
			 {
				 After->Text = "";
				 status->Text = "There is no error to solve !";
			 }
			 else
			 {
				 solve(fastColoredTextBox2->Text);
			 }
		 }
private: System::Void After_Load(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void minifyToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 string zaza;
			 Convert_system_to_std(fastColoredTextBox2->Text, zaza);
			 ltrim(zaza);
			 rtrim(zaza);
			 GeneralTree g ;
			 g = createTree(zaza);
			 string zezo = g.minify();
			 //zezo =Minify_function(zaza);
			 After->Text = gcnew String(zezo.c_str());
			 status->Text = "Minifying Done !";
		 }
private: System::Void formatToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 string s ;
			 GeneralTree t ;
			 Convert_system_to_std(fastColoredTextBox2->Text,s);
			 ltrim(s);
			 rtrim(s);
			 t = createTree(s);
			 s = t.beautify();
			 After->Text = gcnew String(s.c_str());
			 status->Text = "Formatting Done !";
		 }
private: System::Void convertToJSONToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 string s ;
			 GeneralTree t ;
			 Convert_system_to_std(fastColoredTextBox2->Text,s);
			 ltrim(s);
			 rtrim(s);
			 t = createTree(s);
			 s = t.convertJson();
			 After->Text = gcnew String(s.c_str());
			 status->Text = "Converting Done !";
		 }
private: System::Void compressToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 String^ output = "";
			 string input ;
			 Convert_system_to_std(fastColoredTextBox2->Text,input);
			 vector<int> output_code = encoding(input);
			 for (int i = 0; i < output_code.size(); i++)
			 {
				 output += (output_code[i].ToString() + " ");
			 }
			 File^ f ;
			Path^ p ;
			SaveFileDialog^ sfd = gcnew SaveFileDialog;
            sfd->InitialDirectory =  "c:\\"; 
            sfd->FileName = "untitled.txt";
            if (sfd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
            {
                if (p->GetExtension(sfd->FileName) != ".txt")
                {
                    sfd->FileName += ".txt";
                }
                StreamWriter^ sw = gcnew StreamWriter(sfd->FileName);
				sw->WriteLine(output);
                sw->Close();
				status->Text = "Compressing Done !";
			}
		 }
private: System::Void validateToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			if (check(fastColoredTextBox2->Text))
			{
				status->Text = "XML is valid" ;
				After->Text = "";
			}
			else
			{
				status->Text = "XML is not valid !" ;
				detect(fastColoredTextBox2->Text);
			}
		 }
private: System::Void status_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void decodeToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 fastColoredTextBox2->Text = "" ;
			 string ss = "", output = "";
			 int n ;
			 vector<int> input;
				 File^ f ;
				 OpenFileDialog^ ofd = gcnew OpenFileDialog;
				 ofd->InitialDirectory = "c:\\"; 
				 ofd->Filter = "txt files |*.txt";
				 ofd->RestoreDirectory = true;
				  if ( ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK )
				  {
					  fileName = ofd->FileName;
					  readFile = f->ReadAllText(fileName);
					  Convert_system_to_std(readFile,ss);
					  stringstream iss(ss);
					  while ( iss >> n )
						  input.push_back( n );
					  decoding(input,output);
					  fastColoredTextBox2->Text = gcnew String(output.c_str());
				  }
				  status->Text = "Decoding Done !";

		 }
};


	


}

	