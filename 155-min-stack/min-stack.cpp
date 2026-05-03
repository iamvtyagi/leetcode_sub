class MinStack {
public:
    stack<int> s,ss;

    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if(ss.empty()){
            ss.push(val);
        }else{
            int a = ss.top();
            if(a >= val) ss.push(val);
        }
    }
    
    void pop() {

        if(!s.empty()){
            int val = s.top();
            s.pop();

            if(val == ss.top()){
                ss.pop();
            }
        }
        
    }
    
    int top() {
        if(s.empty()) return -1;
        return s.top();
    }
    
    int getMin() {
        if(ss.empty()) return -1;
        return ss.top();
    }
};