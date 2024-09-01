#include <bits/stdc++.h>

/*
brute force
-two for loops
time complexity : O(N2)
space complexity : O(1)

*/
vector<int> findMissingRepeatingNumbers(vector<int> a)
{
    vector<int> ans;
    int n = a.size();
    int rNum, mNum;
    for (int i = 1; i <= n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (i == a[j])
            {
                cnt++;
            }
        }
        if (cnt == 2)
        {
            rNum = i;
        }
        if (cnt == 0)
        {
            mNum = i;
        }
    }
    ans.push_back(rNum);
    ans.push_back(mNum);
    return ans;
}
/*
better
-use hash array
time complexity : O(N) + O(N)
-space complexity : O(N)
*/
vector<int> findMissingRepeatingNumbers(vector<int> a)
{
    int n = a.size();
    vector<int> hashSet(n + 1, 0); // the number are from 1 to n so we need the nth index so the size will be n + 1
    for (int i = 0; i < n; i++)
    {
        hashSet[a[i]]++;
    }
    int rNum;
    int mNum;
    for (int i = 1; i <= n; i++)
    {
        if (hashSet[i] == 0)
        {
            mNum = i;
        }
        if (hashSet[i] == 2)
        {
            rNum = i;
        }
    }
    // vector<int> ans = {rNum, mNum};
    return {rNum, mNum};
}
/*
optimal 1
-maths
*/

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	long long s = 0 ;
    long long s2 = 0 ;
    long long sn = ((n+1)*n)/2 ;
    long long s2n =  ((n+1)*n*(2*n+1))/6 ;
    for(int i = 0 ; i < n ; i++ ){
        s += (long long)arr[i] ;
        s2 += (long long)arr[i] * (long long)arr[i] ;
    }

    long long first = s - sn ; // x-y
    long long second = s2 - s2n ; 
    second = second/first ; // x+y 
    long long x = (first+second)/2;//repeating number
    long long y = x - first ;//missing number
    return {(int)y,(int)x};
}

//optimal 2 
// xor
bool getBit(int n , int i){
    int mask = 1 << i ;
    if((n & mask) == 0){
        return 0 ;
    }
    else{
        return 1 ;
    }
}
pair<int,int> fund(vector<int> arr , int n){
    
    // find the xor of all the elements
    int xorAllElem = 0 ;
    for(int i = 0 ; i < n ; i++ ){
        xorAllElem ^= arr[i] ;
        xorAllElem ^= i+1 ;
    }

    // find the right most set bit
    int ind = 0 ;
    for(int i = 0 ; i < sizeof(int) * 8 ; i++ ){
        if(getBit(xorAllElem,i) == 1){
            ind = i ;
            break; 
        }
    }


    //now check the indth bit of each elem of the array
    int x = 0 ;
    int y = 0 ;
    for(int i = 0 ; i < n ; i++ ){
        if(getBit(arr[i],ind) == 0){
            x ^= arr[i] ;
        }
        else{
            y ^= arr[i] ;
        }
    }
    // do the same for numbers from 1 to n
    for(int i = 1 ; i <= n ; i++ ){
        if(getBit(i,ind) == 0 ){
            x ^= i ;
        }
        else{
            y ^= i ;
        }
    }

    // one of them is the repeating number traverse in the array and figure that out

    int repeating = -1 ;
    int missing = -1 ;

    for(auto it : arr){
        if(it == x){
            repeating = x ;
            missing = y ;
        }
        else if(it == y){
            repeating = y ;
            missing = x ;
        }
    }

    return {missing,repeating} ;

}

