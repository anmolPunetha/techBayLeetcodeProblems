class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        def lca(root, p, q):
            if root is None:
                return None

            if root.val==p.val or root.val==q.val:
                return root
            
            lsa = lca(root.left,p,q)
            rsa = lca(root.right,p,q)

            if lsa!=None and rsa!=None:
                #this is what lca is
                return root
            
            if lsa!=None: #rsa is none
                return lsa
            
            return rsa
        
        return lca(root,p,q)


# p=7,q=4
# ancestors for 7=3,5,2
# ancestors for 4=3,5,2
# ans=2

# # p=6,q=4
# p:3,5,6
# q:3,5,2,4
# # ans=5

# # p=5,q=4
# # for 5=3,5
# # for 4=3,5,2


# # lca=both the nodes are accessible

# p,q
# get all the ancestors: 

# p=4,q=0
# p:3,5,2,4
# q:3,1,0

# p=0: ancestor of 0
# 3,1,0

# 3,1,0

# #=this will be an ancestor---save it----left and right----false/true

# TC: 3xO(N)

# SC: O(N) {excluding the rec call stack}
