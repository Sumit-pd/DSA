//brute : linerar search 
int search(int arr[], int n, int x, int k)
{
    for(int i = 0 ; i < n ; i++ ){
        if(arr[i] == x ){
            return i ;
        }
    }
    return -1 ;
}  

int search(int arr[], int n, int x, int k)
{
    int i = 0 ;
    while(i < n ){
        if(arr[i] == x ){
            return i ;
        }
        int steps = abs(arr[i]-x) / k ; // here the arr[i] is the element of the array and x is the target and k is the difference
        //moving at max k steps
        steps = max(steps,1); // there will be case when the value of k will be 0 which will be resulting in infinite loop
        i += steps;
    }
    return -1 ;
}   