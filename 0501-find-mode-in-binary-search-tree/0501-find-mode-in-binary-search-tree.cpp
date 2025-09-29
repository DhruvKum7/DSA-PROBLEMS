class Solution {
public:
    void inorder(TreeNode* root, unordered_map<int,int>& mp){
        if(!root) return;
        inorder(root->left, mp);
        mp[root->val]++;                 // count frequency
        inorder(root->right, mp);
    }

    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> mp;
        inorder(root, mp);

        int maxi = 0;
        for (auto &p : mp) maxi = max(maxi, p.second);

        vector<int> result;
        for (auto &p : mp) {
            if (p.second == maxi) result.push_back(p.first);
        }
        return result;
    }
};