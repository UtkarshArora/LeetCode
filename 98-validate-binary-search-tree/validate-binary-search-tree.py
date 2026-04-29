# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:


    def isValid(self, root : Optional[ListNode], minVal, maxVal) -> bool:
        if not root:
            return True
        
        if root.val > minVal and root.val < maxVal:
            return self.isValid(root.left, minVal, root.val) and self.isValid(root.right, root.val, maxVal)
       
        return False

    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        
        minVal = float('-inf')
        maxVal = float('inf')

        return self.isValid(root, minVal, maxVal)
        
        