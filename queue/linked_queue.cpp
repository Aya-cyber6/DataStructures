#include <iostream>
using namespace std;

class QNode{
    public:
    int data;
    QNode* next;

    QNode(int new_data){
        this->data = new_data;
        this->next = nullptr;
    }
};


class Queue{
  public:
    QNode *front, *rear;

     Queue() {  // Constructor to initialize front and rear
        front = rear = nullptr;
     }    

    bool isEmpty(){
        return front == nullptr;
    }

    void enqueue(int new_data){
        QNode* new_node = new QNode(new_data);
        
        if(this->isEmpty()){
            rear = front = new_node;
            return;
        }
        rear->next = new_node; // Add the new node at the end of the queue and change rear
        rear = new_node;
    }

    void dequeue(){

        if(this->isEmpty()){
           printf("Queue Underflow\n");
            return;
        }
        QNode *temp = front;
        front = front->next;

        if (front == nullptr){
            rear = nullptr;
        }
        delete temp;
    }

    int getFront(){
        if(isEmpty()){
             printf("Queue is empty\n");
            return 0;
        }
        else{
            return front->data ;
        }
    }

        int getRear(){
        if(isEmpty()){
            printf("Queue is empty\n");
            return 0;
        }
        else{
            return rear->data ;
        }
    }
};

int main(){
    Queue q;

    q.enqueue(56);
    q.enqueue(46);

      // Display the front and rear elements of the queue
    cout << "Queue Front: " << q.getFront() << endl;
    cout << "Queue Rear: " << q.getRear() << endl;

    // Dequeue elements from the queue
    q.dequeue();
    q.dequeue();

    // Enqueue more elements into the queue
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    // Dequeue an element from the queue
    q.dequeue();

    // Display the front and rear elements of the queue
    cout << "Queue Front: " << q.getFront() << endl;
    cout << "Queue Rear: " << q.getRear() << endl << endl;

    return 0;
}