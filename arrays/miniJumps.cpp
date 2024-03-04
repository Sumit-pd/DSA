class Solution{
  public:
    int minJumps(int arr[], int n){
        int maxReach = 0 ; // this will be the max reach 
        int lastJump = 0 ; // this will be the place 
        int jumps = 0;
        if(n == 1 ){
            return 0 ;
        }
        if(arr[0] == 0 ){
            return -1 ;
        }
        for(int i = 0 ; i < n ; i++ ){
            if(i > maxReach){
                return -1 ;
            }
            maxReach = max(maxReach , i + arr[i] );
            if(lastJump == i ){
                lastJump = maxReach ;
                jumps++ ;
                if(maxReach >= n -1 ){
                return jumps ;
            }
            }
            
        }
        return jumps ;
    }
};