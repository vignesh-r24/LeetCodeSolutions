class MyCircularQueue {
private:
    vector <int> cq;
    vector <int>::iterator head;
    vector <int>::iterator tail;
    vector <int> null_q; //using null_q as a sub for null pointer

public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        cq = vector<int> (k);
        null_q = vector<int> (1);
        head=null_q.begin();
        tail=null_q.begin();

    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {

        if (isEmpty()){
            tail = head = cq.begin();
            *tail = value;
            return true;
        }

        else if (isFull()) return false;

        else if (tail==cq.end()-1){
               tail = cq.begin();
               *tail = value;
               return true;
        }

        else {
            *(++tail) = value; return true;
        }
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty()) return false;

        if (head==tail) {
            head=tail=null_q.begin();
            return true;
        }


        else{
            if (head==cq.end()-1) head = cq.begin();
            else head++;
            return true;
        }

    }

    /** Get the front item from the queue. */
    int Front() {
        if(isEmpty()) return -1;
        else return *head;
    }

    /** Get the last item from the queue. */
    int Rear() {
        if (isEmpty()) return -1;
        else return *tail;

    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        if (head==null_q.begin()) return true;
        else return false;
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        if ((tail==head-1) || ((tail==cq.end()-1) && (head==cq.begin())) ) { // can use % cq.size()
            return true;
        }
        else return false;
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
