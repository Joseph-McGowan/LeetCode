//
// Created by joseph on 03/06/2024.
//
#include "vector"
#include "unordered_map"
#include "stack"

using namespace std;

class MinStack {
public:

    stack<int> s;
    int counter ;
    int minVal;
    stack<int> minAt;

    MinStack() {
        counter = 0;
        //return {s, counter};
    }

    void push(int val) {
        s.push(val);
        if (val < minVal || counter == 0)
            minVal = val;
        minAt.push(minVal);
        counter++;
    }

    void pop() {
        if (s.empty())
            return;

        s.pop();
        minAt.pop();
        minVal = minAt.top();
    }

    int top() {
        if(s.empty())
            return 0;
        return s.top();
    }

    int getMin() {
        return minVal;
    }
};

int main()
{
    MinStack minStack = *new MinStack();
    minStack.push(2147483646);
    minStack.push(2147483646);
    minStack.push(2147483647);
    minStack.getMin(); // return -3
    minStack.pop();
    minStack.top();    // return 0
    minStack.getMin(); // return -2
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

[[],[2147483646],[2147483646],[2147483647],[],[],[],[],[],[],[2147483647],[],[],[-2147483648],[],[],[],[]]