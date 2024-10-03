#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;            // Node's data
    struct node *next;   // Pointer to the next node
    struct node *prev;   // Pointer to the previous node
};

struct node *head = NULL;  // Points to the first node
struct node *last = NULL;  // Points to the last node

// Function to print the list
void printList(){
    struct node *p = head;
    cout << "\n[";
    while (p != NULL)  // Traverse through the list
    {
        cout << " " << p->data << " ";  // Print node's data
        p = p->next;  // Move to the next node
    }
    cout << "]";
}

// Check if the list is empty
bool isEmpty(){
    return head == NULL;  // Return true if head is NULL
}

// Insert a new node at the beginning of the list
void insertFirst(int data){
    struct node *lk = (struct node*) malloc(sizeof(struct node));  // Allocate memory for a new node
    lk->data = data;  // Set the data for the new node

    if (isEmpty()){  
        last = lk;        // Last should point to the only node as well
    }
    else{
        head->prev = lk;  // Link current head's previous to the new node
    }
    lk->next = head;  // New node's next is the current head
    head = lk;  // Update head to the new node
}
void insertLast(int data){
    struct node *link = (struct node*) malloc(sizeof(struct node));
    link->data = data;

    if (isEmpty()){
        last = link;
    }
    else{
        last->next = link;
        link->prev = last;
    }
    last = link;
    last->next = NULL;
}


/* //insert link at the last location
void insertLast(int data){

   //create a link
   struct node *link = (struct node*) malloc(sizeof(struct node));
   link->data = data;

   if(isEmpty()) {
      //make it the last link
      last = link;
   } else {

      //make link a new last link
      last->next = link;

      //mark old last node as prev of new link
      link->prev = last;
   }

   //point last to new last node
   last = link;
   last->next = NULL;
} */
struct node* deleteFirst(){

       if (isEmpty()) {  // Check if the list is empty
        cout << "List is empty, nothing to delete.\n";
        return NULL;
    }

    struct node *templink = head;

    if(head->next == NULL){   //if only one link
        last = NULL;
    }
    else{
       head->next->prev = NULL;
    }
    head = head->next;
    free(templink);  // Free memory to avoid memory leaks

    return templink;
}

struct node* deleteLast(){
    struct node *templink = head;
    if (head->next == NULL){
        last = NULL;
    }
    else{
        last->prev->next = NULL;
    }
    last = last->prev;
    return templink;
}

struct node* deleteNode(int data){
    struct node *ptr = head;

    if (head->data == data){
       return deleteFirst();
    }
    else if (last->data == data){
       return deleteLast();
    }
        while(ptr != NULL){

            if (ptr->data == data ){
                ptr == NULL;
                ptr->prev->next = ptr->next;
                ptr->next->prev = ptr->prev;
            }
            ptr = ptr->next;
        }
        return ptr;
}
bool insertAfter(int data, int newdata){
    struct node *tempLink = head;

    while (tempLink->data != data){
        if(tempLink->next == NULL){
            return false;
        } else{
            tempLink = tempLink->next;
        }
    }

    struct node *newLink = (struct node*) malloc(sizeof(struct node));   
        newLink->data = newdata;

        if(tempLink == last){
            newLink->next = NULL;
            last = newLink;
        }
        else{
            newLink->next = tempLink->next;
            tempLink->next->prev = newLink;   
        }
        newLink->prev = tempLink;
        tempLink->next = newLink;
        return true;
}

/*     if (isEmpty()){ // if list is empty 
        return false;
    }
    struct node *ptr = head;

    while (ptr->next != NULL){
        if (ptr == last){
            insertLast(newdata);
        }

        else if (ptr->data == data){
            struct node *newLink = (struct node*) malloc(sizeof(struct node));
            newLink->data = newdata;
            
            newLink->next = ptr->next;
            ptr->next->prev = newLink;
            return true;
        }
        ptr = ptr->next;

    }
    return false; */

int main(){
  insertFirst(10);
   insertFirst(20);
   insertFirst(30);
   insertFirst(1);
   insertLast(4);
   printf("Doubly Linked List: ");
   printList();
   insertAfter(4, 70);
   deleteNode(30);
  /*  deleteFirst(); */
   printList();
   return 0;
}
