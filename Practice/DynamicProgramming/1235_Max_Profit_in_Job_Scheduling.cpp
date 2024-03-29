/*
We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].
You're given the startTime, endTime and profit arrays, return the maximum profit you can take such that there are no two jobs in the subset with overlapping time range.
If you choose a job that ends at time X you will be able to start another job that starts at time X.

Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
Output: 120
Explanation: The subset chosen is the first and fourth job. 
Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.
*/
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = profit.size();
        // 1. sort endTime
        vector<vector<int>> jobs;
        for(int i = 0 ; i < n; i++){
            jobs.push_back({endTime[i], startTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());
        map<int, int> dp = {{0,0}}; // endTime , profit
        for(auto job : jobs){
            int cur = prev(dp.upper_bound(job[1]))->second + job[2]; // profit
            if(cur > dp.rbegin()->second)
                dp[job[0]] = cur;
        }
        return dp.rbegin()->second;
    }
};