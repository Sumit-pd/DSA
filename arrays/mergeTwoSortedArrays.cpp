#include <bits/stdc++.h>
using namespace std;
/*
brute
-normal merge sort type
-create a third array and store the element of both the arrays in sorted order
-replace them back in the original arrays
-time complexity - O(n + m ) + O(n+m)
space complexity - O(n + m)
*/

void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b)
{
    int n = a.size();
    int m = b.size();
    vector<long long> arr(n + m);
    int i = 0, j = 0, k = 0;
    while (i < n && j < m)
    {
        if (a[i] <= b[j])
        {
            arr[k] = a[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = b[j];
            j++;
            k++;
        }
    }
    while (i < n)
    {
        arr[k] = a[i];
        i++;
        k++;
    }
    while (j < m)
    {
        arr[k] = b[j];
        j++;
        k++;
    }

    for (i = 0; i < n + m; i++)
    {
        if (i < n)
        {
            a[i] = arr[i];
        }
        else
        {
            b[i - n] = arr[i];
        }
    }
}

/*
optimal 1
-two pointers left and right
-left = n - 1
-right = 0
-swap if the a[left] > b[right]
time complexity : O(min(n,m)) + O(nlogn) + O(mlogm)
space complexity : O(1)

*/

void mergeTwoSortedArraysWithoutExtraSpace2(vector<long long> &a, vector<long long> &b)
{
    int n = a.size();
    int m = b.size();
    int i = n - 1, j = 0;
    while (i >= 0 && j < m)
    {
        if (a[i] > b[j])
        {
            swap(a[i], b[j]);
            i--;
            j++;
        }
        else
        {
            break;
        }
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
}

/*
optimal 2
-gap method
-

*/
void swapIfGreter(vector<long long> &a, vector<long long> &b, int i, int j)
{
    if (a[i] > b[j])
    {
        swap(a[i], b[j]);
    }
}
void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b)
{
    int n = a.size();
    int m = b.size();
    int gap = ((n + m) / 2) + ((n + m) % 2);

    while (gap > 0)
    {
        int left = 0;
        int right = left + gap;
        // left is in arr1 and right is in arr2
        while (right < n + m)
        {
            if (left < n && right >= n)
            {
                swapIfGreter(a, b, left, right - n);
            }
            // left and right both is in arr2
            else if (left >= n)
            {
                swapIfGreter(a, b, left - n, right - n);

            } // left and right both is in arr1
            else
            {
                swapIfGreter(a, b, left - n, right - n);
            }
            left++;
            right++;
        }
        if (gap == 1)
        {
            break;
        }
        gap = (gap / 2) + (gap % 2);
    }
}