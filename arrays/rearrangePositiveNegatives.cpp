#include <bits/stdc++.h> 

void posAndNeg(vector<int> &arr)
//brute 
{
    vector<int> positive ;
    vector<int> negative ;
    for(int it : arr){
        if(it < 0){
            negative.push_back(it) ;
        }
        else{
            positive.push_back(it) ;
        }
    }

    for(int i = 0 ; i < arr.size()/2 ; i++ ){
        arr[2 * i] = positive[i] ;
        arr[2 * i + 1] = negative[i] ;
    }
}

//better

void posAndNeg(vector<int> &arr)
{
    vector<int> ans(arr.size()) ;
    int pos = 0 ;
    int neg = 1 ;
    for(int i = 0 ; i < arr.size() ; i++ ){
        if(arr[i] >= 0){//positive
            ans[pos] = arr[i];
            pos += 2 ;
        }
        else{
            ans[neg] = arr[i] ;
            neg += 2 ;
        }
    }
    for(int i = 0 ; i < arr.size() ; i++ ){
        arr[i] = ans[i] ;
    }
    
}
