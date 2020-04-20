# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def bstFromPreorder(self, preorder: List[int]) -> TreeNode:
        # if preorder is empty or None return None
        if preorder is None or len(preorder) < 1:
            return None
        
        # create root node using preorder[0]
        root = TreeNode(preorder[0])
        
        
        for i in range(1, len(preorder)):
            self.insert(root, preorder[i])
        
        return root
    
    def insert(self, node: TreeNode, val: int):
          if val < node.val:
              if node.left == None:
                  node.left = TreeNode(val)
              else:
                  self.insert(node.left, val)

              return
          elif val > node.val:
              if node.right == None:
                  node.right = TreeNode(val)
              else:
                  self.insert(node.right, val)

              return
          else:
              return