#include <bits/stdc++.h>

/*
brute force
-two for loops
time complexity : O(N2)
space complexity : O(1)

*/
vector<int> findMissingRepeatingNumbers(vector<int> a)
{
    vector<int> ans;
    int n = a.size();
    int rNum, mNum;
    for (int i = 1; i <= n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (i == a[j])
            {
                cnt++;
            }
        }
        if (cnt == 2)
        {
            rNum = i;
        }
        if (cnt == 0)
        {
            mNum = i;
        }
    }
    ans.push_back(rNum);
    ans.push_back(mNum);
    return ans;
}
/*
better
-use hash array
time complexity : O(N) + O(N)
-space complexity : O(N)
*/
vector<int> findMissingRepeatingNumbers(vector<int> a)
{
    int n = a.size();
    vector<int> hashSet(n + 1, 0); // the number are from 1 to n so we need the nth index so the size will be n + 1
    for (int i = 0; i < n; i++)
    {
        hashSet[a[i]]++;
    }
    int rNum;
    int mNum;
    for (int i = 1; i <= n; i++)
    {
        if (hashSet[i] == 0)
        {
            mNum = i;
        }
        if (hashSet[i] == 2)
        {
            rNum = i;
        }
    }
    // vector<int> ans = {rNum, mNum};
    return {rNum, mNum};
}
/*
optimal 1
-maths
*/
vector<int> findMissingRepeatingNumbers(vector<int> a)
{
    long long n = a.size();
    // s - sn
    long long s = (n * (n - 1)) / 2;

    long long sn = 0;
    long long s2 = (n * (n + 1) * (2 * n + 1)) / 6;
    long long sn2 = 0;
    for (int i = 0; i < n; i++)
    {
        sn += (long long)a[i];
        sn2 += (long long)arr[i] * (long long)arr[i];
    }
    long long val1 = s - sn; //  x - y
    long long val2 = s2 - sn2;
    val2 = val2 / val1; // x + y
    long long x = (val1 + val2) / 2;
    long long y = x - val1;
    return {(int)x, (int)y};
}



