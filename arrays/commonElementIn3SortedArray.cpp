#include <bits/stdc++.h> 
//close to optimal
vector<int> findCommonElements(vector<int> &a, vector<int> &b, vector<int> &c)
{
    vector<int> ans ;
    unordered_map<int,int> mp ;
    for(int it : a){
        if(mp[it] < 1){
            mp[it]++ ;
        }
    }
    for(int it : b ){
        if(mp[it] == 1){
            mp[it]++ ;
        }
    }
    for(int it : c ){
        if(mp[it] == 2 ){
            mp[it]++ ;
            ans.push_back(it) ;
        }
    }

    return ans ;
}

vector<int> findCommonElements(vector<int> &a, vector<int> &b, vector<int> &c)
{
    int i = 0 ;
    int j = 0 ;
    int k = 0 ;
    int n1 = a.size();
    int n2 = b.size();
    int n3 = c.size();
    vector<int> v ;
    while (i < n1 && j < n2 && k < n3)
    {
        if(a[i] == b[j] && b[j] == c[k]){
            int temp = a[i];
            v.push_back(temp);
            i++ ;
            j++;
            k++;
            while(a[i] == b[j] && b[j] == c[k] && temp == a[i]){
                i++;
                j++;
                k++;
            }
        }
        else if(a[i] < b[j]){
            i++;
        }
        else if(b[j] < c[k]){
            j++;
        }
        else{
            k++;
        }
    }
    return v;
    
}