vector<int> MinimumCoins(int n)
{
    vector<int> coinList ;
    while(n != 0 ){
        if(n >= 1000 ){
            coinList.push_back(1000) ;
            n -= 1000 ;
        }
        else if(n >= 500 ){
            coinList.push_back(500) ;
            n -= 500 ;
        }
        else if(n >= 100 ){
            coinList.push_back(100) ;
            n -= 100 ;
        }
        else if(n >= 50 ){
            coinList.push_back(50) ;
            n -= 50 ;
        }
        else if(n >= 20 ){
            coinList.push_back(20) ;
            n -= 20 ;
        }
        else if(n >= 10 ){
            coinList.push_back(10) ;
            n -= 10 ;
        }
        else if(n >= 5 ){
            coinList.push_back(5) ;
            n -= 5 ;
        }
        else if(n >= 2 ){
            coinList.push_back(2) ;
            n -= 2 ;
        }
        else{
            coinList.push_back(1) ;
            n -= 1 ;
        }
    }
    return coinList ;
}



vector<int> MinimumCoins(int n)
{
    int arr[9] = {1000,500,100,50,20,10,5,2,1} ;
    int i = 0 ;
    vector<int> ans ;
    while(n > 0 ){
        if(n >= arr[i]){
            ans.push_back(arr[i]) ;
            n -= arr[i] ;
        }
        else{
            i++;
        }
    }
    return ans ;
}