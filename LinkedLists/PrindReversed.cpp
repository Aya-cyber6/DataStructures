#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};
struct Node *head;

void print(struct Node *p){
    if(p == NULL){
        printf("\n");
        return;
    }
    printf("%d ", p->data);
    print(p->next);
}

void ReversePrint(struct Node *p){
    if(p == NULL){
        return;
    }
    ReversePrint(p->next);
    printf("%d ", p->data);
}

void insert(int a){

    struct Node* temp = new Node();
    temp->data = a;
    temp->next = head;
    head = temp;
}

void insertAtPos(int pos, int data){

    struct Node* temp = new Node();
    temp->data = data;

    if (pos == 1){
    temp->next = head;
    head = temp;
    return;
    }

    struct Node* prev = head;

    for (int i =0; i<pos-2; i++){
        prev = prev->next;
    }
    temp->next = prev->next;
    prev->next = temp;
}

int main(){
  
    insert(1);
    insert(15);
    insert(6);
    insert(8);
    print(head);
    insertAtPos(3, 9);
    print(head);
    ReversePrint(head);
    cout<<"Great!!!!!!!";
}