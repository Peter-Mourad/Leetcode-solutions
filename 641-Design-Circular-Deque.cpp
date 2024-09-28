class MyCircularDeque {
public:
    deque<int> d;
    int k;
    MyCircularDeque(int k) {
        this->k = k;
    }
    
    bool insertFront(int value) {
        if(isFull()) return false;
        d.push_front(value);
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()) return false;
        d.push_back(value);
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()) return false;
        d.pop_front();
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()) return false;
        d.pop_back();
        return true;
    }
    
    int getFront() {
        return (isEmpty() ? -1 : d.front());
    }
    
    int getRear() {
        return (isEmpty() ? -1 : d.back());
    }
    
    bool isEmpty() {
        return d.empty();
    }
    
    bool isFull() {
        return d.size()==k;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */