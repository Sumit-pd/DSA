#include<bits/stdc++.h>
int calculateMinPatforms(int at[], int dt[], int n) {
    sort(at,at+n) ;
    sort(dt,dt+n) ;
    int ans = 1 ;
    int occupied = 1 ;
    int i = 1 ;
    int j = 0 ;
    while(i < n){
        if(at[i] > dt[j]){
            //train departed and freed a platform
            occupied--;
            j++;
        }
        else{
            //train arrived and occupied a platform
            occupied++;
            ans = max(ans,occupied) ;
            i++;
        }
    }
    return ans ;
    
}