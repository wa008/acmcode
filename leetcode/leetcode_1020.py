class Solution:
    def numEnclaves(self, arr):
        n = len(arr)
        m = len(arr[0])
        des = [[0,1],[0,-1],[1,0],[-1,0]]
        vis = [[0 for i in range(m)] for j in range(n)]
        def dfs(i,j):
            nonlocal vis
            if i<0 or j<0 or i>=n or j>=m or arr[i][j] == 0 or vis[i][j] == 1:
                return 
            vis[i][j] = 1
            for k in range(4):
                ni = i+des[k][0]
                nj = j+des[k][1]
                dfs(ni,nj)
        for i in range(n):
            if arr[i][0] == 1 and vis[i][0] == 0:
                dfs(i,0)
            if arr[i][m-1] == 1 and vis[i][m-1] == 0:
                dfs(i,m-1)
        for i in range(m):
            if arr[0][i] == 1 and vis[0][i] == 0:
                dfs(0,i)
            if arr[n-1][i] == 1 and vis[n-1][i] == 0:
                dfs(n-1,i)
        ans = 0
        for i in range(n):
            for j in range(m):
                if arr[i][j] == 1 and vis[i][j] == 0:
                    ans += 1
        return ans
