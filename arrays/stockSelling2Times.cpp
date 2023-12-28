int maxProfit(vector<int>& prices)
{
    int n = prices.size() ;
    vector<int> profit(n,0) ;
    int maxPrice = prices[n-1] ;
    for(int i = n-2 ; i >= 0 ; i-- ){
        if(prices[i] > maxPrice){
            //checking if the array got any higher price
            //this idea is to sell at the maximum price
            maxPrice = prices[i];
        }
        profit[i] = max(profit[i+1],maxPrice - prices[i]) ;
    }

    int minPrice = prices[0] ;
    for(int i = 1 ; i < n ; i++ ){
        if(prices[i] < minPrice){
            //checking if the array got any lower price 
            //the idea to is to buy at the lowest price
            minPrice = prices[i] ;
        }
        profit[i] = max(profit[i-1],profit[i] +( prices[i] - minPrice));
    }
    return profit[n-1] ;
}
