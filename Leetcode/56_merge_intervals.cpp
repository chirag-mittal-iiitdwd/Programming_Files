#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();

        vector<vector<int>> answer;

        int start = intervals[0][0];
        int end = intervals[0][1];

        for (int i = 0; i < n - 1; i++)
        {
            if (intervals[i + 1][0] <= end)
                end = max(intervals[i + 1][1], end);
            else
            {
                answer.push_back({start, end});
                start = intervals[i + 1][0];
                end = intervals[i + 1][1];
            }
        }
        answer.push_back({start, end});

        return answer;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> intervals(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            int x;
            cin >> x;
            intervals[i].push_back(x);
        }
    }

    Solution obj;
    vector<vector<int>> ans = obj.merge(intervals);
    for (auto &it : intervals)
    {
        for (auto &i : it)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl;
}