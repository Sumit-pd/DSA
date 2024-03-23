#include <bits/stdc++.h> 
class Stack
{
    deque<int> d ;
public:
    // Initialize your data structure.
    Stack()
    {
    }

    // Pushes 'X' into the stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x)
    {
        d.push_front(x) ;
    }

    // Pops top element from Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop()
    {
        if(d.size()){
            int front = d.front() ;
            d.pop_front() ;
            return front ;
        }
        else{
            return -1 ;
        }
    }

    // Returns the topmost element of the stack. In case the stack is empty, it returns -1.
    int top()
    {
        if(d.size()){
            return d.front() ;
        }
        return -1 ;
    }

    // Returns true if the stack is empty, otherwise false.
    bool isEmpty()
    {
        return d.size() == 0 ;
    }

    // Returns the number of elements currently present in the stack.
    int size()
    {
        return d.size() ;
    }
};
