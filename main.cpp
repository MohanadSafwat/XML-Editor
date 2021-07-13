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
    Node* nodePointer = nullptr ;
    

    GeneralTree();
    void newNode(Node* &node, bool rootCheck);
//    void LevelOrderTraversal(Node * root)
//    {
//        if (root==NULL)
//            return;
//
//        // Standard level order traversal code
//        // using queue
//        queue<Node *> q; // Create a queue
//        q.push(root); // Enqueue root
//        while (!q.empty())
//        {
//            int n = q.size();
//
//            // If this node has children
//            while (n > 0)
//            {
//                // Dequeue an item from queue and print it
//                Node * p = q.front();
//                q.pop();
//                cout << p->key << " ";
//
//                // Enqueue all children of the dequeued item
//                for (int i=0; i<p->child.size(); i++)
//                    q.push(p->child[i]);
//                n--;
//            }
//
//            cout << endl; // Print new line between two levels
//        }
//    }
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
    vector<string> seglist;
    string segment;
    stringstream ss;
    vector<string> att;


     

//    <employees><employee><id>1</id><firstName>Leonardo</firstName><lastName>DiCaprio</lastName><photo>http://1.bp.blogspot.com/-zvS_6Q1IzR8/T5l6qvnRmcI/AAAAAAAABcc/HXO7HDEJKo0/s200/Leonardo+Dicaprio7.jpg</photo></employee><employee><id>2</id><firstName>Johnny</firstName><lastName>Depp</lastName><photo>http://4.bp.blogspot.com/_xR71w9-qx9E/SrAz--pu0MI/AAAAAAAAC38/2ZP28rVEFKc/s200/johnny-depp-pirates.jpg</photo></employee><employee><id>3</id><firstName>Hritik</firstName><lastName>Roshan</lastName><photo>http://thewallmachine.com/files/1411921557.jpg</photo></employee></employees>
    
    cin>>xmlCode;

    bool rootTag = true;
    for(int i = 0 ; i< xmlCode.length(); i++)
    {
        if (xmlCode[i] == '<' && xmlCode[i+1] != '/')
        {
            int endTag;
            string tagNameAttr;
            endTag = xmlCode.find('>',i);
            tagNameAttr = xmlCode.substr(i+1, endTag - i-1);
//            ss.str(tagNameAttr);
//            cout<<(tagNameAttr)<<endl;
            
//            while(std::getline(ss, segment, ' '))
//            {
//               seglist.push_back(segment);
//            }
            Node* node = new Node;

            node->key = tagNameAttr;
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
                tree.newNode(node, false);
        
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


    return 0;
}
