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
    int prevVal = -1;
    int result = INT_MAX;

    void solve(TreeNode* root){
        if(!root) return;
        solve(root->left);
        if(prevVal != -1){
            result = min(result, root->val - prevVal);
        }
        prevVal = root->val;
        solve(root->right);
    }

    int minDiffInBST(TreeNode* root) {
        solve(root);
        return result;
    }
};
