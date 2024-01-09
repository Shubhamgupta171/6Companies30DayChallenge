class Solution {
public:
    unordered_map<int, unordered_map<int,int>> dp;
    int const mod = 1e9+7;
    int solve(int start, int end, int k)
    {
        if(start==end && k==0)
        {
            return 1;
        }
        if(k<=0 || start+k < end || start-k > end) return 0;
        if(dp[start].count(k)) return dp[start][k];
        
        int a = (solve(start+1, end, k-1))%mod;
        int b = (solve(start-1, end, k-1))%mod;
        return dp[start][k] = (a+b)%mod;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        return ((solve(startPos, endPos, k)))%mod;
    }
};
