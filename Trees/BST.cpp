#include<iostream>
using namespace std;

struct BSTnode{
    int data;
    BSTnode *right;
    BSTnode *left;
};
    BSTnode* root = NULL;
           ////////STILL WORKING ON THIS/////////
/* void insert(int a){
    struct BSTnode* newNode = new BSTnode();
        if(root == NULL){
            newNode->data = a;
            root = newNode;
            return;
        }
        BSTnode *current = root;
        while (a >= current->data){
            if (current->right != NULL){
                current = current->right;
            }
          }

        while (a <= current->data){
            if (current->left != NULL){
                current = current->left;
            }
                newNode = current->left;
                newNode->data = a;
                newNode->left, newNode->right = NULL;
          }
} */

BSTnode* RecursionInsert(BSTnode* root, int data){
    if(root == NULL){ // tree is empty
        root = new BSTnode();
        root->data = data;
    }
    else if (data <= root->data){
            root->left = RecursionInsert(root->left, data);
    }
    else if (data >= root->data){
            root->right = RecursionInsert(root->right, data);
    }
    return root;
}

bool search(BSTnode* root, int data){
    if(root == NULL) return false;
    else if(root->data == data) return true;
    else if(root->data <= data) return search(root->right, data);
    else return search(root->left, data);
}

int main(){
    root = RecursionInsert(root, 5);
    root = RecursionInsert(root, 4);
    root = RecursionInsert(root, 8);
    
    if (search(root, 7)== true){
        cout<< "FOUND!";
    }
     else{
        cout<< "NOT FOUND!";
     }
}