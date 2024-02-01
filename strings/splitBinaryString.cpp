#include <bits/stdc++.h> 
int splitString(string &str) 
{
    int oneCnt = 0 ;
    int zeroCnt = 0 ;
    int ans = 0 ;
    for(char it : str){
        if(it == '0'){
            zeroCnt++;
        }
        else{
            oneCnt++;
        }
        if(zeroCnt == oneCnt){
            ans++;
            zeroCnt = 0 ;
            oneCnt = 0 ;
        }
    }
    if(oneCnt != zeroCnt) return -1 ;
    if(ans == 0) return -1 ;
    return ans;
}