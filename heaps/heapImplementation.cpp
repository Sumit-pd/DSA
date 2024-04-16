#include<bits/stdc++.h>
class minHeap
{
    int arr[200] ;
    int size = 0 ;
    void insert(int val){
        size++ ;
        int ind = size;
        arr[ind] = val ;
        while (parent > 0 )
        {
            int parent = floor(ind/2) ;
            if(arr[parent] > arr[ind]){
                swap(arr[parent],arr[ind]);
                ind = parent
            }
            else {
                break ;
            }
        }
    }
    void delete(){
        //deletion will be from the top 
        arr[1] = arr[size] ;
        size-- ;
        int ind = 1 ;
        while(ind <= size ){
            int left = 2 * i ;
            int right = 2 * i + 1 ;
            if(left < size && arr[left] < arr[ind]){
                swap(arr[left],arr[ind]) ;
                ind = left ;
            }
            else if( right < size && arr[right] < arr[ind]){
                swap(arr[right],arr[ind]) ;
                ind = right
            }
            else break ;
        }
    }
};

class maxHeap
{
    int arr[200] ;
    int size = 0 ;
    void insert(int val){
        size++ ;
        int ind = size ;
        arr[ind] = val ;
        while(ind > 0 ){
            int parent = floor(ind / 2);
            if (arr[parent] < arr[ind] )
            {
                swap(arr[parent],arr[ind]);
                ind = parent
            }
            else break;
        }
    }
    void delete(){
        //deletion will be from the end
        int ind = 1;
        arr[ind] = arr[size] ;
        size-- ;
        while (ind < size)
        {
            int left = 2 * i ;
            int right = 2 * i + 1 ;
            if(left < size && arr[ind] < arr[left ]){
                swap(arr[left],arr[ind]) ;
                ind = left ;
            }
            else if(right < size && arr[ind] < arr[right]){
                swap(arr[right],arr[ind]) ;
                ind = right
            }
            else{
                break;
            }
        }
        
    }
}