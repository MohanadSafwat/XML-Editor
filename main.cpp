#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <sstream>
#include <fstream>
#include <map>
using namespace std;

int iBeautify = 0 ;
int counter = 0;
int counter2 = 0;
bool checker=false;
stringstream json;
string prevTag = "";
vector<string> tmpTag;
string return_string;

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

struct Node
{
    string key;
    string value;
    string attr;
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
        stringstream ss;
        Node* tmp = node;
        Node* nodePointerBeautify =tmp;
        int tmpCounter;
        if (tmp==NULL)
            return 0;


        //cout<<"---"<<prevTag;
        if(tmp->key != prevTag){
            json<<endl<<string(iBeautify+1,'\t')<<"\""<<tmp->key<<"\":";

        }
        if( tmp!=root && counter < tmp->parent->child.size()-1 &&tmp->key == tmp->parent->child[counter+1]->key && tmp->key != prevTag){
            json<<"[";
            prevTag = tmp->key;
            checker = true;


        }
        else{
            checker = false;
        }

        if((tmp->child).size() != 0){

            json<<"{"<<tmp->value;
            tmpCounter = counter;
            counter = 0;
            tmpTag.push_back(prevTag);
            prevTag = "";

        }else{

            json<<"\""<<tmp->value<<"\"";
            //cout<<counter<<"     "<<(tmp->parent->child).size() ;
            if(counter != (tmp->parent->child).size()-1 ){
                if(tmp->key ==prevTag && counter == (tmp->parent->child).size()-2)  json<<"]";
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
            if(tmp->key ==prevTag && counter == (tmp->parent->child).size()) ss<<"]";
            if(nodePointerBeautify != root )
                if(counter2 != (nodePointerBeautify->parent->child).size()-1 && nodePointerBeautify->parent == root){
                    //cout<<counter2 <<"    " << (nodePointerBeautify->parent->child).size()<< "   " << (nodePointerBeautify->parent == root) ;
                    json<<",";

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

GeneralTree createTree(string xmlCode){
    
    GeneralTree tree;
    vector<string> seglist1;
    vector<string> seglist2;

    string segment;
    stringstream ss;
    vector<string> att;
    string attr;

    
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

//            equalCheck = xmlCode.find('=',i);
//            if (equalCheck > endTag)
//                equalCheck =-1;
            
//            if(equalCheck != -1)
//            {
//                while(getline(ss, segment, '='))
//                {
//                   seglist1.push_back(segment);
//                }
//
//                vector<string>::iterator it = seglist1.begin();
//                while(it != seglist1.end())
//                {
//                    stringstream ss2(*it);
//                    string segment2;
//                while(getline(ss2, segment2, ' '))
//                {
//                   seglist2.push_back(segment2);
//                }
//
//                    it++;
//
//                }
//                vector<string>::iterator it2 = seglist2.begin();
//                tagName = *it2;
//                it2++;
//                while(it2 != seglist2.end())
//                {
//                    att.insert(pair<string,string>(*it2,*(++it2)));
//                    it2++;
//                }
//
//
//            }
//            else{

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
                
//            }

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



// Driver program
int main()
{

    string xmlCode;
    GeneralTree tree;

 

    string allFile;
    ifstream file("/Users/mohanadsafwat/Downloads/test2.xml");
    copy( istream_iterator<char>{ file >> noskipws }, {}, back_inserter( allFile ) );
    file.close();



//    <employees><employee><id>1</id><firstName>Leonardo</firstName><lastName>DiCaprio</lastName><photo>http://1.bp.blogspot.com/-zvS_6Q1IzR8/T5l6qvnRmcI/AAAAAAAABcc/HXO7HDEJKo0/s200/Leonardo+Dicaprio7.jpg</photo></employee><employee><id>2</id><firstName>Johnny</firstName><lastName>Depp</lastName><photo>http://4.bp.blogspot.com/_xR71w9-qx9E/SrAz--pu0MI/AAAAAAAAC38/2ZP28rVEFKc/s200/johnny-depp-pirates.jpg</photo></employee><employee><id>3</id><firstName>Hritik</firstName><lastName>Roshan</lastName><photo>http://thewallmachine.com/files/1411921557.jpg</photo></employee></employees>

//    xmlCode = "<?xml version=\"1.0\" encoding=\"UTF-8\" ?><employees><employee><id class=\"mohanad\" class2=\"mohanad2\">1</id><firstName>Leonardo</firstName><lastName>DiCaprio</lastName><photo>http://1.bp.blogspot.com/-zvS_6Q1IzR8/T5l6qvnRmcI/AAAAAAAABcc/HXO7HDEJKo0/s200/Leonardo+Dicaprio7.jpg</photo></employee><employee><id>2</id><firstName>Johnny</firstName><lastName>Depp</lastName><photo>http://4.bp.blogspot.com/_xR71w9-qx9E/SrAz--pu0MI/AAAAAAAAC38/2ZP28rVEFKc/s200/johnny-depp-pirates.jpg</photo></employee><employee><id>3</id><firstName>Hritik</firstName><lastName>Roshan</lastName><photo>http://thewallmachine.com/files/1411921557.jpg</photo></employee></employees>";
    xmlCode = allFile;
    
    
    
//    cin>>xmlCode;
    rtrim(xmlCode);
    ltrim(xmlCode);
    tree = createTree(xmlCode);
 

   cout<< tree.beautify();
    cout<< tree.beautify();


    cout<<tree.convertJson();

    cout<<tree.convertJson();
    cout<<endl;
    return 0;
}
