void merge(vector<int> &arr,int low ,int mid ,int high){
    vector<int> temp ;
    int i = low ;
    int j = mid + 1 ;
    while(i <= mid && j <= high ){
        if(arr[i] < arr[j]){
            temp.push_back(arr[i]) ;
            i++ ;
        }
        else{
            temp.push_back(arr[j]) ;
            j++;
        }
    }
    while(i <= mid){
        temp.push_back(arr[i]) ;
        i++ ;
    }
    while(j <= high){
        temp.push_back(arr[j]);
        j++ ;
    }

    int k = 0 ;
    for(int i = low ; i <= high ; i++ ){
        arr[i] = temp[k] ;
        k++ ;
    }
}
void mergeSortHelper(vector<int> &arr , int low , int high ){
    if(low >= high){
        return ; //when the element is single then it is sorted
    }
    int mid = (low + high) /2 ;
    mergeSortHelper(arr,low,mid) ;
    mergeSortHelper(arr,mid+1,high) ;
    merge(arr,low,mid,high) ;
}
void mergeSort(vector < int > & arr, int n) {
    mergeSortHelper(arr,0,n-1);
}
