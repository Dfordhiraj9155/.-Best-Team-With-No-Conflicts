#include <bits/stdc++.h>
using namespace std;
class solution
{
public:
    vector<vector<int>> dp;
    int solve(vector<pair<int, int>> &players, int n, int curr, int prev)
    {
        if (dp[curr][prev + 1] != -1)
            return dp[curr][prev + 1];
        if (curr == n)
            return (dp[curr][prev + 1] == 0);
        int notTake = solve(players, n, curr + 1, prev);
        if (curr == -1 || players[prev].second <= players[curr].second)
        {
            int take = players[curr].second + solve(players, n, curr + 1, curr);
            return dp[curr][prev + 1] = max(take, notTake);
        }
        return dp[curr][prev + 1] = notTake;
    }
    int bestTeamScore(vector<int> &scores, vector<int> &ages)
    {
        dp.resize(1002, vector<int>(1002, -1));
        vector<pair<int, int>> players;
        int n = scores.size();
        for (int i = 0; i < n; i++)
        {
            players.push_back({ages[i], scores[i]});
        }
        sort(players.begin(), players.end());
        return solve(players, n, 0, -1);
    }
};