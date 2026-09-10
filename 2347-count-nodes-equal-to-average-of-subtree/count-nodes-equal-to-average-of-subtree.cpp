/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
//  1234567890-=qwertyuiopasdfghjkl;         zxcvbnm,./

class Solution {
    int ans = 0;
    // {sum, total nodes};
    pair<int,int> findAverageOfSubTree(TreeNode* node) {
        if(node == nullptr) return {0,0};

        pair<int,int> l = findAverageOfSubTree(node->left);
        pair<int,int> r = findAverageOfSubTree(node->right);

        int sum = l.first + r.first + node->val;
        int count =l.second + r.second + 1;

        int avg = (sum/count) ;
        if(avg == node->val) ans++;
        
        return {sum,count};
    }

public:
    int averageOfSubtree(TreeNode* root) {
        findAverageOfSubTree(root);
        return ans;
    }
};