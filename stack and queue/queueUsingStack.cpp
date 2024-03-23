class Queue {
    stack<int> st1 ;
    stack<int> st2 ;
    int capacity ;
    
    public:
    Queue() {
        capacity = 0 ;
    }

    void enQueue(int val) {
        st1.push(val) ;
        capacity++ ;
    }

    int deQueue() {
        if(capacity == 0 ){
            return -1 ;
        }

        else{
            if( st2.size() ){
                int top = st2.top() ;
                st2.pop() ;
                capacity--;
                return top ;
            }
            else{
                while(st1.size()){
                    st2.push(st1.top()) ;
                    st1.pop() ;
                }
                int top = st2.top() ;
                st2.pop() ;
                capacity--;
                return top ;
            }
        }
    }

    int peek() {
        if(capacity == 0 ){
            return -1 ;
        }
        else{
            if(st2.size()){
                return st2.top() ;
            }
            else{
                while(st1.size()){
                    st2.push(st1.top()) ;
                    st1.pop() ;
                }
                return st2.top() ;
            }
        }
    }

    bool isEmpty() {
        return capacity == 0 ;
    }
};