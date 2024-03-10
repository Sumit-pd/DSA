#include <bits/stdc++.h> 
bool cmp( vector<int> a , vector<int> b){
    return a[1] < b[1] ;
}
int maxStop(vector<vector<int>> &trains, int n, int m)
{
    //sorting on the basis of trains depearture time
    sort(trains.begin(),trains.end(),cmp) ;
    // array for keeping the track of the platform
    vector<pair<int,int>> platform(m+1,{-1,-1});

    int maxi = 0 ; // maximum  number of trains that can be accommodated in the platform
    for(int i = 0 ; i < n ; i++ ){
        int platformNo = trains[i][2] ;
        if(platform[platformNo].first == -1 ){
            //no trains in the platform has  been added before
            maxi++ ;
            platform[platformNo] = {trains[i][0],trains[i][1]} ; // pair of arrival time and departure time
        }
        else{
            if(platform[platformNo].second <= trains[i][0]){ // here we need to add a = this will not be the case for activity selection problem
                //the train that have arrived has left
                maxi++;
                platform[platformNo] = {trains[i][0],trains[i][1]} ;  // pair of arrival time and departure time
            }
        }
    }
    return maxi ;
}
