#include <bits/stdc++.h>
using namespace std;

class Node{
  public:
    int data;
    Node* next;

    Node(int new_data){
        this->data = new_data;
        this->next = nullptr;
    }
};

class Stack{
    // head of the linked list
    Node* head;
public:    
    // Constructor to initialize the stack
    Stack() {this->head = nullptr;}

    bool isempty(){
        return head == nullptr;
    }


    void push(int new_data){
        Node* new_node = new Node(new_data);
           // Check if memory allocation for the new node
        // failed
        if (!new_node){
            printf("stack overflow");
        }
        new_node->next = head;
        head = new_node;
    }

    void pop(){
          // Check for stack underflow
          if (isempty()){
            printf("Stack is empty");
          }
          else{
        Node* temp = head;
        head = head->next;
        delete temp;
    }
  }  
        // Function to return the top element of the stack
    int peek() {

        // If stack is not empty, return the top element
        if (!isempty())
            return head->data;
        else {
            cout << "\nStack is empty";
            return INT_MIN;
        }
    }
};

int main(){
    Stack st;
    st.push(5);
    st.push(6);
    st.push(7);
    st.push(8);

       // Print top element of the stack
    cout << "Top element is " << st.peek() << endl;

    printf("Poping off some elements\n");
    st.pop();
    st.pop();
    
    cout << "Top element is " << st.peek() << endl;



}