class Solution:
    
    #Function to return a list of nodes visible from the top view 
    #from left to right in Binary Tree.
    minLevel=1
    maxLevel=-1
    def topView(self,root):
        
        d={}
        def helper(root, vLevel, hLevel):
            if root is None:
                return
            
            self.minLevel=min(self.minLevel,vLevel)
            self.maxLevel=max(self.maxLevel,vLevel)
            # check in dict for this corresponding vLevel
            if vLevel not in d:
                d[vLevel] = (root.data, hLevel)
            elif hLevel < d[vLevel][1]:
                d[vLevel] = (root.data, hLevel)
            
            helper(root.left,vLevel-1,hLevel+1)
            helper(root.right,vLevel+1,hLevel+1)
        
        helper(root, 0, 1)
        ans=[]
        #how much max and min is there
        #simply iterate your dict, and get the min and max from there
        for i in range(self.minLevel, self.maxLevel+1):
            ans.append(d[i][0])
        return ans
