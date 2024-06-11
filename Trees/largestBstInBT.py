class nodeInfo:
 
    def __init__(self, count, min_, max_):
        self.count=count
        self.min_=min_
        self.max_=max_
        

class Solution:
    # Return the size of the largest sub-tree which is also a BST
    def helper(self, root):
        if root is None:
            node = nodeInfo(0, 10000000, -10000000) # None
            return node
        
        if root.left==None and root.right==None:
            node = nodeInfo(1, root.data, root.data)
            return node
        
        l_node = self.helper(root.left)
        r_node = self.helper(root.right)
        
        #node->val
        if (l_node.max_<root.data) and (root.data<r_node.min_):
            total_count=l_node.count+r_node.count+1
            node = nodeInfo(total_count, min(l_node.min_,r_node.min_,root.data), max(r_node.max_,l_node.max_,root.data))
            return node
        else:
            total_count = max(l_node.count,r_node.count)
            node = nodeInfo(total_count, -10000000, 10000000)
            return node
        
        #return node
        # that the current node if roming a bst
        # or its not
    def largestBst(self, root):
        #code here
        node = self.helper(root)
        return node.count
