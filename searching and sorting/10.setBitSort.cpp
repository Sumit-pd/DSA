//count of set bit is the number of 1's in the binary representation of the a number
//return in the decreasing order of the set bit
//if the set bit is equal then the sort will be in normal mannar
#include <bits/stdc++.h> 
using namespace std ;
int countSetBits(int n){
    int cnt = 0 ;
    while(n != 0 ){
        int digit = n % 2 ;
        if(digit == 1 ){
            cnt++;
        }
        n = n >> 1 ;
    }
    return cnt ;

}
bool cmp(int p1 , int p2){
    if(countSetBits(p1) > countSetBits(p2)){
        return true ;
    }
    return false;
}
void sortSetBitsCount(vector<int>& arr, int n)
{
	stable_sort(arr.begin(),arr.end(),cmp);
}



// time complexity
int coutnBitSet(int n){
    int cnt = 0 ;
    while(n != 0 ){
        int digit = n % 2 ;
        if(digit==1){
            cnt++;
        }
        n = n/2;
    }
    return cnt;
}
void sortSetBitsCount(vector<int>& arr, int size)
{
	unordered_map<int,vector<int>> mp ;
    int maxi = INT_MIN ;
    int mini = INT_MAX ;
    for(auto it : arr ){
        int bitSet = coutnBitSet(it) ;
        mp[bitSet].push_back(it) ;
        //here we are storing all the element with bitset number of setbits
        maxi = max(maxi,bitSet);
        mini = min(mini,bitSet);

    }
    int ind = 0 ;
    for(int i = maxi ; i >= mini ; i-- )
    {
        if(mp[i].size()){
            for(auto it : mp[i]){
                arr[ind] = it ;
                ind++;
            }
        }
    }
}