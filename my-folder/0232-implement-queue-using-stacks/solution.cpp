class MyQueue {
    stack<int> st1;
    stack<int> st2;
public:
    MyQueue() {

    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        if(!st2.empty()) {
            int ans = st2.top();
            st2.pop();
            return ans;
        } else {
            while(!st1.empty()) {
                int temp = st1.top();
                st2.push(temp);
                st1.pop();
            }
            int ans = st2.top();
            st2.pop();
            return ans;
        }
    }
    
    int peek() {
        if(!st2.empty()) {
            return st2.top();
        } else {
            while(!st1.empty()) {
                int temp = st1.top();
                st2.push(temp);
                st1.pop();
            }
            return st2.top();
        }
    }
    
    bool empty() {
        if(!st2.empty()) 
            return st2.empty();
        else
            return st1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
