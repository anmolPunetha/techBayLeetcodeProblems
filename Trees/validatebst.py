class Solution:
    ans=True
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        minVal=-math.inf
        maxVal=math.inf


        def helper(root, minVal, maxVal):
            if root is None:
                return
            
            if root.val<=minVal or root.val>=maxVal:
                self.ans=False

            helper(root.left,minVal,root.val)
            helper(root.right,root.val,maxVal)

        helper(root,minVal,maxVal)
        return self.ans
