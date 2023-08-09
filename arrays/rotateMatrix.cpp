#include <bits/stdc++.h>

void brute(vector<vector<int>> &arr)
{
    int row = arr.size();
    int col = arr[0].size();
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; i++)
        {
            if (arr[i][j] = 0)
            {
                arr[i][j] = -1
            }
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] == -1)
            {
                arr[i][j] = 0;
                for (int k = 0; k < col; k++)
                {
                    if (arr[i][k] != -1)
                    {
                        arr[i][k] = 0;
                    }
                }

                for (int k = 0; k < row; k++)
                {
                    if (arr[k][j] != -1)
                    {
                        arr[k][j] = 0;
                    }
                }
            }
        }
    }
}

void setZeros(vector<vector<int>> &arr)
{
    unordered_set<int> row;
    unordered_set<int> col;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            if (arr[i][j] == 0)
            {
                row.insert(i);
                col.insert(j);
            }
        }
    }
    for (int x : row)
    {
        for (int i = 0; i < arr[0].size(); i++)
        {
            arr[x][i] = 0;
        }
    }
    for (int y : col)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            arr[i][y] = 0;
        }
    }
}

void setZeros(vector<vector<int>> &arr)
{
    bool firstCol = false;
    bool firstRow = false;
    
    // checking for the first col O(n)
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i][0] == 0)
        {
            firstCol = true;
            break;
        }
    }
    
    // checking for the first row O(m)
    for (int i = 0; i < arr[0].size(); i++)  
    {
        if (arr[0][i] == 0)
        {
            firstRow = true;
            break;
        }
    }

    // checking for the entire matrix O(n*m)
    for (int i = 1; i < arr.size(); i++)
    {
        for (int j = 1; j < arr[0].size(); j++)
        {
            if (arr[i][j] == 0)
            {
                arr[i][0] = 0;
                arr[0][j] = 0;
            }
        }
    }

    // updating the matrix for row
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i][0] == 0)
        {
            for (int j = 1; j < arr[0].size(); j++)
            {
                arr[i][j] = 0;
            }
        }
    }
    
    // updating the matrix for col
    for (int j = 1; j < arr[0].size(); j++)  // Corrected the loop index variable from i to j
    {
        if (arr[0][j] == 0)  // Removed the unnecessary semicolon
        {
            for (int i = 1; i < arr.size(); i++)
            {
                arr[i][j] = 0;
            }
        }
    }
    
    if (firstRow)
    {
        for (int i = 0; i < arr[0].size(); i++)
        {
            arr[0][i] = 0;
        }
    }
    if (firstCol)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            arr[i][0] = 0;
        }
    }
}
