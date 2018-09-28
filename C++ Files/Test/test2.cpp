#include<iostream> 
using namespace std; 
struct Node { 
    struct Node *left, *right; 
    int data; 
}; 
  
void displayCList(Node *head) { 
    cout << "Circular Linked List is :\n"; 
    Node *itr = head; 
    do{ 
        cout << itr->data <<" "; 
        itr = itr->right; 
    } while (head!=itr); 
    cout << "\n"; 
} 
  
Node *newNode(int data) { 
    Node *temp = new Node(); 
    temp->data = data; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
  
Node* bTreeToCList(Node* root){
	
}
  
int main() { 
    Node *root = newNode(10); 
    root->left = newNode(12); 
    root->right = newNode(15); 
    root->left->left = newNode(25); 
    root->left->right = newNode(30); 
    root->right->left = newNode(36); 
  
    Node *head = bTreeToCList(root); 
    displayCList(head); 
}