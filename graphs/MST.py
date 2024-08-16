class DSU:
    def __init__(self, v): #constructor
        self.parent = [0]*v
        self.rank = [1]*v
        for i in range(v):
            self.parent[i]=i
    
    def find(self, x):
        if self.parent[x]==x:
            return x
        
        self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
        
    def union(self, x, y):
        s1 = self.find(x)
        s2 = self.find(y)
        if s1!=s2:
            if self.rank[s1]<self.rank[s2]:
                self.parent[s1]=s2
                self.rank[s2]+=self.rank[s1]
            else:
                self.parent[s2]=s1
                self.rank[s1]+=self.rank[s2]

class Solution:
    #Function to find sum of weights of edges of the Minimum Spanning Tree.
    def spanningTree(self, v, adj):
        #code here
        obj = DSU(v)
        # define own custom comparator/ re-arrange the values to bring weight 
        # on the first place
        edges = []
        for i in range(len(adj)):
            for nbr in adj[i]:
                edges.append([nbr[1], i, nbr[0]]) #5 0 1
        
        edges.sort()
        ans=0
        #sort the edges
        #traverse the edges==> check with find, then we will union and add the cost
        for edge in edges:
            x, y = edge[1], edge[2]
            if obj.find(x)!=obj.find(y):
                ans+=edge[0]
                obj.union(x,y)
        
        return ans
