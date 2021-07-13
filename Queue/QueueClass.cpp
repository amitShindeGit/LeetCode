//Not from Leetcode, just for practise
#include <iostream>
#include <stdlib.h>
using namespace std;

class Queue{
 private:
    int front;
    int rear;
    int size;
    int *Q;

 public:
    Queue(){
      front=rear=-1;
      size=10;
      Q = new int[size];
    }

    Queue(int size){
        front=rear=-1;
        this->size=size;
        Q = new int[this->size];
    }

    void enqueue(int x);
    int dequeue();
    void Display();
};

void Queue::enqueue(int x){
  if(rear == size-1 ){
    cout << "Queue full, can't enqueue";
  }else{
    rear++;
    Q[rear] = x;
  }
}

int Queue::dequeue(){
  int x = -1;
  if(front == rear){
    cout << "Queue is empty already,can't dequeue" << endl;
  }else{
    x = Q[front+1];
    for(int i=front+1; i<=rear;i++){
        Q[i] = Q[i+1];
    }

    rear--;
  }

  return x;
}

void Queue::Display(){
    if(front == -1 && rear == -1){
        cout <<"Queue empty, nothing to display." << endl;
        return;
    }
  for(int i=front+1; i<=rear; i++){
    cout << Q[i] << " ";
  }
}

int main(){
 int sizeQ;
 cout << "Enter size of Queue : ";
 cin >> sizeQ;
 Queue q(sizeQ);
 int choice;

 do{
        cout<<"Enter choice"<<endl;
        cout<<"1.)Enqueue ?" <<endl;
        cout<<"2.)Dequeue ?" <<endl;
        cout<<"3.)Display ?" <<endl;
        cout << "4.) Exit ?" <<endl;
        cout << "Enter Choice : ";
        cin >> choice;
     switch(choice){
         case 1:
             int data;
             cout << "Enter any number to Enqueue : ";
             cin >> data;
             q.enqueue(data);
             break;

         case 2:{
             int deletedData = q.dequeue();
             if(deletedData != -1){
              cout << deletedData << " deleted" << endl;
             }
             break;
         }

         case 3:{
             cout << endl;
             cout << "Queue : Front->| ";
             q.Display();
             cout << " |<-Rear" ;
             cout<<endl << endl;
             break;
         }

         case 4:{
            cout<< "BYE" <<endl;
            break;
         }

          default:
            cout << endl << "Err something went wrong!";
            break;
     }
 }while(choice != 4);

}
