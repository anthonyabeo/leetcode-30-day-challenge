/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode
 * left; TreeNode right; TreeNode() {} TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) { this.val = val; this.left
 * = left; this.right = right; } }
 */
class Solution {
    public boolean isUnivalTree(TreeNode root) {
        if (root == null)
            return false;

        int x = root.val;

        return isUnivalTree(root, x);
    }

    public boolean isUnivalTree(TreeNode node, int x) {
        if (node == null)
            return true;

        return isUnivalTree(node.left, x) && node.val == x && isUnivalTree(node.right, x);
    }
}