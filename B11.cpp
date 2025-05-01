#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        string word;
        string meaning;
        Node *left;
        Node *right;

        Node(){
            word = "";
            meaning = "";
            left = nullptr;
            right = nullptr;
        }

        Node(string w, string m){
            word = w;
            meaning = m;
            left = nullptr;
            right = nullptr;
        }
};

void insertKeyword(Node *&root, string word, string meaning){
    if (root == nullptr){
        root = new Node(word, meaning);
        return;
    }
    if (word < root->word){
        insertKeyword(root->left, word, meaning);
    }
    if (word > root->word){
        insertKeyword(root->right, word, meaning);
    }
    return;
}

void deleteKeyword(Node *&root, string word){
    if (root == nullptr){
        cout << "The word does not exist" << endl;
        return;
    }

    if (word < root->word){
        deleteKeyword(root->left, word);
    }
    else if (word > root->word){
        deleteKeyword(root->right, word);
    }
    else{
        // it is a leaf node
        if (root->left == nullptr && root->right == nullptr){
            delete root;
            return;
        }
        // it has one child
        else if (root->left != nullptr || root->right != nullptr){
            if (root->left != nullptr){
                Node *temp = root;
                root = root->right;
                delete temp;
            }
            else if (root->right != nullptr){
                Node *temp = root;
                root = root->left;
                delete temp;
            }
        }
        else{
            // it has two children
            Node *parent = root;
            Node *inorderPred = root->left;

            while (inorderPred->right != nullptr){
                parent = inorderPred;
                inorderPred = inorderPred->right;
            }

            root->word = inorderPred->word;
            root->meaning = inorderPred->meaning;

            if (parent == root)
                parent->left = inorderPred->left;
            else
                parent->right = inorderPred->left;

            delete inorderPred;
        }
    }
}

void updateKeyword(Node *&root, string word, string newMeaning){
    if (root == nullptr){
        cout << "Word does not exist!!" << endl;
        return;
    }

    if (root->word == word){
        root->meaning = newMeaning;
        cout << "Word meaning updated" << endl;
        return;
    }
    if (root->word < word){
        updateKeyword(root->right, word, newMeaning);
    }
    else{
        updateKeyword(root->left, word, newMeaning);
    }
}

void searchKeyword(Node *&root, string word){
    if (root == nullptr){
        cout << "Word does not exist!!" << endl;
        return;
    }

    if (root->word == word){
        cout << "The meaning of '" << word << "' is: " << root->meaning << endl;
        return;
    }
    if (root->word < word){
        searchKeyword(root->right, word);
    }
    else{
        searchKeyword(root->left, word);
    }
}

void inorder(Node *&root){
    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->word << ": " << root->meaning << endl;
    inorder(root->right);
}

void reverseInorder(Node *&root){
    if (root == nullptr)
        return;

    reverseInorder(root->right);
    cout << root->word << ": " << root->meaning << endl;
    reverseInorder(root->left);
}

int maxComparisions(Node *&root){
    if (root == nullptr)
        return 0;
    return 1 + max(maxComparisions(root->left), maxComparisions(root->right));
}

int main(){
    string word, meaning;
    cout << "Enter the first word and its meaning: " << endl;
    getline(cin, word);
    getline(cin, meaning);

    transform(word.begin(), word.end(), word.begin(), ::tolower);
    transform(meaning.begin(), meaning.end(), meaning.begin(), ::tolower);

    Node *root = new Node(word, meaning);

    int choice;
    do{
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

        switch (choice){
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
            cout << "Enter the word whose meaning is to be updated: ";
            getline(cin, word);
            cout << "Enter the new meaning: ";
            getline(cin, meaning);
            updateKeyword(root, word, meaning);
            break;
        case 4:
            cout << "Enter the word to be searched: ";
            getline(cin, word);
            searchKeyword(root, word);
            break;
        case 5:
            cout << "Entries in Ascending order: \n";
            inorder(root);
            break;
        case 6:
            cout << "Entries in Descending order: \n";
            reverseInorder(root);
            break;
        case 7:
            cout << "The maximum comparisons to find any element is: " << maxComparisions(root) << endl;
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 0);
}