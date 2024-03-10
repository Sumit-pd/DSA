#include <bits/stdc++.h> 
class Data{
    public:
    int weights ;
    int values ;
    double ratio ;
};

bool cmp(Data a , Data b){
    return a.ratio > b.ratio ;
}

double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    double ans = 0 ;
    Data arr[n] ;
    for(int i = 0 ; i < n ; i++ ){
        arr[i].weights = items[i].first ;
        arr[i].values = items[i].second;
        double ratio = (double)items[i].second / (double)items[i].first ;
        arr[i].ratio = ratio ;
    }

    sort(arr,arr+n,cmp) ;
    for(auto it : arr){
        if(it.weights < w ){
            ans += it.values ;
            w -= it.weights ;
        }
        else{
            ans += w * it.ratio ;
            w = 0 ;
            break;
        }
    }
   return ans ;
}

