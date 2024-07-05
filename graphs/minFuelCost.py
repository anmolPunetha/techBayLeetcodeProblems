class Solution:
    def minimumFuelCost(self, roads: List[List[int]], seats: int) -> int:
        #need to make the graph
        #dfs from 0
        #fuel
        #d={} #key=node, value=list of neighbors
        if len(roads)==0:
            return 0
        d={}
        self.fuel=0
        for l in roads:
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

        def dfs(node,parent,d):
            count=1
            for nbr in d[node]:
                if nbr!=parent:
                    count+=dfs(nbr,node,d)

            if node!=0:
                self.fuel+=count//seats
                if count%seats:
                    self.fuel+=1
            
            return count
            
        dfs(0,-1, d)
        return self.fuel
        
            
