class MyQueue {
public:
    stack<int> s;
    MyQueue() {
    }
    
    void push(int x) {
        stack<int> t;
        while(!s.empty()){
            t.push(s.top());s.pop();
        }
        s.push(x);
        while(!t.empty()){
            s.push(t.top());t.pop();
        }
    }
    
    int pop() {
        int x=s.top();
        s.pop();
        return x;
    }
    
    int peek() {
        return s.top();
    }
    
    bool empty() {
        return s.empty();
    }
};

