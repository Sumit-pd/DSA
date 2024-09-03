class Stack {
	
    queue<int> q ;

   public:
    Stack() {
        // Implement the Constructor.
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        return q.size() ;
    }

    bool isEmpty() {
        return q.size() == 0 ;
    }

    void push(int element) {
        q.push(element) ;
        int size = q.size() ;
        for(int i = 0 ; i < size ; i++ ){
            int val = q.front() ;
            q.pop() ;
            q.push(val) ;
        }
    }

    int pop() {
        if(q.size()){
            int val = q.front() ;
            q.pop() ;
            return val ;
        }
        else{
            return -1 ;
        }
    }

    int top() {
        if(q.size()){
            return q.front() ;
        }
        return -1 ;
    }
};