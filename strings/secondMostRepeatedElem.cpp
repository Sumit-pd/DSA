#include <map>
#include <string>
#include <queue>
using namespace std;

// the following is not a nice solution
// this will fail in the case all elements have same frequency

string second_repeat(vector<string> &arr, int n)
{
    unordered_map<string, int> mp;
    for (auto it : arr)
    {
        mp[it]++;
    }

    priority_queue<pair<int, string>> pq;
    for (auto it : mp)
    {
        pq.push({it.second, it.first});
    }
    pq.pop();
    return pq.top().second;
}

// avoid using priority queue
string second_repeat(vector<string> &arr, int n)
{
    map<string, int> mpp;
    int largest = 0;
    int second_largest = 0;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }

    for (auto it : mpp)
    {
        if (it.second > largest)
        {
            second_largest = largest;
            largest = it.second;
        }
        else if (it.second > second_largest && it.second < largest)
        {
            second_largest = it.second;
        }
    }

    for (auto it : mpp)
    {
        if (it.second == second_largest)
        {
            return it.first;
        }
    }
    return "";
}