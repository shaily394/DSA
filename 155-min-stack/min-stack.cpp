class MinStack {
public:
    stack <long long> st;
    long long mini =INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            mini = val;
            st.push(val);
        }
        else{
            if(val> mini) st.push(val);
            else{
                st.push(2LL*val - mini);
                mini = val;
            }
        }
    }
    
    void pop() {
        long long n = st.top();
        st.pop();
        if(n<mini) mini = 2LL*mini - n;
    }
    
    int top() {
        long long n = st.top();
        if(mini < n) return n;
        else return mini;
    }
    
    int getMin() {
        return mini;
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