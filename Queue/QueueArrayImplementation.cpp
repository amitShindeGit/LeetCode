//Not from Leetcode, just for practise
#include <iostream>
#include<stdlib.h>
using namespace std;

struct Queue{
  int size;
  int front;
  int rear;
  int *Q;
};

void create(struct Queue *q, int size){
    q->size = size;
    q->front = q->rear = -1;
    q->Q = new int[q->size];
}

void enqueue(struct Queue *q, int data){
    if(q->rear == q->size-1){
        cout << "Queue is Full";
    }else{
       q->rear++;
       q->Q[q->rear] = data;
    }
}

int dequeue(struct Queue *q){
    int x = -1;
   if(q->front == q->rear){
       cout << "Queue is empty";
   }else{
      q->front++;
      x = q->Q[q->front];
   }

   return x;
}

void Display(struct Queue q){
  for(int i=q.front+1; i <= q.rear; i++){
    cout << q.Q[i]<<" ";
  }
}

int main(){
  struct Queue q;
  create(&q, 5);

  enqueue(&q, 1);
  enqueue(&q, 4);
  Display(q);

  int data = dequeue(&q);
  cout << endl << "Dequeued data : " << data << endl ;
  cout << "Queue after dequeue : ";
  Display(q);

  return 0;
}
