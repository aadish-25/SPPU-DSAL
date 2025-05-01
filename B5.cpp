// A book consists of chapters, chapters consist of sections and sections consist of
// subsections. Construct a tree and print the nodes. Find the time and space requirements
// of your method. 

#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        string name;
        vector <Node*> children;

        Node(){
            name = "";
        }

        Node(string n){
            name = n;
        }
};

void printTree(Node* root, int level = 0){
    if(root == nullptr) return;

    for(int i=0; i<level; i++){
        cout << "   ";
    }
    cout << root->name << endl;

    for(int i=0; i<root->children.size(); i++){
        printTree(root->children[i], level+1);
    }
}

int main(){
    string bookname;
    cout << "Enter the name of the book : ";
    getline(cin, bookname);

    Node * book = new Node(bookname);

    int chapterNum;
    cout << "Enter number of chapters: ";
    cin >> chapterNum;
    cin.ignore();

    for(int i=0; i<chapterNum; i++){
        string chaptername;
        cout << "Enter name of chapter " << i+1 << " : ";
        getline(cin, chaptername);
        Node *chapter = new Node(chaptername);

        int sectionNum;
        cout << "Enter number of sections in " << chaptername << ": ";
        cin >> sectionNum;
        cin.ignore();

        for(int j=0; j<sectionNum; j++){
            string sectionName;
            cout << "Enter name of section " << j+1 << " : ";
            getline(cin, sectionName);
            Node *section = new Node(sectionName);
    
            int subsectionNum;
            cout << "Enter number of sub-sections in " << sectionName << ": ";
            cin >> subsectionNum;
            cin.ignore();

            for(int k=0; k<subsectionNum; k++){
                string subsectionName;
                cout << "Enter name of sub-section " << k+1 << " : ";
                getline(cin, subsectionName);
                Node *subsection = new Node(subsectionName);

                section->children.push_back(subsection);
            }
            chapter->children.push_back(section);
        }
        book->children.push_back(chapter);
    }

    cout << "\nTree Structure of Book:\n";
    printTree(book);
}