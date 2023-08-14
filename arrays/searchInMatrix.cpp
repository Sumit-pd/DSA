// extreme brute
bool findTargetInMatrix(vector<vector<int>> &mat, int m, int n, int target)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == target)
            {
                return true;
            }
        }
    }
    return false;
}

// better
bool searchMatrix(vector<vector<int>> &mat, int target)
{
    int n = mat.size();
    int m = mat[0].size();

    for (int i = 0; i < n; i++)
    {
        if (mat[i][0] <= target && mat[i][m - 1] >= target)
        {
            bool smallAns = binary_search(mat[i].begin(), mat[i].end(), target);
            if (smallAns)
            {
                return true;
            }
        }
    }

    return false;
}

// optimal

bool searchMatrix(vector<vector<int>> &mat, int target)
{
    int n = mat.size();
    int m = mat[0].size();
    int low = 0;
    int high = (n * m) - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int row = mid / m;
        int col = mid % m;
        if (mat[row][col] == target)
        {
            return true;
        }
        if (mat[row][col] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return false;
}