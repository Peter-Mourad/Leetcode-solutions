class CustomStack {
public:
    vector<int> s;
    int p, n;
    CustomStack(int maxSize) {
        s = vector<int> (maxSize,0);
        p = 0, n = maxSize;
    }
    
    void push(int x) {
        if(p!=n)
            s[p++] = x;
    }
    
    int pop() {
        return (!p) ? -1 : s[--p];
    }
    
    void increment(int k, int val) {
        for(int i = 0;i < min(p, k);i++)
            s[i] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */