class MyCircularQueue{
private:
    vector <int> cq;
    int head;
    int tail;
    int size;
public:
    MyCircularQueue(int k){
        head=-1;
        tail=-1;
        size = k;
        cq.resize(k);
    }

    bool enQueue(int val){
        if (isFull()) return false;


        if (isEmpty()) head=0;
        tail = (tail+1 )%size;
        cq[tail] = val;
        return true;
    }


    bool deQueue(){
        if (isEmpty()) return false;

        else{
            if ( head == tail) head = tail = -1;
            else head = (head+1) % size;
            return true;
        }
    }

    int Front(){
        if(!isEmpty()) return cq[head];
        else return -1;
    }

    int Rear(){
        if(!isEmpty()) return cq[tail];
        else return -1;
    }

    bool isEmpty(){
        return (head==-1);
    }

    bool isFull(){
        return (((tail+1)%size) == head);
    }
};
