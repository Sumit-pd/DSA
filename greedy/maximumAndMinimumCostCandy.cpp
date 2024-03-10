// Function to calculate minimum cost.
#include<algorithm>
long long minimumCost(vector<int> &cost, int n, int k)
{
    sort(cost.begin(),cost.end()) ;
    int buy = 0 ;
    int free = n -1 ;
    long long mini = 0 ;
    while(buy <= free){
        mini += cost[buy] ;
        //one bought k free
        buy++;

        free -= k ;
    }
    return mini ;
}

// Function to calculate maximum cost.
long long maximumCost(vector<int> &cost, int n, int k)
{
    sort(cost.begin(),cost.end()) ;
    int buy = n-1 ;
    int free = 0 ;
    long long maxi = 0 ;
    while(buy >= free){
        maxi += cost[buy] ;
        //one bought k free
        buy--;

        free += k ;
    }
    return maxi ;
}
