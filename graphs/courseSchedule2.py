class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        # //create a graph
        # //create the indegree array
        # //for starting bfs, insert 0 indegree nodes in queue
        # //perform bfs
        # //during bfs, when indegree of a node is 0, insert it in the queue
        # //check: at the end, if all nodes have 0 indegree, then u return the array
        # //otherwise retrun an empty array

        graph = {}
        ans=[]
        indegree = [0]*numCourses
        for connection in prerequisites:
            a,b = connection[0],connection[1]
            #b->a
            if b in graph:
                graph[b].append(a)
            else:
                graph[b]=[a]
            
            #updating the indegree
            indegree[a]+=1
        
        q = deque()
        for i in range(numCourses):
            if indegree[i]==0:
                q.append(i)
            
        while len(q)>0:
            node = q.popleft() #pop, and save in the variable node
            ans.append(node)

            if node in graph:
                for nbr in graph[node]:
                    indegree[nbr]-=1
                    if indegree[nbr]==0:
                        q.append(nbr)
                    
        print(indegree)
        for i in range(numCourses):
            if indegree[i]!=0:
                #topological sort can not be applied
                return []
        
        return ans

