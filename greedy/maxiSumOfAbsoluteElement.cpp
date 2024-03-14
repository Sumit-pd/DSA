/*
    we will create the that permuation with the ans 
    - for doing so we will be first sorting the array
    - initialize two pointers i = 0 and the j = n - 1 
    - we will be keeping the larger element at the even indexes and the smaller element at odd index or vice versa
    - after that we will find the sum 
*/


//time complexity : O(nlogn) + O(n) + O(n)
// space complexity : O(n)
int maxAbsSum(vector<int> &arr, int n) 
{
    sort(arr.begin(),arr.end()) ;
    vector<int> temp(n) ;
    int cnt = 0 ; 
    int i = 0 ; 
    int j = n - 1 ;
    while(i <= j ){
        if(cnt % 2 == 0 ){
            temp[cnt] = arr[i] ;
            i++ ;
            cnt++ ;
        }
        else{
            temp[cnt] = arr[j] ;
            j--;
            cnt++ ;
        }
    }


    int sum = 0 ; 
    for(int i = 0 ; i < n-1 ;i++ ){
        sum += abs(temp[i+1] - temp[i]) ;
    }

    sum += temp[n-1] - temp[0] ;
    return sum ;
}

//time complexity : O(NlogN) + O(n)
//time compleixty : O(1)

int maxAbsSum(vector<int> &arr, int n) {


    sort(arr.begin(),arr.end()) ;

    int i = 0 ; 
    int j = n -1 ; 

    int sum = 0 ;


    while(i < j ){
        sum += abs(arr[i] - arr[j]) ;
        sum += abs(arr[i+1] - arr[j]) ;
        i++ ;
        j-- ;
    }


    sum += abs(arr[i]-arr[0]) ;


    return sum ;

}


