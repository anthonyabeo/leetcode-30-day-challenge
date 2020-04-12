#include <stack>

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack(): mainStack{}, minStack{} {}
    
    void push(int x) {
        mainStack.push(x);
        
        if(!minStack.empty()) {
            if(x < minStack.top())
                minStack.push(x);
            else
                minStack.push(minStack.top());
        }
        else
            minStack.push(x);
        
    }
    
    void pop() {
        mainStack.pop();
        minStack.pop();
    }
    
    int top() {
        return mainStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
private:
    std::stack<int> mainStack;
    std::stack<int> minStack;
};
