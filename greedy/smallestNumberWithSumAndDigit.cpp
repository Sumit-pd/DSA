#include <bits/stdc++.h> 
string smallestNumber(int digits, int sum)
{
	if(9 * digits < sum){
        return "-1" ;
    }
    if(sum == 0  ){
        if( digits == 1) {
            return "0" ;
        }
        else{
            return "-1";
        }
    }


    string ans = "" ;

    sum-- ;
    while(digits > 1){
        if(sum > 9 ){
            ans = '9' + ans   ;
            sum -= 9 ;
            digits-- ;
        }
        else{
            ans = to_string(sum) + ans ;
            sum = 0 ;
            digits-- ;
        }
    }
    sum++ ;
    ans = to_string(sum) + ans ;

    return ans ;
}
