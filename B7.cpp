// Construct an expression tree from the given prefix expression eg. +--a*bc/def and
// traverse it using postorder traversal(non recursive) and then delete the entire tree. 

#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        char data;
        Node* left;
        Node* right;

        Node(){
            data = ' ';
            left = nullptr;
            right = nullptr;
        }
        Node(char c){
            data = c;
            left = nullptr;
            right = nullptr;
        }
};

Node* createTree(string prefixExp){
    stack <Node*> s;
    for(int i=prefixExp.length()-1; i>=0; --i){
        char c = prefixExp[i];

        if(isalpha(c) != 0){
            s.push(new Node(c));
        }
        else{
            if(s.size() < 2){
                cout << "Invalid prefix expression";
                return nullptr;
            }

            Node* rightChild = s.top();
            s.pop();
            Node* leftChild = s.top();
            s.pop();
            
            Node * newNode = new Node(c);

            newNode->left = leftChild;
            newNode->right = rightChild;
            s.push(newNode);
        }
    }

    if(s.size() != 1){
        cout << "Invalid prefix expression";
        return nullptr;
    }
    return s.top();
}

void postorderTraversal(Node*root){
    if(root == nullptr)
        return;
    
        Node*curr = root;
        stack <Node*> st;

        while(curr!=nullptr || !st.empty()){

            if(curr!=nullptr){
                st.push(curr);
                curr = curr->left;
            } // checks for left childs
            else{
                // no left tree, now chec if right tree exists
                Node*temp = st.top()->right;

                if(temp == nullptr){
                    temp = st.top();
                    st.pop();
                    cout << temp->data << " ";

                    while(!st.empty() && temp == st.top()->right){
                        temp = st.top();
                        st.pop();
                        cout << temp->data << " ";
                    }
                }
                else{
                    curr = temp;
                }
            }

        }
}

void deleteTree(Node*root){
    if(root == nullptr)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;

}

int main(){
    string prefixExp;
    cout << "Enter the prefix expression : ";
    cin >> prefixExp;
    cin.ignore();

    Node* root = createTree(prefixExp);

    if(root!= nullptr){
        cout << "Postorder traversal : " <<endl;
        postorderTraversal(root);
        deleteTree(root);
    }

}