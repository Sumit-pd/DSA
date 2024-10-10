#include <string>
#include <algorithm>
using namespace std ;
// time complexity:O(2n)
int makeBeautiful(string arr ){
    int n = arr.size() ;
    int cnt1 = 0 ;
    int cnt2 = 0 ;
    char prev = '0';
    for (int i = 0; i < n; i++)
    {
        if(arr[i] != prev){
            cnt1++ ;
        }

        prev = prev == '0' ? '1' : '0' ;
    }

    prev = '1' ;
    for (int i = 0; i < n; i++)
    {
        if(arr[i] != prev){
            cnt2++ ;
        }

        prev = prev == '0' ? '1' : '0' ;
    }

    return min(cnt1, cnt2);
}

// better 
// time complexity:O(n)
int makeBeautiful2(string arr ){
     int n = arr.size() ;
    int cnt1 = 0 ;
    int cnt2 = 0 ;
    char prev = '0';
    for (int i = 0; i < n; i++)
    {
        if(arr[i] != prev){
            cnt1++ ;
        }

        prev = prev == '0' ? '1' : '0' ;
    }

    cnt2 = n - cnt1 ;

    return min(cnt1, cnt2);
}



/*****************************************************LEETCODE*****************************/
// whenever we see something taking first elem and attaching it to the end we attach the same string to itself

// create a copy of the string and attach it to the same string and iterate on all of the substring using the sliding window

class Solution {
public:
    int minFlips(string s) {
        int n = s.size() ;
        s = s + s ;
        string alt1 = "" ;
        string alt2 = "" ;
        for(int i = 0 ; i < s.size() ; i++ ){
            alt1 += i % 2 == 0 ? '1' : '0'; 
            alt2 += i % 2 == 0 ? '0' : '1'; 
        }
        int l = 0 ; 
        int res = s.length() ;
        int cnt1 = 0 ;
        int cnt2 = 0 ;
        for(int r = 0 ; r < s.length() ; r++ ){
            if(alt1[r] != s[r]){
                cnt1++ ;
            }
            if(alt2[r] != s[r]){
                cnt2++ ;
            }

            if(r - l +1 > n){
                if(alt1[l] != s[l]){
                    cnt1-- ;
                }
                if(alt2[l] != s[l]){
                    cnt2-- ;
                }
                l++ ;
            }
            if(r-l+1 == n){
                res = min(res,min(cnt1,cnt2)) ;
            }
        }
        return res ;
    }
};