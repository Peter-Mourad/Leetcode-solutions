class MinStack {
public:
    vector<int> mins;
    stack<int> st;
    MinStack() {
        mins.push_back(INT_MAX);
    }
    
    void push(int val) {
        st.push(val);
        if(val <= mins.back())
            mins.push_back(val);
    }
    
    void pop() {
        if(mins.back()==st.top()) mins.pop_back();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mins.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */