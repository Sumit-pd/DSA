#include <bits/stdc++.h> 
bool isPossibleToSurvive(int n, int x, int d){
    if(d>=7){
        if(n*6 >= x * 7 ){
            return true ;
        }
        return false ;
    }
    else{
        if(n>=x){
            return true;
        }
        return false ;
    }
}


bool isPossibleToSurvive(int n, int x, int d){
    int totalFoodWeNeed = x * d ; // total food we need to survive


    int sundays = d / 7 ; // total number of sundays calculated because we can't buy on that days
    int daysWeCanBuy = d - sundays ; // days we can buys 

    int weCanBuy = daysWeCanBuy * n ; // total food we can buy


    if(weCanBuy >= totalFoodWeNeed){
        return true ;
    }
    return false ;
}
