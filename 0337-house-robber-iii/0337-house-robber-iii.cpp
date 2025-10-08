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
    int solve(TreeNode* root,unordered_map<TreeNode*,int>&mp){
        if(root==NULL){
            return 0;
        }
        //int take = root->val + solve(root->left->left) + solve(root->left->right)+solve(root->right->right)+solve(root->right->left);
        if(mp.count(root)){
            return mp[root];
        }
        int take = root->val;
        if(root->left){
           take  = root->val + solve(root->left->left,mp) + solve(root->left->right,mp);
        }
        if(root->right){
            take = take + solve(root->right->right,mp) + solve(root->right->left,mp);
        }
        int skip = solve(root->left,mp)+solve(root->right,mp);

        return mp[root]=max(take,skip);
    }
    int rob(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        unordered_map<TreeNode*,int>mp;
      return  solve(root,mp); 
    }
};