/*
Input: head = [2,1,5]
Output: [5,5,0]
*/
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> res, stack;
        for(ListNode* node = head; node; node = node->next){
            while(stack.size() && res[stack.back()] < node->val){
                res[stack.back()] = node->val;
                stack.pop_back();
            }
            stack.push_back(res.size());
            res.push_back(node->val);
        }
        for(int i : stack) res[i] = 0;
        return res;
    }
};