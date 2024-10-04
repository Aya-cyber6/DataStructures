#include <iostream>
#include <string>
#define MAX 6
int intArray[MAX];
int front = 0;
int rear = -1;
int itemCount = 0;
int peek(){
   return intArray[front];
}
bool isFull(){
   return itemCount == MAX;
}
void insert(int data){
   if(!isFull()) {
    /*   if(rear == MAX-1) {   // this makes circular queue
         rear = -1;
      } */
      intArray[++rear] = data;
      itemCount++;
   }
}
int main(){
   int i;
   /* insert 5 items */
   insert(3);
   insert(5);
   insert(9);
   insert(1);
   insert(12);
   insert(15);
   printf("Queue: ");
   for(i = 0; i < MAX; i++)
      printf("%d ", intArray[i]);
   printf("\nElement at front: %d\n",peek());
}