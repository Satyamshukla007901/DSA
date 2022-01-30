class MyCircularQueue {
public:
    int front;
    int back;
    vector<int> vp;
    int size;
    MyCircularQueue(int k) {
        size=k;
        vp.resize(k);
        front=-1;
        back=-1;
    }
    
    bool enQueue(int value) {
        if(isFull())
                return false;
        if(isEmpty())
        {
            front++;
            back++;
            vp[back]=value;return true;
        }
        back=(back+1)%size;
        vp[back]=value;
        return true;
        
    }
    
    bool deQueue() {
        if(isEmpty())
                return false;
        if(front==back)
        {
            front=back=-1;
            return true;
        }
        front=(front+1)%size;
        return true;
    }
    
    int Front() {
        if(isEmpty())
                return -1;
        return vp[front];
    }
    
    int Rear() {
        if(isEmpty())
                return -1;
        return vp[back];
    }
    
    bool isEmpty() {
        if(front==-1&&back==-1)
                return true;
        return false;
    }
    
    bool isFull() {
        if((back+1)%size==front)
                return true;
        return false;
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