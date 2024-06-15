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
