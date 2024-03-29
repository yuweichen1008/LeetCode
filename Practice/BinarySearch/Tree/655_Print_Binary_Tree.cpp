/**
Input: root = [1,2,3,null,4]
Output: 
[["","","","1","","",""],
 ["","2","","","","3",""],
["","","4","","","",""]]
 */
class Solution {
public:
    vector<vector<string>> printTree(TreeNode* root) {
        int h = getHeight(root);
        int w = pow(2,h)-1;
        vector<vector<string>> ans(h, vector<string>(w, ""));
        fillin(ans, root, 0, 0, w);
        return ans;
    }
    int getHeight(TreeNode* root){
        if(!root) return 0;
        return max(getHeight(root->left), getHeight(root->right)) + 1;
    }
    void fillin(vector<vector<string>>& ans, TreeNode* p, int level, int l, int r){
        if (!p) return;
        int mid = l+(r-l)/2;
        ans[level][mid] = to_string(p->val);
        fillin(ans, p->left, level+1, l, mid-1);
        fillin(ans, p->right, level+1, mid+1, r);
    }
};