int getMaxIndex(int amount[],int n)
{
    int ind=0;
    for(int i=1;i<n;i++)
    {
        if(amount[i]>amount[ind])
        {
            ind=i;
        }
    }
    return ind;
}
int getMinIndex(int amount[],int n)
{
    int ind=0;
    for(int i=1;i<n;i++)
    {
        if(amount[i]<amount[ind])
        {
            ind=i;
        }
    }
    return ind;
}
void MinimumCashFlow(int amount[],int n,vector<vector<int>>&ans)
{
    int MaxDebt=getMinIndex(amount,n);
    int MaxCredit=getMaxIndex(amount,n);
    
    if(amount[MaxDebt]==0 && amount[MaxCredit]==0)
    {
        return ;
    }
    
    int mini = min( (-1) *amount[MaxDebt] , amount[MaxCredit]);
    amount[MaxCredit]-=mini;
    amount[MaxDebt]+=mini;



    ans[MaxDebt][MaxCredit]=mini;
    
    MinimumCashFlow(amount,n,ans);
}

vector<vector<int>> minCashFlow(vector<vector<int>>& transaction, int n)
{
    int amount[n]={0};
    vector<vector<int>>ans(n,vector<int>(n,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            amount[i]+=(transaction[j][i]-transaction[i][j]);
        }
    }
    MinimumCashFlow(amount,n,ans);
    return ans;
}