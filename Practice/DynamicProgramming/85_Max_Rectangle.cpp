/*
Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
*/
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m == 0) return 0;
        int n = matrix[0].size();
        if(n == 0) return 0;
        int ans = 0;
        vector<int> L(n, 0);
        vector<int> R(n, n);
        vector<int> H(n, 0);
        for(int i = 0; i < m; i++){
            int cur_left = 0, cur_right = n;
            // Get height
            for(int j = 0; j < n; j++){
                if(matrix[i][j]=='1') H[j]++;
                else H[j] = 0;
            }
            // Get Left
            for(int j = 0; j < n; j++){
                if(matrix[i][j]=='1') L[j] = max(L[j], cur_left);
                else L[j] = 0, cur_left = j+1;
            }
            // Get Right
            for(int j = n-1; j >= 0; j--){
                if(matrix[i][j]=='1') R[j] = min(R[j], cur_right);
                else R[j] = n, cur_right = j;
            }
            // Get Area
            for(int j = 0; j < n; j++){
                ans = max(ans, (R[j]-L[j])*H[j]);
            }
        }
        return ans;
    }
};
/*
If you think this algorithm is not easy to understand, you can try this example:

0 0 0 1 0 0 0 
0 0 1 1 1 0 0 
0 1 1 1 1 1 0
row 0:

l: 0 0 0 3 0 0 0
r: 7 7 7 4 7 7 7
row 1:

l: 0 0 2 3 2 0 0
r: 7 7 5 4 5 7 7 
row 2:

l: 0 1 2 3 2 1 0
r: 7 6 5 4 5 6 7
*/