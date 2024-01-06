class MyStack {
private:
    queue<int> q1;
    queue<int> q2;

public:
    MyStack() {
        // Constructor
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        int ans = q1.front();
        q1.pop();
        std::swap(q1, q2);  // Swap the queues
        
        return ans;
    }
    
    int top() {
        int tmp = pop();
        q1.push(tmp);
        return tmp;
    }
    
    bool empty() {
        return q1.empty();
    }
};


/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */