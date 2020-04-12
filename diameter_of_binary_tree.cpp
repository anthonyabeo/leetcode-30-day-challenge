/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <pair>

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        
        return diameterOfSubtree(root).second;
    }
    
    std::pair<int,int> diameterOfSubtree(TreeNode* node) {
        if(node == NULL)
            return {0, 0};
        
        auto l = diameterOfSubtree(node->left);
        auto r = diameterOfSubtree(node->right);
        
        auto new_depth = std::max(l.first, r.first) + 1;
        auto new_diameter = std::max({l.second, r.second, l.first+r.first});
        
        return {std::max(l.first, r.first) + 1, new_diameter};
    }
};