class BitManipulation{
    public:
    int getBit(int n , int i){
        // the function to get bit at i'th position
        int mask = 1 << i ;
        if((n & mask) == 0){
            return 0 ;
        }
        else{
            return 1 ;
        }
    }

    int setBit(int n , int i ){
        // make the ith bit one
        int mask = 1 << i ;
        return n | mask ;
    }

    int toggle(int n , int i){
        int mask = 1 << i ;
        return n^mask ;
    }

    int resetBit(int n , int i){
        int mask = 1 << i ;
        return n & (~mask) ;
    }
};