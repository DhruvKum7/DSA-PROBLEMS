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
    int answer ;

    int dfs(TreeNode* root){
        if(root==NULL){
            return 2;
        }
        
       
        int l=dfs(root->left);
        int r=dfs(root->right);

        if(l==0 || r==0){
            answer++;
            return 1;
        }
        if(l==1||r==1){
            return 2;
        }
        return 0;

    }
    int minCameraCover(TreeNode* root) {
        answer = 0;
        if(dfs(root)==0) answer++;
    
        return answer;

    }
};