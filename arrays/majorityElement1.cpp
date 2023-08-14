// brute

int majorityElement(vector<int> arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                cnt++;
            }
        }
        if (cnt >= n / 2)
            return arr[i];
    }
}

// better
int majorityElement(vector<int> arr)
{
    int n = arr.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }

    for (auto it : mp)
    {
        if (it.second >= n / 2)
            return it.first;
    }
    return -1;
}

int majorityElemet(vector<int> arr)
{
    int n = arr.size();
    int element = arr[0];
    int cnt = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == cnt)
        {
            cnt++
        }
        if (cnt == 0)
        {
            element = arr[i]; // we have neutralized the array , up to this part there is no majority element
        }
        else
        {
            cnt--;
        }
    }
    return element;
}