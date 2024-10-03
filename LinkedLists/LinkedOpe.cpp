#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

struct node{
    int data;
    struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

void printlist(){
    struct node *p = head;
    cout << "\n[";

    while (p != NULL)
    {
        cout << " "<< p->data << " ";
        p = p->next;
    }
    cout << "]";    
}


void insertatbegin(int data){
    struct node *lk = (struct node*) malloc(sizeof(struct node));
    lk->data = data;
    lk->next = head;
    head = lk;
}


void deleteatspecific(int data){
    struct node *temp = head, *prev;
    if (temp != NULL && temp->data == data){
          head = temp->next;
          return;
    }

    while (temp != NULL && temp->data != data){
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL) return;

  prev->next = temp->next; 
  
}

int main(){
    insertatbegin(35);
    insertatbegin(55);
    insertatbegin(70);
    insertatbegin(88);
    
    printlist();

    deleteatspecific(88);

    printlist();
}