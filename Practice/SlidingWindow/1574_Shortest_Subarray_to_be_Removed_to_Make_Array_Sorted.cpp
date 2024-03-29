/*
Input: arr = [1,2,3,10,4,2,3,5]
Output: 3
Explanation: The shortest subarray we can remove is [10,4,2] of length 3. The remaining elements after that will be [1,2,3,3,5] which are sorted.
Another correct solution is to remove the subarray [3,10,4].
*/
// Time O(N) Space O(1)
class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& A) {
        int N = A.size();
        int r;
        for(r = N-1; r > 0; r--) if(A[r] < A[r-1]) break;
        int ans = r;
        for(int i = 0; i < N-1 && i < r; i++){
            if(r == N || A[i] <= A[r]) ans = min(ans, r - i - 1);
            else r++;
            if(A[i] > A[i+1]) break;
        }
        return ans;
    }
};