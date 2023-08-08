int findNcr(int n, int r)
{
    int ans = 1 ;
    for (int i = 0; i < r; i++) // this should only run for n times
    {
        ans = ans * (n - i) ; // fo the numerator 
        ans = ans / i + 1 ;
    }
    return ans ;
}

//time complexity : O()