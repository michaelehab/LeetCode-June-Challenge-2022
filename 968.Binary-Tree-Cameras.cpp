/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // States
    enum {NO, MAY, YES};
    int ans = 0;
    
    int dfs(TreeNode *root) {
        if (!root) return MAY;
        int l = dfs(root->left);
        int r = dfs(root->right);
        if (!l || !r) {
            ans++;
            return YES;
        } 
        else if (l == YES || r == YES) return MAY;
        else return NO;
    }
    
    int minCameraCover(TreeNode* root) {
        if (dfs(root) == NO) ans++;
        return ans;
    }
};