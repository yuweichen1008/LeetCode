class Solution {
public:
    int numWays(int n, int k) {
      if(n == 1) return k;
      if(n == 2) return k*k;
      vector<int> dp(n+1, 0);
      dp[1] = k;
      dp[2] = k * k;
      for(int i = 3; i <= n; ++i){
        // num_way[i] = num_same[i] + num_diff[i]
        // num_diff[i] = num_way[i-1] * (k-1)
        // num_same[i] = num_diff[i-1] * 1
        // => num_way[i] = num_diff[i-1] + num_diff[i]
        dp[i] = (dp[i-1] + dp[i-2]) * (k-1);
      }
      return dp[n];
    }
};