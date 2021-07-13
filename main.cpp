//
//  main.cpp
//  XML Editor
//
//  Created by Mohanad Safwat on 12/07/2021.
//

#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <sstream>


using namespace std;

int iBeautify = 0 ;

static inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
}

// trim from end (in place)
static inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

// trim from both ends (in place)
static inline void trim(std::string &s) {
    ltrim(s);
    rtrim(s);
}

struct Node
{
    string key;
    string value;
    vector<string> attr;
    vector<Node*> child;
    Node* parent;

};

class GeneralTree{
    Node* root;

public:
    vector<string> start;
    Node* nodePointer = nullptr ;
    

    GeneralTree();
    void newNode(Node* &node, bool rootCheck);
    void beautify(){
        vector<string>::iterator it = start.begin();
        int size = start.size();
        for (it; it != start.end() ; it++) {
            cout<<*it;
            size--;
            if(size != 0)
                cout<<endl;
            
        }

        beautifyPriv(this->root);
    }
    void beautifyPriv(Node* node)
    {
        Node* tmp = node;
        Node* nodePointerBeautify =tmp;
        if (tmp==NULL)
            return;
        
        string att;
        
        vector<string>::iterator itAttr = tmp->attr.begin();
        while(itAttr != tmp->attr.end())
        {
            att+=" ";
            att += *itAttr;
            itAttr++;
        }
        

        cout<<endl<<string(iBeautify,'\t')<<"<"<<tmp->key<<att<<">"<<tmp->value;
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
            cout<<endl<<string(iBeautify-1,'\t')<<"</"<<nodePointerBeautify->key<<">";

        }
        else
        {
            cout<<"</"<<tmp->key<<">";
            nodePointerBeautify = nodePointerBeautify->parent;
           
                

        }

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



// Driver program
int main()
{
  
    string xmlCode;
    GeneralTree tree;
    vector<string> att;
     

//    <employees><employee><id>1</id><firstName>Leonardo</firstName><lastName>DiCaprio</lastName><photo>http://1.bp.blogspot.com/-zvS_6Q1IzR8/T5l6qvnRmcI/AAAAAAAABcc/HXO7HDEJKo0/s200/Leonardo+Dicaprio7.jpg</photo></employee><employee><id>2</id><firstName>Johnny</firstName><lastName>Depp</lastName><photo>http://4.bp.blogspot.com/_xR71w9-qx9E/SrAz--pu0MI/AAAAAAAAC38/2ZP28rVEFKc/s200/johnny-depp-pirates.jpg</photo></employee><employee><id>3</id><firstName>Hritik</firstName><lastName>Roshan</lastName><photo>http://thewallmachine.com/files/1411921557.jpg</photo></employee></employees>
    
    xmlCode = "  <?xml version=\"1.0\" encoding=\"UTF-8\" ?><employees><employee><id class=\"mohanad\">1</id><firstName>Leonardo</firstName><lastName>DiCaprio</lastName><photo>http://1.bp.blogspot.com/-zvS_6Q1IzR8/T5l6qvnRmcI/AAAAAAAABcc/HXO7HDEJKo0/s200/Leonardo+Dicaprio7.jpg</photo></employee><employee><id>2</id><firstName>Johnny</firstName><lastName>Depp</lastName><photo>http://4.bp.blogspot.com/_xR71w9-qx9E/SrAz--pu0MI/AAAAAAAAC38/2ZP28rVEFKc/s200/johnny-depp-pirates.jpg</photo></employee><employee><id>3</id><firstName>Hritik</firstName><lastName>Roshan</lastName><photo>http://thewallmachine.com/files/1411921557.jpg</photo></employee></employees>   ";
    rtrim(xmlCode);
    ltrim(xmlCode);
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
            
            Node* node = new Node;

            node->key = tagName;
            node->attr = att;
            i = endTag;
            if (rootTag)
            {
                tree.newNode(node, true);
                rootTag = false;
                seglist.clear();
                att.clear();
            }
            else
            {
                tree.newNode(node, false);
                seglist.clear();
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
            tree.nodePointer->value = tagValue;
            i = endTag -1 ;
        }
        
    }

    tree.beautify();
    cout<<endl;
    return 0;
}

