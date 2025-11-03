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
    int maxDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        stack<pair<TreeNode*,int>>st;
        int maxpnt = 0;
        st.push({root,1});
        while(!st.empty()){
            auto it = st.top();
            st.pop();
           // st.top();
            TreeNode*first = it.first;
            int second = it.second;

            if(first->left==NULL && first->right==NULL)
                maxpnt=max(maxpnt,second);
            if(first->left){
                st.push({first->left , second+1});
            }
            if(first->right){
                st.push({first->right,second+1});
            }
            
        }
        return maxpnt;
    }
};