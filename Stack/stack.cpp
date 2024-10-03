#include <iostream>
int MAXSIZE = 8;
int stack[8];
int top = -1;

int isfull(){
    if (top == MAXSIZE){
        return 1;
    }
    else {
        return 0;
    }
  }
int isEmpty(){
    if (top == -1){
        return 1;
    }
    else {
        return 0; 
    }
  }

int push(int data){
    if (!isfull()){
        top = top + 1;
        stack[top] = data;
    } else{
        printf("Stack is full \n");;
    }
    return data;
}

int pop(){
  int data;
    if (!isEmpty()){
        data = stack[top];
        top = top -1;  
        return data;
    } else{
       printf("Stack is empty\n");
    }
    return data;
}

int peek(){
   return stack[top];
}

int main(){
   int i;
   push(44);
   push(10);
   push(62);
   push(123);
   push(15);
   printf("Stack Elements: \n");

   // print stack data
   for(i = 0; i < 8; i++) {
      printf("%d ", stack[i]);
   }
   printf("\nElement at top of the stack: %d" ,peek());
   
   /*printf("Element at top of the stack: %d\n" ,peek());*/
   printf("\nElements popped: \n");

   // print stack data
   while(!isEmpty()) {
      int data = pop();
      printf("%d ",data);
   }
   return 0;
}