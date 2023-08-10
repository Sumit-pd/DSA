int bestTimeToBuyAndSellStock(vector<int> &arr)
{
    int minimun = arr[0];
    int n = arr.size();
    int maxi = 0;
    for (int i = 1; i < n; i++)
    {
        int profit = arr[i] - minimun;
        maxi = max(profit, maxi);
        minimun = min(minimun, arr[i]);
    }
    return maxi;
}
