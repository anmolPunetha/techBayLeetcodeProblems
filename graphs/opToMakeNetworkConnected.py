class Solution:
    def makeConnected(self, n: int, connections: List[List[int]]) -> int:
        #how many cable are there for us = number of connections
        #how many extra cables needed?? = number of connected comp - 1

        #make a graph
        #find cc
        # do the maths
        if len(connections) < n-1: # to make everything connected u need n-1
            return -1

        d={}
        visited=[0]*n
        for l in connections:
            a,b=l[0],l[1]
            #a->b
            if a in d:
                d[a].append(b)
            else:
                d[a]=[b]

            #b->a
            if b in d:
                d[b].append(a)
            else:
                d[b]=[a]
            
        def dfs(node):
            visited[node]=1

            if node in d:
                for nbr in d[node]:
                    if visited[nbr]!=1:
                        dfs(nbr)
                    
        ccc=0
        for i in range(n):
            if visited[i]==0:
                dfs(i)
                ccc+=1
        
        return ccc-1
        
