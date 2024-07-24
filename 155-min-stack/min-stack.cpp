class MinStack {
private:
    stack<pair<int,int>> st;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        int min_val;
        if(st.empty()){
            min_val=val;
        }
        else{
            min_val=min(st.top().second,val);
        }
        st.push({val,min_val});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
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