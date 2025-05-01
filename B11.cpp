#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    string word;
    string meaning;
    Node *left;
    Node *right;

    Node()
    {
        word = "";
        meaning = "";
        left = nullptr;
        right = nullptr;
    }

    Node(string w, string m)
    {
        word = w;
        meaning = m;
        left = nullptr;
        right = nullptr;
    }
};

void insertKeyword(Node *&root, string word, string meaning)
{
    if (root == nullptr)
    {
        root = new Node(word, meaning);
        return;
    }
    if (word < root->word)
    {
        insertKeyword(root->left, word, meaning);
    }
    if (word > root->word)
    {
        insertKeyword(root->right, word, meaning);
    }
    return;
}

void deleteKeyword(Node*&root, string word){
    if(root == nullptr){
        cout << "The word does not exist";
        return;
    }

    if(word < root->word){
        deleteKeyword(root->left, word);
    }
    else if (word > root->word) {
        deleteKeyword(root->right, word);
    }
    else{
        // it is a leaf node
        if(root->left == nullptr && root->right == nullptr){
            delete root;
            return;
        }

        // it has one child
        else if(root->left != nullptr || root->right != nullptr){
            if(root->left != nullptr){
                Node* temp = root;
                root = root->right;
                delete temp;
            }
            else if(root->right != nullptr){
                Node* temp = root;
                root = root->left;
                delete temp;
            }
        }

        else{
            // it has two child
            Node* parent = root;
            Node* inorderPred = root->left;

            while(inorderPred->right != nullptr){
                parent = inorderPred;
                inorderPred = inorderPred->right;
            }

            root->word = inorderPred->word;
            root->meaning = inorderPred->meaning;

            if(parent == root)
                parent->left = inorderPred->left;
            else
                parent->right = inorderPred->left;    
            
            delete inorderPred;
            
        }
    }

}


int main()
{
    string word, meaning;
    cout << "Enter the first word and its meaning :" << endl;
    getline(cin, word);
    getline(cin, meaning);

    transform(word.begin(), word.end(), word.begin(), ::tolower);
    transform(meaning.begin(), meaning.end(), meaning.begin(), ::tolower);

    Node *root = new Node(word, meaning);

    int choice;
    do
    {
        cout << "\nDictionary Operations Menu:\n";
        cout << "1. Add a new keyword and its meaning\n";
        cout << "2. Delete a keyword\n";
        cout << "3. Update the meaning of a keyword\n";
        cout << "4. Search for a keyword\n";
        cout << "5. Display all entries in Ascending order\n";
        cout << "6. Display all entries in Descending order\n";
        cout << "7. Find maximum comparisons needed to find any keyword\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            cout << "Enter the word to insert and its meaning: ";
            getline(cin, word);
            getline(cin, meaning);
            insertKeyword(root, word, meaning);
            break;

        case 2:
            cout << "Enter the word to delete: ";
            getline(cin, word);
            deleteKeyword(root, word);
            break;
        case 3:
            // Update keyword
            break;
        case 4:
            // Search keyword
            break;
        case 5:
            // Display ascending
            break;
        case 6:
            // Display descending
            break;
        case 7:
            // Max comparisons
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 0);
}