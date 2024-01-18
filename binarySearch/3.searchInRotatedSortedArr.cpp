//brute 
//linear search


//Optimal 
//Binary Search
int search(vector<int>& arr, int n, int k)
{
    int low = 0 ;
    int high = n -1 ;
    while(low <= high ){
        int mid = (low+high)/2 ;
        if(arr[mid] == k ){
            return mid ;
        }
        else{
            //checking if the left part is sorted or not
            if(arr[low] <= arr[mid] ){
                //this is sorted 
                //now checking if k lies within the range
                if(k >= arr[low] && k < arr[mid]){
                    high = mid - 1 ;
                }
                else{
                    low = mid + 1 ;
                }
            }
            else{
                if(k >= arr[mid] && k <= arr[high]){
                    low = mid + 1 ;
                }
                else{
                    high = mid -1 ;
                }
            }
        }
    }
    return -1 ;
}

