class Solution:
    ans=0
    def longestCycle(self, edges: List[int]) -> int:
        #create the graph
        #0 is the source
        #visited, current_path

        graph={}
        for i in range(0,len(edges)):
            # i to edges[i]
            if edges[i]==-1:
                continue
            if i in graph:
                graph[i].append(edges[i])
            else:
                graph[i]=[edges[i]]

        def dfs(node, visited, current_path, count):
            #mark it visited
            #save it in the current path
            #traverse its neighbors
            #check the nbr, if it is the current path
            #if not, make the dfs call

            visited[node]=1
            current_path[node]=count

            if node in graph:
                for nbr in graph[node]:
                    if visited[nbr]==0:
                        dfs(nbr,visited,current_path,count+1)
                    else:
                        if current_path[nbr]!=0:
                            #there is a cycle
                            length = current_path[node]-current_path[nbr]+1
                            self.ans=max(self.ans,length)
            current_path[node]=0
            return

        visited=[0]*(len(edges))
        current_path = [0]*len(edges)
        for i in range(len(edges)):
            if visited[i]==0:
                count=1
                dfs(i, visited, current_path, count)
        if self.ans==0:
            return -1
        return self.ans
