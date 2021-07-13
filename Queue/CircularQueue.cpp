class MyCircularQueue {
public:
    int rear, front, *Q, size;
    MyCircularQueue(int k) {
        rear = 0;
        size = k+1;
        front = 0;
        Q = new int[size];
    }
    
    bool enQueue(int value) {
        if((rear+1) % size == front){
            return false;
        }else{
            rear = (rear+1) % size;
            Q[rear] = value;
            return true;
        }
    }
    
    bool deQueue() {
        if((front == rear)){
            return false;
        }else{
            front = (front+1) % size;
            return true;
            
        }
    }
    
    int Front() {
        if(front == rear){
            return -1;
        }
        return Q[front+1];
    }
    
    int Rear() {
        if(front == rear){
            return -1;
        }
        return Q[rear];
    }
    
    bool isEmpty() {
        if(front == rear){
            return true;
        }else{
            return false;
        }
    }
    
    bool isFull() {
        if((rear+1) % size == front){
            return true;
        }else{
            return false;
        }
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */